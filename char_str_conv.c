#include "ft_printf.h"

// char	*percent_conv(void)
// {
// 	char c[1];

// 	c[0] = '%';
// 	return (c);
// }

char	*ft_multicat(char *dst, int c, size_t size)
{
	while (size--)
		ft_strncat(dst, (const char*)&c, 1);
	return (dst);
}

char	*short_char(char c)
{
	char *p;

	p = ft_strnew(1);
	p[0] = c;
	return (p);
}

char	*short_str(char *s, t_mods *mods)
{
	char *p;
	char *st;
	size_t i;

	i = (!mods->prec || ft_strlen(s) <= mods->prec) ? ft_strlen(s) : mods->prec;
	p = ft_strnew(i);
	ft_memcpy((void*)p, (void*)s, i);
	if (mods->width > i && (mods->flags & (1 << minus)))
		ft_multicat(p, ' ', mods->width - i);
	else if (mods->width > i)
	{
		st = ft_strnew(mods->width - i);
		ft_memset((void*)st, (mods->flags & (1 << zero)) ? '0' : ' ', mods->width - i);
		ft_strncat(st, p, i);
		free (p);
		return(st);
	}
	return (p);
}