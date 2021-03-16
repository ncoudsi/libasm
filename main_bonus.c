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

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_ftc)(void *))
{
	t_list	*actual_node;
	t_list	*tmp;

	actual_node = *begin_list;
	tmp = actual_node;
	while (actual_node != NULL)
	{
		if (cmp(actual_node->data, data_ref) == 0)
		{
			free_ftc(actual_node->data);
			tmp->next = actual_node->next;
			tmp = actual_node;
			actual_node = actual_node->next;
			if (tmp == *begin_list)
				*begin_list = actual_node;
			free (tmp);
		}
		else
		{
			tmp = actual_node;
			actual_node = actual_node->next;
		}
	}
}

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
	ft_list_sort(&node1, strcmp);
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
	//	Free all.
	free(data1);
	free(data2);
	free(new_data);
	free(node1);
	free(node2);
	free(node2->next);
	return (0);
}