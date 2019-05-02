/*
@author: rj
Topic: Implementation of Threaded Binary Search Tree
*/
#include<iostream>
using namespace std;

class thread
{
	typedef struct bst
	{
		int data;
		int lth,rth;
		struct bst *left,*right;
	}node;
	node *root,*dummy,*nth,*temp;
public:
	thread()
	{
		root = NULL;
	}
	void create();
	void insert(node *,node *);
	void inorder_display();
	
};

void thread :: create()
{
	nth = new node;
	nth->lth = 0;
	nth->rth = 0;
	nth->left = NULL;
	nth->right = NULL;
	cout << "\nEnter the data : ";
	cin >> nth->data;
	if(root == NULL)
	{
		root = nth;
		dummy = new node;
		dummy->data = -999;
		dummy->left = root;
		dummy->right = dummy;
		root->left = dummy;
		root->right = dummy;
	}
	else
	{
		insert(root,nth);
	}
}

void thread :: insert(node *root, node *nth)
{
	if(nth->data < root->data)
	{
		if(root->lth == 0)
		{
			nth->left = root->left;
			nth->right = root;
			root->left = nth;
			root->lth = 1;
		}
		else
		{
			insert(root->left,nth);
		}
	}
	else if(nth->data > root->data)
	{
		if(root->rth == 0)
		{
			nth->right = root->right;
			nth->left = root;
			root->right = nth;
			root->rth = 1;
		}
		else
		{
			insert(root->right,nth);
		}
	}
	else
		cout << "\nDuplicate value entered...!!!!"<<endl;
	
}

void thread :: inorder_display()
{
	temp = root;
	while(temp != dummy)
	{
		while(temp->lth==1)
		{
			temp = temp->left;
		}
		cout << temp->data << "	";
		while(temp->rth==0)
		{
			temp = temp->right;
			if(temp == dummy)
				return ;
			cout << temp->data << " ";
		}
		temp = temp->right;
	}
}

int main()
{
	int ch;
	char choice;
	thread th;
	do
	{
		cout << "\n1.CREATE\n2.DISPLAY INORDER TRAVERSAL\n3.EXIT"<<endl;
		cout << "\nEnter your choice : ";
		cin >> ch;
		switch(ch)
		{
			case 1 : do
					 {
					 	th.create();
					 	cout << "\nDo you want to enter more elements? (y/n) : ";
					 	cin >> choice;
					 }while(choice == 'y' || choice == 'Y');
					 break;
			case 2 : th.inorder_display();
					 break;
			case 3 : cout << "\nExiting the program...!!!"<<endl;break;
			default : cout << "\nPlease choose appropriate option....!!!"<<endl;
		}
	}while(ch!=3);
return 0;
}

