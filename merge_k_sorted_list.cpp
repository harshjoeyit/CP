#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
// Traverse all the linked lists and collect the values of the nodes into an array.
// sort and make new list 


// Approach 2: Use a priority Queue 
// compare element based on the head -> val, lowest one is at the top

// O(n*klog(k))
struct comp {
      bool operator()(const ListNode *a, const ListNode *b) {
            return a->val > b->val;
      }
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode *, vector<ListNode*>, comp> pq;
      ListNode *head = NULL, *tail;
      
      for(auto &list: lists) {
            if(list) {
                  pq.push(list);
            }
      }
      while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            if(head == NULL) {
                  head = node;
                  tail = node;
            } else {
                  tail->next = node;
                  tail = tail->next;
            }
            if(node->next) {
                  pq.push(node->next);
            }
      }
      return head;
} 



// Approach 3
// divide and conquer 
// merge lists in pairs and finally single list is formed takes 
// n ---> n/2 ---> n/4 ---->....----> 1
// log(k) total steps to merge all list into 1 and O(n) time for each level of merging 
// while loop runs log k times and every time it processes nk elements.

// O(n*klog(k))
ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.empty()) {
            return NULL;
      }

      int len = lists.size();
      while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                  lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
      }
      
      return lists.begin();
}

ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
      if(a == NULL) {
            return b;
      } else if(b == NULL) {
            return a;
      }

      ListNode *head, *last;
      if(a->val > b->val) {
            head = last = b;
            b = b->next;
      } else {
            head = last = a;
            a = a->next;
      }

      while(a && b) {
            if(a->val < b->val) {
                  last->next = a;
                  last = a;
                  a = a->next;
            } else {
                  last->next = b;
                  last = b;
                  b = b->next;
            }
      }
      if(a) {
            last->next = a;
      } else if(b) {
            last->next = b;
      } else {
            last->next = NULL;
      }

      return head;
}

// custom comparitor 
struct comp {
      bool operator()(const ListNode *a, const ListNode *b) {
            // makes a min heap (comparision is reversed in linked lists)
            return a->val > b->val;
      }
};

// Approach 3
// using priority queue O(k) + O((n-k)*log(k)) = O(nlogk)
ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode *, vector<ListNode*>, comp> pq;
      ListNode *head = NULL, *tail;
      
      for(auto &list: lists) {
            if(list) {
                  pq.push(list);
            }
      }
      while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            if(head == NULL) {
                  head = node;
                  tail = node;
            } else {
                  tail->next = node;
                  tail = tail->next;
            }
            if(node->next) {
                  pq.push(node->next);
            }
      }
      return head;
}