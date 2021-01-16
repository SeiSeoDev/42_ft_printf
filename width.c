/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:46:59 by dasanter          #+#    #+#             */
/*   Updated: 2021/01/16 10:32:20 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int puiss(int pui)
{
	int result;
	int i;

	i = 0;
	result = 1;
	while (i < pui)
	{
		result *= 10;
		i++;
	}
	return (result);
}

int width(oneforall *lst, va_list ap)
{
	int i;
	int nb;

	(void)ap;
	nb = 0;
	i = 0;
	while (lst->form[lst->pos + i] >= '0'&& lst->form[lst->pos + i] <= '9')
	{
		nb = (lst->form[lst->pos + i] - 48) +  nb * puiss(i);
		i++;
	}
	lst->pos += i - 1;
	lst->taille = nb;
	return (0);
}

int zero(oneforall *lst, va_list ap)
{
	(void)ap;
	if (!lst->moins)
		lst->zero = '0';
	else
		lst->zero = ' ';
	return (0);
}

int preci(oneforall *lst, va_list ap)
{
	int i;
	int nb;

	(void)ap;
	nb = 0;
	i = 0;
	lst->pos++;
	if (lst->form[lst->pos] < '0' || lst->form[lst->pos] > '9')
		lst->non_preci = 1;
	while (lst->form[lst->pos + i] >= '0' && lst->form[lst->pos + i] <= '9')
	{
		nb = (lst->form[lst->pos + i] - 48)  + nb * puiss(i);
		i++;
	}
	if (nb > 0)
		lst->zero = ' ';
	lst->pos += i - 1;
	lst->preci = nb;
	return (0);
}

int heytoile(oneforall *lst, va_list ap)
{
	int nb;

	(void)ap;
	nb = va_arg(ap, int);
	if (lst->form[lst->pos - 1] == '.')
		lst->preci = nb;
	else
	{
		if (nb < 0)
		{
			lst->moins = 1;
			nb *= -1;
		}
		lst->taille = nb;
	}
	return (0);
}
