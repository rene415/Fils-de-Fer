#include "libft.h"

size_t		ft_int_len(int n)
{
	size_t i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n /= 10)
		i++;
	return (i);
}
