/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:46:53 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/03 18:36:32 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_alive(t_philo *philos)
{
	long int	last;
	t_data		*data;

	data = data_call();
	last = get_time() - philos->last_meal;
	if (last >= data->die_time)
	{
		philos->is_dead = 1;
		if (philos->is_dead == 1)
		{
			printf("%ld ms %i is dead\n", get_time() - \
		philos->data->start, philos->id_num);
			exit (1);
		}
	}
	return (1);
}
