/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:07:06 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/29 19:14:38 by gade-alm         ###   ########.fr       */
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
	int				die_time;
	int				sleep_time;
	int				think_time;
	int				must_eat_num;
	int				eat_time;
	int				philo_num;
	long int		seconds;
}			t_data;

typedef struct s_philo{
	int				id_num;
	int				*is_dead;
	int				times_eat;
	long int		last_meal;
	int				has_fork;
	pthread_t		philo;
	t_data			*data;
}			t_philo;

int			ft_atoi(const char *str);
t_data		*data_call(void);
t_philo		*phi_call(void);
void		parse_philo(int ac, char **av);
void		start_philos(void);
int			philo_alive(t_philo *philos);
t_philo		*create_philos(t_data *data);
long int	get_time(void);
void		*philo_jobs(void *arg);
void		*print_message(void *arg);

#endif