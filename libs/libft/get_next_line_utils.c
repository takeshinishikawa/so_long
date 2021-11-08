#include "libft.h"

size_t	ft_strlen_gnl(const char*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*strjoin;

	s1_len = 0;
	s2_len = 0;
	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	while (s1[s1_len])
	{
		strjoin[s1_len] = s1[s1_len];
		s1_len++;
	}
	while (s2[s2_len])
	{
		strjoin[s1_len] = s2[s2_len];
		s1_len++;
		s2_len++;
	}
	strjoin[s1_len] = '\0';
	return (strjoin);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*aux;
	size_t	counter;
	size_t	s1_size;

	s1_size = ft_strlen_gnl(s1);
	aux = malloc(s1_size + 1);
	counter = 0;
	while (s1[counter])
	{
		((unsigned char *)aux)[counter] = ((unsigned char *)s1)[counter];
		counter++;
	}
	((unsigned char *)aux)[counter] = '\0';
	return (aux);
}

size_t	ft_linelen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_linedup_gnl(const char *s1)
{
	void	*dst;
	size_t	counter;
	size_t	s1_size;

	s1_size = ft_linelen_gnl(s1);
	dst = (char *)malloc((s1_size + 1) * sizeof(char));
	counter = 0;
	if (dst == NULL)
		return (NULL);
	while (counter < s1_size)
	{
		((unsigned char *)dst)[counter] = ((unsigned char *)s1)[counter];
		counter++;
	}
	((unsigned char *)dst)[counter] = '\0';
	return (dst);
}
