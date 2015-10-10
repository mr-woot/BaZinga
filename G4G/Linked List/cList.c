#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

void push(struct node **head_ref, int num)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *head = *head_ref;
	
	temp->data = num;
	temp->next = *head_ref;

	if(head == NULL)
	{
		temp->next = temp;
	}
	else
	{
		while(head->next != *head_ref)
			head = head->next;
		head->next = temp;
	}
	*head_ref = temp;
}

void printLst(struct node *head)
{
	struct node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        while (temp != head);
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

}



