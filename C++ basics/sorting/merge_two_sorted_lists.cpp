#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Read the recursive code */

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


