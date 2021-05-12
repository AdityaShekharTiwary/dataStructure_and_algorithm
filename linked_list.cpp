#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    
    if(!head){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL) temp=temp->next;

    temp->next=n;

}

bool search(node* head,int key){
    node* temp=head;
    while(temp){
        if(temp->data==key) return true;
        temp=temp->next;
    }
    return false;
}


void deletition(node* &head,int val){
     if(val==head->data){
        head=head->next;
        return;
    }
    node* temp=head;
    while(temp->next->data!=val) temp=temp->next;
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void reverse(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* next;

    while(curr){
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
        
    }
    head=prev;
    
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main(){

    node* head=NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    display(head);

    // insertAtHead(head,8);
    // display(head);

    // if(search(head,7)) cout<<"Found\n";
    // else cout<<"Not Found\n";

    // deletition(head,1);
    // display(head);

    reverse(head);
    display(head);

    return 0;
}