void	ft_strupper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}