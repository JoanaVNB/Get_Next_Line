/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidon-n <joanavidon@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:30:59 by jvidon-n          #+#    #+#             */
/*   Updated: 2022/05/12 17:03:25 by jvidon-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	cont;

	cont = 0;
	if (s == NULL)
		return (0);
	while (*s++)
		cont++;
	return (cont);
}

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	size_t	i;
	size_t	len_s;
	char	*nstr;

	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
		nstr = (char *)malloc(1);
	else if (size >= len_s)
		nstr = (char *)malloc(len_s - start + 1);
	else
		nstr = (char *)malloc(size + 1);
	if (!nstr)
		return ((char *)s);
	while (start < len_s && i < size)
		nstr[i++] = s[start++];
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_join(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ptr_res;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr_res = (char *)malloc(len * sizeof(char));
	if (!ptr_res)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			ptr_res[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
		ptr_res[i++] = s2[j++];
	ptr_res[i] = '\0';
	return (ptr_res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}
