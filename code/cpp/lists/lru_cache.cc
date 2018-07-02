#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

struct node {
   string key;
   int val;
   list<node *>::iterator pos;
};

class Cache {
private:
   unordered_map<string, node*> cache;	
   list<node*> lru;
   static const int CACHE_SIZE = 5;
  
public:
   int get(string key) {
      if (cache.find(key) != cache.end()) {
   	     const node* n = cache[key];
		 // move n to front of lru 
		 list<node *>::iterator it = n->pos;
   	     lru.splice(lru.begin(), lru, it); // moves n to front of list 
		 /*
		 for (list<node*>::iterator it = lru.begin(); it != lru.end(); it++) {
	        //node* n = *it;
			if ((*it)->key == key) {
			    // move to front
				lru.splice(lru.begin(), lru, it);	
			}
	     }*/
		 
   	     return n->val;
      }
      return -1;
   }
   
   void put(string key, int val) {
   	  node* n = new node;
   	  n->val = val;
   	  n->key = key;
	  
   	  if (lru.size() >= CACHE_SIZE) {
   	     const node* last = lru.back();
   		 cache.erase(last->key);
   		 lru.pop_back();
   	  }
   	
   	  cache[key] = n;
	  //lru.push_front(n);
	  
	  list<node *>::iterator it = lru.insert(lru.begin(), n);
   	  n->pos = it; 
   }
   
   // utility
   void printTable() {
   	cout << "printing table" << endl;
   	for (unordered_map<string, node*>::iterator it = cache.begin(); it!= cache.end(); it++) {
   		cout << "k: v - " << it->first << ": " << it->second->val << endl;
   	}
   }
   void printList() {
   	cout << "printing list" << endl;
   	for (list<node*>::iterator it = lru.begin(); it != lru.end(); it++) {
   		node* n = *it;
   		cout << n->val << ", ";
   	}
   	cout << endl;
   }
};


int main() {
   Cache c;
   c.put("k1", 1);
   c.put("k2", 2);
   c.put("k3", 3);
   c.put("k4", 4);
   c.put("k5", 5);
   c.printTable(); c.printList();
   c.put("k6", 6);
   c.printTable(); c.printList();
   c.put("k7", 7);
   c.printTable(); c.printList();
   return 0;
}
