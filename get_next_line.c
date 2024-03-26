/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:13:45 by yobourai          #+#    #+#             */
/*   Updated: 2024/03/26 09:48:10 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdlib.h>
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
	size = ft_strlen(str) + ft_strlen(ptr);
    new = malloc(size + 1);
    if(!new)
        return (NULL);
    while(ptr && ptr[i])
    {
        new[i] = ptr[i];
        i++;            
    }
    if(ptr)
        free(ptr);
    while(str && str[j])
        new[i++] = str[j++];
    new[size] = '\0';
    return new;
}
int  ft_strchr(char *str , ssize_t nbyte)
{
    int i ;
    i = 0;
    while(str && str[i])
    {
        if(str[i] == '\n')
          return (i + 1);
        i++;
    }
    if(nbyte <= BUFFER_SIZE)
        return i;
    return 0;
}
char *ft_saveline(char *str, ssize_t nbyte)
{
	char	*new;
    int 	i;
	
    i = 0;
	int size = ft_strchr(str,nbyte) + 1;
	new = str + size;
	while(new && new[i])
         i++;
	if (!i)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
    char* ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
    i = 0;
    while(new && new[i])
    {
        ptr[i] = new[i];
        i++;
    }
    ptr[i] = '\0';
    free(str);
	str = NULL;
    return ptr ;
}
char *ft_newline(char *ptr, ssize_t nbyte)
{
    int i;
    char *str ;
    
	i = 0;
	int size =ft_strchr(ptr,nbyte);
    str =malloc(size+1);
    if(!str)
        return NULL ;
    while(size--)
    {
        str[i]=ptr[i];
        i++;
    }
	str[i+1]='\0';
	return str;
}
char *get_next_line(int fd)
{
    static char *ptr; 
    ssize_t     nbyte;
    char        *str;
    
    nbyte = BUFFER_SIZE;
    str = malloc(BUFFER_SIZE + 1);
    if(!str)
    {
        free(ptr);
        ptr = NULL;
        return NULL;
    }
    while(nbyte>0)
    {
        nbyte = read(fd, str, BUFFER_SIZE);
        ptr = ft_strjoin(ptr, str);
        if (!ptr)
        {
            free(str);
            str= NULL ;
            return (NULL);
        }
        if (ft_strchr(ptr, nbyte))
            break;
    }
    free(str);
    str = ft_newline(ptr,nbyte);
    ptr = ft_saveline(ptr, nbyte);
    return (str);
}
 int main()
{
    char *str;
    int fd;
    fd = open("txt.txt", O_RDONLY); 
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
   
}