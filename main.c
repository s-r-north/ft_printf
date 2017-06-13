#include "ft_printf.h"

int		main()
{
	char c = 51;
	char *s = "hello world";

	prelim_printf("12345\n");
	prelim_printf("%-12s\n", s);
	prelim_printf("%08.4s\n", s);
	prelim_printf("%s\t12345\n", s);
	prelim_printf("%2c\t%%\n", c);
	prelim_printf("%123abc\n");
}