#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

Hash::Hash() {
  for (int i = 0; i < _tablesize; i++) {
    //_hashtable[i] = new item;
    _hashtable[i] = NULL;
  }
}

Hash::~Hash() {
  for (int i = 0; i < _tablesize; i++) {
    // if (next) delete hashtable->next
    if (_hashtable[i]) delete _hashtable[i];
    _hashtable[i] = NULL;
  }
}

int Hash::_getHash(string key) {
  int hash = 0;
  for (int i = 0; i < key.length(); i++) {
    hash = (hash + (int)key[i]) * 17;
  }
  return hash % _tablesize;
}

int Hash::_lengthOfBucket(int index) {
  int length = 0;
  item* runner = _hashtable[index];
  if (!runner) {
    return length;
  }
  else {
    length++;
    while (runner->next) {
      runner = runner->next;
      length++;
    }
  }
  return length;
}

int Hash::getLength(string str) {
  int index = _getHash(str);
  return _lengthOfBucket(index);
}

void Hash::printTable() {
  for (int i = 0; i < _tablesize; i++) {
    cout << "Postion " << i << " ";
    cout << _hashtable[i]->key << " ";
    cout << _hashtable[i]->value << " ";
    cout << ", length = " << _lengthOfBucket(i);
    printItemsAtIndex(i);
    cout << endl;
  }
}

void Hash::printItemsAtIndex(int index) {
  item* runner = _hashtable[index];
  int count = 1;
  while (runner->next) {
    runner = runner->next;
    count++;
    cout << " , " << count << " - "<<runner->key << " - " << runner->value;
  }
}

void Hash::erase(string key) {
  int bucket = _getHash(key);
  item* it = _hashtable[bucket];
  if (!it) {
    cout << key << " not found, cannot erase" << endl;
    return;
  }
  else if (it->key == key) {
    _hashtable[bucket] = _hashtable[bucket]->next;
    delete it;
    it = NULL;
    return;
  }
  else {
    while ((it->next) && (it->next->key != key)) {
      it = it->next;
    }
    if (! it->next) {
      // no match in the list
      cout << key << " not found in hashtable" << endl;
      return;      
    }
    else {
      item* delPtr = it->next;
      it->next = it->next->next;
      delete delPtr; 
      delPtr = NULL;
      return;
      //item* n = it->next->next;
      //delete it->next;
      //it->next = n;
      //return;
    }
  }
  cout << key << " not found in hashtable" << endl;
}

void Hash::put(string key, string val) {
  int bucket = _getHash(key);
  if (!_hashtable[bucket]) {
    _hashtable[bucket] = new item;
    _hashtable[bucket]->key = key;
    _hashtable[bucket]->value = val;
    _hashtable[bucket]->next = NULL;
  }
  else {
    /* working code
    item* runner = _hashtable[bucket];
    cout << "before entering while loop" << endl;
    while (runner->next != NULL) {
      cout << "in while loop until runner becomes null" << endl;
      runner = runner->next;
    }
    runner->next = new item;
    runner->next->key = key;
    runner->next->value = val;
    runner->next->next = NULL;
    */
    // below code works which is same as above
    item* runner = _hashtable[bucket];
    while (runner->next) {
      runner = runner->next;
    }
    item* n = new item;
    n->key = key;
    n->value = val;
    n->next = NULL;
    runner->next = n;
  }
}

bool Hash::exists(string key) {
  int bucket = _getHash(key);
  item* it = _hashtable[bucket];
  do {
    if (it->key == key) {
      return true;
    }
  } while ((it = it->next));
  return false;
}

string Hash::get(string key) {
  int bucket = _getHash(key);
  item* it = _hashtable[bucket];
  if (! it) {
    cout << key << " not found in hashtable";
    return "";
  }
  else if (it->key == key) { 
    return it->value;
  }
  else {
    while (it->next) {
      it = it->next;
      if (it->key == key) {
        return it->value;
      }
    }
  }
  cout << key << " not found in hashtable";
  return "";
}


int main(int argc, char** argv) {
  string s = "vivek";
  Hash hashtable;

  cout << "hash.get(cat)" << hashtable.get("cat") << endl;
  cout << "hash.get(orange)" << hashtable.get("orange") << endl;

  hashtable.put("cat", "dog");
  hashtable.put("orange", "grape");
  hashtable.put("vivek", "sudha");
  hashtable.put("sudha", "sudha2");
  hashtable.put("reya", "sudha3");
  hashtable.put("lion", "tiger");
  hashtable.put("rose", "sudha4");
  hashtable.put("rose1", "sudha4");
  hashtable.put("rose2", "sudha4");
  hashtable.put("rose333", "sudha4");
  hashtable.put("rose4", "sudha5");
  hashtable.put("rose5", "sudha6");
  hashtable.put("rose6", "sudha7");

  hashtable.printTable();

  cout << "hash.get(cat)" << hashtable.get("cat") << endl;
  cout << "hash.get(orange)" << hashtable.get("orange") << endl;
  cout << "hash.get(vivek)" << hashtable.get("vivek") << endl;
  cout << "hash.get(sudha)" << hashtable.get("sudha") << endl;
  cout << "hash.get(reya)" << hashtable.get("reya") << endl;
  cout << "hash.get(lion)" << hashtable.get("lion") << endl;
  cout << "hash.get(rose)" << hashtable.get("rose") << endl;
  cout << "hash.get(rose1)" << hashtable.get("rose1") << endl;
  cout << "hash.get(rose2)" << hashtable.get("rose2") << endl;
  cout << "hash.get(rose333)" << hashtable.get("rose333") << endl;
  cout << "hash.get(rose4)" << hashtable.get("rose4") << endl;
  cout << "hash.get(rose5)" << hashtable.get("rose5") << endl;
  cout << "hash.get(rose6)" << hashtable.get("rose6") << endl;

/*
  cout << "hash len for rose333=" << hashtable.getLength("rose333") << endl;
  cout << "hash len for rose5=" << hashtable.getLength("rose5") << endl;
  cout << "hash len for sudha=" << hashtable.getLength("sudha") << endl;
*/
  hashtable.printTable();

  cout << "erasing 'sudha' and 'rose333' and 'orange'" << endl; 
  hashtable.erase("sudha");
  hashtable.erase("rose333");
  hashtable.erase("orange");

  hashtable.printTable();

  return 0;
}
