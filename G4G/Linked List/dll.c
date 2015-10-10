#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

void push(struct node **head_ref, int num)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *head = *head_ref;

	temp->data = num;
	temp->next = *head_ref;
	temp->prev = NULL;

	if(*head_ref != NULL)
		(*head_ref)->prev = temp;

	*head_ref = temp;
}

void display(struct node *head_ref)
{
	while(head_ref != NULL)
	{
		printf("%d\t", head_ref->data);
		head_ref = head_ref->next;
	}
}

int main()
{
	struct node *dll = NULL;

	push(&dll, 1);
	push(&dll, 3);
	push(&dll, 5);
	push(&dll, 7);
	push(&dll, 9);

	display(dll);

	return 0;
}