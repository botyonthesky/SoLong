/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:30:59 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/08 16:11:15 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

int	ft_loop_hook_bonus(t_game *game)
{
	ft_animate_enemy(game);
	ft_animate_item(game);
	ft_animate_player(game);
	ft_manage_moves(game);
	if (game->items == 0)
		ft_anime_door(game);
	return (0);
}

int	ft_loop_end(t_game *game)
{
	ft_animate_item(game);
	return (0);
}

void	ft_put_string(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->window.win_ptr,
		40, 20, -1, "You did : ");
	mlx_string_put(game->mlx_ptr, game->window.win_ptr,
		100, 20, -1, str);
	mlx_string_put(game->mlx_ptr, game->window.win_ptr,
		125, 20, -1, "moves");
	free(str);
}

void	ft_put_string_item(t_game *game)
{
	char	*str;

	str = ft_itoa(game->items);
	if (game->items > 0)
	{
		mlx_string_put(game->mlx_ptr, game->window.win_ptr,
			40, 40, -1, "You must catch ");
		mlx_string_put(game->mlx_ptr, game->window.win_ptr,
			130, 40, -1, str);
		mlx_string_put(game->mlx_ptr, game->window.win_ptr,
			145, 40, -1, " items to get out !");
	}
	else if (game->end_game == 0)
	{
		mlx_string_put(game->mlx_ptr, game->window.win_ptr,
			40, 60, -1, "You can escape now, find the exit !");
	}
	free(str);
}

void	ft_render_wall(t_game *game, int x, int y, int i)
{
	if (i % 3 == 0)
		ft_render_img_bonus(game, &game->wall, x, y);
	else if (i % 5 == 1)
		ft_render_img_bonus(game, &game->wall2, x, y);
	else
		ft_render_img_bonus(game, &game->wall3, x, y);
}
