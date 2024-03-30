/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:34:21 by yobourai          #+#    #+#             */
/*   Updated: 2024/03/30 17:48:18 by yobourai         ###   ########.fr       */
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
char *ft_strjoin(char *ptr, char *str)
{
    int i = 0;
    int j = 0;
	int 	size;
	char	*new;
    if (!str && !ptr)
        return NULL;
    if(!ptr)
        return ft_strdup(str);
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