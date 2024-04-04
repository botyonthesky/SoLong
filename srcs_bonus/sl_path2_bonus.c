/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:42:35 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/04 11:42:40 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

char	ft_have_wall(int fd, size_t *length, size_t *row, size_t count)
{
	char	*line;
	char	*lineb;

	line = get_next_line(fd);
	if (line == NULL || line[0] == '\n')
		return ('0');
	*length = ft_gnl(line);
	lineb = malloc((*length + 1));
	if (lineb == NULL)
		return ('A');
	while (line)
	{
		if (*length != ft_gnl(line))
			return ('R');
		if (line[0] != '1' || line[*length - 1] != '1')
			return ('1');
		ft_strlcpy(lineb, line, *length + 1);
		free(line);
		line = get_next_line(fd);
		if ((*row)++ == 0)
			while (count < *length)
				if (lineb[count++] != '1')
					return ('1');
	}
	return (ft_last_line(line, lineb, length, count));
}

char	ft_last_line(char *line, char *lineb, size_t *length, size_t count)
{
	count = 0;
	if (line == NULL)
	{
		while (count < *length)
		{
			if (lineb[count++] != '1')
				return ('1');
		}
	}
	free(line);
	free(lineb);
	return (0);
}
