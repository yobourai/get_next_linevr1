/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:18:31 by yobourai          #+#    #+#             */
/*   Updated: 2024/04/01 05:24:16 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *ptr, char *str);
int		ft_strchr(char *str);
char	*ft_saveline(char *str);
char	*ft_newline(char *ptr);
char	*ft_strdup(char *ptr);
void	ft_free(char **str);
void	ft_read(char **str, char **ptr, int fd, ssize_t nbyte);

#endif
