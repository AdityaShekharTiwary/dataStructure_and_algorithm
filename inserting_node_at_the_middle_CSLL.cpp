#include<iostream>
using namespace std;

struct Node* addafter(struct Node *last, int data ,int item)
{
    if(last == NULL)
        return NULL;
    struct Node *temp, *p;
    p = last -> next;

    do
    {
        if(p->data == item)
        {
            // creating node dynamically
            struct Node* = (struct Node *)malloc(sizeof(struct Node));
            // assigning value
            temp->data = data;
            // adjusting node
            temp->next = p->next;
            // assigning address
            p->next=temp;

            if(p==last)
                last=temp;
                return last;
        }
        p = p -> next;
     while (p != last -> next);
    }
    cout << item << " not present in the list." << endl;
    return last;
}




    }

};
