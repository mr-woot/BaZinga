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

	temp->data = num;
	temp->next = *head_ref;

	*head_ref = temp;
}

void printLst(struct node *head_ref)
{
	while(head_ref != NULL)
	{
		printf("%d\t", head_ref->data);
		head_ref = head_ref->next;
	}
}


void MoveNode(struct node** destRef, struct node** sourceRef)
{
  /* the front source node  */
  struct node* newNode = *sourceRef;
  if(newNode == NULL) return;
 
  /* Advance the source pointer */
  *sourceRef = newNode->next;
 
  /* Link the old dest off the new node */
  newNode->next = *destRef; 
 
  /* Move dest to point to the new node */
  *destRef = newNode;
}
void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef)
{
  struct node* fast;
  struct node* slow;
  if (source==NULL || source->next==NULL)
  {
    /* length < 2 cases */
    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}
/*
struct node* sortedMerge(struct node *aRef, struct node *bRef)
{
	struct node *result;
	struct node **lastRef = &result;

	while(1)
	{
		if(aRef == NULL)
		{
			*lastRef = bRef;
			break;
		}

		if(bRef == NULL)
		{
			*lastRef = aRef;
			break;
		}

		if(aRef->data <= bRef->data)
		{
			MoveNode(lastRef, &aRef);
		} 
		else
		{
			MoveNode(lastRef, &bRef);
		}

		lastRef = &((*lastRef)->next);
	}

	return result;
}
*/

struct node *sortedMerge(struct node *a, struct node *b)
{
	struct node *result = NULL;

	if(a == NULL) return b;

	else if(b == NULL) return a;

	else if(a->data <= b->data)
	{
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedMerge(a, b->next);
	}

	return result;
}

void mSort(struct node **head_ref)
{
	struct node *head = *head_ref;
	struct node *a = NULL;
	struct node *b = NULL;

	if(head == NULL || head->next == NULL) return;

	FrontBackSplit(head, &a, &b);

	mSort(&a);
	mSort(&b);

	*head_ref = sortedMerge(a, b);
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

	mSort(&head);

	printf("\n");
	printLst(head);
}



