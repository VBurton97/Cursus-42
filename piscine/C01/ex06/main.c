#include<stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char *str;
	int nb;

	str = "papa";
	nb = ft_strlen(str);
	printf("%d\n", nb);
	 
}
