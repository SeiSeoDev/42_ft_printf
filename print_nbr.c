/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:48:57 by dasanter          #+#    #+#             */
/*   Updated: 2021/01/06 12:05:32 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nbr(oneforall *lst, va_list ap)
{
	int nb = va_arg(ap, int);
	int i;

	(void)lst;
	(void)nb;
	i = 0;
	
	return (0);
}

