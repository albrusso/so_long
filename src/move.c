/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:49:01 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/18 14:10:57 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_left(t_game *root, int x, int y)
{
	mlx_destroy_image(root->mlx_ptr, root->img.minotaur);
	root->img.minotaur = mlx_xpm_file_to_image(root->mlx_ptr, MINOTAUR_FLIP,
			&root->img.width, &root->img.height);
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.minotaur, (x - 1) * 64, y * 64);
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.background, x * 64, y * 64);
	root->minotaur_x--;
}

void	ft_move_right(t_game *root, int x, int y)
{
	mlx_destroy_image(root->mlx_ptr, root->img.minotaur);
	root->img.minotaur = mlx_xpm_file_to_image(root->mlx_ptr, MINOTAUR,
			&root->img.width, &root->img.height);
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.minotaur, (x + 1) * 64, y * 64);
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.background, x * 64, y * 64);
	root->minotaur_x++;
}

void	ft_move_down(t_game *root, int x, int y)
{
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.minotaur, x * 64, (y + 1) * 64);
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.background, x * 64, y * 64);
	root->minotaur_y++;
}

void	ft_move_up(t_game *root, int x, int y)
{
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.minotaur, x * 64, (y - 1) * 64);
	mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
		root->img.background, x * 64, y * 64);
	root->minotaur_y--;
}

void	ft_execute_moves(t_game *root, int keycode)
{
	if (keycode == 97 && ft_is_possible(root, 'a') == 1)
		ft_swap_img(root, keycode);
	if (keycode == 100 && ft_is_possible(root, 'd') == 1)
		ft_swap_img(root, keycode);
	if (keycode == 115 && ft_is_possible(root, 's') == 1)
		ft_swap_img(root, keycode);
	if (keycode == 119 && ft_is_possible(root, 'w') == 1)
		ft_swap_img(root, keycode);
}
