/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:19:58 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/25 16:39:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*parse_philo(int ac, char **av)
{
	t_data	*phi;

	phi->philo_num = ft_atoi(av[1]);
	phi->die_time = ft_atoi(av[2]);
	phi->eat_time = ft_atoi(av[3]);
	phi->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		phi->must_eat_num = ft_atoi(av[5]);
	else
		phi->must_eat_num = 0;
	return (phi);
}

t_data	*phicall(void)
{
	static t_data	philos;

	return (&philos);
}

t_philo	*create_philos(t_data *phi)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		printf("error on malloc");
	return (philo);
}

void	start_philos(void)
{
	int			i;
	t_philo		*philo;
	t_data		*data;

	i = -1;
	printf("philo %i\n", data->philo_num);
	while (++i < data->philo_num)
	{
		i = pthread_create(&philo->philo, NULL, print_message, NULL);
		if (!i)
			printf("error on creation of philo");
	}
	pthread_detach(philo->philo);
	printf("philo:num %i\n", i);
	return ;
}
