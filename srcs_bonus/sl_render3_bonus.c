/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:34:42 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/08 09:34:47 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

int	ft_render_map_bonus(t_game *game)
{
	ft_render_default_map_bonus(game);
	ft_put_string(game);
	ft_put_string_item(game);
	ft_render_enemy(game);
	return (0);
}

int	ft_render_map2_bonus(t_game *game)
{
	ft_put_string(game);
	ft_put_string_item(game);
	ft_animate_player_dead(game);
	return (0);
}

void	ft_render_img_bonus(t_game *game, t_img *img, int x, int y)
{
	img->x = x;
	img->y = y;
	mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr,
		img->add, img->y * PIXEL_SIZE, img->x * PIXEL_SIZE);
}

void	ft_render_default_map_bonus(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				ft_render_wall(game, x, y, i++);
			if (game->map[x][y] == 'P')
				ft_render_img_bonus(game, &game->player, x, y);
			if (game->map[x][y] == '0')
				ft_render_img_bonus(game, &game->background, x, y);
			if (game->map[x][y] == 'C')
				ft_render_img_bonus(game, &game->item, x, y);
			if (game->map[x][y] == 'E')
				ft_render_img_bonus(game, &game->exit, x, y);
			y++;
		}
		x++;
	}
}
