#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void insertempty(Node** head_ref,int data)
    {
        Node* new_node = new Node();
        new_node->data=data;
        new_node->next=(*head_ref);
        *head_ref=new_node;
    }
    void insertafter(Node* prev_node,int data)
    {
        if(prev_node==NULL)
        {
            cout<<"Can't insert if there's no previous node"<<endl;
            return;
        }
        else
        {
            Node* new_node=new Node();
            new_node->data=data;
            new_node->next=prev_node->next;
            prev_node->next=new_node;
        }
    }
    void append(Node** head_ref,int data)
    {
        Node* new_node=new Node();
        Node *last=(*head_ref);
        new_node->data=data;
        new_node->next=NULL;
        if(*head_ref==NULL)
        {
            new_node=*head_ref;
            return ;
        }

        while(*head_ref!=last)
        {
            last->next=last;
        }
        last->next=new_node;
        return ;
    }

    void printlist(Node* node)
    {
        while(node!=NULL)
        {
            cout<<" " << node->data;
            node=node->next;
        }
    }
};

int main()
{
    Node n;
    Node* head=NULL;

    n.insertempty(&head,6);
    n.append(&head,16);
    n.insertafter(head->next,65);
    n.insertempty(&head,26);
    n.insertafter(head->next,9);
    n.append(&head,87);

    cout<<"Created Linked list is: ";
    n.printlist(head);

    return 0;
}
