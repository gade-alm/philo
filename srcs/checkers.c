/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:46:53 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/29 19:19:22 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_alive(t_philo *philos)
{
	long int	last;
	t_data		*data;

	data = data_call();
	last = philos->last_meal - data->seconds;
	if (last > data->die_time)
		*philos->is_dead = 1;
	if (*philos->is_dead)
		return (1);
	return (0);
}
