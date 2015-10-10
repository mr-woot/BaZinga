#include<stdio.h>
#include<stdlib.h>

#define STACKSIZE 200	
// A structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    char* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
//    printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}
 
// Function to get top item from stack
char peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

int Prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		case '/':
		case '*':
			return 2;
		case '^':
			return 3;
	}
	
	return -1;
}

void infixToRPN(char *exp)
{
	struct Stack* stack = createStack(STACKSIZE);
	int i,k;
	if(!stack) return;
	
	for(i = 0,k = -1; exp[i]; i++)
	{
		if(isOperand(exp[i]))
		{
			exp[++k] = exp[i];
		}
		else if(exp[i] == '(')
		{
			push(stack,exp[i]);
		}
		else if(exp[i] == ')')
		{
			while(!isEmpty(stack) && peek(stack) != '(')
			{
				exp[++k] = pop(stack);
			}
			if(!isEmpty(stack) && peek(stack) != '(')
				return ;
			else
			{
				pop(stack);
			}
		}
		else
		{
			while(!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
			{
				exp[++k] = pop(stack);
			}
			push(stack,exp[i]);
		}
	}
	
	// pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack);
 
    exp[++k] = '\0';
    printf( "%s\n", exp );
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char expression[400];
		int i;
		scanf("%s",&expression);
		infixToRPN(expression);
	}
	return 0;
}




