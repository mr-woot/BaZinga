#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node **head, int num)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = *head;
	*head = temp;
}

void print(struct node *head)
{
	if(head == NULL) return;
	print(head->next);
	printf("%d\n", head->data);
}

int listLength(struct node *head)
{
	while(head && head->next)
	{
		head = head->next->next;
	}
	if(!head) return (int)"Even";
	return (int)"Odd";
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
	printf("%s\n", (char *)listLength(head));
	return 0;
}