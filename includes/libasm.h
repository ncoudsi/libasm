#ifndef LIBASM_H
# define LIBASM_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_write(unsigned int fd, const char *buf, size_t count);
size_t	ft_read(unsigned int fd, char *buf, size_t count);
char	*ft_strdup(const char *str);

#endif