/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:18:45 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/09 17:44:55 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
// Your(s) program(s) should take the following arguments:
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
void *teste(void *abc)
{
	(void)abc;
	printf("teste %d\n", getpid());
	return (NULL);
}

int main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("Error\n"));
	data.philos = ft_atoi(av[1]);
	data.die_time = ft_atoi(av[2]);
	data.eat_time = ft_atoi(av[3]);
	data.sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data.n_must_eat = ft_atoi(av[5]);
	else
		data.n_must_eat = -1;
	printf("%i\n", data.die_time);
}
