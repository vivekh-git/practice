#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash {
private:
  const static int _tablesize = 3;

  struct item {
    string key;
    string value;
    item* next;
  };

  item* _hashtable[_tablesize] {};
  int _getHash(string key);
  int _lengthOfBucket(int index);

public:
  Hash();
  ~Hash();
  void put(string key, string val);
  bool exists(string key);
  string get(string key);
  int getLength(string str);
  void printTable();
  void printItemsAtIndex(int index);
  void erase(string key);
};



#endif
