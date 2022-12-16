/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:07:06 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/16 18:18:39 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data{
	int			die_time;
	int			sleep_time;
	int			think_time;
	int			must_eat_num;
	int			eat_time;
	int			philo_num;
	long int	seconds;
}			t_data;

typedef struct s_philos{
	pthread_t		philo;
	t_data			data;
}		t_philos;

int			ft_atoi(const char *str);
t_philos	*phicall(void);
t_philos	start_philos(int ac, char **av);
void		*create_philos(t_philos phi);
long int	calc_time(long int start, long int end);
long int	gettime(void);
void	*print_message(void *arg);

#endif