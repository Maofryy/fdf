#include "libft.h"

/*
static char	ft_base_char(int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'a');
}

char		*ft_lltoa_base(long long n, int base)
{
	unsigned long long int	value;
	int			count;
	char			*str;

	if (base < 2 || base > 36)
		return (NULL);
	value = (n < 0) ? -n : n;
	count = (n == 0 || (n < 0 && base == 10));
	while (value != 0)
	{
		value /= base;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	value = (n < 0) ? -n : n;
	while (--count > 0)
	{
		str[count] = ft_base_char(value % base);
		value /= base;
	}
	*str = (n < 0 && base == 10 ? '-' : ft_base_char(value));
	return (str);
}*/

char		*ft_lltoa_baset(long long n, int base)
{
	int		i;
	char	*str;

	if (n < 0)
	{
		str = ft_ulltoa_base((unsigned long long)-n, base);
		i = ft_strlen(str);
		ft_reverse_str(str, i);
		str[i++] = '-';
		ft_reverse_str(str, i);
		str[i] = '\0';
	}
	else
		str = ft_ulltoa_base((unsigned long long)n, base);
	return (str);
}