#include "./includes/libasm.h"

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
	printf("\n==No test are made on undefined behaviors\n\n");
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
	printf("OFFICIAL  : [%d]\n", strcmp("CCC", "AAA"));
	printf("HOME MADE : [%d]\n", ft_strcmp("CCC", "AAA"));
	//	s1 < s2
	printf("==Test with s1 < s2\n");
	printf("OFFICIAL  : [%d]\n", strcmp("AAA", "BBB"));
	printf("HOME MADE : [%d]\n", ft_strcmp("AAA", "BBB"));
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
	//	--error test with NULL string
	printf("==Error test with NULL string\n");
	write_ret = write(1, NULL, 1);
	printf("OFFICIAL  RETURN : [%ld]\n", write_ret);
	printf("ERRNO VALUE : [%d]\n", errno);
	errno = 0;
	write_ret = ft_write(1, NULL, 1);
	printf("HOME MADE RETURN : [%ld]\n", write_ret);
	printf("ERRNO VALUE : [%d]\n", errno);
	//	--error test with bad FD
	fd = open("./not_a_file.lol", O_RDONLY);
	printf("==Error test with wrong fd\n");
	write_ret = write(fd, "TEST", 4);
	printf("OFFICIAL  RETURN : [%ld]\n", write_ret);
	printf("ERRNO VALUE : [%d]\n", errno);
	errno = 0;
	write_ret = ft_write(fd, "TEST", 4);
	printf("HOME MADE RETURN : [%ld]\n", write_ret);
	printf("ERRNO VALUE : [%d]\n", errno);
	close(fd);
	/*
	**	FT_READ
	*/
	printf("\t===FT_READ===\n");
	printf("==Basic test\n");
	fd = open("./main.c", O_RDONLY);
	printf("OFFICIAL RETURN  : [%ld]\n", read(fd, read_buf, 10));
	printf("OFFICIAL BUF     : [%s] \n", read_buf);
	//	--reset read_buf value, close the fd, and re-open it
	read_buf = strcpy(read_buf, "          ");
	close(fd);
	fd = open("./main.c", O_RDONLY);
	printf("HOME MADE RETURN : [%ld]\n", ft_read(fd, read_buf, 10));
	printf("HOME MADE BUF    : [%s] \n", read_buf);
	//	--test with error
	fd = open("./not_a_file.lol", O_RDONLY);
	printf("==Error test with wrond fd\n");
	printf("OFFICIAL RETURN  : [%ld]\n", read(fd, read_buf, 10));
	printf("ERRNO VALUE : [%d]\n", errno);
	//	--reset errno value
	errno = 0;
	printf("HOME MADE RETURN : [%ld]\n", ft_read(fd, read_buf, 10));
	printf("ERRNO VALUE : [%d]\n", errno);
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