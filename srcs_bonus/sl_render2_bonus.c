/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:31:13 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 09:54:51 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

void	ft_general_render_bonus(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	ft_init_wind_bonus(game);
	ft_set_image_bonus(game);
	game->moves = 0;
	game->end_game = 0;
	game->nb_anim_enemy = 0;
	game->nb_anim_item = 0;
	game->nb_anim_player = 0;
	game->nb_anim_player_dead = 0;
	game->nb_anim_door = 0;
	game->frame_enemy = 0;
	game->frame_item = 0;
	game->frame_player = 0;
	game->frame_door = 0;
	game->frame_player_dead = 0;
	game->movement = 0;
	game->moves_enemy = 0;
	game->items = ft_control_player(game->map, 'C');
	mlx_expose_hook(game->window.win_ptr, &ft_render_map_bonus, game);
	mlx_hook(game->window.win_ptr, 2, 1L << 0, &ft_handle_input_bonus, game);
	mlx_hook(game->window.win_ptr, 17, 0, &ft_destroy_all_bonus, game);
	mlx_loop_hook(game->mlx_ptr, &ft_loop_hook_bonus, game);
	mlx_loop(game->mlx_ptr);
}

t_wind	ft_wind_size(char **map)
{
	t_wind	window;

	if (!map[0] || !ft_count_line(map))
	{
		window.width = 0;
		window.height = 0;
		return (window);
	}
	window.width = ft_strlen(map[0]) * PIXEL_SIZE;
	window.height = ft_count_line(map) * PIXEL_SIZE;
	return (window);
}

void	ft_init_wind_bonus(t_game *game)
{
	game->window = ft_wind_size(game->map);
	game->window.win_ptr = mlx_new_window(game->mlx_ptr, game->window.width,
			game->window.height, "So Long Bonus");
	if (game->window.win_ptr == NULL)
	{
		free(game->window.win_ptr);
		return ;
	}
}
