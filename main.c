#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_printf.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	if (s1[i] != s2[i])
		return (-1);
	return (0);
}

void	ft_rescmp(char * s1, int len, int *numtest, int *success)
{
	int fd;
	int i;
	char s2[len + 1];

	freopen ("/dev/tty", "a", stdout); printf("\033[0m"); printf("%i>>", *numtest);
	fd = open("out.txt", O_RDONLY);
	i = 0;
	while (i <= (len))
	{
		s2[i] = 0;
		i++;
	}
	read(fd, s2, len);
	freopen ("/dev/tty", "a", stdout); printf("\033[0m"); printf("\ns1 =%s\ns2 =%s\n", s1, s2); //remove comments to see results
	if (!(ft_strcmp(s1, s2)))
	{
		*success += 1;
		freopen ("/dev/tty", "a", stdout); printf("\033[1;32m"); printf("OK\n");
	}
	else
	{
		freopen ("/dev/tty", "a", stdout); printf("\033[1;31m"); printf("KO\n");
	}
}

void	ft_test(char *str, void *conv, char c, int *numtest, int *success)
{
	FILE *out = freopen("./out.txt", "w", stdout);
	int len;
	char *s1;
	int lenft;

	if (c == 's')
		(char *)conv;
	if (c == 'c')
		(char)conv;
	if (c == 'p')
		(int *)conv;
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		(int)conv;
	if (c == 'u')
		(unsigned int)conv;
	if (c == '%')
		(char)conv;
	*numtest += 1;
	lenft = ft_printf(str, conv);
	len = snprintf(NULL, 0, str, conv);
	s1 = malloc(len + 1);
	snprintf(s1, len + 1, str, conv);
	ft_rescmp(s1, len, numtest, success);
	freopen ("/dev/tty", "a", stdout); printf("\033[0m"); printf("len f =%i\nlen t =%i\n", lenft, len); //remove comments to see length
	if (lenft != len)
	{
		freopen ("/dev/tty", "a", stdout); printf("\033[1;31m"); printf("return KO\n");
	}
	else
		*success += 1;
}

