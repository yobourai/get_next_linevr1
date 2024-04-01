/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:34:21 by yobourai          #+#    #+#             */
/*   Updated: 2024/04/01 01:18:01 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;
    
	if(!str)
		return (0);
    while(str && str[i])
        i++;
    return i ;
}
void ft_free(char **str)
{
    if(str && *str)
    {
        free(*str);
        *str = NULL ;
    }
}
char *ft_strjoin(char *ptr, char *str)
{
    int i = 0;
    int j = 0;
	int 	size;
	char	*new;
    if(!ptr && str)
        return ft_strdup(str);
    if (!ptr && !str)
        return NULL ;
	size = ft_strlen(str) + ft_strlen(ptr);
    new = malloc(size + 1);
    if(!new)
        return (NULL);
    while(ptr && ptr[i])
    {
        new[i] = ptr[i];
        i++;            
    }
    while(str && str[j])
        new[i++] = str[j++];
    new[size] = '\0';
    return new;
}
int  ft_strchr(char *str)
{
    int i ;
    i = 0;       

    while(str && str[i])
    {
        if(str[i] == '\n')
          return (i + 1);
        i++;
    }
    return 0;
}
