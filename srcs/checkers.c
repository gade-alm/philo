/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:46:53 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/06 12:48:03 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_corpse(void)
{
	int			corpse;

	pthread_mutex_lock(&dead_call()->killer);
	corpse = dead_call()->is_dead;
	pthread_mutex_unlock(&dead_call()->killer);
	if (corpse)
		return (0);
	return (1);
}

int	philo_alive(t_philo *philos)
{
	long int	last;
	t_data		*data;

	if (!check_corpse())
		return (0);
	data = data_call();
	last = get_time() - philos->last_meal;
	if (last >= data->die_time)
	{
		pthread_mutex_lock(&dead_call()->killer);
		dead_call()->is_dead = 42;
		if (dead_call()->is_dead)
			print_message(philos, "died");
		pthread_mutex_unlock(&dead_call()->killer);
		return (0);
	}
	return (1);
}
