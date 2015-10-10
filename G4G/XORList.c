#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node *ptrdiff;
};

struct node* XORList(struct node *a, struct node *b)
{
	return (struct node *)((unsigned int)(a) ^ (unsigned int)(b));
}

void push(struct node **head, int num)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	temp->ptrdiff = XORList(*head, NULL);
	
	if(*head != NULL)
	{
		struct node *next = XORList((*head)->ptrdiff, NULL);
		(*head)->ptrdiff = XORList(temp, next);
	}
	*head = temp;
}

void print(struct node *head)
{
	struct node *curr = head;
	struct node *prev = NULL;
	struct node *next;
	while(curr != NULL)
	{
		printf("%d\n", curr->data);
		next = XORList(prev, curr->ptrdiff);
		prev = curr;
		curr = next;
	}
}

int main()
{ 
	struct node *head = NULL;
	push(&head, 1);
	push(&head, 3);
	push(&head, 5);
	push(&head, 7);
	push(&head, 9);
	print(head);
	printf("\n");
	return 0;
}