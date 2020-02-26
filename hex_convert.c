/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:18:06 by dasanter          #+#    #+#             */
/*   Updated: 2020/02/26 15:17:27 by dasanter         ###   ########.fr       */
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

	if (base <= 16)
		table = "0123456789abcdef";
	else
	{
		table = "0123456789ABCDEF";
		base -= 10;
	}
	while (tmp > 0)
	{
		i++;
		tmp /= base;
	}
	if (i == 0)
		lst->buf[lst->buf_i++] = '0';
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

int putunsi(oneforall *lst, va_list ap)
{
	long long unsigned int nb;

	nb = va_arg(ap, long long unsigned int);
	hex_convert(nb, 10, lst);
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

int putint(oneforall *lst, va_list ap)
{
	long long int nb;
	int i;
	int tmp;
	int minus;

	minus = 0;
	nb = va_arg(ap, long long int);
	i = 0;
	tmp = nb;
	if (nb == 0)
		i++;
	if ((int)nb < 0)
	{
		if (nb < 2147483648)
			nb *= -1;
		else
			nb = (int)nb * -1;
		i++;
		minus = 1;
		tmp = nb;
	}
	if (lst->zero == '0' && minus)
	{
		minus--;
		ft_putchar(lst, '-');
	}
	if (lst->space && !minus && !lst->plus)
	{
		i++;
		ft_putchar(lst, ' ');
	}
	if (lst->moins)
	{
		if (minus)
			ft_putchar(lst, '-');
		hex_convert(nb, 10, lst);
	}
	if (lst->plus == 1 && !minus)
		ft_putchar(lst, '+');
	while (tmp > 0)
	{
		i++;
		tmp /= 10;
		//printf("i : %d\n", i);
	}
//	printf("i : %d\n", i);
	if (i > lst->preci)
		lst->preci = i;
	//printf("taille : %d\n", lst->taille);
	while (lst->taille > lst->preci)
	{
		lst->buf[lst->buf_i++] = lst->zero;
		lst->taille--;
	}
	//printf("preci : %d\n", lst->preci);
	while(i + minus < lst->preci)
	{
		lst->buf[lst->buf_i++] = '0';
		i++;
	}
//	printf("nombre convert : %d\n", nb);
	if (!lst->moins)
	{
		if (minus)
			ft_putchar(lst, '-');
		hex_convert(nb, 10, lst);
	}
	return (1);
}
