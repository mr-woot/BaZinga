#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	bool thread;
};

struct node *create(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->thread = false;
	return temp;
}

struct node* leftmost(struct node *n) 
{
	if(n == NULL)
		return NULL;
	while(n->left != NULL)
		n = n->left;
	return n;
}

void inorder(struct node *root)
{
	struct node *cur = leftmost(root);

	while(cur!=NULL)
	{
		cout << cur->data << " ";
		if(cur->thread)
			cur = cur->right;
		else
			cur = leftmost(cur->right);
	}
}

int main()
{ _
	struct node *root = create(6);
	root->left = create(3);
	root->left->left = create(1);
	root->left->left->thread = true;
	root->left->right = create(5);
	root->left->right->thread = true;
	inorder(root);
	return 0;
}
