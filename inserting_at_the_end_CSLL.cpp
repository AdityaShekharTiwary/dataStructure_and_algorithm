#include<iostream>
using namespace std;

struct addend(struct *Node,int data)
{
    if(last == NULL)
        return insertnode();
    // creating code dynamically
    struct Node *temp = struct(Node*)malloc(sizeof(struct Node));
    // assigning data
    temp->data = data;
    // assigning address
    temp->next=last->next;
    last->next=temp;
    // pointing last to the newly added node
    last=temp;

    return last;
};

