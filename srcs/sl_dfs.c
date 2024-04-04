/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:48:52 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/28 08:13:56 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

char	ft_dfs_check(char **map, size_t x, size_t y, size_t row)
{
	size_t	i;

	if (ft_dfs2(map, x, y, row) == 'V')
		return ('V');
	if (ft_dfs2(map, x, y, row) == 'E')
		return ('E');
	if (ft_dfs2(map, x, y, row) == 'C')
		return ('C');
	i = 0;
	while (i < row)
	{
		if ((!ft_strchr_p(map[i], 'C')) == false)
			return ('Q');
		else if (ft_strchr_p(map[i], 'E'))
			return ('V');
		i++;
	}
	return (0);
}

int	ft_dfs(char **map, size_t x, size_t y, size_t row)
{
	if (x < 1 || y < 1 || x >= ft_strlen(*map) || y > row
		|| map[y][x] == 'X' || map[y][x] == '1')
		return ('V');
	map[y][x] = 'X';
	ft_dfs(map, x - 1, y, row);
	ft_dfs(map, x + 1, y, row);
	ft_dfs(map, x, y - 1, row);
	ft_dfs(map, x, y + 1, row);
	return (0);
}

int	ft_dfs2(char **map, size_t x, size_t y, size_t row)
{
	if (x < 1 || y < 1 || x >= ft_strlen(*map) || y > row
		|| map[y][x] == 'C' || map[y][x] == '1')
		return ('V');
	if (row == 3)
	{
		return (ft_dfs3(map, x, y));
	}
	map[y][x] = 'X';
	ft_dfs(map, x - 1, y, row);
	ft_dfs(map, x + 1, y, row);
	ft_dfs(map, x, y - 1, row);
	ft_dfs(map, x, y + 1, row);
	return (0);
}

int	ft_dfs3(char **map, size_t x, size_t y)
{
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (map[y][x + 1] == 'E')
					return ('E');
				if (map[y][x + 1] == 'C')
					return ('C');
				x++;
				while (map[y][x] == '0')
				{
					x++;
					if (map[y][x] == 'E')
						return ('E');
					if (map[y][x] == 'C')
						return ('C');
				}		
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_free_map(char **map, size_t row)
{
	size_t	i;

	i = 0;
	while (i < row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
