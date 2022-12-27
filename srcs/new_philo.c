/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:19:58 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/27 18:13:02 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	parse_philo(int ac, char **av)
{
	datacall()->philo_num = ft_atoi(av[1]);
	datacall()->die_time = ft_atoi(av[2]);
	datacall()->eat_time = ft_atoi(av[3]);
	datacall()->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		datacall()->must_eat_num = ft_atoi(av[5]);
	else
		datacall()->must_eat_num = -1;
	if (!datacall()->philo_num || !datacall()->die_time || \
	!datacall()->sleep_time || !datacall()->eat_time)
		printf("AJEITAR O FREE");
	start_philos();
}

t_data	*datacall(void)
{
	static t_data	data;

	return (&data);
}

t_philo	*phicall(void)
{
	static t_philo	philo;

	return (&philo);
}

t_philo	*create_philos(int num)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		printf("error on malloc");
	return (philo);
}

void	start_philos(void)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = malloc(sizeof(t_philo) * (datacall()->philo_num));
	while (++i < datacall()->philo_num)
		pthread_create(&philo[i].philo, NULL, print_message, NULL);
	printf("valor de i %i\n", i);
	while (--i > -1)
		pthread_join(philo[i].philo, NULL);
	return ;
}
