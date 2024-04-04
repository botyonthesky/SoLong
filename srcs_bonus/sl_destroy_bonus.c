/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_destroy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:29:47 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 09:58:47 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

int	ft_destroy_all_bonus(t_game *game)
{
	ft_free(game->map);
	mlx_destroy_image(game->mlx_ptr, game->wall.add);
	mlx_destroy_image(game->mlx_ptr, game->wall2.add);
	mlx_destroy_image(game->mlx_ptr, game->wall3.add);
	mlx_destroy_image(game->mlx_ptr, game->background.add);
	mlx_destroy_image(game->mlx_ptr, game->item.add);
	mlx_destroy_image(game->mlx_ptr, game->player.add);
	mlx_destroy_image(game->mlx_ptr, game->exit.add);
	mlx_destroy_image(game->mlx_ptr, game->bonus.enemy.add);
	mlx_destroy_window(game->mlx_ptr, game->window.win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

void	ft_game_over(t_game *game)
{
	game->end_game = 1;
	ft_anim_item(game, "src_xpm/Anim_item_64x64_1.xpm");
	mlx_loop_hook(game->mlx_ptr, ft_render_map2_bonus, game);
	ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_1.xpm");
	ft_anim_enemy(game, "src_xpm/Anim_enemy_64x64_1.xpm");
	ft_printf("YOU DEAD !!! TRY AGAIN\n");
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
