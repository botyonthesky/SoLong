/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:59:39 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/26 08:19:32 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_swap_player(t_game *game, char coord, int move)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (coord == 'x')
	{
		if (move == 1)
			game->player.x += 1;
		else if (move == 0)
			game->player.x -= 1;
	}
	else if (coord == 'y')
	{
		if (move == 1)
			game->player.y += 1;
		else if (move == 0)
			game->player.y -= 1;
	}
	game->map[x][y] = '0';
	game->map[game->player.x][game->player.y] = 'P';
}
