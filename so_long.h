/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:50:24 by albrusso          #+#    #+#             */
/*   Updated: 2024/05/27 16:00:34 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "mylib/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define MINOTAUR "image/minotaur.xpm"
# define EXIT "image/exit.xpm"
# define COLLECT "image/collect.xpm"
# define WALL "image/wall.xpm"
# define BACKGROUND "image/background.xpm"
# define MINOTAUR_FLIP "image/minotaur_flip.xpm"
# define EXIT_OPEN "image/exit_open.xpm"
# define ARGS_MSG "Errror\nIl numero degli argomenti e' diverso da 2\n"
# define WALL_MSG "Error\nLa mappa non e' circondata da muri\n"
# define PATH_MSG	"Error\nNon esiste un percorso per concludere il gioco\n"
# define OBJ_MSG "Error\nIl numero delle exit, player, collect non e' corretto\n"
# define MAP_MSG "Error\nLa mappa deve essere rettangolare\n"
# define FD_MSG "Error\nLa mappa non esiste\n"

typedef struct s_sprite
{
	void	*minotaur;
	void	*exit;
	void	*collect;
	void	*wall;
	void	*background;
	int		width;
	int		height;
	int		line_size;
	int		endian;
}			t_sprite;

typedef struct s_game
{
	int			max_collect;
	int			collected;
	int			minotaur_x;
	int			minotaur_y;
	int			width;
	int			height;
	int			exit_status;
	int			n;
	void		*mlx_ptr;
	void		*mlx_win;
	t_sprite	img;
	char		**maps;
}			t_game;

int			ft_width(char *path, t_game *root);
int			ft_height(char *path, t_game *root);
int			ft_close(t_game *root, char *msg);
int			key_hook(int keycode, void *r);
int			ft_add_collect(t_game *root, char c);
int			ft_check_exit(t_game *root, char c);
int			ft_is_possible(t_game *root, char s);
int			ft_close_cross(t_game *root);
void		ft_free_maps(int height, char **maps);
void		ft_init_img(t_game *root);
void		ft_choose_img(t_game *root, int x, int y);
void		ft_put_img(t_game *root);
void		ft_start_game(t_game *root);
void		ft_move_left(t_game *root, int x, int y);
void		ft_move_right(t_game *root, int x, int y);
void		ft_move_down(t_game *root, int x, int y);
void		ft_move_up(t_game *root, int x, int y);
void		ft_init_maps(t_game *root, char *path);
void		ft_minotaur_position(t_game *root, char c);
void		ft_init_img_null(t_game *root);
void		ft_init(t_game *root, char *path);
void		ft_set_zero(t_game *root, int y, int x);
void		ft_swap_img(t_game *root, int keycode);
void		ft_execute_moves(t_game *root, int keycode);
void		ft_refresh_exit(t_game *root, int x, int y);
void		ft_check_size(t_game *root);
void		ft_check_wall_up_down(t_game *root);
void		ft_check_wall_left_right(t_game *root);
void		ft_check_wall(t_game *root);
void		ft_check_path(t_game *root);
void		ft_check(t_game *root);
void		ft_max_collect(t_game *root);
void		ft_check_nbr(t_game *root, char p, char e);
char		**ft_flood_fill(int x, int y, char **maps);
char		**ft_alloc_maps(t_game *root);
char		**ft_read_map(char *path, t_game *root);

#endif
