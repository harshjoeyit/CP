int main()
{
    struct node *head1 = NULL , *head2 = NULL;
    int n, data;
    printf()

    for(int i=0; i < n; i++)
    {
        cout<<i+1<<". data: ";
        cin>>data;
        insert_node(&head1,data,i+1);
    }
    display(head1);

    cout<<"nodes: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". data: ";
        cin>>data;
        insert_node(&head2,data,i+1);
    }
    display(head2);

    head1 = merge_lists_with_sort( &head1 ,&head2 );
    display( head1);
}