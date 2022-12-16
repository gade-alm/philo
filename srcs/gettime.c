/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:24:08 by gabriel           #+#    #+#             */
/*   Updated: 2022/12/16 17:54:47 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Get the time in miliseconds (the start time according to the EPOCH)

long int	gettime(void)
{
	struct timeval	time;
	t_data			data;

	gettimeofday(&time, NULL);
	data.seconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (data.seconds);
}
