#include<iostream>
using namespace std;

class Node{

public:
	int key;
	int data;
	Node* next;
	Node* previous;

	Node()
	{
		key=0;
		data=0;
		next=NULL;
		previous=NULL;
	}
	Node(int k,int d)
	{
		key=k;
		data=d;
	}

};

class DoublyLinkedList
{
	public:
		Node* head;
		DoubyLinkedList()
		{
			head=NULL;
		}
		DoublyLinkedList(Node *n)
		{
			head=n;
		}

		// 1. Check if node exists using keyvalue.

		Node* nodeExists(int k)
		{
			Node* temp = NULL;
			Node* ptr = head;

			while(ptr != NULL)
			{
				if(ptr->key == k)
				{
					temp=ptr;
				}
				ptr=ptr->next;
			}
			return temp;
		}

		// 2. Append a node to the list.

		void AppendNode(Node* n)
		{
			if(nodeExists(n->key)!=NULL)    // checking if a node already exists with the key
			{
				cout << "Node Already exists with the key value : " << n->key << ". Append another node with different key value" << endl;
			}
			else
			{
				if(head == NULL)    // if the linked list is empty i.e. we are appending the first element in the list.
				{
					head=n;
					cout << "Node Append as head node" << endl;
				}
				else 					// if there already exists nodes the linked list.
				{
					Node* ptr = head;
					while(ptr->next!=NULL)
					{
						ptr = ptr->next;
					}
					ptr->next=n;
					n->previous = ptr;
					cout << "Node Appended" << endl;
				}
			}
		}

		//3. Prepend Node - Attach a Node at the start

	void prependNode(Node* n)
	{

        if(nodeExists(n->key)!=NULL)			 // checking if a node already exists with the key
        {
			cout <<"Node already exists with key value: " << n->key <<". Append another node with different key value"<< endl;
        }

        else
		{
			if(head == NULL)    // if the linked list is empty i.e. we are appending the first element in the list.
			{
				head=n;
				cout << "Node prepend as head node" << endl;
			}
			else
			{
			head->previous=n; 		// head of previous should store the newly passed node(back linking)
			n->next=head;			// next pointer to point at the head
			head = n;				// storing the value of new node in the head
			cout << "Node Prepended" << endl;
			}
		}
	}

	//  4. Insert node after a particular node

	void insertNodeAfter(int k, Node *n)
	{
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout << "No node exists with key value : " << k << endl;
		}
		else
		{
			if(nodeExists(n->key!=NULL))
			{
				cout << "No node exists with key value : " <<n->key<<".Append another node with different key value" << endl;
			}
			else
			{
				Node *nextNode = ptr->next;
				// appending at the end
				if(nextNode == NULL)
				{
					ptr->next = n;
				    n->previous = ptr;
				    cout << "Node Inserted at the end" <<endl;
				}

				// Inserting in between

				else
				{
					n->next = nextNode;
					nextNode->previous = n;
					n->previous = ptr;
					ptr->next = n;
					cout << "Node Insterted in between " << endl;
				}
			}
		}

	}

	// 5. Delete node by unique key,basically de-link not delete

	void deleteNodeByKey(int k)
	{
		Node* ptr = nodeExists(k);
		if(ptr ==NULL)
		{
			cout <<"Node exists with key value : " << k << endl;
		}
		else
		{
			if(head->key == k)
			{
			    head = head->next;
				cout << "Node unlinked with keys value : " << k << endl ;
			}
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->previous;
                // deleting node at the end
                if(nextNode == NULL)
                {
                    prevNode->next=NULL;
                    cout << "Node Deleted at the end" << endl;
                }

					// deleting in between
					else
					{
						prevNode->next = nextNode;
						nextNode->previous = prevNode;
						cout << "Node Deleted in between" << endl;
					}


			}
		}
	}

	// 6. update node

	void updateNodeByKey(int k,int d)
	{
		Node* ptr = nodeExists(k);
		if(ptr!=NULL)
		{
			ptr->data=d;
			cout<<"Node doesnt exists with key value:" << k <<endl;
		}

		else
		{
			cout << "Node doesnt exists with key value : " << k << endl;
		}
	}

	// 7. printing

	void printList()
	{
		if(head == NULL)
		{
			cout << "No Nodes in Doubly Linked Lists";
		}
		else
		cout << endl<< "Doubly Linked list values : ";
		Node* temp = head;

		while(temp!=NULL)
		{
			cout <<"(" <<temp->data<<") <--> ";
			temp = temp = temp->next;
		}
	}
};

int main()
{
	DoublyLinkedList obj;
	int option ;
	int key1,k1,data1;

	do
	{
		cout << "\nWhat operation do you want to perform ? Select option number. Enter 0 to exit" << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" <<endl<< endl;

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
				obj.AppendNode(n1);
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
