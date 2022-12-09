/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:07:06 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/09 17:40:31 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>	

typedef struct s_data{
	int			die_time;
	int			sleep_time;
	int			think_time;
	int			n_must_eat;
	int			eat_time;
	int			philos;
}			t_data;

typedef struct s_philos{
	pthread_t	philo;
	t_data		data;
}		t_philos;

int		ft_atoi(const char *str);
void	create_philo(int num);
void	*teste(void *abc);

#endif