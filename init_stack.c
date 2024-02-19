#include "prueba.h"

void	ft_error()
{
	write(2, "ERROR", 5);
	exit(EXIT_FAILURE);
}

int		 ft_valid(char *str)
{
	unsigned long num;
	int sign;
	int i;

	i = 0;
	sign = 1;
	num = 0;
	if(str == NULL || !str[i])
		return (0);
	while(str[i] == ' ')
		i++;
	if(str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if(str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		i++;
	}
	while(str[i] && num < 2147483648)
	{
		if(str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	if((sign == 1 && num > 2147483648) || (sign == -1 && num > 2147483648))
		return (0);
	return (1);
}

int	ft_repeat(int *arr, int len)
{
    int i;
    int j;

	i = 0;
	while(i < len - 1)
	{
		j = i + 1;
		while(j < len)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init_stack(char **argv, t_data *data, int argc)
{
	char	*str;
	int 	i;

	i = 0;
	data->arr = malloc(ft_strlen_ps(argv) * sizeof(int));
	if(!data->arr)
		write(2, "ERROR", 5); // funcion limpieza nodos
	str = ft_strjoin_ps(argv, argc);
	argv = ft_split(str, ' ');
	while(argv[i])
	{
		if(!ft_valid(argv[i]))
			ft_error();
		data->arr[i] = ft_atoi(argv[i]);
		i++;
	}
	data->len = i;
	if (!ft_repeat(data->arr, data->len))
		ft_error();
	data->stack_A = listGenerator(data->arr, data->len);
	//////////////////IMPRIMIR//////////////////////
	/* for(int i = 0; i < data->len; i++)
	{
		printf("nodo :	%d\n", data->stack_A->n);
		data->stack_A = data->stack_A->next;
	} */
	/* int arr2[] = {4, 5, 6};
	t_node *segundoNodo = listGenerator(arr2, 3);
	for(int i = 0; i < data->len; i++)
	{
		printf("nodo 2:	%d\n", segundoNodo->n);
		segundoNodo = segundoNodo->next;
	} */  
}