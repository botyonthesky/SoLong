/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:44:02 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 17:14:55 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

void	ft_render_img(t_game *game, t_img *img, int x, int y)
{
	img->x = x;
	img->y = y;
	mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr,
		img->add, img->y * PIXEL_SIZE, img->x * PIXEL_SIZE);
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

void	ft_render_default_map(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				ft_render_wall(game, x, y, i++);
			if (game->map[x][y] == 'P')
				ft_render_img(game, &game->player, x, y);
			if (game->map[x][y] == '0')
				ft_render_img(game, &game->background, x, y);
			if (game->map[x][y] == 'C')
				ft_render_img(game, &game->item, x, y);
			if (game->map[x][y] == 'E')
				ft_render_img(game, &game->exit, x, y);
			y++;
		}
		x++;
	}
}

void	ft_render_wall(t_game *game, int x, int y, int i)
{
	if (i % 3 == 0)
		ft_render_img(game, &game->wall, x, y);
	else if (i % 5 == 1)
		ft_render_img(game, &game->wall2, x, y);
	else
		ft_render_img(game, &game->wall3, x, y);
}
