/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibn-yah <yibn-yah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 08:43:22 by yibn-yah          #+#    #+#             */
/*   Updated: 2026/11/26 14:21:54 by yibn-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>    // for testing remove later...
# include <string.h>   // same here for testing...

#ifndef BUFFER_SIZE
# define  BUFFER_SIZE 67
#endif

size_t      ft_strlen(const char *str);
char        *get_next_line(int fd);
char        *ft_strchr(const char *str, int c);
char        *ft_strdup(char *str);
char        *ft_strjoin(const char *s1, const char *s2);
char        *ft_substr(char const *s, unsigned int start, size_t len);

#endif