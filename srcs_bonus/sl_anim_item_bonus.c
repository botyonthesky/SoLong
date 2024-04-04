/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_item_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:28:43 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/08 15:01:16 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_animate_item(t_game *game)
{
	if (game->nb_anim_item < 9000)
	{
		game->nb_anim_item++;
		return ;
	}
	game->nb_anim_item = 0;
	ft_update_frame_item(game);
	ft_item_anim(game);
	ft_render_map_bonus(game);
}

void	ft_update_frame_item(t_game *game)
{
	if (game->frame_item < 8)
		game->frame_item++;
	else
		game->frame_item = 1;
}

void	ft_item_anim(t_game *game)
{
	if (game->frame_item == 1)
		ft_anim_item(game, "src_xpm/Anim_item_64x64_1.xpm");
	else if (game->frame_item == 2)
		ft_anim_item(game, "src_xpm/Anim_item_64x64_2.xpm");
	else if (game->frame_item == 3)
		ft_anim_item(game, "src_xpm/Anim_item_64x64_3.xpm");
	else if (game->frame_item == 4)
		ft_anim_item(game, "src_xpm/Anim_item_64x64_4.xpm");
	else if (game->frame_item == 5)
		ft_anim_item(game, "src_xpm/Anim_item_64x64_5.xpm");
	else if (game->frame_item == 6)
		ft_anim_item(game, "src_xpm/Anim_item_64x64_6.xpm");
	else if (game->frame_item == 7)
		ft_anim_item(game, "src_xpm/Anim_item_64x64_7.xpm");
}

void	ft_anim_item(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->item.add);
	game->item.add = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&game->item.width, &game->item.height);
}
