/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:17:48 by gabriel           #+#    #+#             */
/*   Updated: 2023/01/06 11:45:33 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_message(t_philo *philos, char *str)
{
	printf("%ldms %i %s\n", get_time() - \
		philos->data->start, philos->id_num, str);
	return ;
}
