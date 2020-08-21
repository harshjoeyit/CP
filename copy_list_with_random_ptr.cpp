
/*
Copy linked list with a random pointer 
https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
*/


/*
Method 1: Uses O(n) space for storing the next pointer of all the nodes of original list

- store the next for each node 
- create new nodes and point original_node -> next = new node 
- new node->random points to the original node, next point to the next new node 
- place random pointers of the duplicate list 
      - copy_list_node->arbit = copy_list_node->arbit->arbit->next;
- use the stored result to place next pointers of original list 
*/


/*
Method 2: Uses O(1) space

-  we create duplicate node just after the original node and then 
      - set the random pointers     
      - next pointers 
      - after this the list are seperated 
- placing the random pointers
      - traverse list by skipping on at a time(we skip the duplicates) 
      - original->next->arbitrary = original->arbitrary->next;
- placing the next pointers 
      - original->next = original->next->next;
*/