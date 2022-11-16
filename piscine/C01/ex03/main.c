#include<stdio.h>
void ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
	int a;
	int b;
	int x;
	int y;
	int *div; 
	int *mod;

	a = 13;
	b = 10;
	div = &x;
	mod = &y;
	ft_div_mod(a, b, div, mod);
	printf("%d\n", *div);
	printf("%d\n", *mod);


}
