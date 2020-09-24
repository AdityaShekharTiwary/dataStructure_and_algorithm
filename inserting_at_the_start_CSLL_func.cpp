#include<iostream>
using namespace std;

struct Node *addbegin(struct Node *last,int data)
{
    if(last == NULL)
        return insertnode(lst,data)

    // creating a node dynamically
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;      // assigning the data;
    temp->next = last->next;        // assigning address
    last->next=temp;

    return last;

};

