/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:48:52 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/28 08:15:58 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

char	ft_error_types(char *argv)
{
	char	error_type;

	error_type = ft_map_validator(argv);
	if (error_type == 'V')
		ft_printf("");
	else if (error_type == 'A')
		ft_printf("Error\nWrong map format A!");
	else if (error_type == 'R')
		ft_printf("Error\nWrong map format R!");
	else if (error_type == '1')
		ft_printf("Error\nWrong map format 1!");
	else if (error_type == 'Q')
		ft_printf("");
	else if (error_type == 'E')
		ft_printf("");
	else
		return (0);
	return (1);
}

char	ft_map_validator(char *argv)
{
	size_t	l;
	size_t	row;
	char	error;

	row = 0;
	error = ft_have_wall(open(argv, O_RDONLY), &l, &row, 0);
	if (error != 0)
		return (error);
	error = ft_map_have_all(open(argv, O_RDONLY), 0, 0, 0);
	if (error != 0)
		return (error);
	error = ft_map_valid_path(argv, row, l, 0);
	if (error != 0)
		return (error);
	return (0);
}

char	ft_map_valid_path(char *argv, size_t row, size_t col, int fd)
{
	size_t	x;
	size_t	y;
	size_t	path;
	char	**map;
	char	*line;

	fd = open(argv, O_RDONLY);
	map = malloc(row * sizeof(char *));
	if (map == NULL)
		return ('A');
	line = get_next_line(fd);
	path = 0;
	while (line != NULL)
	{
		map[path] = malloc((col + 1));
		if (map[path] == NULL)
			return ('A');
		ft_strlcpy(map[path++], line, col + 1);
		free(line);
		line = get_next_line(fd);
	}
	ft_get_player(map, &x, &y, col);
	path = ft_dfs_check(map, x, y, row);
	ft_free_map(map, row);
	return (path);
}

void	ft_get_player(char **map, size_t *x, size_t *y, size_t col)
{
	char	player_pos;

	*x = 0;
	*y = 1;
	player_pos = '0';
	while (player_pos != 'P')
	{
		if (*x < col - 2)
			(*x)++;
		else
		{
			*x = 1;
			(*y)++;
		}
		player_pos = map[*y][*x];
	}
}
