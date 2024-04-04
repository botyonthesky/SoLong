/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:16:26 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/26 08:16:59 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

char	ft_map_have_all(int fd, char ext, char pic, char plyr)
{
	size_t	length;
	size_t	count;
	char	*line;
	char	linecopy;

	line = get_next_line(fd);
	length = ft_gnl(line);
	while (line)
	{
		count = 0;
		while (count < length)
		{
			linecopy = line[count++];
			if (ft_map_element_check(linecopy, &plyr, &pic, &ext) == 'I')
				return ('I');
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!plyr || !ext || plyr > 1 || ext > 1 || ((plyr + ext + pic) != 3))
		return ('0');
	return (0);
}

char	ft_map_element_check(char c, char *plyr, char *pic, char *ext)
{
	if (c == 'C')
		*pic = 1;
	else if (c == 'E')
		(*ext)++;
	else if (c == 'P')
		(*plyr)++;
	else if (c != '1' && c != '0' && c != '\n')
		return ('I');
	return (0);
}
