#include<stdio.h>
#include<malloc.h>

int main()
{
	int *a, *b, *c;
	int i, n;
	int sum, carry = 0;

	printf("Enter n: \n");
	scanf("%d", &n);
	
	a = (int *)malloc(sizeof(int) * n);
	b = (int *)malloc(sizeof(int) * n);
	c = (int *)malloc(sizeof(int) * (n + 1));

	for(i = 0; i <= n; i++)
		c[i] = 0;

	printf("Enter n bit a[0...n-1] binary nos.: \n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Enter n bit b[0...n-1] binary nos.: \n");
	for(i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for(i = n-1; i >= 0; i--)
	{
		sum = a[i] + b[i] + carry;
		c[i+1] = sum % 2;
		carry = sum / 2;
	}
	c[0] = carry;
	printf("Result n+1 bit c[0...n] binary nos. is: \n");
	for(i = 0; i <= n; i++)
		printf("%d ", c[i]);

	return 0;
}