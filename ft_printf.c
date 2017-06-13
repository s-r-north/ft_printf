#include "ft_printf.h"

char	*eval_data_type(t_mods *mods, va_list ap)
{
	//char *s;
	if (mods->conv == '%')
		return (short_char('%'));
	// else if (ft_strchr("uUboOxXp", mods->conv))
	// 	return (ft_unsigned_ints(ap, mods));
	// else if (ft_strchr("idD", mods->conv))
	// 	return (ft_signed_ints(ap, mods));
	// else if ((mods->conv == 'c' && (mods->length & 1 << L)) || mods->conv == 'C')
	// 	return (long_char(va_arg(ap, int)));
	else if (mods->conv == 'c' && !(mods->length & 1 << L))
	{
		//char c;

		//c = (char)va_arg(ap, int);
		return (short_char(va_arg(ap, int)));
	}
	// else if ((mods->conv == 's' && (mods->length & 1 << L)) || mods->conv == 'S')
	// 	return (long_str(va_arg(ap, char*), mods));
	else if (mods->conv == 's' && !(mods->length & 1 << L))
	{
		//s = va_arg(ap, char*);
		//printf("%s\n", s);
		//return (s);
		return (short_str(va_arg(ap, char*), mods));
	}
	else
		return (NULL);
}

int		eval_modifiers(char *s, t_mods *mods)
{
	int i;

	i = 0;
	while (!ft_strchr("cCsSdDiuUoOxXp%", *s))
	{
		++i;
		if (!ft_strchr("0123456789+-# ztjLlh.", *s))
			return (i);
		mods->flags |= (*s == '#') << hash;
		mods->flags |= (*s == '+') << plus;
		mods->flags |= (*s == '-') << minus;
		mods->flags |= (*s == '0' && (*(s - 1) < '0' || *(s - 1) > '9') && *(s - 1) != '.') << zero;
		mods->flags |= (*s == ' ') << space;
		mods->flags |= (*s == '.') << precis;
		mods->length |= (*s == 'z') << Z;
		mods->length |= (*s == 't') << T;
		mods->length |= (*s == 'j') << J;
		mods->length |= (*s == 'L' || (*s == 'l' && *(s - 1) == 'l')) << LL;
		mods->length |= (*s == 'l' && *(s + 1) != 'l') << L;
		mods->length |= (*s == 'h' && *(s + 1) != 'h' && *(s - 1) != 'h') << H;
		mods->length |= (*s == 'h' && *(s + 1) == 'h') << HH;
		mods->prec |= (*s == '.') ? (size_t)ft_atoi(s + 1) : 0;
		mods->width |= (*s >= '1' && *s <= '9' && (*(s - 1) < '1' ||
			*(s - 1) > '9') && *(s - 1) != '.') ? (size_t)ft_atoi(s) : 0;
		s++;
	}
	mods->conv = *s;
	return (i);
}

void	zero_mods(t_mods *mods)
{
	mods->conv = 0;
	mods->flags = 0;
	mods->length = 0;
	mods->width = 0;
	mods->prec = 0;
	return ;
}

void	prelim_printf(const char *fmt, ...)
{
	va_list ap;
	t_mods *mods;
	char *s;
	char *butt;
	char *tmp;
	int i;

	i = 0;
	va_start(ap, fmt);
	tmp = (char*)fmt;
	mods = (t_mods*)malloc(sizeof(t_mods));
	zero_mods(mods);
	s = NULL;
	while (*tmp)
	{
		if (*tmp++ == '%')
		{
			s = (char*)ft_realloc(s, i + (!s ? 1 : ft_strlen(s)));
			if (i < 0)
				ft_strncat(s, tmp - (i + 2), i);
			tmp += eval_modifiers(tmp, mods);
			if (!ft_strchr("cCsSdDiuUoOxXp%", *tmp))
			{
				i = 1;
				continue ;
			}
			//printf("check3: %i, %zu\n", mods->flags, mods->width);
			butt = eval_data_type(mods, ap);
			s = (char*)ft_realloc(s, i + (!s ? 1 : ft_strlen(s)) + ft_strlen(butt));
			//printf("check5\n");
			ft_strncat(s, butt, ft_strlen(butt));
			//printf("check6\n");
			ft_strclr(butt);
			ft_strdel(&butt);
			zero_mods(mods);
			i = -1;
			tmp++;
		}
		i++;
	}
	s = (char*)ft_realloc(s, i + (!s ? 1 : ft_strlen(s)));
	//printf("check69: %d %s\n", i, s);
	ft_strncat(s, tmp - i, i);
	//printf("check420\n");
	write(1, s, ft_strlen(s));
	ft_strclr(s);
	ft_strdel(&s);
	if (mods)
		free(mods);
	return ;
}