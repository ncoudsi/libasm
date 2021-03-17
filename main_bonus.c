#include "./includes/bonus.h"

int		comp(void *data1, void *data2)
{
	int	result;

	result = 0;
	if (ft_strcmp((char *)data1, (char *)data2) == 0)
		result = 1;
	return (result);
}

void	free_ftc(void *data)
{
	free(data);
	data = NULL;
}

int	is_double_char(char actual_char, char *base, int char_index)
{
	while (base[char_index] != '\0')
	{
		char_index ++;
		if (base[char_index] == actual_char)
			return (1);
	}
	return (0);
}

int	is_valid_base(char *base)
{
	int		index;

	index = 0;
	if (base == NULL || ft_strlen(base) < 2)
		return (0);
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		else if (is_double_char(base[index], base, index) == 1)
			return (0);
		index++;
	}
	return (1);
}

int	is_whitespace(char actual_char)
{
	if (actual_char == '\t' || actual_char == '\v' || 
	actual_char == '\n' || actual_char == '\r' || actual_char == '\f' || 
	actual_char == ' ')
		return (1);
	return (0);
}

int	is_base(char actual_char, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == actual_char)
			return (index);
		index++;
	}
	return (-1);
}

// int		ft_atoi_base(char *str, char *base)
// {
// 	int	result;
// 	int	sign;
// 	int	index;

// 	result = 0;
// 	sign = 1;
// 	index = 0;
// 	if (is_valid_base(base) == 0)
// 		return (result);
// 	while (is_whitespace(str[index]) == 1)
// 		index++;
// 	while (str[index] == '+' || str[index] == '-')
// 	{
// 		if (str[index] == '-')
// 			sign *= -1;
// 		index++;
// 	}
// 	while (is_base(str[index], base) != -1)
// 	{
// 		result = result * ft_strlen(base) + is_base(str[index], base);
// 		index++; 
// 	}
// 	return (result * sign);
// }

int	main(void)
{
	char	*data1;
	char	*data2;
	char	*new_data;
	char	*data_ref;
	t_list	*node1;
	t_list	*node2;

	data1 = ft_strdup("BBB");
	data2 = ft_strdup("AAA");
	new_data = ft_strdup("CCC");
	data_ref = ft_strdup("BBB");
	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node1->data = (void *)data1;
	node1->next = node2;
	node2->data = (void *)data2;
	node2->next = NULL;
	//	Print list size before adding a new node.
	printf("Nodes in list : [%d]\n", ft_list_size(node1));
	//	Print list nodes before adding a new one.
	printf("First node data : [%s]\n", (char *)node1->data);
	printf("Second node data : [%s]\n", (char *)node1->next->data);
	ft_list_push_front(&node1, new_data);
	//	Print list nodes after adding a new one.
	printf("==After push front : \n");
	printf("New first node data : [%s]\n", (char *)node1->data);
	printf("Second node data : [%s]\n", (char *)node1->next->data);
	printf("Third node data : [%s]\n", (char *)node1->next->next->data);
	//	Print list new size.
	printf("Nodes in list : [%d]\n", ft_list_size(node1));
	ft_list_sort(&node1, ft_strcmp);
	//	Print list nodes after sorting.
	printf("==After sorting nodes : \n");
	printf("First node data : [%s]\n", (char *)node1->data);
	printf("Second node data : [%s]\n", (char *)node1->next->data);
	printf("Third node data : [%s]\n", (char *)node1->next->next->data);
	printf("Nodes in list : [%d]\n", ft_list_size(node1));
	//	Print list after remove_if.
	printf("==After remove_if, with \"BBB\" as data_ref : \n");
	ft_list_remove_if(&node1, (void *)data_ref, comp, free_ftc);
	printf("Only node data : [%s]\n", (char *)node1->data);
	printf("Nodes in list : [%d]\n", ft_list_size(node1));
	//	Print ft_atoi_base results.
	printf("==FT_ATOI_BASE==\n");
	printf("str = \"ff\" base = \"0123456789abcdef\" RETURN : [%d]\n", ft_atoi_base("ff", "0123456789abcdef"));
	printf("str = \"    ++---1502ffPOIET\" base = \"0123456789abcdef\" RETURN : [%d]\n", ft_atoi_base("    ++---1502ffPOIET", "0123456789abcdef"));
	//	Free all.
	free(data1);
	free(data2);
	free(new_data);
	free(node1);
	free(node2);
	free(node2->next);
	return (0);
}