// IMP


// --------------------------------------------------------------------



// remove duplicate from an unsorted list 
Node * removeDuplicates( Node *head) 
{
    if(head == NULL || head->next == NULL)
        return head;
        
    Node *p = head;
    Node *q, *prev;
    
    while(p != NULL && p->next != NULL) {
        prev = p;
        q = p->next;
        int data = p->data;
        while(q != NULL) {
            if(q->data == data) {
                prev->next = q->next;
                delete q;
                q = prev->next;
            } else {
                prev = prev->next;
                q = q->next;
            }
        }
        p = p->next;
    }
    
    return head;
}



// ---------------------------------------------------------------



/*
    Removing a loop from the linked list 

    let p - be the node where loop is created
        q - be node in loop where slow, fast ptr meet

    m = length head ---> p
    k = length p ---> q 
    l - loop length

    length traverse by 
    slow ptr = m + k + x*l      - x is number of rounds taken in loop 
    fast ptr = m + k + y*l      - y is number of rounds taken in loop

    length fast ptr = 2 * length slow ptr
    so 
    x*l - 2*(y*l) = m+k
    
    m+k is a multiple of loop length

    NOTE:   we are at q - length k away from p
            if we travel m more then we reach q and complete the loop

            also if from head we travel m
            we reach q,
            so this is the logic behind approach
*/


void removeTheLoop(Node *head) {
    
    Node *fast = head;
    Node *slow = head;
    
    // check if loop exists 
    bool loop = 0;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            loop = 1;
            break;
        }
    }
    
    if(loop) {
           slow = head;                     // both pointers meet after travelling m distace
           while(slow != fast) {
               slow = slow->next;
               fast = fast->next;
           }
           // we are at junction 
           // travel in a loop now
           while(fast->next != slow)
               fast = fast->next;
           
           // fast is one before junction
           fast->next = NULL;
    }
}
