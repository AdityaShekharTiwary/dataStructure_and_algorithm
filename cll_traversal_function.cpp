// function to traverse a circular singly linked list and
// print the elements

void traverse(struct Node *first)
{
    struct Node *temp=first;

    if(first!=NULL)
    {
        // keep printing nodes till we reach the start
        do
    {
        cout << temp->data << " " ;
        temp=temp->next;
    }
    while(temp!=first);
    }
}
