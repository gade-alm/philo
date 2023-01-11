/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:53:09 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/11 18:33:33 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_data	*data_call(void)
{
	static t_data	data;

	return (&data);
}

t_dead	*dead_call(void)
{
	static t_dead	death;

	return (&death);
}
