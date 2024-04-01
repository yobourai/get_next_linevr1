/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:18:49 by yobourai          #+#    #+#             */
/*   Updated: 2024/04/01 05:23:07 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

void	ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strjoin(char *ptr, char *str)
{
	int		i;
	int		j;
	int		size;
	char	*new;

	i = 0;
	j = 0;
	if (!ptr && str)
		return (ft_strdup(str));
	if (!ptr && !str)
		return (NULL);
	size = ft_strlen(str) + ft_strlen(ptr);
	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (ptr && ptr[i])
	{
		new[i] = ptr[i];
		i++;
	}
	while (str && str[j])
		new[i++] = str[j++];
	new[size] = '\0';
	return (new);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
