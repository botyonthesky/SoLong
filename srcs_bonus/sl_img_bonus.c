/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:30:18 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/08 15:47:38 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_set_image_bonus(t_game *game)
{
	game->wall.add = mlx_xpm_file_to_image(game->mlx_ptr,
			"src_xpm/AnyConv.com__TILE_3C.xpm",
			&game->wall.width, &game->wall.height);
	game->wall2.add = mlx_xpm_file_to_image(game->mlx_ptr,
			"src_xpm/AnyConv.com__TILE_3D.xpm",
			&game->wall2.width, &game->wall2.height);
	game->wall3.add = mlx_xpm_file_to_image(game->mlx_ptr,
			"src_xpm/AnyConv.com__TILE_3E.xpm",
			&game->wall3.width, &game->wall3.height);
	game->background.add = mlx_xpm_file_to_image(game->mlx_ptr,
			"src_xpm/Background_64x64.xpm",
			&game->background.width, &game->background.height);
	game->player.add = mlx_xpm_file_to_image(game->mlx_ptr,
			"src_xpm/Player_64x64.xpm",
			&game->player.width, &game->player.height);
	game->item.add = mlx_xpm_file_to_image(game->mlx_ptr,
			"src_xpm/Anim_item_64x64_1.xpm",
			&game->item.width, &game->item.height);
	game->exit.add = mlx_xpm_file_to_image(game->mlx_ptr,
			"src_xpm/Exit_door_64x64.xpm",
			&game->exit.width, &game->exit.height);
	game->bonus.enemy.add = mlx_xpm_file_to_image(game->mlx_ptr,
			"src_xpm/Anim_enemy_64x64_1.xpm",
			&game->bonus.enemy.width, &game->bonus.enemy.height);
}
