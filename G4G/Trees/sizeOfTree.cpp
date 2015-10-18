#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

struct node *create(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int size(struct node *root)
{
	if(root == NULL)  return 0;
	return (1 + size(root->left) + size(root->right));
}

int main()
{ _
	struct node *root = create(6);
	root->left = create(3);
	root->left->left = create(1);
	root->left->right = create(5);
	cout << size(root);
	return 0;
}
