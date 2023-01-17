/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:18:45 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/17 11:29:41 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
// Your(s) program(s) should take the following arguments:
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("Error\n"));
	parse_philo(ac, av);
	return (1);
}
