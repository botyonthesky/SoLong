/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:29:53 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/26 08:18:42 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_render_enemy(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'X')
				ft_render_img_bonus(game, &game->bonus.enemy, x, y);
			y++;
		}
		x++;
	}
}

void	ft_swap_enemy(t_game *game, int direction)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'X')
				ft_swap_enemy_space(game, direction, x, y);
			y++;
		}
		x++;
	}
}

void	ft_swap_enemy_space(t_game *game, int direction, int x, int y)
{
	if (direction == 1)
	{
		if (game->map[x][y] == 'X' && game->map[x + 1][y] == '0')
			ft_swap_position(&game->map[x][y], &game->map[x + 1][y], 'X', '0');
		else if (game->map[x][y] == 'X' && game->map[x + 1][y] == 'P')
			ft_game_over(game);
	}
	else if (direction == 0)
	{
		if (game->map[x][y] == 'X' && game->map[x - 1][y] == '0')
			ft_swap_position(&game->map[x][y], &game->map[x - 1][y], 'X', '0');
		else if (game->map[x][y] == 'X' && game->map[x - 1][y] == 'P')
			ft_game_over(game);
	}
}
