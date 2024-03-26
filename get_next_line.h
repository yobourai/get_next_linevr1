/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:34:55 by yobourai          #+#    #+#             */
/*   Updated: 2024/03/26 09:43:15 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 8

#endif
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd);
int ft_strlen(char *str);
char *ft_strjoin(char *ptr , char *str);
int  ft_strchr(char *str,ssize_t nbyte);
char *ft_saveline(char *str,ssize_t nbyte);
char *ft_newline(char *ptr,ssize_t nbyte);

#endif