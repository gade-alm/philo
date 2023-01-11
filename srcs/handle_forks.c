/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:00:47 by gabriel           #+#    #+#             */
/*   Updated: 2023/01/11 18:39:22 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	available_forks(t_philo *phi, int index)
{
	while (philo_alive(phi))
	{
		pthread_mutex_lock(&phi->forks[index].forks);
		if (phi->forks[index].has_fork == 0)
		{
			phi->forks[index].has_fork = 1;
			pthread_mutex_unlock(&phi->forks[index].forks);
			break ;
		}
		else
			pthread_mutex_unlock(&phi->forks[index].forks);
	}
}

int	check_forks(t_philo *phi)
{
	int	left;
	int	right;

	right = phi->id_num - 1;
	if (phi->id_num == 1)
		right = phi->data->philo_num - 1;
	left = phi->id_num - (phi->id_num == 1);
	available_forks(phi, right);
	print_message(phi, "has taken a fork");
	check_corpse();
	available_forks(phi, left);
	print_message(phi, "has taken a fork");
	return (1);
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
