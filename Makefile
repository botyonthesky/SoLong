# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 17:33:09 by tmaillar          #+#    #+#              #
#    Updated: 2023/07/12 09:43:51 by tmaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= so_long
NAME_BONUS			= so_long_bonus

SRCS_FILES			= sl_controls.c sl_controls2.c sl_destroy.c sl_img.c sl_main.c \
						sl_map.c sl_player.c sl_render.c sl_render2.c sl_path.c \
						sl_path2.c sl_path3.c sl_utils.c sl_dfs.c
						

SRCS_BONUS_FILES	= sl_anim_door_bonus.c sl_main_bonus.c sl_anim_enemy_bonus.c \
						sl_anim_item_bonus.c sl_anim_player_bonus.c sl_anim_player_dead_bonus.c \
						sl_controls_bonus.c sl_controls2_bonus.c sl_destroy_bonus.c \
						sl_enemy_bonus.c sl_img_bonus.c sl_map_bonus.c \
						sl_moves_bonus.c sl_render_bonus.c sl_render2_bonus.c \
						sl_render3_bonus.c sl_utils_bonus.c sl_dfs_bonus.c sl_path_bonus.c \
						sl_path2_bonus.c sl_utils2_bonus.c sl_path3_bonus.c

SRCS_DIR			= srcs

SRCS_DIR_BONUS		= srcs_bonus

HEADERS				= so_long.h

HEADERS_DIR			= srcs/include

HEADERS_BONUS		= so_long_bonus.h

HEADERS_BONUS_DIR	= srcs_bonus/include

SRCS 				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

SRCS_BONUS 			= $(addprefix $(SRCS_DIR_BONUS)/, $(SRCS_BONUS_FILES))

OBJS				= $(SRCS:.c=.o) 

OBJS_BONUS			= $(SRCS_BONUS:.c=.o)

LIBFT_DIR			= ./libft
MINILIBX_DIR		= ./minilibx-linux

LIBFT				= ./libft/libft.a
MINILIBX			= ./minilibx-linux/libmlx.a

RM					= rm -f

CC					= cc

CFLAGS				= -Wall -Wextra -Werror -g -MD
MINILIB_FLAGS		= -Lmlx -lXext -lX11 -lm -L.


all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(MINILIBX) $(OBJS)
					$(CC) $(CFLAGS) $(OBJS)  $(LIBFT) $(MINILIBX) $(MINILIB_FLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(MINILIBX) $(OBJS_BONUS)
					$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MINILIBX) $(MINILIB_FLAGS) -o $(NAME_BONUS)

$(LIBFT):			
					$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
					$(MAKE) -C $(MINILIBX_DIR)

clean:				
					$(MAKE) clean -C $(LIBFT_DIR)
					$(MAKE) clean -C $(MINILIBX_DIR)
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)
					$(RM) $(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)
					

re:					fclean all

.PHONY:				all clean fclean re libft minilibx bonus

-include $(OBJS:.o=.d)
-include $(OBJS_BONUS:.o=.d)
