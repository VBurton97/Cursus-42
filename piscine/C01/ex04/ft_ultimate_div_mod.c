void	ft_ultimate_mod(int *a, int *b)
{
	int quotient;
	int reste;

	quotient = *a / *b;
	reste = *a % *b;
	*a = quotient;
	*b = reste;

}
