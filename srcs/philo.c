/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:18:45 by gade-alm          #+#    #+#             */
/*   Updated: 2022/12/09 16:00:38 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
// Your(s) program(s) should take the following arguments:
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
void *teste(void *abc)
{
	(void)abc;
	printf("teste %d\n", getpid());
	return (NULL);
}

int main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("Error\n"));
	pthread_t thread[3];
	
	int i = -1;
	while (++i < 3)
		pthread_create(&thread[i], NULL, teste, NULL);
	while (--i >= 0)
		pthread_join(thread[i], NULL);
}
