/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:07:06 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/25 16:30:54 by gabriel          ###   ########.fr       */
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
	pthread_t		philo;
	t_data			*data;
}			t_philo;

int			ft_atoi(const char *str);
t_data		*phicall(void);
t_data		*parse_philo(int ac, char **av);
t_philo		*create_philos(t_data *phi);
void		start_philos(void);
long int	calc_time(long int start, long int end);
long int	gettime(void);
void		*print_message(void *arg);

#endif