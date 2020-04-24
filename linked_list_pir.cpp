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



// intersection point in y shaped linked list
int intersectPoint(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL)
        return -1;
    
    int d1 = 0, d2 = 0;
    Node *p = head1;
    Node *q = head2;
    
    while(p != NULL) {
        ++d1;
        p = p->next;
    }
    while(q != NULL) {
        ++d2;
        q = q->next;
    }
    
    if(d1 > d2) {
        p = head1;
        q = head2;
    } else {
        p = head2;
        q = head1;
    }
    
    int diff = abs(d1-d2);
    while(diff--) {
        p = p->next;
    }
    
    while(p != NULL && q != NULL) {
        if(p == q) {
            return p->data;
        } 
        p = p->next;
        q = q->next;
    }
    return -1;
}




// merge sorted list 
struct node *merge(struct node *head1 , struct node *head2 )
{
    struct node *dummy = new node;                                           
    struct node *temp;
    dummy->next = NULL;
    temp = newNode;                                                            

    while(head1 && head2) {                                                                            
        if( head1->data <= head2->data ) {
            temp->next = head1;                                                  
            temp = temp->next;                                                  
            head1 = head1->next;                                                  
        }
        else {                                                                        
            temp->next = head2;                                                    
            temp = temp->next;                                                      
            head2 = head2->next;                                                    
        }
    }
    if(head1 != NULL )                                                             
        temp->next = head1;                                                        
    if(head2 != NULL ) 
        temp->next = head2;

    temp = newNode->next;
    free(newNode);
    return temp;
}


