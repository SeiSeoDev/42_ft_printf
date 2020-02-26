/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:06:52 by dasanter          #+#    #+#             */
/*   Updated: 2020/02/26 15:21:05 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int pourc (oneforall *lst, va_list ap, int (*p[])(oneforall *lst, va_list ap))
{
	while (lst->form[lst->pos])
	{
		lst->pos++;
		if (p[(int)(lst->form[lst->pos])](lst, ap))
		{
			resetlst(lst);
			return (1);
		}
	}
	return (0);
}

void initlst(oneforall *lst, char *form)
{
	lst->pos = 0;
	lst->form = form;
	lst->diese = 0;
	lst->zero = ' ';
	lst->moins = 0;
	lst->space = 0;
	lst->taille = 0;
	lst->preci = -1;
	lst->ret_value = 0;
}

void resetlst(oneforall *lst)
{
	lst->diese = 0;
	lst->zero = ' ';
	lst->moins = 0;
	lst->space = 0;
	lst->taille = 0;
	lst->preci = -1;
}

void new_buf(oneforall *lst)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
		lst->buf[i++] = 0;
}
int skip(oneforall *lst, va_list ap)
{
	if (lst->form[lst->pos] == ' ')
		lst->space = 1;
	(void)ap;
	return (0);
}
int	ft_printf(char *form, ...)
{
	int (*p[128]) (oneforall *lst, va_list ap);
	va_list ap;
	oneforall *lst;

	if (!(lst = malloc(sizeof(oneforall))))
		return (0);
	initlst(lst, form);
	while (lst->pos < 127)
		p[lst->pos++] = skip;
	p['s'] = putstr;
	p['d'] = putint;
	p['i'] = putint;
	p['c'] = char_buf;
	p['p'] = print_po;
	p['0'] = zero;
	p['1'] = width;
	p['2'] = width;
	p['3'] = width;
	p['4'] = width;
	p['5'] = width;
	p['6'] = width;
	p['7'] = width;
	p['8'] = width;
	p['9'] = width;
	p['.'] = preci;
	p['*'] = heytoile;
	p['-'] = moins;
	p['%'] = pourcent;
	p['+'] = plus;
	p['x'] = puthexmin;
	p['X'] = puthexmaj;
	va_start(ap, form);
	lst->pos = 0;
	new_buf(lst);
	while (form[lst->pos])
	{
		if (form[lst->pos] == '%')
			pourc(lst, ap, p);
		else
			ft_putchar(lst, form[lst->pos]);
		lst->pos++;
	}
	buf_print(lst->buf, lst);
	va_end(ap);
	return (lst->ret_value);
}
/*
int main()
{
//	ft_printf("|%X|\n", -42);
//
	printf("le vrai %d\n", -13 + printf("le vrai : |%10d|\n", -42));
	printf("le mien %d\n", -13 + ft_printf("le mien : |%10d|\n", -42));
	ft_printf("{%10d}\n", 42);
	printf("{%10d}\n", 42);
	//  ft_printf("%X\n", 4294967296);
//  printf("%X\n", 4294967296);
//	printf("|%X|\n", -42);
//	printf("%d\n", sizeof(intmax_t));
//	printf("%d\n", sizeof(unsigned long long int));
//	printf("%d\n", sizeof(void*));
//	printf("%d\n", sizeof(void));
//	ft_printf("%s %s\n", "this", "is");
//	printf("%s %s\n", "this", "is");
//	ft_printf("%-10s is a string\n", "this");
//	printf("%-10s is a string\n", "this");
//	ft_printf("%5.2s is a string\n", "");
//	printf("%5.2s is a string\n", "");
//	ft_printf("le mien |%-.2s is a string|\n", "this");
//	printf("le vrai |%-.2s is a string|\n", "this");
}*/
