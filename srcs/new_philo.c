/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:19:58 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/29 19:18:16 by gade-alm         ###   ########.fr       */
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

t_data	*data_call(void)
{
	static t_data	data;

	return (&data);
}

t_philo	*phi_call(void)
{
	static t_philo	philo;

	return (&philo);
}

t_philo	*create_philos(t_data *data)
{
	int		i;
	int		is_dead;
	t_philo	*philo;

	i = -1;
	philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!philo)
		return (NULL);
	is_dead = 0;
	while (++i < data->philo_num)
	{
		philo[i].data = data_call();
		philo[i].id_num = i + 1;
		philo[i].has_fork = 0;
		philo[i].times_eat = 0;
		philo[i].is_dead = &is_dead;
	}
	return (philo);
}

void	start_philos(void)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = create_philos(data_call());
	data_call()->seconds = get_time();
	while (++i < data_call()->philo_num)
		pthread_create(&philo[i].philo, NULL, philo_jobs, (void *)&philo[i]);
	while (--i > -1)
		pthread_join(philo[i].philo, NULL);
	return ;
}
