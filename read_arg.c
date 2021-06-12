#include "push_swap.h"

static long	ft_atoi_long(char *str)
{
	unsigned int	i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((str[i] > 8) && (str[i] < 14)) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] && str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((sign == -1) && (res > 9223372036854775808u))
		return (0);
	if ((sign == 1) && (res >= 9223372036854775808u))
		return (-1);
	return (sign * res);
}



int read_argv(char **argv, int i, t_var *par)
{
	int j;

	j = 0;
	while (argv[i][j])
	{
		if ((!ft_isdigit(argv[i][j])) && (argv[i][j] != '-'))
		{
			ft_putstr_fd("Error", 1);
			return (0);
		}
		par->nb = ft_atoi_long(argv[i]);
		if ((par->nb > 2147483647) || (par->nb < -2147483648))
		{
			ft_putstr_fd("Error", 1);
			return (0);
		}
		j++;
	}
	return (1);
}