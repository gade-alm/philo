/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:46:53 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/05 17:15:32 by gade-alm         ###   ########.fr       */
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
		pthread_mutex_lock(&dead_call()->killer);
		dead_call()->is_dead++;
		if (dead_call()->is_dead == 1)
		{
			printf("%ld ms %i is dead\n", get_time() - \
		philos->data->start, philos->id_num);
		}
		pthread_mutex_unlock(&dead_call()->killer);
		exit (1);
	}
	return (1);
}
