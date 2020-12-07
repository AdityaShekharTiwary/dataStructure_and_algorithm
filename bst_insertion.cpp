#include<iostream>
#define SPACE 10
using namespace std;
class TreeNode{
	public:
		int value;		// key or data
		TreeNode* left;
		TreeNode *right;   // both are the same things

		TreeNode()
		{
			value =0;
			left = NULL;
			right = NULL;
		}
		TreeNode(int v)
		{
			value = v;
			left = NULL;
			right = NULL;
		}
};

class BST
{
	public:
		TreeNode*root;
		BST()
		{
			root = NULL;
		}

		bool isEmpty()
		{
			if(root == NULL)
			return true;
			else
			return false;
		}
		void insertNode(TreeNode *new_node)
		{
			if(root == NULL)
			{
				root == new_node;
				cout << "value inserted as root node" << endl;
			}
			else
			{
				TreeNode *temp = root;
				while(temp!=NULL)
				{
					if(new_node->value == temp->value)
					{
						cout << "Value Already exist, Insert another value" << endl;
						return ;
					}
					else if((new_node->value < temp->value) && (temp->left == NULL))
					{
						temp->left = new_node;
						cout << "Value Inserted to the left" << endl;
						break;
					}
					else if(new_node->value < temp->value)
					{
						temp = temp->left;
					}
					else if((new_node->value > temp->value) && (temp->right == NULL))
					{
						temp->right = new_node;
						cout << "Value Inserted to the right" << endl;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
			}
		}

		void print2D(TreeNode *r,int space)
		{
			if(r == NULL)     // base case
			return ;
			space +=SPACE;		// Icrease distance between levels
			print2D(r->right,space);		//Process right child first
			cout << endl;
			for(int i = SPACE; i<space; i++)  
			{		
				cout <<" ";				// Printing current node after space count
			}
			cout <<r->value<<"\n";
			print2D(r->left,space);			// Process Left child
		}
};


int main()
{
	BST obj;
	int option,val;
	do
	{
		cout << "What operation do you want to perform ?"
		<<"Select an option number .Enter 0 to exit" << endl;
		cout << "1. Insert node" << endl;
		cout << "2. Search  node" << endl;
		cout << "3. Delete node" << endl;
		cout << "4. print BST value"<< endl;
		cout << "5. clear screen" << endl;
		cout << "0.Exit program" << endl;

		cin >> option;
		// Node n1 = new Node();					// can only used one time
		TreeNode * new_node = new TreeNode();		// it will create a new node in Heap memory and uses dynamic memory allocation

		switch(option)
		{
		case 0:
			break;
		case 1:
			cout <<"Insert" << endl;
			cout << "Enter the valueof tree node to insert in BST: ";
			cin >> val;
			new_node->value = val;
			obj.insertNode(new_node);
			cout << endl;
			break;
		case 2:
			cout <<"Search" << endl;
			break;
		case 3:
			cout <<"Delete" << endl;
			break;
		case 4:
			cout <<"Print BST Value" << endl;
			obj.print2D(obj.root,5);
			break;
		case 5:
			cout <<"Clear Screen" << endl;
			system("cls");
			break;
		default:
			cout << "Enter proper option no." << endl;
		}
	}

	while(option!=0);

	return 0;
}
