#include <stdio.h>

size_t	ft_strlen(const char *str);

int	main(void)
{
	ft_strlen("Allo");
	printf("%ld\n", ft_strlen("Allo"));
	return (0);
}