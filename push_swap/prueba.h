#ifndef PRUEBA_H
# define PRUEBA_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct s_node
{
	int n;
	struct s_node *next;
	struct s_node *prev;
} t_node;
#endif