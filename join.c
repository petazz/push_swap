#include "prueba.h"

int	ft_strlen_ps(char **argv)
{
	int i;
	int j;
	int num;

	i = 0;
	num = 0;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			j++;
			num++;
		}
		i++;
	}
	return (num);
}

char	*ft_strjoin_ps(char **argv, int argc)
{
	int i;
	int j;
	int s;
	char *str;

	i = 0;
	s = 0;
	str = malloc((ft_strlen_ps(argv) + argc)); //argc = espacios
	if (!str)
		return (NULL);
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{	
			str[s] = argv[i][j];
			s++;
			j++;
		}
		str[s++] = ' ';
		i++;
	}
	str[s] = '\0';
	return (str);
}