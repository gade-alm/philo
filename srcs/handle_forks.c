/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:00:47 by gabriel           #+#    #+#             */
/*   Updated: 2023/01/09 17:00:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	forks_init(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data_call()->philo_num)
		philos->forks->num_forks[i] = malloc(sizeof(int *) * \
	(data_call()->philo_num));
	if (!philos->forks->num_forks)
		return ;
	while (++i < data_call()->philo_num)
		pthread_mutex_init(&forks_call()->forks[i], NULL);
}
