#include<iostream>
using namespace std;

struct insertnode(struct *Node, int data)       // Only for Empty circular singly linked list
{
    if(last!=NULL)
    {
        return last;
    }
    struct Node *last = (struct Node*)malloc(sizeof(struct Node));       // creating node dynamically
    last->data = data;      // assigning data to node
    last->next = last;      // pointing back to itself bcz its the only node
    return last;

};
