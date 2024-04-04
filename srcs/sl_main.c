/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:48:52 by tmaillar          #+#    #+#             */
/*   Updated: 2023/09/04 11:09:38 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!ft_argv(argv[1]))
			ft_printf("Error\nOnly one argv (*.ber)");
		else
		{
			game.map = ft_get_map(argv[1]);
			if (!ft_control_map(game.map) || (ft_error_types(argv[1]) == 1))
			{
				ft_printf("Error\nWrong map format ! Check your map... ");
				ft_free(game.map);
				return (1);
			}
			ft_general_render(&game);
		}
	}
	else
		ft_printf("Error\nWrong argv !!");
	return (0);
}
