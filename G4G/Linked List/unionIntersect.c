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

struct node * unionList(struct node **aRef, struct node **bRef)
{
	struct node *result = NULL;
	struct node *t1 = *aRef;
	struct node *t2 = *bRef;
	while(t1!=NULL)
	{
		push(&result,t1->data);
		t1 = t1->next;
	}
	while(t2!=NULL)
	{
		if(!isPresent(result,t2->data))
		{
			push(&result,t2->data);	
		}
		t2 = t2->next;
	}
	return result;
}

int isPresent(struct node *head, int num)
{
	struct node *t = head;
	while(t!=NULL)
	{
		if(t->data == num)
			return 1;
		t = t->next;
	}
	return 0;
}
struct node *getIntersection (struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1;
 
    // Traverse list1 and search each element of it in list2. If the element
    // is present in list 2, then insert the element to result
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            push (&result, t1->data);
        t1 = t1->next;
    }
 
    return result;
}
int main()
{
	struct node *head = NULL;
	struct node *a = NULL, *b = NULL;
	push(&a,11);
	push(&a,9);
	push(&a,7);
	push(&b,5);
	push(&b,3);
	push(&b,1);
	push(&a,1);
	printf("\n");
	printList(a);
	printf("\n");
	printList(b);
	head = unionList(&a,&b);
	printf("\n");
	printList(head);
	
	return 0;
}