/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:07:06 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/26 11:11:44 by gade-alm         ###   ########.fr       */
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
	int				is_dead;
	pthread_t		*philo;
	t_data			*data;
}			t_philo;

int			ft_atoi(const char *str);
t_data		*datacall(void);
t_philo		*phicall(void);
void		parse_philo(int ac, char **av);
void		start_philos(void);
t_philo		*create_philos(int num);
long int	calc_time(long int start, long int end);
long int	gettime(void);
void		*print_message(void *arg);

#endif