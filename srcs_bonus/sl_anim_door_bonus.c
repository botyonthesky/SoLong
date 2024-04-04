/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:33:41 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/08 09:33:52 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_anime_door(t_game *game)
{
	if (game->nb_anim_door < 23000)
	{
		game->nb_anim_door++;
		return ;
	}
	game->nb_anim_door = 0;
	ft_update_frame_door(game);
	ft_door_anim(game);
	ft_render_map_bonus(game);
}

void	ft_update_frame_door(t_game *game)
{
	if (game->frame_door < 4)
		game->frame_door++;
}

void	ft_door_anim(t_game *game)
{
	if (game->frame_door == 1)
		ft_set_door(game, "src_xpm/Anim_door_64x64_1.xpm");
	else if (game->frame_door == 2)
		ft_set_door(game, "src_xpm/Anim_door_64x64_2.xpm");
	else if (game->frame_door == 3)
		ft_set_door(game, "src_xpm/Anim_door_64x64_3.xpm");
}

void	ft_set_door(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->exit.add);
	game->exit.add = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&game->exit.width, &game->exit.height);
}
