#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_write(unsigned int fd, const char *buf, size_t count);
size_t	ft_read(unsigned int fd, char *buf, size_t count);
char	*ft_strdup(const char *str);

int	main(void)
{
	char	*src;
	char	*dest;
	char	*read_buf;
	char	*tmp1;
	char	*tmp2;
	int		fd;
	size_t	write_ret;

	src = ft_strdup("HELLO");
	dest = ft_strdup("hello");
	read_buf = ft_strdup("          ");
	fd = open("./main.c", O_RDONLY);
	/*
	**	FT_STRLEN
	*/
	printf("\t===FT_STRLEN===\n");
	printf("==Test on src string.\n");
	printf("OFFICIAL  : [%ld]\n", strlen(src));
	printf("HOME MADE : [%ld]\n", ft_strlen(src));
	printf("==Test on empty string.\n");
	printf("OFFICIAL  : [%ld]\n", strlen(""));
	printf("HOME MADE : [%ld]\n", ft_strlen(""));
	/*
	**	FT_STRCPY
	*/
	printf("\t===FT_STRCPY===\n");
	//	dest = "hello", src = "HELLO"
	printf("==Test with \"HELLO\" as src and \"hello\" as dest string.\n");
	printf("OFFICIAL  : [%s]\n", strcpy(dest, src));
	//	--reset dest value
	dest = strcpy(dest, "hello");
	printf("HOME MADE : [%s]\n", ft_strcpy(dest, src));
	//	dest = "LONGR" src = "SHO"
	dest = strcpy(dest, "LONGR");
	printf("==Test with longer dest than src string.\n");
	printf("OFFICIAL  : [%s]\n", strcpy(dest, "SHO"));
	//	--reset dest value
	dest = strcpy(dest, "LONGR");
	printf("HOME MADE : [%s]\n", ft_strcpy(dest, "SHO"));
	//	dest = "empty" src = ""
	dest = strcpy(dest, "empty");
	printf("==Test with empty src and \"empty\" as dest string.\n");
	printf("OFFICIAL  : [%s]\n", strcpy(dest, ""));
	//	--reset dest value
	dest = strcpy(dest, "empty");
	printf("HOME MADE : [%s]\n", ft_strcpy(dest, ""));
	//	no test with dest smaller than src since it is undefined behaviors
	printf("==No test with dest smaller than src since OFFICIAL one SEGV in this case.\n");
	/*
	**	FT_STRCMP
	*/
	printf("\t===FT_STRCMP===\n");
	//	both strings are equivalent
	printf("==Test with equivalent strings\n");
	printf("OFFICIAL  : [%d]\n", strcmp("AAA", "AAA"));
	printf("HOME MADE : [%d]\n", ft_strcmp("AAA", "AAA"));
	//	s1 > s2
	printf("==Test with s1 > s2\n");
	printf("OFFICIAL  : [%d]\n", strcmp("BAA", "AAA"));
	printf("HOME MADE : [%d]\n", ft_strcmp("BAA", "AAA"));
	//	s1 < s2
	printf("==Test with s1 < s2\n");
	printf("OFFICIAL  : [%d]\n", strcmp("AAA", "BAA"));
	printf("HOME MADE : [%d]\n", ft_strcmp("AAA", "BAA"));
	/*
	**	FT_WRITE
	*/
	printf("\t===FT_WRITE===\n");
	//	--test with "TEST" string
	printf("==Test with \"TEST\" string\n");
	printf("HOME MADE STRING :\n");
	write_ret = ft_write(1, "TEST\n", 5);
	printf("HOME MADE RETURN : [%ld]\n", write_ret);
	printf("OFFICIAL  STRING :\n");
	write_ret = write(1, "TEST\n", 5);
	printf("OFFICIAL  RETURN : [%ld]\n", write_ret);
	//	--test with empty string
	printf("==Test with empty string\n");
	printf("HOME MADE STRING :\n");
	write_ret = ft_write(1, "", 0);
	printf("HOME MADE RETURN : [%ld]\n", write_ret);
	printf("OFFICIAL  STRING :\n");
	write_ret = write(1, "", 0);
	printf("OFFICIAL  RETURN : [%ld]\n", write_ret);
	/*
	**	FT_READ
	*/
	printf("\t===FT_READ===\n");
	printf("OFFICIAL RETURN  : [%ld]\n", read(fd, read_buf, 10));
	printf("OFFICIAL BUF     : [%s] \n", read_buf);
	//	--reset read_buf value, close the fd, and re-open it
	read_buf = strcpy(read_buf, "          ");
	close(fd);
	fd = open("./main.c", O_RDONLY);
	printf("HOME MADE RETURN : [%ld]\n", read(fd, read_buf, 10));
	printf("HOME MADE BUF    : [%s] \n", read_buf);
	/*
	**	FT_STRDUP
	*/
	printf("\t===FT_STRDUP===\n");
	//	--test with "HELLO" string
	printf("==Test with \"HELLO\" string\n");
	tmp1 = strdup("HELLO");
	printf("OFFICIAL   : [%s]\n", tmp1);
	tmp2 = ft_strdup("HELLO");
	printf("HOME_MADE  : [%s]\n", tmp2);
	//	--free tmps
	free(tmp1);
	free(tmp2);
	//	--test with empty string
	printf("==Test with empty string\n");
	tmp1 = strdup("");
	printf("OFFICIAL   : [%s]\n", tmp1);
	tmp2 = ft_strdup("");
	printf("HOME_MADE  : [%s]\n", tmp2);
	//	--free all
	free(tmp1);
	free(tmp2);
	free(src);
	free(dest);
	free(read_buf);
	return (0);
}