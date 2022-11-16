#include<stdio.h>

void	ft_ultimate_mod(int *a, int *b);

int main(void)
{
	int *a;
	int *b;
	int x;
	int y;
	
	x = 13;
	y = 10;
	a = &x;
	b = &y;
	ft_ultimate_mod(a, b);
	printf("%d,\n", *a);
	printf("%d, \n", *b);
	
}
