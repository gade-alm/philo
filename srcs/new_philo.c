/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:19:58 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/12 17:10:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philos	start_philos(int ac, char **av)
{
	t_philos	philos;

	philos.data.philo_num = ft_atoi(av[1]);
	philos.data.die_time = ft_atoi(av[2]);
	philos.data.eat_time = ft_atoi(av[3]);
	philos.data.sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		philos.data.must_eat_num = ft_atoi(av[5]);
	else
		philos.data.must_eat_num = 0;
	return (philos);
}
