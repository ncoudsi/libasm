#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);

char	*ft_strdup(char *src)
{
	int		index;
	int		len;
	char	*result;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	for (int l = 0; l < len; l++)
		result[l] = '\0';
	index = 0;
	while (index < len)
	{
		result[index] = src[index];
		index++;
	}
	return (result);
}

int	main(void)
{
	char	*src;
	char	*dest;

	src = ft_strdup("HELLO");
	dest = ft_strdup("hello");
	// FT_STRLEN
	printf("\t===FT_STRLEN===\n");
	printf("Test on src string.\n");
	printf("[%ld]\n", ft_strlen(src));
	printf("Test on empty string.\n");
	printf("[%ld]\n", ft_strlen(""));
	// FT_STRCPY
	printf("\t===FT_STRCPY===\n");
	// dest = "hello", src = "HELLO"
	printf("Test with \"HELLO\" as src and \"hello\" as dest string.\n");
	printf("[%s]\n", ft_strcpy(dest, src));
	// Set dest with "empty" value, to do the new test.
	dest = ft_strcpy(dest, "empty");
	// dest = "empty" src = ""
	printf("Test with empty src and \"empty\" as dest string.\n");
	printf("[%s]\n", ft_strcpy(dest, ""));
	// dest = "" src = "HELLO"
	printf("Test with src and empty dest string.\n");
	printf("[%s]\n", ft_strcpy("", src));
	return (0);
}