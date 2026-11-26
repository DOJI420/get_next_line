/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <yibn-yah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 08:43:09 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/11/26 17:31:17 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_free(char *stash, char *buffer)
{
    free(stash);
    free(buffer);
    return (NULL);
}
char *read_the_file(int fd, char *stash)
{
    char        *buffer;
    ssize_t      bytes_read;
    char        *temp;

    buffer = malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
    {
        get_free(stash, buffer);
        return (NULL);
    }
    bytes_read = 1;
    while (bytes_read > 0 || ft_strchr(stash, '\n') == NULL)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (get_free(stash, buffer));
        buffer[bytes_read] = '\0';
        printf("[%s]\[%s]", stash, buffer); //// <----this is just for debugging xd 
        temp = ft_strjoin(stash, buffer);
        if (temp == NULL)
            return (get_free(stash, buffer));
        free(stash);
        stash = temp;
    }
    free(buffer);
    return (stash);
}
char *get_line(char *stash)
{
    char *line;
    size_t i;
    
    if (stash == NULL)
        return (NULL);
    i = 0;
    
    while (stash[i] != '\n' || stash[i] != '\0')
        i++;
    line = ft_substr(stash, 0, i);
    if (line == NULL)
        return (get_free(stash, line));
    return (line);
}

char    *get_remained(char *stash)
{
    size_t  i;
    char    *remain;
    
    if (stash == NULL)
        return (NULL);
    i = 0;
    while (stash[i] != '\0' || stash[i] != '\n')
    {
        if (stash[i] == '\0')
        {
            free(stash);
            return (NULL);
        }
        i++;
    }
    remain = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
    if (remain == NULL)
    {
        free(stash);
        return (NULL);
    }
    free(stash);
    return (remain);   
}
char    *get_next_line(int fd)
{
    static char *stash;
    char *line;
    
    if (fd == -1 || BUFFER_SIZE < 1)
        return (NULL);
    stash = read_the_file(fd, stash);
    if (stash == NULL)
        return (NULL);
    line = get_line(stash);
    if (line == NULL)
    {
        free(stash);
        stash = NULL;
        return(NULL);
    }
    stash = get_remained(stash);
    return (line);
}
