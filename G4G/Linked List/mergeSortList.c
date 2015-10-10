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


struct node *sortedMerge(struct node *a, struct node *b)
{
	struct node *result = NULL;
	
	if(a == NULL)
		return (b);
	else if(b == NULL)
		return (a);
	
	if(a->data <= b->data)
	{
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedMerge(a, b->next);
	}
	return (result);
}

void FrontBackSplit(struct node *source, struct node **frontRef, struct node **backRef)
{
	struct node *fast;
	struct node *slow;
	
	if(source == NULL || source->next == NULL)
	{
		*frontRef = source;
		*backRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		
		while(fast!=NULL)
		{
			fast = fast->next;
			if(fast!=NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

void mergesort(struct node **head_ref)
{
	struct node *head = *head_ref;
	struct node *a;
	struct node *b;
	
	if(head == NULL || head->next == NULL)
		return ;
	
	
		FrontBackSplit(head,&a,&b);
		
		mergesort(&a);
		mergesort(&b);
		
		*head_ref = sortedMerge(a,b);
	
}

int main()
{
	struct node *head = NULL;
	push(&head,11);
	push(&head,92);
	push(&head,7);
	push(&head,5);
	push(&head,3);
	push(&head,1);
	
	printList(head);
	printf("\n");
	
	mergesort(&head);
	printf("\n");
	printList(head);	
	
	return 0;
}