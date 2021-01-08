/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seiseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:14:15 by seiseo            #+#    #+#             */
/*   Updated: 2021/01/08 15:10:56 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int calc_width(int width, int preci, int nbchar, int minus)
{
	int retour;

	retour = 0;
	if (minus)
	{
		while (width >= preci + minus && width > nbchar)
		{
			retour++;
			width--;
		}
	}
	else
	{
		while (width > preci + minus && width > nbchar)
		{
			retour++;
			width--;
		}
	}

	if (minus && retour > 0)
	   retour--;
	return (retour);
}

int calc_preci(int preci, int nbchar, int minus)
{
	int retour;
	(void)minus;
	retour = 0;
	while (preci > nbchar)
	{
		retour++;
		preci--;
	}

	return (retour);
}

void spac_int(int nbchar, oneforall *lst, int minus)
{
	int size;
	int width;
	int preci;
	
	if (minus)
		nbchar++;

	//if (nbchar >= lst->taille && nbchar >= lst->preci)
	//	return;
	size = nbchar;
	width = calc_width(lst->taille, lst->preci, nbchar, minus);
	preci = calc_preci(lst->preci, nbchar, minus);
//printf("width : %d\npreci : %d\n nbchar : %d\n", width, preci, nbchar);	
	while (width )
	{
		lst->buf[lst->buf_i++] = lst->zero;
		width--;
	}
	if (minus)
		lst->buf[lst->buf_i++] = '-';
	while (preci)
	{
		lst->buf[lst->buf_i++] = '0';
		preci--;
	}
}
