/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:00:47 by gabriel           #+#    #+#             */
/*   Updated: 2023/01/16 10:33:15 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	available_forks(t_philo *phi, int index)
{
	while (philo_alive(phi))
	{
		pthread_mutex_lock(&phi->forks[index].forks);
		if (phi->forks[index].has_fork == 0)
		{
			phi->forks[index].has_fork = 1;
			phi->many_forks++;
			print_message(phi, "has taken a fork");
			pthread_mutex_unlock(&phi->forks[index].forks);
			return (1);
		}
		if (phi->has_eaten > 0 && phi->forks[index].has_fork == 1)
		{
			phi->forks[index].has_fork = 0;
			phi->has_eaten--;
			pthread_mutex_unlock(&phi->forks[index].forks);
			return (0);
		}
		pthread_mutex_unlock(&phi->forks[index].forks);
	}
	return (1);
}

int	check_forks(t_philo *phi)
{
	int	left;
	int	right;

	right = phi->id_num;
	left = phi->id_num + 1;
	if (phi->id_num == phi->data->philo_num)
		left = 1;
	phi->right_fork = right;
	phi->left_fork = left;
	while (philo_alive(phi))
	{
		available_forks(phi, right);
		available_forks(phi, left);
		if (phi->many_forks == 2)
			philo_eat(phi);
		return (1);
	}
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
