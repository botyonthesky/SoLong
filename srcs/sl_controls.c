/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:29:40 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 09:47:46 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_destroy_all(game);
	if (keysym == XK_w || keysym == XK_Up)
		ft_up_action(game);
	if (keysym == XK_s || keysym == XK_Down)
		ft_down_action(game);
	if (keysym == XK_a || keysym == XK_Left)
		ft_left_action(game);
	if (keysym == XK_d || keysym == XK_Right)
		ft_right_action(game);
	ft_render_map(game);
	return (0);
}

void	ft_right_action(t_game *game)
{
	if (game->map[game->player.x][game->player.y + 1] == 'E'
			&& game->items == 0)
	{
		game->moves++;
		game->map[game->player.x][game->player.y] = '0';
		ft_printf("CONGRATULATIONS ! Want to try another level ?\n");
		ft_destroy_all(game);
	}
	else if (game->map[game->player.x][game->player.y + 1] != '1'
			&& game->map[game->player.x][game->player.y + 1] != 'E'
			&& game->end_game == 0)
	{
		if (game->map[game->player.x][game->player.y + 1] == 'C')
			game->items--;
		ft_anim_player(game, "src_xpm/Anim_player_64x64_1.xpm");
		ft_swap_player(game, 'y', 1);
		game->moves++;
	}
}

void	ft_left_action(t_game *game)
{
	if (game->map[game->player.x][game->player.y - 1] == 'E'
			&& game->items == 0)
	{
		game->map[game->player.x][game->player.y] = '0';
		ft_printf("CONGRATULATIONS !! Want to try another level ?\n");
		ft_destroy_all(game);
	}
	else if (game->map[game->player.x][game->player.y - 1] != '1'
			&& game->map[game->player.x][game->player.y - 1] != 'E'
			&& game->end_game == 0)
	{
		if (game->map[game->player.x][game->player.y - 1] == 'C')
			game->items--;
		ft_anim_player(game, "src_xpm/Anim_player_64x64_1.xpm");
		ft_swap_player(game, 'y', 0);
		game->moves++;
	}
}

void	ft_up_action(t_game *game)
{	
	if (game->map[game->player.x - 1][game->player.y] == 'E'
			&& game->items == 0)
	{
		game->map[game->player.x][game->player.y] = '0';
		ft_printf("CONGRATULATIONS !! Want to try another level?\n");
		ft_destroy_all(game);
	}
	else if (game->map[game->player.x - 1][game->player.y] != '1'
			&& game->map[game->player.x - 1][game->player.y] != 'E'
			&& game->end_game == 0)
	{
		if (game->map[game->player.x - 1][game->player.y] == 'C')
			game->items--;
		ft_anim_player(game, "src_xpm/Anim_player_64x64_1.xpm");
		ft_swap_player(game, 'x', 0);
		game->moves++;
	}
}

void	ft_down_action(t_game *game)
{
	if (game->map[game->player.x + 1][game->player.y] == 'E'
			&& game->items == 0)
	{
		game->map[game->player.x][game->player.y] = '0';
		ft_printf("CONGRATULATIONS !! Want to try another level?\n");
		ft_destroy_all(game);
	}
	else if (game->map[game->player.x + 1][game->player.y] != '1'
			&& game->map[game->player.x + 1][game->player.y] != 'E'
			&& game->end_game == 0)
	{
		if (game->map[game->player.x + 1][game->player.y] == 'C')
			game->items--;
		ft_anim_player(game, "src_xpm/Anim_player_64x64_1.xpm");
		ft_swap_player(game, 'x', 1);
		game->moves++;
	}
}
