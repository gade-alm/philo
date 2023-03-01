/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:53:09 by gade-alm          #+#    #+#             */
/*   Updated: 2023/03/01 16:21:37 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_data	*data_call(void)
{
	static t_data	data;

	return (&data);
}

t_dead	*dead_call(void)
{
	static t_dead	death;

	return (&death);
}

t_forks	*forks(void)
{
	static t_forks	forks;

	return (&forks);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			signal;
	long long	conv;

	i = 0;
	signal = 1;
	conv = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str [i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		conv = (conv * 10 + (str[i] - '0'));
			i++;
		if (conv > 2147483647)
			return (0);
	}
	return (conv * signal);
}

void	print_message(t_philo *philos, char *str)
{
	printf("%ld %i %s\n", get_time() - \
		philos->data->start, philos->id_num, str);
	return ;
}
