#include<iostream>
using namespace std;


class Node{
 public:
	int key;
	int data;
	Node* next;

	
	Node()
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

class CircularLinkedList
{
	public:
		Node* head;

		CircularLinkedList()
		{
			head = NULL;
		}

		// 1. Check if node exists using key value

		Node* nodeExists(int k)				// Checking if Node exists
		{
			Node* temp = NULL;				// temporary pointer of Node type
			Node* ptr = head;				// Another Pointer and assign head value to it

			if(ptr == NULL)					// when there are no node in the list
			{
				return temp;
			}
			else
			{
				do
				{
					if(ptr->key == k)
					{
						temp = ptr;
					}
					ptr = ptr -> next;
				}
				while(ptr!=head);
				return temp;
			}
		}



		// 2. Append a node to the list

		void appendNode(Node *new_node)
		{
			if(nodeExists(new_node->key)!=NULL)
			{
				cout << "Node Already exists with key value : "
				<< new_node->key
				<<".Append another node with different key value"
				<<endl;
			}
			else
			{
				if(head == NULL)			// if the linkedlist is empty
				{
					head = new_node;
					new_node->next=head;			// there is only one node thst we added so head will point to itself
					cout<< "Node Appende dat the first head position "<< endl;
				}
				else 						// if the nodes are already present in the list
				{
					Node* ptr=head;
					while(ptr->next!=head)		// when then pointeris not pointing back to head
					{
						ptr = ptr->next;
					}
					ptr->next = new_node;
					new_node->next= head;		// newly added node will point to the head
					cout << "Node Appended" << endl;
				}
			}
		}


		//3. Prepend Node - Attach a node at the front

		void prependNode(Node* new_node)
		{
			if(nodeExists(new_node->key)!=NULL)
                {
				cout << "Node Already exists with key value : "
				<< new_node->key
				<<".Append another node with different key"
				<<endl;
				}
		    else
			{
				Node* ptr = head;
				while(ptr->next!=head)
				{
					ptr = ptr->next;
				}
				ptr->next = new_node;
				new_node->next = head;
				head=new_node;
				cout <<"Node Prepended" << endl;

			}
		}

		// 4. Insert a Node after aparticular Node

		void insertNodeAfter(int k,Node *new_node)
		{
			Node* ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout << "No Node exists with key valueof : " << k << endl;
			}
			else
			{
				if(nodeExists(new_node->key)!=NULL)
				{
					cout << "No Node exists with key value :"
					<<new_node->key
					<<".Append another node with different key value"
					<<endl;
				}
				else
				{
					if(ptr->next == head)
					{
						new_node->next = head;
						ptr->next =new_node;
						cout << "Node Inserted at the end" << endl;
					}
					else
					{
						new_node->next=ptr->next;
						ptr->next=new_node;
						cout <<"Node Instered in between" << endl;
					}
				}
			}
		}

       // 5. Delete Node by unique key

	   void deleteNodeByKey(int k)
	   {
	   		Node* ptr = nodeExists(k);
	   		if(ptr ==NULL)
	  		{
	   			cout << "NO Node exists with key value of : " << k <<endl;
	  		}
	  		else
	  		{
	  			if(ptr == head)
	  			{
				  	if(head->next == NULL)
		  			{
		  				head==NULL;
		  				cout << "Head node unlinked ... List empty";
					}
					else
					{
						Node* ptr = head;
						while(ptr->next!=head)
						{
							ptr = ptr->next;
						}
						ptr->next = head->next;
						cout <<"Node unlinked with key value : "<< k <<endl;
					}
				}
				else
				{
					Node* temp = NULL;
					Node* prevptr = head;
					Node* currentptr = head->next;
					while(currentptr!=NULL)
					{
						if(currentptr->key == k)
						{
							temp = currentptr;
							currrentptr=NULL;
						}
						else
						{
							prevptr = prevptr->next;
							currentptr = currentptr->next;
						}
					}
					prevptr->next = temp->next;
					cout << "Node unlinked with key values : " << k << endl;
				}
	   		}
	   }

	   // 6. Update node

	    void updateNodeByKey(int k,int new_data)
	    {
	    	Node* ptr = nodeExists(k);
	    	if(ptr!=NULL)
	    	{
	    		ptr->data=new_data;
	    		cout << "Node Data Updated Successfully" << endl;
			}
			else
			{
				cout << "Node doesn't exists with key value: "<< k << endl;
			}
		}

		// 7. Printing

		void printList()
	{
		if(head==NULL)				// checking if the list exists ornot
		{
			cout << "No Node in Singly Linked list";
    	}
		else
		{
			cout<< endl <<"head address : " <<head <<endl;
			cout << "singly Linked List values : " << endl;
			Node* temp = head;

			do
			{
			cout << "(" << temp->key << "," <<temp->data <<") -->";
			temp = temp->next;
			}
			while(temp!=head);
		}

	}

};


int main()
{
	CircularLinkedList obj;
	int option ;
	int key1,k1,data1;

	do
	{
		cout << "\nWhat operation do you want to perform ? Select option number. Enter 0 to exit" << endl;
		cout << "1. AppendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
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
				obj.appendNode(n1);
				break;
			case 2:
				cout << "Prepend Node Operation \n enter key & data of the Node tobe Prepended" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.prependNode(n1);
				break;
			case 3:
				cout << "Insert Node After Operation \n enter key of existing Node after which you want to Insert this new node :" << endl;
				cin >> k1;
				cout << "Enter Key & data of the New Node first" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.insertNodeAfter(k1,n1);
				break;
			case 4:
				cout << "delete Node By Key Operation - \n Enter key of the Node to be deleted : " << endl;
				cin >> k1;
				obj.deleteNodeByKey(k1);
				break;
			case 5:
				cout << "Update Node By Key Operation - \n enter Key & new data to be updated "<< endl;
				cin >> key1;
				cin >> data1;
				obj.updateNodeByKey(key1,data1);
				break;
			case 6:
				obj.printList();
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
