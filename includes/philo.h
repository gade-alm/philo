/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:07:06 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/11 18:43:56 by gade-alm         ###   ########.fr       */
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
	long int		start;
	int				m;
}			t_data;

typedef struct s_dead
{
	int				is_dead;
	pthread_mutex_t	killer;
}			t_dead;

typedef struct s_forks
{
	int				has_fork;
	pthread_mutex_t	forks;
}		t_forks;

typedef struct s_philo{
	int				id_num;
	int				times_eat;
	long int		last_meal;
	long int		sleeping;
	pthread_t		philo;
	t_data			*data;
	t_dead			*death;
	t_forks			*forks;
}			t_philo;

typedef struct s_clean
{
	t_philo	*philos;
}	t_clean;

int			ft_atoi(const char *str);
t_data		*data_call(void);
t_dead		*dead_call(void);
void		parse_philo(int ac, char **av);
void		start_philos(void);
t_philo		*create_philos(t_data *data);
void		print_message(t_philo *philos, char *str);
int			philo_alive(t_philo *philos);
long int	get_time(void);
void		*philo_jobs(void *arg);
void		philo_eat(t_philo *philos);
void		philo_nap(t_philo *philos);
int			check_corpse(void);
t_forks		*forks_init(t_data *data);
int			check_forks(t_philo *philos);

#endif