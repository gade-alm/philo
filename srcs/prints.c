/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:17:48 by gabriel           #+#    #+#             */
/*   Updated: 2022/12/29 18:12:00 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*print_message(void *arg)
{
	(void)arg;
	printf("teste philo: %i\n", data_call()->philo_num);
	return (0);
}
