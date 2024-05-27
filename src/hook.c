/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:22:24 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/18 15:12:16 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_add_collect(t_game *root, char c)
{
	int	x;
	int	y;

	x = root->minotaur_x;
	y = root->minotaur_y;
	if (c == 'a' && root->maps[y][x - 1] == 'C')
		ft_set_zero(root, y, x - 1);
	if (c == 's' && root->maps[y + 1][x] == 'C')
		ft_set_zero(root, y + 1, x);
	if (c == 'd' && root->maps[y][x + 1] == 'C')
		ft_set_zero(root, y, x + 1);
	if (c == 'w' && root->maps[y - 1][x] == 'C')
		ft_set_zero(root, y - 1, x);
	return (1);
}

int	ft_is_possible(t_game *root, char s)
{
	int	x;
	int	y;

	x = root->minotaur_x;
	y = root->minotaur_y;
	if (s == 'a' && root->maps[y][x - 1] != '1' && ft_check_exit(root, s) == 1)
		return (ft_add_collect(root, s));
	if (s == 's' && root->maps[y + 1][x] != '1' && ft_check_exit(root, s) == 1)
		return (ft_add_collect(root, s));
	if (s == 'd' && root->maps[y][x + 1] != '1' && ft_check_exit(root, s) == 1)
		return (ft_add_collect(root, s));
	if (s == 'w' && root->maps[y - 1][x] != '1' && ft_check_exit(root, s) == 1)
		return (ft_add_collect(root, s));
	return (0);
}

void	ft_swap_img(t_game *root, int keycode)
{
	int	x;
	int	y;

	x = root->minotaur_x;
	y = root->minotaur_y;
	if (keycode == 97)
		ft_move_left(root, x, y);
	if (keycode == 100)
		ft_move_right(root, x, y);
	if (keycode == 115)
		ft_move_down(root, x, y);
	if (keycode == 119)
		ft_move_up(root, x, y);
	root->n++;
	ft_putnbr_fd(root->n, 0);
	write(1, "\n", 1);
}

void	ft_refresh_exit(t_game *root, int x, int y)
{
	x = root->minotaur_x;
	y = root->minotaur_y;
	mlx_destroy_image(root->mlx_ptr, root->img.exit);
	root->img.exit = mlx_xpm_file_to_image(root->mlx_ptr, EXIT_OPEN,
			&root->img.width, &root->img.height);
	ft_minotaur_position(root, 'E');
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.exit, root->minotaur_x * 64, root->minotaur_y * 64);
	root->minotaur_x = x;
	root->minotaur_y = y;
}

int	key_hook(int keycode, void *r)
{
	t_game	*root;
	int		x;
	int		y;

	x = 0;
	y = 0;
	root = (t_game *)r;
	if (keycode == 65307)
		ft_close(root, "");
	else if (keycode == 97 || keycode == 100
		|| keycode == 115 || keycode == 119)
		ft_execute_moves(root, keycode);
	if (root->collected == root->max_collect)
		ft_refresh_exit(root, x, y);
	if (root->maps[root->minotaur_y][root->minotaur_x] == 'E'
		&& root->collected == root->max_collect)
		ft_close(root, "");
	return (1);
}
