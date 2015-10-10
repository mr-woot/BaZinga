#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define V 4
#define INF 99999
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node * ROOT;
ROOT newNode(int key)
{
	ROOT temp = (ROOT)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}
ROOT insert(ROOT x, int num)
{
	if(x == NULL) return newNode(num);

	if(num < x->data) 
		x->left = insert(x->left, num);
	else 
		x->right = insert(x->right, num);

	return x;
}

void inorder(ROOT x)
{
	if(x!=NULL)
	{
		inorder(x->left);
		cout << x->data << "\t";
		inorder(x->right);
	}
}

int main() 
{ _
	ROOT root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
	return 0;
}