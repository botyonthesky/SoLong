/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:29:04 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/08 15:07:12 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_animate_player(t_game *game)
{
	if (game->nb_anim_player < 7000)
	{
		game->nb_anim_player++;
		return ;
	}
	game->nb_anim_player = 0;
	ft_update_frame_player(game);
	ft_player_anim(game);
	ft_player_anim2(game);
	ft_render_map_bonus(game);
}

void	ft_update_frame_player(t_game *game)
{
	if (game->frame_player < 14)
		game->frame_player++;
	else
		game->frame_player = 1;
}

void	ft_player_anim(t_game *game)
{
	if (game->frame_player == 1)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_1.xpm");
	else if (game->frame_player == 2)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_2.xpm");
	else if (game->frame_player == 3)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_3.xpm");
	else if (game->frame_player == 4)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_4.xpm");
	else if (game->frame_player == 5)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_5.xpm");
	else if (game->frame_player == 6)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_6.xpm");
	else if (game->frame_player == 7)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_7.xpm");
	else if (game->frame_player == 8)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_8.xpm");
}

void	ft_player_anim2(t_game *game)
{
	if (game->frame_player == 9)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_9.xpm");
	else if (game->frame_player == 10)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_10.xpm");
	else if (game->frame_player == 11)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_11.xpm");
	else if (game->frame_player == 12)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_12.xpm");
	else if (game->frame_player == 13)
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_13.xpm");
}

void	ft_anim_player_bonus(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->player.add);
	game->player.add = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&game->player.width, &game->player.height);
}
