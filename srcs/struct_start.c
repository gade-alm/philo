/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:53:09 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/08 18:38:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo	*phi_call(void)
{
	static t_philo	philo;

	return (&philo);
}

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

t_forks	*forks_call(void)
{
	static t_forks	forks;

	return (&forks);
}
