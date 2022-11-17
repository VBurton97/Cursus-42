# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(int nbr, char *base, int len);

int	main(void)
{
	int	c = 1556;
	int	p;
	int	ft;
	char	*s = "hello";
	p = printf(" %d \n", -10);
	ft = ft_printf(" %d \n", -10);
	printf("len p = %d\n", p);
	printf("len ft = %d\n", ft);
	return (0);
}
