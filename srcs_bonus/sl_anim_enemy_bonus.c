/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:34:11 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/08 09:34:18 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_animate_enemy(t_game *game)
{
	if (game->nb_anim_enemy < 12000)
	{
		game->nb_anim_enemy++;
		return ;
	}
	game->nb_anim_enemy = 0;
	ft_update_frame_enemy(game);
	ft_enemy_anim(game);
	ft_render_map_bonus(game);
}

void	ft_update_frame_enemy(t_game *game)
{
	if (game->frame_enemy < 11)
		game->frame_enemy++;
	else
		game->frame_enemy = 1;
}

void	ft_enemy_anim(t_game *game)
{
	if (game->frame_enemy == 1)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_1.xpm");
	else if (game->frame_enemy == 2)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_2.xpm");
	else if (game->frame_enemy == 3)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_3.xpm");
	else if (game->frame_enemy == 4)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_4.xpm");
	else if (game->frame_enemy == 5)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_5.xpm");
	else if (game->frame_enemy == 6)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_6.xpm");
	else if (game->frame_enemy == 7)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_7.xpm");
	else if (game->frame_enemy == 8)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_8.xpm");
	else if (game->frame_enemy == 9)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_9.xpm");
	else if (game->frame_enemy == 10)
		ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_10.xpm");
}

void	ft_anim_enemy(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->bonus.enemy.add);
	game->bonus.enemy.add = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&(game->bonus.enemy.width), &(game->bonus.enemy.height));
}

void	ft_put_dead(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->player.add);
	game->player.add = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&game->player.width, &game->player.height);
}
