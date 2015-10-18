#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int *arr;
};

typedef struct Queue* Q;

Q createQueue(unsigned capacity)
{
	Q q = (Q)malloc(sizeof(struct Queue));
	q->capacity = capacity;
	q->front = q->size = 0;
	q->rear = capacity - 1;
	q->arr = (int *)malloc(q->capacity * sizeof(int));
	return q;
}

int isFull(Q q)
{
	return q->size == q->capacity;
}

int isEmpty(Q q)
{
	return q->size == 0;
}

void enQueue(Q q, int item)
{
	if(isFull(q))
		return;
	q->rear = (q->rear + 1)%q->capacity;
	q->arr[q->rear] = item;
	q->size = q->size + 1;

	cout << item << " added to Queue\n";
}

void deQueue(Q q)
{
	if(isEmpty(q))
		cout << INT_MIN << endl;
	int data = q->arr[q->front];
	q->front = (q->front + 1)%q->capacity;
	q->size = q->size + 1;
	
	cout << data << " deQueued from Queue.\n";
}

void front(Q q)
{
	if(isEmpty(q))
		cout << INT_MIN << endl;
	cout << q->arr[q->front] << endl;
}

void rear(Q q)
{
	if(isFull(q))
		cout << INT_MIN << endl;
	cout << q->arr[q->rear] << endl;
}

int main()
{ _
	Q q = createQueue(1000);

	enQueue(q, 10);
	enQueue(q, 20);
	enQueue(q, 40);
	enQueue(q, 60);
	enQueue(q, 30);
	enQueue(q, 70);

	deQueue(q);
	deQueue(q);

	front(q);
	rear(q);

	return 0;
}