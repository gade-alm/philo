/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:19:58 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/06 14:05:10 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	parse_philo(int ac, char **av)
{
	data_call()->philo_num = ft_atoi(av[1]);
	data_call()->die_time = ft_atoi(av[2]);
	data_call()->eat_time = ft_atoi(av[3]);
	data_call()->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data_call()->must_eat_num = ft_atoi(av[5]);
	else
		data_call()->must_eat_num = -1;
	if (!data_call()->philo_num || !data_call()->die_time || !data_call()-> \
	sleep_time || !data_call()->eat_time || !data_call()->must_eat_num)
		printf("AJEITAR O FREE\n");
	start_philos();
}

void	start_philos(void)
{
	int		i;
	t_philo	*philo;

	i = -1;
	pthread_mutex_init(&dead_call()->killer, NULL);
	philo = create_philos(data_call());
	data_call()->start = get_time();
	dead_call()->is_dead = 0;
	while (++i < data_call()->philo_num)
		pthread_create(&philo[i].philo, NULL, philo_jobs, (void *)&philo[i]);
	while (--i > -1)
		pthread_join(philo[i].philo, NULL);
	return ;
}

t_philo	*create_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!philos)
		return (NULL);
	while (++i < data->philo_num)
	{
		philos[i].data = data_call();
		philos[i].id_num = i + 1;
		philos[i].has_fork = 0;
		philos[i].times_eat = 0;
		philos[i].last_meal = 0;
		philos[i].sleeping = 0;
	}
	return (philos);
}
