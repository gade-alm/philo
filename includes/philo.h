/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:07:06 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/28 15:05:10 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_dead	t_dead;
typedef struct s_forks	t_forks;
typedef struct s_philo	t_philo;

struct s_data{
	int				die_time;
	int				sleep_time;
	int				think_time;
	int				must_eat_num;
	int				eat_time;
	int				philo_num;
	long int		start;
	t_data			*data;
	t_dead			*death;
	t_forks			*forks;
	t_philo			*philos;
};

struct s_dead
{
	int				is_dead;
	pthread_mutex_t	killer;
};

struct s_forks
{
	int				has_fork;
	pthread_mutex_t	forks;
};

struct s_philo{
	int				id_num;
	int				times_eat;
	long int		last_meal;
	long int		sleeping;
	int				many_forks;
	int				has_eaten;
	int				left_fork;
	int				right_fork;
	pthread_t		philo;
	t_data			*data;
	t_dead			*death;
	t_forks			*forks;
};

int			ft_atoi(const char *str);
t_data		*data_call(void);
t_dead		*dead_call(void);
t_forks		*forks(void);
void		parse_philo(int ac, char **av);
void		start_philos(void);
long int	get_time(void);
t_forks		*forks_init(t_data *data);
t_philo		*create_philos(t_data *data);
void		*philo_jobs(void *arg);
int			philo_alive(t_philo *philos);
int			check_corpse(void);
void		print_message(t_philo *philos, char *str);
int			check_forks(t_philo *philos);
int			available_forks(t_philo *phi, int index);
void		put_forks(t_philo *phi, int index);
int			philo_eat(t_philo *philos);
int			philo_nap(t_philo *philos);

#endif