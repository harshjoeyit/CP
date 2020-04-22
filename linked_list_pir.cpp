// IMP

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

