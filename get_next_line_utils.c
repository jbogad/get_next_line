/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:06:55 by marvin            #+#    #+#             */
/*   Updated: 2025/02/20 11:06:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int len;

    len = 0;
    if (!str)
        return (0);
    while (str[len])
        len++;
    return (len);
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
    size_t i;
    size_t s_len;
    char *sub_str;

    s_len = ft_strlen(s);
    if (!s || start >= s_len || len == 0)
        return (NULL);
    if (s_len - start < len)
        len = s_len - start;
    sub_str = (char *)malloc(sizeof(char) * (len + 1));
    if (!sub_str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub_str[i] = s[start + i];
        i++;
    }
    sub_str[i] = '\0';
    return (sub_str);
}

char *ft_strchr(const char *s, int c)
{
    int i;
    unsigned char char_to_find;

    char_to_find = (unsigned char)c;
    i = 0;
    while (s[i])
    {
        if (s[i] == char_to_find)
            return ((char *)&s[i]);
        i++;
    }
    if (char_to_find == '\0')
        return ((char *)&s[i]);
    return (NULL);
}


char *ft_strjoin(char *s1, char *s2)
{
    size_t i;
    size_t j;
    char *result;
    size_t len1;
    size_t len2;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    if (!s2)
        return (NULL);
    result = malloc(len1 + len2 + 1);
    if (!result)
        return (free(s1), s1 = NULL);
    i = 0;
    j = 0;
    while (i < len1)
        result[j++] = s1[i++];
    i = 0;
    while (i < len2)
        result[j++] = s2[i++];
    result[j] = '\0';
    free(s1);
    return (result);
}
