#include<stdio.h>
void	ft_swap(int *a, int *b);

int main(void)
{
	int *a = NULL;
	int *b = NULL;
	int x = 12;
	int z = 42;

	a = &x;
	b = &z;
	printf("%p\n", &a);
	printf("%p\n", a);
	printf("%d\n", *a);
	printf("%p\n", &b);
	printf("%p\n", b);
	printf("%d\n", *b);
	ft_swap(a, b);
	printf("%p\n", &a);
	printf("%p\n", a);
	printf("%d\n", *a);
	printf("%p\n", &b);
	printf("%p\n", b);
	printf("%d\n", *b);
}
