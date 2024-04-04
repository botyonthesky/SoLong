/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_controls2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:36:00 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/26 08:18:13 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

int	ft_control_content_bonus(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
					&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'X')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_control_player(char **map, char player)
{
	int	i;
	int	j;
	int	len_i;
	int	len_j;
	int	nb_player;

	nb_player = 0;
	i = 1;
	len_i = ft_count_line(map);
	len_j = ft_strlen(map[0]);
	while (i < len_i - 1)
	{
		j = 1;
		while (j < len_j - 1)
		{
			if (map[i][j] == player)
				nb_player++;
			j++;
		}
		i++;
	}
	return (nb_player);
}

int	ft_control_wall(char **map)
{
	int		i;
	char	*first;
	char	*last;

	first = map[0];
	last = map[ft_count_line(map) - 1];
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_argv(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 'r' || file[i - 2] != 'e' || file[i - 3] != 'b'
		|| file[i - 4] != '.')
		return (0);
	return (1);
}
