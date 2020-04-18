

Node* deleteK(Node *head, int K) {
    if(head == NULL || K == 0)
        return head;
    
    if(K == 1)
        return NULL;
    
    Node *p, *q;
    
    p = head;
    int i;
    for(i=1; i<=K-2; i++) {
        if(p == NULL)
            break;
        p = p->next;
    }
    if(p == NULL || p->next == NULL)
        return head;

    q = p->next;
    p->next = deleteK(q->next, K);
    delete q;
    return head;
}