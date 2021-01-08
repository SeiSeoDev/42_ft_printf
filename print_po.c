/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_po.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:42:26 by dasanter          #+#    #+#             */
/*   Updated: 2021/01/06 12:07:05 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_po(oneforall *lst, va_list ap)
{
	void *ad;

	ad = va_arg(ap, void *);
	ft_putbuf(lst, '0');
	ft_putbuf(lst, 'x');
	hex_convert((unsigned long long)ad, 16, lst);
	return (1);
}
