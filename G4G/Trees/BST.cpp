#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;


struct node{
    int data;
    struct node *left, *right;
};

typedef struct node* T;

T insert(T root, int data)
{
    if(root == NULL)
    {
        T temp = (T)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    T t = root;
    if(root->data < data)
    {
        t->left = insert(root->left, data);
    }
    else
        t->right = insert(root->right, data);

    return t;

}

void inorder(T root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{ _
    T root = NULL;
    int a[] = {10, 5, 15, 6, 25, 11, 3};
    T t = root;
    for(int i=0; i<6; i++)
    {
        if(i==0)
            t = root = insert(root, a[i]);
        root = insert(t, a[i]);
    }

    inorder(t);
    return 0;
}