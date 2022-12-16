/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:19:58 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/16 18:20:06 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philos	start_philos(int ac, char **av)
{
	t_philos	phi;

	phi.data.philo_num = ft_atoi(av[1]);
	phi.data.die_time = ft_atoi(av[2]);
	phi.data.eat_time = ft_atoi(av[3]);
	phi.data.sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		phi.data.must_eat_num = ft_atoi(av[5]);
	else
		phi.data.must_eat_num = 0;
	return (phi);
}

t_philos	*phicall(void)
{
	static t_philos	philos;

	return (&philos);
}

void	*create_philos(t_philos phi)
{
	int			i;
	pthread_t	philos;

	i = -1;
	while (++i < phi.data.philo_num)
	{
		i = pthread_create(&philos, NULL, print_message, &phi);
		if (i != 0)
			printf("error on creation");
	}
	pthread_detach(philos);
	printf("philo:num %i\n", phi.data.philo_num);
	return (0);
}
