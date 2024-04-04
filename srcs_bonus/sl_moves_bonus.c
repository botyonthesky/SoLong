/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:37:26 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/08 09:37:30 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_manage_moves(t_game *game)
{
	if (game->moves_enemy < 30000)
	{
		game->moves_enemy++;
		return ;
	}
	game->moves_enemy = 0;
	ft_update_move(game);
	ft_swap_direction(game);
	ft_render_map_bonus(game);
}

void	ft_update_move(t_game *game)
{
	if (game->movement < 6)
		game->movement++;
	else
		game->movement = 1;
}

void	ft_swap_direction(t_game *game)
{
	if (game->movement == 1)
		ft_swap_enemy(game, 0);
	else if (game->movement == 2)
		ft_swap_enemy(game, 0);
	else if (game->movement == 3)
		ft_swap_enemy(game, 0);
	else if (game->movement == 4)
		ft_swap_enemy(game, 1);
	else if (game->movement == 5)
		ft_swap_enemy(game, 1);
}

void	ft_swap_position(char *current, char *next, char old, char new)
{
	*current = new;
	*next = old;
}
