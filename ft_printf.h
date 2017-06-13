#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include "./libft/libft.h"

typedef enum	s_flag
{
	hash,
	plus,
	minus,
	zero,
	space,
	precis
}				t_flag;

typedef enum	s_bool
{
	false,
	true
}				t_bool;

typedef enum	s_len
{
	HH,
	H,
	L,
	LL,
	J,
	T,
	Z
}				t_len;

typedef struct	s_mods
{
	char		conv;
	short		flags;
	short		length;
	size_t		width;
	size_t		prec;
}				t_mods;

void	prelim_printf(const char *fmt, ...);
char	*eval_data_type(t_mods *mods, va_list ap);
int		eval_modifiers(char *s, t_mods *mods);

char	*percent_conv(void);
char	*short_char(char c);
char	*short_str(char *s, t_mods *mods);

size_t	find_base(char c);
char	*length_to_size(va_list ap, char len, size_t base);
size_t	prec_width(size_t base, t_mods *mods, size_t len);
char	*int_width_flags(size_t base, t_mods *mods, size_t len);
char	*ft_multicat(char *dst, int c, size_t size);
void	ft_strupper(char *s);
char	*ft_unsigned_ints(va_list ap, t_mods *mods);


#endif