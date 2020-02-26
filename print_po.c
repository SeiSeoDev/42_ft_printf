/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_po.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:42:26 by dasanter          #+#    #+#             */
/*   Updated: 2020/01/28 15:34:17 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_po(oneforall *lst, va_list ap)
{
	void *ad;

	ad = va_arg(ap, void *);
	ft_putchar(lst, '0');
	ft_putchar(lst, 'x');
	hex_convert((unsigned long long)ad, 16, lst);
	return (1);
}
