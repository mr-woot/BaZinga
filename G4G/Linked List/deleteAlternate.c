#include<stdio.h>
#include<malloc.h>

/*Driver Programs*/

struct node{
	int data;
	struct node *next;
};

void push(struct node **head_ref, int num)
{
//	if(*head_ref == NULL) return ;
	
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = *head_ref;
	
	*head_ref = temp;
}

void sortedInsert(struct node **head, int num)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = num;
	struct node *temp = *head;
	if(*head == NULL || temp->data > num)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		while(temp->next!=NULL && temp->data < num)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void printList(struct node *head)
{
//	if(head == NULL) return;
	
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head = head->next;
	}
}

void Movenode(struct node **dest, struct node **source)
{
	struct node *temp = *source;
	(*source) = (*source)->next;
	temp->next = *dest;
	*dest = temp;
}

void AlternateSplit(struct node *source, struct node **aRef, struct node **bRef)
{
	struct node *current = source;
	struct node *a = NULL;
	struct node *b = NULL;
	
	while(current!=NULL)
	{
		Movenode(&a,&current);
		if(current!=NULL)
		{
			Movenode(&b,&current);
		}
	}
	*aRef = a;
	*bRef = b;
}

int main()
{
	struct node *head = NULL;
	push(&head,11);
	sortedInsert(&head, 32);
	push(&head,9);
	push(&head,7);
	push(&head,5);
	push(&head,1);
	printList(head);
	/*
	struct node *a = NULL, *b = NULL;
	printf("\n");
	AlternateSplit(head, &a, &b);
	printf("\n");
	printList(a);
	printf("\n");
	printList(b);
	*/
	return 0;
}