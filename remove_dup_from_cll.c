
#include <stdio.h>
#include <cstdlib>

struct Node
{
      int val;
      struct Node *next;
};
#define node struct Node

node *createList()
{
      int n;
      scanf("%d", &n);

      node *head = NULL, *tail;
      while (n--)
      {
            node *temp = (node *)malloc(sizeof(node));
            scanf("%d", &temp->val);

            if (head == NULL)
            {
                  head = temp;
                  tail = head;
            }
            else
            {
                  tail->next = temp;
                  tail = temp;
            }
      }
      tail->next = head;
      return head;
}

void print(node *head)
{
      if (head == NULL)
      {
            printf("empty\n");
            return;
      }
      node *temp = head;
      do
      {
            printf("%d ", temp->val);
            temp = temp->next;
      } while (temp != head);
}

node *removeDup(node *head)
{
      if (head == NULL || head->next == head)
      {
            return head;
      }
      node *temp = head;

      while (temp->next != head)
      {
            if (temp->val == temp->next->val)
            {
                  node *del = temp->next;
                  temp->next = del->next;
                  free(del);
            }
            else
            {
                  // go to next if adjacent not equal
                  temp = temp->next;
            }
      }

      // the last node could have same value as head, then
      if (temp != head && temp->val == head->val)
      {
            temp->next = head->next;
            return temp;
      }

      return head;
}
int main()
{
      node *head = createList();
      head = removeDup(head);
      print(head);
}