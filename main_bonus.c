#include "./includes/bonus.h"

// void	ft_list_push_front(t_list **begin_list, void *data)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (new == NULL)
// 		return ;
// 	new->data = data;
// 	new->next = *begin_list;
// 	*begin_list = new;
// }

int	main(void)
{
	char	*data1;
	char	*data2;
	char	*new_data;
	t_list	*node1;
	t_list	*node2;

	data1 = ft_strdup("NODE1");
	data2 = ft_strdup("NODE2");
	new_data = ft_strdup("NEW");
	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node1->data = (void *)data1;
	node1->next = node2;
	node2->data = (void *)data2;
	node2->next = NULL;
	printf("First node data : [%s]\n", (char *)node1->data);
	printf("Second node data : [%s]\n", (char *)node1->next->data);
	ft_list_push_front(&node1, new_data);
	printf("New first node data : [%s]\n", (char *)node1->data);
	printf("Second node data : [%s]\n", (char *)node1->next->data);
	printf("Third node data : [%s]\n", (char *)node1->next->next->data);
	free(data1);
	free(data2);
	free(new_data);
	return (0);
}