/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:19:58 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/26 11:16:49 by gade-alm         ###   ########.fr       */
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

	i = -1;
	while (++i < datacall()->philo_num)
		printf("teste");
	return ;
}
