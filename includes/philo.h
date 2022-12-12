/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:07:06 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/12 18:43:41 by gabriel          ###   ########.fr       */
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
	int			must_eat_num;
	int			eat_time;
	int			philo_num;
}			t_data;

typedef struct s_philos{
	int			p_num;
	int			fork;
	pthread_t	philo;
	t_data		data;
}		t_philos;

int			ft_atoi(const char *str);
void		create_philo(int num);
void		*teste(void *abc);
t_philos	start_philos(int ac, char **av);
void		print_message(t_philos philos, char *str);

#endif