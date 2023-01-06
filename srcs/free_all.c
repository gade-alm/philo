/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:16:48 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/06 10:13:08 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_stuff(t_clean *clean)
{
	int	i;

	i = -1;
	if (clean->philos->death->killer)
		pthread_mutex_destroy(&dead_call()->killer);
	if (clean->philos)
	{
		while (++i < data_call()->philo_num)
			free (clean->philos[i]);
		free (clean);
	}
	return ;
}
