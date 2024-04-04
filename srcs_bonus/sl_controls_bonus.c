/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_controls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:29:32 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 10:01:04 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"
#include "../libft/libft.h"

int	ft_handle_input_bonus(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_destroy_all_bonus(game);
	if (keysym == XK_w || keysym == XK_Up)
		ft_up_action_bonus(game);
	if (keysym == XK_s || keysym == XK_Down)
		ft_down_action_bonus(game);
	if (keysym == XK_a || keysym == XK_Left)
		ft_left_action_bonus(game);
	if (keysym == XK_d || keysym == XK_Right)
		ft_right_action_bonus(game);
	ft_render_map_bonus(game);
	return (0);
}

void	ft_right_action_bonus(t_game *game)
{
	if (game->map[game->player.x][game->player.y + 1] == 'X')
		ft_game_over(game);
	else if (game->map[game->player.x][game->player.y + 1] == 'E'
			&& game->items == 0)
	{
		game->moves++;
		game->map[game->player.x][game->player.y] = '0';
		ft_printf("CONGRATULATIONS ! Want to try another level ?\n");
		ft_destroy_all_bonus(game);
	}
	else if (game->map[game->player.x][game->player.y + 1] != '1'
			&& game->map[game->player.x][game->player.y + 1] != 'E'
			&& game->end_game == 0)
	{
		if (game->map[game->player.x][game->player.y + 1] == 'C')
			game->items--;
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_1.xpm");
		ft_swap_player(game, 'y', 1);
		game->moves++;
	}
}

void	ft_left_action_bonus(t_game *game)
{
	if (game->map[game->player.x][game->player.y - 1] == 'X')
		ft_game_over(game);
	else if (game->map[game->player.x][game->player.y - 1] == 'E'
			&& game->items == 0)
	{
		game->map[game->player.x][game->player.y] = '0';
		ft_printf("CONGRATULATIONS !! Want to try another level ?\n");
		ft_destroy_all_bonus(game);
	}
	else if (game->map[game->player.x][game->player.y - 1] != '1'
			&& game->map[game->player.x][game->player.y - 1] != 'E'
			&& game->end_game == 0)
	{
		if (game->map[game->player.x][game->player.y - 1] == 'C')
			game->items--;
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_1.xpm");
		ft_swap_player(game, 'y', 0);
		game->moves++;
	}
}

void	ft_up_action_bonus(t_game *game)
{
	if (game->map[game->player.x - 1][game->player.y] == 'X')
		ft_game_over(game);
	else if (game->map[game->player.x - 1][game->player.y] == 'E'
			&& game->items == 0)
	{
		game->map[game->player.x][game->player.y] = '0';
		ft_printf("CONGRATULATIONS !! Want to try another level?\n");
		ft_destroy_all_bonus(game);
	}
	else if (game->map[game->player.x - 1][game->player.y] != '1'
			&& game->map[game->player.x - 1][game->player.y] != 'E'
			&& game->end_game == 0)
	{
		if (game->map[game->player.x - 1][game->player.y] == 'C')
			game->items--;
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_1.xpm");
		ft_swap_player(game, 'x', 0);
		game->moves++;
	}
}

void	ft_down_action_bonus(t_game *game)
{
	if (game->map[game->player.x + 1][game->player.y] == 'X')
		ft_game_over(game);
	else if (game->map[game->player.x + 1][game->player.y] == 'E'
			&& game->items == 0)
	{
		game->map[game->player.x][game->player.y] = '0';
		ft_printf("CONGRATULATIONS !! Want to try another level?\n");
		ft_destroy_all_bonus(game);
	}
	else if (game->map[game->player.x + 1][game->player.y] != '1'
			&& game->map[game->player.x + 1][game->player.y] != 'E'
			&& game->end_game == 0)
	{
		if (game->map[game->player.x + 1][game->player.y] == 'C')
			game->items--;
		ft_anim_player_bonus(game, "src_xpm/Anim_player_64x64_1.xpm");
		ft_swap_player(game, 'x', 1);
		game->moves++;
	}
}
