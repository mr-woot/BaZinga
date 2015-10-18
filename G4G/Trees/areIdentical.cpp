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

int areIdentical(struct node *a, struct node *b)
{
	if(a == NULL && b == NULL) return 1;
	if(a != NULL && b != NULL)
	{
		return (
				a->data == b->data &&
				areIdentical(a->left, b->left) && 
				areIdentical(a->right, b->right)
			);
	}
	return 0;
}

int main()
{ _
	struct node *root = create(6);
	root->left = create(3);
	root->left->left = create(1);
	root->left->right = create(5);
	
	struct node *root1 = create(6);
	root1->left = create(3);
	root1->left->left = create(1);
	root1->left->right = create(5);
	cout << areIdentical(root1, root);
	return 0;
}
