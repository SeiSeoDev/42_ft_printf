/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:06:52 by dasanter          #+#    #+#             */
/*   Updated: 2021/01/16 15:33:00 by dasanter         ###   ########.fr       */
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
	lst->buf_i = 0;
	lst->pos = 0;
	lst->form = form;
	lst->diese = 0;
	lst->zero = ' ';
	lst->moins = 0;
	lst->space = 0;
	lst->taille = 0;
	lst->preci = -1;
	lst->plus = 0;
	lst->non_preci = 0;
	lst->ret_value = 0;
	lst->nul[0] = '(';
	lst->nul[1] = 'n';
	lst->nul[2] = 'u';
	lst->nul[3] = 'l';
	lst->nul[4] = 'l';
	lst->nul[5] = ')';
	lst->nul[6] = 0;
}

void resetlst(oneforall *lst)
{
	lst->diese = 0;
	lst->zero = ' ';
	lst->moins = 0;
	lst->non_preci = 0;
	lst->space = 0;
	lst->taille = 0;
	lst->plus = 0;
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

int checkform(char *form)
{
	int pos;
	char x;
	
	pos = 0;
	while (form[pos])
	{
		if (form[pos] == '%')
		{
			pos++;
			x = form[pos];
			while (x != 'd' && x != 'i' && x != 's'&& x != 'c' && x != 'p' && x != '%' && x != 'x' && x != 'X' && x)
				x = form[pos++];
			if (x == 0)
				return (0);
		}
		pos++;
	}
	
	return (1);
	}

int	ft_printf(char *form, ...)
{
	int (*p[128]) (oneforall *lst, va_list ap);
	va_list ap;

	if (checkform(form) == 0)
		return (0);
	oneforall *lst;

	if (!(lst = malloc(sizeof(oneforall))))
		return (0);
	initlst(lst, form);
	while (lst->pos < 127)
		p[lst->pos++] = skip;
	p['s'] = putstr;
	p['u'] = put_unsigned;
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
			ft_putbuf(lst, form[lst->pos]);
		lst->pos++;
	}
	buf_print(lst->buf, lst);
	va_end(ap);
	return (lst->ret_value);
}

int main()
{
//	ft_printf("|%X|\n", -42);
//
//	printf("le vrai %d\n", -13 + printf("le vrai : |%10d|\n", -42));
//	printf("le mien %d\n", -13 + ft_printf("le mien : |%10d|\n", -42));
//	ft_printf("|%-8.5d|\n", -10);
	printf("mon printf %d\n", ft_printf("|%-9c|\n", 'z'));
	printf("real printf %d\n", printf("|%-9c|\n", 'z'));
//	printf("|%-8.5d|\n", -10);
//	printf("|%7.5d|\n", -14);
//	printf("|%7d|\n", -14);
	//printf("%d\n", printf("%-9c\n", 's'));
//printf("valeur de retour : %d\n", ft_printf("%%"));
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
}
