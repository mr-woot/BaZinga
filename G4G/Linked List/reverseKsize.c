#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

void push(struct node **head_ref, int num)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->data = num;
	temp->next = *head_ref;

	*head_ref = temp;
}

struct node* reverse(struct node *head_ref, int k)
{
	struct node *current = head_ref, *prev = NULL, *nextp = NULL;
	int count = 0;

	while(current != NULL && count < k)
	{
		nextp = current->next;
		current->next = prev;
		prev = current;
		current = nextp;
		count++;
	}

	if(nextp != NULL)
	{
		count = 0;
		while(current != NULL && count < k)
		{
			current = current->next;
			count++;
		}
	}

	if(nextp != NULL)
		head_ref->next = reverse(nextp, k);

	return prev;
}

void printLst(struct node *head_ref)
{
	while(head_ref != NULL)
	{
		printf("%d\t", head_ref->data);
		head_ref = head_ref->next;
	}
}

int main(void)
{
	struct node *head = NULL;
	int i = 1;
	for(; i < 10; i++)
	{
		push(&head, i);
	}
	printLst(head);

	head = reverse(head,4);
	printf("\n");
	printLst(head);
}



