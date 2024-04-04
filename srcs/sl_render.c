/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:45:04 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 09:46:41 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

void	ft_general_render(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	ft_init_wind(game);
	ft_set_image(game);
	game->moves = 0;
	game->end_game = 0;
	game->movement = 0;
	game->items = ft_control_player(game->map, 'C');
	mlx_expose_hook(game->window.win_ptr, &ft_render_map, game);
	mlx_hook(game->window.win_ptr, 2, 1L << 0, &ft_handle_input, game);
	mlx_hook(game->window.win_ptr, 17, 0, &ft_destroy_all, game);
	mlx_loop(game->mlx_ptr);
}

int	ft_render_map(t_game *game)
{
	ft_render_default_map(game);
	ft_printf("You did : %d moves !\n", game->moves);
	return (0);
}

void	ft_init_wind(t_game *game)
{
	game->window = ft_wind_size(game->map);
	game->window.win_ptr = mlx_new_window(game->mlx_ptr, game->window.width,
			game->window.height, "So Long");
	if (game->window.win_ptr == NULL)
	{
		free(game->window.win_ptr);
		return ;
	}
}
