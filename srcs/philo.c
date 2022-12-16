/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:18:45 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/16 17:55:13 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
// Your(s) program(s) should take the following arguments:
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]

int	main(int ac, char **av)
{
	t_philos	philos;

	if (ac < 5 || ac > 6)
		return (printf("Error\n"));
	philos = start_philos(ac, av);
	create_philos(philos);
	return (1);
}
