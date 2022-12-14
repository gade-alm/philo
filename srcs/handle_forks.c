/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:00:47 by gabriel           #+#    #+#             */
/*   Updated: 2023/01/12 17:44:18 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	available_forks(t_philo *phi, int index)
{
	while (philo_alive(phi))
	{
		pthread_mutex_lock(&phi->forks[index].forks);
		if (phi->forks[index].has_fork == 0 && phi->many_forks < 2)
		{
			phi->forks[index].has_fork = 1;
			phi->many_forks++;
			pthread_mutex_unlock(&phi->forks[index].forks);
			return (1);
		}
		else if (phi->many_forks == 2 && phi->has_eaten == 1)
		{
			phi->many_forks--;
			phi->forks[index].has_fork = 0;
		}
		else if (phi->many_forks == 1 && phi->has_eaten == 1)
		{
			phi->many_forks--;
			phi->has_eaten = 0;
			phi->forks[index].has_fork = 0;
		}
		pthread_mutex_unlock(&phi->forks[index].forks);
	}
	return (0);
}

int	check_forks(t_philo *phi)
{
	int	left;
	int	right;

	right = phi->id_num - 1;
	if (phi->id_num == 1)
		right = phi->data->philo_num;
	left = phi->id_num;
	if (phi->id_num == phi->data->philo_num)
		left = 1;
	if (available_forks(phi, right))
		print_message(phi, "has taken right fork");
	if (available_forks(phi, left))
		print_message(phi, "has taken left fork");
	if (phi->many_forks == 2)
		return (1);
	return (0);
}

t_forks	*forks_init(t_data *data)
{
	t_forks	*fork;
	int		i;

	i = -1;
	fork = malloc(sizeof(t_forks) * (data->philo_num));
	if (!fork)
		return (NULL);
	while (++i < data->philo_num)
	{
		fork[i].has_fork = 0;
		pthread_mutex_init(&fork[i].forks, NULL);
	}
	return (fork);
}
