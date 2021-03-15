#include "./includes/bonus.h"

// void	ft_list_sort(t_list **begin_list, int (*cmp)())
// {
// 	t_list	*node_tmp;
// 	void	*data_tmp;

// 	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
// 		return ;
// 	node_tmp = *begin_list;
// 	while (node_tmp->next != NULL)
// 	{
// 		if (cmp((char *)node_tmp->data, (char *)node_tmp->next->data) <= 0)
// 			node_tmp = node_tmp->next;
// 		else
// 		{
// 			data_tmp = node_tmp->data;
// 			node_tmp->data = node_tmp->next->data;
// 			node_tmp->next->data = data_tmp;
// 			node_tmp = *begin_list;
// 		}
// 	}
// }

int	main(void)
{
	char	*data1;
	char	*data2;
	char	*new_data;
	t_list	*node1;
	t_list	*node2;

	data1 = ft_strdup("BBB");
	data2 = ft_strdup("CCC");
	new_data = ft_strdup("AAA");
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
	//	Free all.
	free(data1);
	free(data2);
	free(new_data);
	free(node1);
	free(node2);
	free(node2->next);
	return (0);
}