#include<iostream>
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

		bool isEmpty()
		{
			if(root == NULL)
			return true;
			else
			return false;
		}
};


int main()
{
	int option;
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

		switch(option)
		{
		case 0:
			break;
		case 1:
			cout <<"Insert" << endl;
			break;
		case 2:
			cout <<"Search" << endl;
			break;
		case 3:
			cout <<"Delete" << endl;
			break;
		case 4:
			cout <<"Print BST Value" << endl;
			break;
		case 5:
			cout <<"Clear Screen" << endl;
			break;
		default:
			cout << "Enter proper option no." << endl;
		}
	}


	while(option!=0);




	return 0;
}
