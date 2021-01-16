/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:18:06 by dasanter          #+#    #+#             */
/*   Updated: 2021/01/16 14:41:19 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void xchar_buf(oneforall *lst, int nb)
{
	if (lst->buf_i + nb < BUFFER_SIZE)
		return;
	buf_print(lst->buf, lst);
	new_buf(lst);
	lst->buf_i = 0;
}

void hex_convert(unsigned long long int nb, int base, oneforall *lst)
{
	int i;
	unsigned long long tmp;
	char *table;

	tmp = nb;
	i = 0;
	if ((!lst->preci || lst->non_preci == 1) && nb == 0)
	{
		if (lst->taille > 0)
			ft_putbuf(lst, ' ');
		return;
	}
	if (base <= 16)
		table = "0123456789abcdef";
	else
	{
		table = "0123456789ABCDEF";
		base -= 10;
	}
	if (nb == 0)
		lst->buf[lst->buf_i++] = '0';
	while (tmp > 0)
	{
		i++;
		tmp /= base;
	}
//	if (i == 0)
//		lst->buf[lst->buf_i++] = '0';
	xchar_buf(lst, i);
	while (nb > 0)
	{
		lst->buf[lst->buf_i + i - 1] = table[nb % base];
		i--;
		nb /= base;
	}
	while (lst->buf[lst->buf_i])
		lst->buf_i++;
}

int put_unsigned(oneforall *lst, va_list ap)
{
	(void)lst;
	(void)ap;
	while (1)
		printf("dwqdqw\n");
	return (1);
}
char *uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int puthexmaj(oneforall *lst, va_list ap)
{
	 long long int nb;

	nb = va_arg(ap, long long int);
	hex_convert(nb, 26, lst);
	return (1);
}

int puthexmin(oneforall *lst, va_list ap)
{
	 long long int nb;

	nb = va_arg(ap, long long int);
	hex_convert(nb, 16, lst);
	return (1);
}

int getnbchar(int nb)
{
	int i;

	if (nb == -2147483648)
		return (10);
	i = 0;
	if (nb == 0 )
		return (1);
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int putint(oneforall *lst, va_list ap)
{
	int nb;
	int nbchar;
	int minus;
	int preci;
	int largeur;
	unsigned long long int u;

	nb =  va_arg(ap, int);
	if (nb < 0)
	{
		u = -1 * nb;
		minus = 1;
	}
	else
	{
		minus = 0;
		u = nb;
	}
	nbchar = getnbchar((int)u);
	preci = calc_preci(lst->preci, nbchar, minus);
	largeur = calc_width(lst->taille, lst->preci, nbchar, minus);
/*	printf("%d\n", nbchar);
	printf("%d\n", largeur);
*/
	if (lst->moins)
	{
		if (lst->plus && !minus)
		{
			ft_putbuf(lst, '+');
			if (largeur > 0)
				largeur--;
		}
		else if (minus)
			ft_putbuf(lst, '-');
		while (preci--)
			ft_putbuf(lst, '0');
		if (nb == -2147483648)
			hex_convert(2147483648, 10, lst);
		else
			hex_convert(u, 10, lst);
		while (largeur--)
			ft_putbuf(lst, ' ');
	}
	else 
	{
		if (lst->plus && !minus)
			if (largeur > 0)
				largeur--;
		while(largeur && lst->zero == ' ')
		{
			ft_putbuf(lst, lst->zero);
			largeur--;
		}
		if (lst->plus && !minus)
			ft_putbuf(lst, '+');
		else if (minus)
			ft_putbuf(lst, '-');
		while(largeur--)
			ft_putbuf(lst, lst->zero);
		while (preci--)
			ft_putbuf(lst, '0');
		if (nb == -2147483648)
			hex_convert(2147483648, 10, lst);
		else
			hex_convert(u, 10, lst);

	}
	return (1);
}
