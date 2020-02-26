/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:50:26 by dasanter          #+#    #+#             */
/*   Updated: 2020/02/17 15:26:13 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int char_buf(oneforall *lst, va_list ap)
{
	char c;
	int i;

	i = 0;
	c = va_arg(ap, int);
	if (lst->moins)
		ft_putchar(lst, c);
	while (i++ < lst->taille - 1)
		ft_putchar(lst, lst->zero);
	if (!lst->moins)
		ft_putchar(lst, c);
	return 1;
}

int	putstr(oneforall *lst, va_list ap)
{
	char *str;
	int i;
	int size;

	i = -1;
	size = 0;
	str = va_arg(ap, char *);
	while(str[size])
		size++;
	if (lst->preci > size)
		lst->preci = size;
	if (lst->preci == -1)
		lst->preci = size;
//	printf("taille : %d\n", lst->taille);
	//printf("preci  : %d\n", lst->preci);
	if (lst->moins)
		while(str[++i] && i < lst->preci)
			ft_putchar(lst, str[i]);
	while (lst->taille-- > lst->preci)
	{
	//printf("%d\n", lst->taille);
//	printf("taille : %d\n", lst->taille);
//	printf("preci  : %d\n", lst->preci);
		ft_putchar(lst, ' ');
	//	printf("dwqdqw\n");
	}
	if (!lst->moins)
		while(str[++i] && lst->preci--)
			ft_putchar(lst, str[i]);
	return 1;
}

void buf_print(char *buf, oneforall *lst)
{
	int i;

	i = 0;
	write(1, buf, lst->buf_i);
	lst->ret_value += lst->buf_i;
	lst->buf_i = 0;
	while (i < BUFFER_SIZE)
		lst->buf[i++] = 0;
}

void ft_putchar(oneforall *lst, char c)
{
	if (lst->buf_i >= BUFFER_SIZE - 1)
	{
		buf_print(lst->buf, lst);
		new_buf(lst);
		lst->buf_i = 0;
	}
	lst->buf[lst->buf_i] = c;
	lst->buf_i++;
}
