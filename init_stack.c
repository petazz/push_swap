#include "prueba.h"

void	ft_error()
{
	write(2, "ERROR", 5);
	exit(EXIT_FAILURE);
}

int		ft_valid(char *str)
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

int	ft_repeat(int *arr)
{
    int i;
    int j;

	i = 0;
	while(arr[i])
	{
		j = i + 1;
		while(arr[j])
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen_int(int *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
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
	data->len = ft_strlen_int(data->arr);
	while(argv[i])
	{
		if(!ft_valid(argv[i]))
			ft_error();
		data->arr[i] = ft_atoi(argv[i]);
		i++;
	}
	if (!ft_repeat(data->arr))
		ft_error();
	
	data->len = ft_strlen_int(data->arr);
	t_node *primerNodo = listGenerator(data->arr, data->len);
	for(int i = 0; i < data->len; i++)
	{
		printf("nodo :	%d\n", primerNodo->n);
		primerNodo = primerNodo->next;
	}
	sa(primerNodo);
	for(int i = 0; i < data->len; i++)
	{
		printf("movimiento nodo :	%d\n", primerNodo->n);
		primerNodo = primerNodo->next;
	}
}