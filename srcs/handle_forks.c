/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:00:47 by gabriel           #+#    #+#             */
/*   Updated: 2023/02/28 16:27:05 by gade-alm         ###   ########.fr       */
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
			phi->many_forks += 1;
			print_message(phi, "has taken a fork");
			pthread_mutex_unlock(&phi->forks[index].forks);
			break ;
		}
		else
			pthread_mutex_unlock(&phi->forks[index].forks);
	}
	return (0);
}

int	check_forks(t_philo *phi)
{
	int	left;
	int	right;

	right = phi->id_num;
	left = phi->id_num - 1;
	if (right == data_call()->philo_num)
		right = 0;
	phi->right_fork = right;
	phi->left_fork = left;
	if (philo_alive(phi))
	{
		available_forks(phi, right);
		available_forks(phi, left);
		if (phi->many_forks == 2)
			philo_eat(phi);
		return (1);
	}
	return (0);
}

void	put_forks(t_philo *phi, int index)
{
	pthread_mutex_lock(&phi->forks[index].forks);
	phi->forks[index].has_fork = 0;
	pthread_mutex_unlock(&phi->forks[index].forks);
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
