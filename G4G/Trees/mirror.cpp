#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }
void swap(int &a, int &b){ int temp = a; a = b; b = temp; }

struct node *create(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void mirror(struct node *root)
{
	if(root == NULL) return;

	mirror(root->left);
	mirror(root->right);

	swap(root->left, root->right);
}

void inorder(struct node *root)
{
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main()
{ _
	struct node *root = create(6);
	root->left = create(3);
	root->left->left = create(1);
	root->left->right = create(5);
	inorder(root);
	mirror(root);
	inorder(root);
	return 0;
}
