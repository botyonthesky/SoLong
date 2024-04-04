/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:55:10 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/26 08:19:08 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

int	ft_map_size(char **map)
{
	int		i;
	char	*line;

	line = map[0];
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(line))
			return (0);
		i++;
	}
	return (1);
}

char	**ft_get_map(char *path)
{
	char	**map;
	char	*tmp;
	char	*line;
	char	*lines;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = lines;
		lines = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	map = ft_split(lines, '\n');
	free(lines);
	close(fd);
	return (map);
}

int	ft_control_map_bonus(char **map)
{
	if (ft_count_line(map) == 0)
		return (0);
	if (ft_map_size(map) == 0 || ft_control_wall(map) == 0)
		return (0);
	if (ft_control_player(map, 'P') != 1)
		return (0);
	if (ft_control_player(map, 'E') < 1 || ft_control_player(map, 'C') < 1)
		return (0);
	if (ft_control_content_bonus(map) == 1)
		return (0);
	return (1);
}
