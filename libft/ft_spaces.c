#include "libft.h"

int	ft_spaces(int str)
{
	unsigned char s;

	s = (unsigned char)str;
	if (s == '\t' || s == '\r' || s == '\v' || s == '\f' || s == '\n' ||
		s == ' ')
		return (1);
	else
		return (0);
}
