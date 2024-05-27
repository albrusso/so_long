/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:34:18 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/17 15:18:15 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_minotaur_position(t_game *root, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < root->height)
	{
		x = 0;
		while (x < root->width)
		{
			if (root->maps[y][x] == c)
			{
				root->minotaur_x = x;
				root->minotaur_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_init_img_null(t_game *root)
{
	root->img.exit = NULL;
	root->img.minotaur = NULL;
	root->img.wall = NULL;
	root->img.background = NULL;
	root->img.collect = NULL;
	root->mlx_ptr = NULL;
	root->mlx_win = NULL;
}

void	ft_put_img(t_game *root)
{
	int	x;
	int	y;

	y = 0;
	while (y < root->height)
	{
		x = 0;
		while (x < root->width)
		{
			ft_choose_img(root, x, y);
			x++;
		}
		y++;
	}
}

void	ft_init_img(t_game *root)
{
	root->img.exit = mlx_xpm_file_to_image(root->mlx_ptr, EXIT,
			&root->img.width, &root->img.height);
	root->img.minotaur = mlx_xpm_file_to_image(root->mlx_ptr, MINOTAUR,
			&root->img.width, &root->img.height);
	root->img.wall = mlx_xpm_file_to_image(root->mlx_ptr, WALL,
			&root->img.width, &root->img.height);
	root->img.background = mlx_xpm_file_to_image(root->mlx_ptr, BACKGROUND,
			&root->img.width, &root->img.height);
	root->img.collect = mlx_xpm_file_to_image(root->mlx_ptr, COLLECT,
			&root->img.width, &root->img.height);
}

void	ft_choose_img(t_game *root, int x, int y)
{
	if (root->maps[y][x] == '1')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
			root->img.wall, x * 64, y * 64);
	else if (root->maps[y][x] == '0')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
			root->img.background, x * 64, y * 64);
	else if (root->maps[y][x] == 'P')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
			root->img.minotaur, x * 64, y * 64);
	else if (root->maps[y][x] == 'C')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
			root->img.collect, x * 64, y * 64);
	else if (root->maps[y][x] == 'E')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win,
			root->img.exit, x * 64, y * 64);
}
