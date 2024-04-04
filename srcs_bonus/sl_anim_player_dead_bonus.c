/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_player_dead_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:29:13 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 17:15:53 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_animate_player_dead(t_game *game)
{
	if (game->nb_anim_player_dead < 7000)
	{
		game->nb_anim_player_dead++;
		return ;
	}
	game->nb_anim_player_dead = 0;
	ft_update_frame_player_dead(game);
	ft_player_anim_dead(game);
	ft_player_anim_dead2(game);
	ft_render_map_bonus(game);
}

void	ft_update_frame_player_dead(t_game *game)
{
	if (game->frame_player_dead < 19)
		game->frame_player_dead++;
}

void	ft_player_anim_dead(t_game *game)
{
	if (game->frame_player_dead == 1)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_1.xpm");
	else if (game->frame_player_dead == 2)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_2.xpm");
	else if (game->frame_player_dead == 3)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_3.xpm");
	else if (game->frame_player_dead == 4)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_4.xpm");
	else if (game->frame_player_dead == 5)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_5.xpm");
	else if (game->frame_player_dead == 6)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_6.xpm");
	else if (game->frame_player_dead == 7)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_7.xpm");
	else if (game->frame_player_dead == 8)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_8.xpm");
	else if (game->frame_player_dead == 9)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_9.xpm");
	else if (game->frame_player_dead == 10)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_10.xpm");
	else if (game->frame_player_dead == 11)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_11.xpm");
}

void	ft_player_anim_dead2(t_game *game)
{
	if (game->frame_player_dead == 12)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_12.xpm");
	else if (game->frame_player_dead == 13)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_13.xpm");
	else if (game->frame_player_dead == 14)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_14.xpm");
	else if (game->frame_player_dead == 15)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_15.xpm");
	else if (game->frame_player_dead == 16)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_16.xpm");
	else if (game->frame_player_dead == 17)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_17.xpm");
	else if (game->frame_player_dead == 18)
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_18.xpm");
	else if (game->frame_player_dead == 19)
	{
		ft_anim_player_bonus(game, "src_xpm/Anim_dead_64x64_19.xpm");
		ft_put_dead(game, "src_xpm/Anim_dead_64x64_19++.xpm");
	}
}
