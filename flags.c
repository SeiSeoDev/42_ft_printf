/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:30:01 by dasanter          #+#    #+#             */
/*   Updated: 2021/01/07 18:09:07 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int moins(oneforall *lst, va_list ap)
{
	(void)ap;

	if (lst->pos - 1 == '%')
		return 1;
	lst->moins = 1;
	return (0);
}

int plus(oneforall *lst, va_list ap)
{
	(void)ap;
	lst->plus = 1;
	lst->space = 0;
	return (0);
}

int space(oneforall *lst, va_list ap)
{
	(void)ap;
	if (!lst->plus)
		lst->space = 1;
	return (0);
}

int diese(oneforall *lst, va_list ap)
{
	(void)ap;
	lst->diese = 1;
	return (0);
}

int pourcent(oneforall *lst, va_list ap)
{
	int check;
	int i;
	(void)ap;

	check = lst->pos - 1;
	/*while(check > 0 && lst->form[check] != '%')
	{
		if (lst->form[check] == '0' && (lst->form[check - 1] < '0' || lst->form[check - 1] > '9'))
				lst->zero = '0';
		check--;
	}*/
	i = 1;
	if (lst->moins)
		ft_putbuf(lst, '%');
	
	while (i < lst->taille)
	{
		ft_putbuf(lst, lst->zero);
		i++;
	}
	if (!lst->moins)
		ft_putbuf(lst, '%');
	return (1);
}
