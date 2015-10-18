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

struct node *create(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void deleteTree(struct node *root)
{
	if(root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);

	cout << "Node Deleted" << root->data << endl;
	free(root);
}
int main()
{ _
	struct node *root = create(6);
	root->left = create(3);
	root->left->left = create(1);
	root->left->right = create(5);
	
	deleteTree(root);
	return 0;
}