int main()
{
	int num = 0;
	int win = 0;
	int *numtest = &num;
	int *success = &win;
	char *str = "ca marche !"; char *str2 = ""; char *str3 = NULL;
	char c = 'z'; char c2 = 0;
	int i = 42;	int i2 = 0; int i3 = -42; int i4 = -2147483648; int i5 = 2147483647;
	int *p = &i; int *p2 = NULL;
	unsigned int u = 394; unsigned int u2 = 0; unsigned int u3 = -2147483650; unsigned int u4 = 2147483650;






	freopen ("/dev/tty", "a", stdout); printf("\033[0;97m"); printf("-----basic tests-----\n");
	ft_test("salut %s ca va ?", str, 's', numtest, success);
	ft_test("%s", str, 's', numtest, success);
	ft_test("%s", str2, 's', numtest, success);
	ft_test("%s", str3, 's', numtest, success);
	ft_test("%c", c, 'c', numtest, success);
	ft_test("%c", c2, 'c', numtest, success);
	ft_test("%p", p, 'p', numtest, success);
	ft_test("%p", p2, 'p', numtest, success);
	ft_test("%i", i, 'i', numtest, success);
	ft_test("%d", i2, 'i', numtest, success);
	ft_test("%i", i3, 'i', numtest, success);
	ft_test("%i", i4, 'i', numtest, success);
	ft_test("%i", i5, 'i', numtest, success);
	ft_test("%i", i, 'd', numtest, success);
	ft_test("%d", i2, 'd', numtest, success);
	ft_test("%i", i3, 'd', numtest, success);
	ft_test("%i", i4, 'd', numtest, success);
	ft_test("%i", i5, 'd', numtest, success);
	ft_test("%x", u, 'x', numtest, success);
	ft_test("%x", u2, 'x', numtest, success);
	ft_test("%x", u3, 'x', numtest, success);
	ft_test("%x", u4, 'x', numtest, success);
	ft_test("%X", u, 'X', numtest, success);
	ft_test("%X", u2, 'X', numtest, success);
	ft_test("%X", u3, 'X', numtest, success);
	ft_test("%X", u4, 'X', numtest, success);
	ft_test("%u", u, 'u', numtest, success);	
	ft_test("%u", u2, 'u', numtest, success);	
	ft_test("%u", u3, 'u', numtest, success);	
	ft_test("%u", u4, 'u', numtest, success);
	ft_test("%50%", c, '%', numtest, success); freopen ("/dev/tty", "a", stdout); printf("\033[0;97m"); printf("-----advanced tests-----\n");
	ft_test("%-9c", c, 'c', numtest, success);
	ft_test("%9c", c, 'c', numtest, success);
	ft_test("%9s", str, 's', numtest, success);
	ft_test("%9.3s", str, 's', numtest, success);
	ft_test("%3.9s", str, 's', numtest, success);
	ft_test("%2.3s", str, 's', numtest, success);
	ft_test("%-9s", str, 's', numtest, success);
	ft_test("%.9s", str, 's', numtest, success);
	ft_test("%9s", str2, 's', numtest, success);
	ft_test("%-9s", str2, 's', numtest, success);
	ft_test("%.9s", str2, 's', numtest, success);
	ft_test("%9s", str3, 's', numtest, success);
	ft_test("%-9s", str3, 's', numtest, success);
	ft_test("%.9s", str3, 's', numtest, success);
	ft_test("%-21p", p, 'p', numtest, success);
	ft_test("%21p", p, 'p', numtest, success);
	ft_test("%21p", p2, 'p', numtest, success);
	ft_test("%-21p", p2, 'p', numtest, success);
	ft_test("%30i", i4, 'i', numtest, success);
	ft_test("%6i", i4, 'i', numtest, success);
	ft_test("%030i", i4, 'i', numtest, success);
	ft_test("%06i", i4, 'i', numtest, success);
	ft_test("%-30i", i4, 'i', numtest, success);
	ft_test("%-6i", i4, 'i', numtest, success);
	ft_test("%30.6i", i4, 'i', numtest, success);
	ft_test("%30.20i", i4, 'i', numtest, success);
	ft_test("%30.40i", i4, 'i', numtest, success);
	ft_test("%-30.6i", i4, 'i', numtest, success);
	ft_test("%-30.20i", i4, 'i', numtest, success);
	ft_test("%-30.40i", i4, 'i', numtest, success);
	ft_test("%030.6i", i4, 'i', numtest, success);
	ft_test("%030.20i", i4, 'i', numtest, success);
	ft_test("%030.40i", i4, 'i', numtest, success);
	ft_test("%0-2.50u", i, 'i', numtest, success);
	ft_test("%0-2.50u", i2, 'i', numtest, success);
	ft_test("%0-2.0u", i2, 'i', numtest, success);
	ft_test("%.0u", i2, 'i', numtest, success);
	ft_test("%2.0u", i2, 'i', numtest, success);
	ft_test("%0-2.50u", i3, 'i', numtest, success);
	ft_test("%0-2.50u", i4, 'i', numtest, success);
	ft_test("%0-2.5u", i, 'i', numtest, success);
	ft_test("%0-2.5u", i2, 'i', numtest, success);
	ft_test("%0-2.5u", i3, 'i', numtest, success);
	ft_test("%0-2.5u", i4, 'i', numtest, success);
	ft_test("%0-50.2u", i, 'i', numtest, success);
	ft_test("%0-50.2u", i2, 'i', numtest, success);
	ft_test("%0-50.2u", i3, 'i', numtest, success);
	ft_test("%0-50.2u", i4, 'i', numtest, success);
	ft_test("%0-50.30u", i, 'i', numtest, success);
	ft_test("%0-50.30u", i2, 'i', numtest, success);
	ft_test("%0-50.30u", i3, 'i', numtest, success);
	ft_test("%0-50.30u", i4, 'i', numtest, success);
	ft_test("%50u", u, 'u', numtest, success);
	ft_test("%50u", u2, 'u', numtest, success);
	ft_test("%50u", u3, 'u', numtest, success);
	ft_test("%50u", u4, 'u', numtest, success);
	ft_test("%2u", u, 'u', numtest, success);
	ft_test("%2u", u2, 'u', numtest, success);
	ft_test("%2u", u3, 'u', numtest, success);
	ft_test("%2u", u4, 'u', numtest, success);
	ft_test("%-50u", u, 'u', numtest, success);
	ft_test("%-50u", u2, 'u', numtest, success);
	ft_test("%-50u", u3, 'u', numtest, success);
	ft_test("%-50u", u4, 'u', numtest, success);
	ft_test("%-2u", u, 'u', numtest, success);
	ft_test("%-2u", u2, 'u', numtest, success);
	ft_test("%-2u", u3, 'u', numtest, success);
	ft_test("%-2u", u4, 'u', numtest, success);
	ft_test("%050u", u, 'u', numtest, success);
	ft_test("%050u", u2, 'u', numtest, success);
	ft_test("%050u", u3, 'u', numtest, success);
	ft_test("%050u", u4, 'u', numtest, success);
	ft_test("%02u", u, 'u', numtest, success);
	ft_test("%02u", u2, 'u', numtest, success);
	ft_test("%02u", u3, 'u', numtest, success);
	ft_test("%02u", u4, 'u', numtest, success);
	ft_test("%.50u", u, 'u', numtest, success);
	ft_test("%.50u", u2, 'u', numtest, success);
	ft_test("%.50u", u3, 'u', numtest, success);
	ft_test("%.50u", u4, 'u', numtest, success);
	ft_test("%.2u", u, 'u', numtest, success);
	ft_test("%.2u", u2, 'u', numtest, success);
	ft_test("%.2u", u3, 'u', numtest, success);
	ft_test("%.2u", u4, 'u', numtest, success);
	ft_test("%50.2u", u, 'u', numtest, success);
	ft_test("%50.2u", u2, 'u', numtest, success);
	ft_test("%50.2u", u3, 'u', numtest, success);
	ft_test("%50.2u", u4, 'u', numtest, success);
	ft_test("%2.50u", u, 'u', numtest, success);
	ft_test("%2.50u", u2, 'u', numtest, success);
	ft_test("%2.50u", u3, 'u', numtest, success);
	ft_test("%2.50u", u4, 'u', numtest, success);
	ft_test("%050.2u", u, 'u', numtest, success);
	ft_test("%050.2u", u2, 'u', numtest, success);
	ft_test("%050.2u", u3, 'u', numtest, success);
	ft_test("%050.2u", u4, 'u', numtest, success);
	ft_test("%02.50u", u, 'u', numtest, success);
	ft_test("%02.50u", u2, 'u', numtest, success);
	ft_test("%02.50u", u3, 'u', numtest, success);
	ft_test("%02.50u", u4, 'u', numtest, success);
	ft_test("%0-2.50u", u, 'u', numtest, success);
	ft_test("%0-2.50u", u2, 'u', numtest, success);
	ft_test("%0-2.50u", u3, 'u', numtest, success);
	ft_test("%0-2.50u", u4, 'u', numtest, success);
	ft_test("%0-2.5u", u, 'u', numtest, success);
	ft_test("%0-2.5u", u2, 'u', numtest, success);
	ft_test("%0-2.5u", u3, 'u', numtest, success);
	ft_test("%0-2.5u", u4, 'u', numtest, success);
	ft_test("%0-50.2u", u, 'u', numtest, success);
	ft_test("%0-50.2u", u2, 'u', numtest, success);
	ft_test("%0-50.2u", u3, 'u', numtest, success);
	ft_test("%0-50.2u", u4, 'u', numtest, success);
	ft_test("%0-50.30u", u, 'u', numtest, success);
	ft_test("%0-50.30u", u2, 'u', numtest, success);
	ft_test("%0-50.30u", u3, 'u', numtest, success);
	ft_test("%0-50.30u", u4, 'u', numtest, success);
	ft_test("%50%", c, '%', numtest, success);
	ft_test("%2%", c, '%', numtest, success);
	ft_test("%-50%", c, '%', numtest, success);
	ft_test("%-2%", c, '%', numtest, success);
	ft_test("%050%", c, '%', numtest, success);
	ft_test("%02%", c, '%', numtest, success);
	ft_test("%.50%", c, '%', numtest, success);
	ft_test("%.2%", c, '%', numtest, success);
	ft_test("%50.2%", c, '%', numtest, success);
	ft_test("%2.50%", c, '%', numtest, success);
	ft_test("%050.2%", c, '%', numtest, success);
	ft_test("%02.50%", c, '%', numtest, success);
	ft_test("%0-2.50%", c, '%', numtest, success);
	ft_test("%0-2.5%", c, '%', numtest, success);
	ft_test("%0-50.2%", c, '%', numtest, success);
	ft_test("%0-50.30%", c, '%', numtest, success);

	if (*success != (*numtest * 2))
	{
		printf("\033[1;31m"); printf("%i/%i\n", *success, (*numtest * 2));
	}
	else
	{
		printf("\033[1;33m"); printf("%i/%i\n", *success, (*numtest * 2));
		printf("   . .       . .   \n");
		printf(".+'|=|`+. .+'|=|`+. \n");
		printf("|  | `+.| |  | `+.| \n");
		printf("|  | .    |  | . \n");
		printf("|  | |`+. |  | |`+. \n");
		printf("|  | `. | |  | `. | \n");
		printf("|  | .+ | |  | .+ | \n");
		printf("`+.|=|.+' `+.|=|.+' \n\n");
	}
	return (0);
}

