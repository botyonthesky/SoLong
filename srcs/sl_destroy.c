/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:49:33 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 09:50:25 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

int	ft_destroy_all(t_game *game)
{
	ft_free(game->map);
	mlx_destroy_image(game->mlx_ptr, game->wall.add);
	mlx_destroy_image(game->mlx_ptr, game->wall2.add);
	mlx_destroy_image(game->mlx_ptr, game->wall3.add);
	mlx_destroy_image(game->mlx_ptr, game->background.add);
	mlx_destroy_image(game->mlx_ptr, game->item.add);
	mlx_destroy_image(game->mlx_ptr, game->player.add);
	mlx_destroy_image(game->mlx_ptr, game->exit.add);
	mlx_destroy_window(game->mlx_ptr, game->window.win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit (0);
	return (0);
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
