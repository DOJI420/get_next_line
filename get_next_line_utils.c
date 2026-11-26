/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <yibn-yah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 08:43:04 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/11/26 16:43:46 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  len;

    len = 0;
    if (str == NULL)
        return (len);
    while (str[len] != '\0')
        len++;
    return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;
	int				i;

	i = 0;
	find = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)(s + i));
		i++;
	}
	if (find == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char *ft_strdup(char *str)
{
    char    *dup;
    size_t     i;
    size_t  len;

    i = 0;
    len = 0;
    while (str[len] != '\0')
        len++;
    dup = malloc(len + 1);
    if (dup == NULL)
        return (NULL);
    while (i < len)
    {
        dup[i] = str[i];
        i++;
    }
    dup[len] = '\0';
    return (dup);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    char    *joined;
    size_t  index_s1;
    size_t  index_s2;

    if (!s2)
        return (NULL);
    if (!s1)
        s1 = "";
    joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (joined == NULL)
        return (NULL);
    index_s1 = 0;
    index_s2 = 0;
    while (s1[index_s1] != '\0')
    {
        joined[index_s1] = s1[index_s1];
        index_s1++;
    }
    while (s2[index_s2] != '\0')
    {
        joined[index_s1 + index_s2] = s2[index_s2];
        index_s2++;
    }
    joined[index_s1 + index_s2] = '\0';
    return (joined);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t s_len;
    size_t i;

    if (s == NULL)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        len = 0;
    else if (len > start - s_len)
        len = start - s_len;
    sub = malloc((len + 1) * sizeof(char *));
    if (sub == NULL)
        return (NULL);
    i = 0;
    while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
