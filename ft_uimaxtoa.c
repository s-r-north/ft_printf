size_t	ft_unumsize(unsigned long long n, size_t base)
{
	size_t	len;

	if (base < 2 || base > 36)
		return (0);
	len = 1;
	while (n /= base)
		len++;
	return (len);
}


char	*ft_umaxtoa_base(uintmax_t n, size_t base)
{
	size_t	len;
	size_t	i;
	char	tmp;
	char	*ret;

	len = ft_unumsize(n, base);
	if (!len || !(ret = ft_strnew(len)))
		return (NULL);
	i = -1;
	if (n == 0)
		ret[++i] = '0';
	while (n)
	{
		ret[++i] = ((n % base) + (n % base < 9 ? 48 : 87));
		n /= base;
	}
	ret[++i] = '\0';
	i = -1;
	while (++i < len / 2)
	{
		tmp = ret[i];
		ret[i] = ret[len - (i + 1)];
		ret[len - (i + 1)] = tmp;
	}
	return (ret);
}