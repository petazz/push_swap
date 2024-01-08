#include "prueba.h"
#include "libft.h"

int		ft_is_valid(char *str)
{
	unsigned long num;
	int sign;
	int i;

	i = 0;
	sign = 1;
	num = 0;
	if(str == NULL || !str[i])
		return (0);
	while(str[i] == '-')
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


int	ft_comprobation(char **argv, int argc)
{
	int num;
	int c;

	c = 1;
	num = 0;
	while(c < argc)
	{
		if(!ft_is_valid(argv[c]))
			return (0);
		ft_atoi(argv[c]);
		c++;
	}
	return (1);
}

int ft_count_numbers(char **argv)
{	
	int i;
	
	i = 0;
	while(argv[i] != NULL)
		i++;
	return (i);
}

int ft_repeat(char *argv, int argc)
{
    int i;
    int j;

    i = 0;
    while(argv[i] < argc)
    {
        j = 0;
        while(argv[j] < argc)
        {
            if(argv[i] == argv[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}