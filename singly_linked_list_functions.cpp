#include<iostream>
using namespace std;

class Node{
public:
    int key;
    int data;
    Node* next;

    Next()
    {
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d)
    {
        key = k;
        data = d;
    }

};

class SinglyLinkedList{

public:
    Node* head;
    SinglyLinkedList()
    {
    head=NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head=n;
    }
    // 1. check if node exists using key value
    Node* nodeExists(int k)
    {
        Node* temp = NULL;
        Node* ptr =head;
        while(ptr!=NULL)
        {
            if(ptr->key == k)
            {
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    // 2. append  a node to the list.

    void appendNode(Node *n)
    {
        if(nodeExists(n->key)!=NULL)  // if node already exists with the same key value
        {
            cout << "Node already exist with key value : " << n->key << "Append another node with different key value "<< endl;
        }
        else // if node does not exist with the same key value
        {
            if(head==NULL)// if the list is empty
            {
                head = n;
                cout << "Node Appended "<< endl;
            }
            else  // if there are already elements in the list
            {
                Node* ptr = ptr;
                while(ptr-> next);     // if the next pointer contains the address of the next node
                {
                    ptr = ptr->next;
                }                       // exit from this loop when we reach the end of the node
                ptr->next=n;
                cout << "Node Appended" << endl;
            }
        }

    }

    // 3. Prepend Node - Attach a node at the start

    void prependNode(Node* n)
    {
       if(nodeExists(n->key)!=NULL)            //if node already exists with the key
       {
           cout << "Node Already exist with key value : " <<n->key << "Append another node with different key value " <<endl;
       }
       else                          // if node does not exists
       {
           n->next=head;     // storing the address of 1st node in the newly added node(head)
           head=n;          //newly added node(head)
           cout << "Node prepended" << endl;
       }
    }

    // 4. Insert a node after a particular node in a list

    void insertNodeAfter(int k,Node* n)
    {
        Node* ptr = nodeExists(k);          //we have to access that node that's why storing it in a pointer
        if(ptr  ==  NULL)
        {
            cout << "No Node exists with key value : "<<  k << endl;
   		 }
        else
        {
            if(nodeExists(n->key)!=NULL)            //if node already exists with the key
         {
           cout << "Node Already exist with key value : " <<n->key << "Append another node with different key value " <<endl;
         }
            else
            {
                n->next = ptr->next;        // address of next node which is present in the previous node is transfered to the newly addded node
                ptr->next = n;
                cout << "Node inserted"<< endl;
            }
        }
	}

    //5. Delete node by key

    void deletNodeByKey(int k)
    {
        if(head=NULL)
        {
            cout << " singly list is already empty " <<endl;
        }
        else if(head!=NULL)
        {
            if(head->key == k)
            {
                head = head->next;
                cout << "Node unlinked with key values : " << k <<endl;
            }
            else
            {
                Node* temp = NULL;
                Node* prevptr = head;
                Node* currentptr = head->next;
                while(currentptr!=NULL)
                {
                    if(currentptr->key==k)
                    {
                        temp = currentptr;
                        currentptr=NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr ->next;
                    }
                }
                if(temp!=NULL)
                {
                    prevptr->next=temp->next;
                    cout << "Node unlinked with key value : " << k << endl;
                }
                else
                {
                    cout << "Node does not exists with key value : " << k << endl;
                }
            }
        }
    }

    // 6.Updating the node

    void updateNodeByKey(int k,int d)
    {
    	Node* ptr = nodeExists(k);
    	if(ptr!=NULL)
    	{
    		ptr->data=d;
    		cout << "Node Data Updated Successfully" << endl;
		}
		else
		{
			cout << "Node doesn't exists with key value: "<< k << endl;
		}
	}

	// 7. Printing the entire node

	void printList()
	{
	    Node* temp;
		if(head==NULL)				// checking if the list exists ornot
		{
			cout << "No Node in Singly Linked list";
    	}
		else
		{
			cout << endl << "Singly Linked List values : " ;
			Node* temp = head;
		}
			while(temp != NULL) 			// loop will iterate till we reach at the end node
		{
			cout << "(" << temp->key << "," <<temp->data <<") -->";
			temp = temp->next;
		}

	}
};

int main()
{
	SinglyLinkedList s;
	int option ;
	int key1,k1,data1;

	do
	{
		cout << "\nWhat operation do you want to perform ? Select option number. Enter 0 to exit" << endl;
		cout << "1. AppendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNode()" << endl;
		cout << "4. deleteNode()" << endl;
		cout << "5. updateNode()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" << endl;

		cin >> option ;
        Node* n1 = new Node();
		//Node n1;

		switch(option)
		{
			case 0:
				break;
			case 1:
				cout << "Append Node operation \nEnter key & data of the Node to be appended" << endl;
				cin >> key1;
				cin >> data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				break;
			case 2:
				cout << "Prepend Node Operation \n enter key & data of the Node tobe Prepended" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				s.prependNode(n1);
				break;
			case 3:
				cout << "Insert Node After Operation \n enter key of existing Node after which you want to Insert this new node :" << endl;
				cin >> k1;
				cout << "Enter Key & data of the New Node first" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				s.insertNodeAfter(k1,n1);
				break;
			case 4:
				cout << "delete Node By Key Operation - \n Enter key of the Node to be deleted : " << endl;
				cin >> k1;
				s.deletNodeByKey(k1);
				break;
			case 5:
				cout << "Update Node By Key Operation - \n enter Key & new data to be updated "<< endl;
				cin >> key1;
				cin >> data1;
				s.updateNodeByKey(key1,data1);
				break;
			case 6:
				s.printList();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout << "Enter Proper option number" << endl;
		}



	} while(option!=0);



 return 0;
}
