/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:48:07 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/28 08:16:18 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

void	ft_set_image(t_game *game)
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
}

void	ft_anim_player(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->player.add);
	game->player.add = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&game->player.width, &game->player.height);
}
