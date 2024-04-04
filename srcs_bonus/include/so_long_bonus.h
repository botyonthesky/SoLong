/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:51:05 by tmaillar          #+#    #+#             */
/*   Updated: 2023/07/11 09:53:01 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../minilibx-linux/mlx.h"
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <stddef.h>

# define PIXEL_SIZE 64

typedef struct s_img
{
	int		width;
	int		height;
	void	*add;
	int		x;
	int		y;
}		t_img;

typedef struct s_wind
{
	int		width;
	int		height;
	void	*win_ptr;
}		t_wind;

typedef struct s_bonus
{
	t_img	enemy;
	t_img	dead;
}		t_bonus;

typedef struct s_game
{
	void			*mlx_ptr;
	char			**map;
	int				moves;
	int				items;
	int				nb_anim_enemy;
	int				nb_anim_door;
	int				nb_anim_player;
	int				nb_anim_item;
	int				nb_anim_player_dead;
	int				frame_item;
	int				frame_player;
	int				frame_enemy;
	int				frame_player_dead;
	int				frame_door;
	int				moves_enemy;
	int				end_game;
	int				movement;
	t_wind			window;
	t_bonus			bonus;
	t_img			wall;
	t_img			wall2;
	t_img			wall3;
	t_img			background;
	t_img			exit;
	t_img			player;
	t_img			item;
}		t_game;

typedef struct s_dead_img
{
	int	x;
	int	y;
	int	width;
	int	height;
}		t_dead_img;

/* ----------MAP--------------*/

t_wind	ft_wind_size(char **map);
int		ft_count_line(char **map);
int		ft_argv(char *file);
char	**ft_get_map(char *path);
int		ft_map_size(char **map);
int		ft_control_player(char **map, char player);
void	ft_free(char **map);
void	ft_game_over(t_game *game);
int		ft_control_wall(char **map);
void	ft_swap_player(t_game *game, char coord, int move);
void	ft_render_wall(t_game *game, int x, int y, int i);
char	ft_error_types(char *argv);
char	ft_map_validator(char *argv);
char	ft_map_valid_path(char *argv, size_t row, size_t col, int fd);
void	ft_get_player(char **map, size_t *x, size_t *y, size_t col);
char	ft_dfs_check(char **map, size_t x, size_t y, size_t row);
char	*ft_strchr_p(const char *s, int c);
int		ft_dfs(char **map, size_t x, size_t y, size_t row);
int		ft_dfs2(char **map, size_t x, size_t y, size_t row);
int		ft_dfs3(char **map, size_t x, size_t y);
void	ft_free_map(char **map, size_t row);
char	ft_have_wall(int fd, size_t *length, size_t *row, size_t count);
char	ft_map_have_all(int fd, char ext, char pic, char plyr);
char	ft_map_element_check(char c, char *plyr, char *pic, char *ext);
size_t	ft_gnl(const char *line);
char	ft_last_line(char *line, char *lineb, size_t *length, size_t count);

/* -------------------BONUS------------------------*/

void	ft_general_render_bonus(t_game *game);
void	ft_render_img_bonus(t_game *game, t_img *img, int x, int y);
void	ft_render_default_map_bonus(t_game *game);
void	ft_init_wind_bonus(t_game *game);
int		ft_control_content_bonus(char **map);
int		ft_destroy_all_bonus(t_game *game);
void	ft_render_enemy(t_game *game);
void	ft_swap_enemy(t_game *game, int direction);
void	ft_swap_enemy_space(t_game *game, int direction, int x, int y);
int		ft_control_player(char **map, char player);
void	ft_game_over(t_game *game);
void	ft_set_dead(t_game *game, char *path);
void	ft_put_dead(t_game *game, char *path);
void	ft_set_image_bonus(t_game *game);
int		ft_render_map_bonus(t_game *game);
int		ft_render_map2_bonus(t_game *game);
int		ft_control_map_bonus(char **map);
int		ft_control_content_bonus(char **map);
void	ft_anim_player_bonus(t_game *game, char *path);
int		ft_handle_input_bonus(int keysym, t_game *game);
void	ft_right_action_bonus(t_game *game);
void	ft_left_action_bonus(t_game *game);
void	ft_up_action_bonus(t_game *game);
void	ft_down_action_bonus(t_game *game);
int		ft_loop_hook_bonus(t_game *game);
int		ft_loop_end(t_game *game);
void	ft_put_string(t_game *game);
void	ft_put_string_item(t_game *game);

/* --------------------ANIMATIONS---------------------*/

void	ft_anime_door(t_game *game);
void	ft_update_frame_door(t_game *game);
void	ft_door_anim(t_game *game);
void	ft_set_door(t_game *game, char *path);
void	ft_animate_player_dead(t_game *game);
void	ft_update_frame_player_dead(t_game *game);
void	ft_player_anim_dead(t_game *game);
void	ft_player_anim_dead2(t_game *game);
int		ft_loop_end(t_game *game);
void	ft_animate_item(t_game *game);
void	ft_update_frame_item(t_game *game);
void	ft_animate_enemy(t_game *game);
void	ft_update_frame_enemy(t_game *game);
void	ft_animate_player(t_game *game);
void	ft_update_frame_player(t_game *game);
void	ft_enemy_anim(t_game *game);
void	ft_player_anim(t_game *game);
void	ft_player_anim2(t_game *game);
void	ft_anim_player(t_game *game, char *path);
void	ft_anim_enemy(t_game *game, char *path);
void	ft_swap_enemy_space(t_game *game, int direction, int x, int y);
void	ft_swap_enemy(t_game *game, int direction);
void	ft_swap_position(char *current, char *next, char old, char new);
void	ft_swap_direction(t_game *game);
void	ft_swap_player(t_game *game, char coord, int move);
void	ft_update_move(t_game *game);
void	ft_item_anim(t_game *game);
void	ft_anim_item(t_game *game, char *path);
void	ft_manage_moves(t_game *game);

#endif
