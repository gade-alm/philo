/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:17:48 by gabriel           #+#    #+#             */
/*   Updated: 2022/12/16 18:19:37 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*print_message(void *arg)
{
	t_philos *philos;

	philos = (t_philos *)arg;
	printf("teste, %i\n", philos->data.philo_num);
	return (0);
}
