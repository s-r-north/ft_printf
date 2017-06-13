#include "ft_printf.h"

size_t	find_base(char c)
{
	if (ft_strchr("dDiuUeEfFgG", c))
		return (10);
	if (ft_strchr("pxXaA", c))
		return (16);
	if (c == 'o' || c == 'O')
		return (8);
	if (c == 'b')
		return (2);
	return (0);
}

char	*length_to_size(va_list ap, char len, size_t base)
{
	if (!len)
		return (ft_ulltoa_base(va_arg(ap, unsigned int), base));
	if (len & 1 << Z)
		return (ft_ulltoa_base(va_arg(ap, size_t), base));
	if (len & 1 << J)
		return (ft_ulltoa_base(va_arg(ap, uintmax_t), base));
	if (len & 1 << LL)
		return (ft_ulltoa_base(va_arg(ap, unsigned long long), base));
	if (len & 1 << L)
		return (ft_ulltoa_base(va_arg(ap, unsigned long), base));
	if (len & 1 << H)
		return (ft_ulltoa_base((unsigned short)va_arg(ap, int), base));
	if (len & 1 << HH)
		return (ft_ulltoa_base((unsigned char)va_arg(ap, int), base));
	return (NULL);
}

size_t	prec_width(size_t base, t_mods *mods, size_t len)
{
	size_t wid;
	size_t prec;

	wid = mods->width;
	prec = mods->prec;
	if ((len >= wid && len >= prec) || ((mods->flags & (1 << minus)) && !(mods->flags & 1 << precis)))
		return (0);
	if (base == 16 && mods->flags & (1 << hash) && wid <= prec + 2)
		return (2 + (len < prec ? prec - len : 0));
	if (base == 8 && mods->flags & (1 << hash) && prec < len + 1)
		prec = len + 1;
	if (base == 2 && len % 8)
		prec = len + 8 - (len % 8);
	mods->flags |= ((prec > 0) << precis);
	if ((mods->flags & (1 << minus)))
		return (prec > len ? prec - len : 0)
	return ((wid > prec ? wid : prec) - len);
}

char	*int_width_flags(size_t base, t_mods *mods, size_t len)
{
	char *ret;
	size_t size;

	if (!(size = prec_width(base, mods, len)));
		return (NULL);
	ret = ft_strnew(size);
	if (!(mods->flags & (1 << precis)))
		;
	if ((!(mods->flags & (1 << precis)) && (mods->flags & (1 << zero))) || prec <= (width - ((base == 16 && (mods->flags &(1 << hash))) ? 2 : 0)))
		f
	return (NULL);
	//ft_memset((void*)ret, ((mods->flags & 1 << zero) || !()) ? '0' : ' ', size);

	// if (mods->flags & 1 << hash && !(base / 8))
	// {
	// 	if ((mods->flags & 1 << zero) && base == 16)
	// 		ret[1] = mods->conv;
	// 	else
	// 	{
	// 		ret[size - 2] = base == 16 ? '0' : ret[size - 2];
	// 		ret[size - 1] = base == 16 ? mods->conv : '0';
	// 	}
	// }
	// return (ret);
}

char	*ft_multicat(char *dst, int c, size_t size)
{
	while (size--)
		ft_strncat(dst, &c, 1);
	return (dst);
}

void	ft_strupper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

char	*ft_unsigned_ints(va_list ap, t_mods *mods)
{
	char *st;
	char *end;
	size_t base;
	size_t size;

	if (ft_strchr("DUOp", mods->conv))
		mods->length |= (1 << (mods->conv == p ? Z : L));
	if (mods->conv == 'p')
		mods->flags |= (1 << hash);
	base = find_base(mods->conv);
	end = length_to_size(ap, mods->length, base);
	st = int_width_flags(base, mods, len);
	if (mods->conv == 'X')
		ft_strupper(end);
	if (!st || (mods->flags & (1 << minus)))
		return (ft_multicat(end, ' ', wid > len ? wid - len : 0));
	ft_strncat(st, end, ft_strlen(end));
	return (st);
	// if (ft_strchr("oOxX", mods->conv))
	// {
	// 	st = hex_oct_flags(base, mods, ft_strlen(end));
	// 	if (mods->conv == 'X')
	// 		ft_strupper(end);
	// 	out.content = (void*)ft_strcat(st, end);
	// 	return (ft_strlen((char*)out.content));
	// }
	// if ((mods->flags & 1 << minus) || (wid <= ft_strlen(end)))
	// {
	// 	out.content = (void*)end;
	// 	return (ft_strlen(end));
	// }
	// else
	// {
	// 	size = wid - ft_strlen(end);
	// 	st = ft_strnew(size);
	// 	ft_memset(st, (mods->flags & 1 << zero) ? '0' : ' ', size);
	// 	out.content = (void*)ft_strcat(st, end);
	// 	return ()
	// }
}