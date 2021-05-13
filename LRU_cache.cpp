#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
      Node *prev, *next;
      int key, val;
      Node (int _key=0, int _val=0):key(_key), val(_val) {}
};

class LRUCache {
      unordered_map<int, Node *> ump;
      int capacity, count;
      Node *head, *tail;

public:
      LRUCache(int capacity) {
            unordered_map<int, Node*> temp;
            ump = temp;
            this->capacity = capacity;
            // make doubly linked list of 2 nodes 
            head = new Node();
            tail = new Node();
            head->next = tail;
            head->prev = NULL;
            tail->next = NULL;
            tail->prev = head;
            count = 0;
      }

      void addToHead(Node *node) {
            // like we do in doubly linked list 
            node->next = head->next;
            node->next->prev = node;
            node->prev = head;
            head->next = node;
      }

      void deleteNode(Node *node) {
            // like in doubly linked list
            node->prev->next = node->next;
            node->next->prev = node->prev;
      }

      int get(int key) {
            if(ump.count(key) > 0) {
                  Node *ptr = ump[key];
                  int result = ptr->val;
                  // delete from here 
                  deleteNode(ptr);
                  // add to front
                  addToHead(ptr);
                  return result;
            }
            return -1;
      }

      void put(int key, int value) {
            if(ump.count(key) > 0) {
                  Node *ptr = ump[key];
                  // update value
                  ptr->val = value;
                  deleteNode(ptr);
                  addToHead(ptr);
            } else {
                  Node *newNode = new Node(key, value);
                  ump[key] = newNode;
                  if(count < capacity) {
                        count += 1;
                        addToHead(newNode);
                  } else {
                        // count > capacity
                        // remove the last node from list 
                        ump.erase(tail->prev->key);
                        deleteNode(tail->prev);
                        addToHead(newNode);
                  }
            }
      }
};


/*
      can be implememtned using list in c++ 
      list::erase function works in liner complexity of number of elements deleted 
      that means we can delete a single element in constant time 
*/

class LRUCache {
    unordered_map<int, list<pair<int,int>>::iterator> table;
    list<pair<int,int>> usage;
    int size;

public: 
    LRUCache(int capacity): size(capacity) { }

    int get(int key) {
         if(table.count(key)) {
            int val = table[key]->second;
            usage.erase(table[key]);
            usage.emplace_front(key, val);
            table[key] = usage.begin();
            return val;
        }       
        return -1;
    }
    
    void put(int key, int value) {
        if(table.count(key)) {
            usage.erase(table[key]);
            usage.emplace_front(key, value);
            table[key] = usage.begin();            
        } else {
            if(static_cast<int>(usage.size()) == size) {
                auto leastUsed = *usage.rbegin();
                table.erase(leastUsed.first);
                usage.pop_back();
            }
            usage.emplace_front(key, value);
            table[key] = usage.begin();
        }        
    }
};



// simplae integer LRU Cache 

class LRUCache {
      list<int> cache;
      unordered_map<int, list<int>::iterator> ump;
      int cap;

public:
      LRUCache(int n): cap(n) {}
      
      int get(int key) {
           if(ump.count(key)) {
                 auto it = ump[key];
                 cache.erase(it);
                 cache.push_front(key);
                 ump[key] = cache.begin();
                 return key;
           }
           return -1;
      }

      void put(int key) {
            if(ump.count(key)) {
                  auto it = ump[key];
                  cache.erase(it);
                  cache.push_front(key);
                  ump[key] = cache.begin();
            } else {
                  if(cache.size() == cap) {
                        ump.erase(cache.back());
                        cache.pop_back();
                  }
                  cache.push_front(key);
                  ump[key] = cache.begin();
            }
      }
};