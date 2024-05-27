/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:50:19 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/18 14:44:22 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close_cross(t_game *root)
{
	if (root->img.background)
		mlx_destroy_image(root->mlx_ptr, root->img.background);
	if (root->img.collect)
		mlx_destroy_image(root->mlx_ptr, root->img.collect);
	if (root->img.exit)
		mlx_destroy_image(root->mlx_ptr, root->img.exit);
	if (root->img.minotaur)
		mlx_destroy_image(root->mlx_ptr, root->img.minotaur);
	if (root->img.wall)
		mlx_destroy_image(root->mlx_ptr, root->img.wall);
	if (root->mlx_win)
		mlx_destroy_window(root->mlx_ptr, root->mlx_win);
	if (root->mlx_ptr)
	{
		mlx_destroy_display(root->mlx_ptr);
		free(root->mlx_ptr);
	}
	if (root->maps)
		ft_free_maps(root->height, root->maps);
	exit(0);
}

int	ft_close(t_game *root, char *msg)
{
	if (root->img.background)
		mlx_destroy_image(root->mlx_ptr, root->img.background);
	if (root->img.collect)
		mlx_destroy_image(root->mlx_ptr, root->img.collect);
	if (root->img.exit)
		mlx_destroy_image(root->mlx_ptr, root->img.exit);
	if (root->img.minotaur)
		mlx_destroy_image(root->mlx_ptr, root->img.minotaur);
	if (root->img.wall)
		mlx_destroy_image(root->mlx_ptr, root->img.wall);
	if (root->mlx_win)
		mlx_destroy_window(root->mlx_ptr, root->mlx_win);
	if (root->mlx_ptr)
	{
		mlx_destroy_display(root->mlx_ptr);
		free(root->mlx_ptr);
	}
	if (root->maps)
		ft_free_maps(root->height, root->maps);
	ft_putstr_fd(msg, 0);
	exit(0);
}

void	ft_init(t_game *root, char *path)
{
	root->max_collect = 0;
	root->collected = 0;
	root->n = 0;
	ft_init_img_null(root);
	ft_init_maps(root, path);
	ft_read_map(path, root);
	ft_minotaur_position(root, 'P');
	ft_max_collect(root);
}

void	ft_start_game(t_game *root)
{
	root->mlx_ptr = mlx_init();
	root->mlx_win = mlx_new_window(root->mlx_ptr, 64 * root->width,
			64 * root->height, "so_long");
	ft_init_img(root);
	ft_put_img(root);
	mlx_hook(root->mlx_win, 17, 0, ft_close_cross, root);
	mlx_key_hook(root->mlx_win, key_hook, root);
	mlx_loop(root->mlx_ptr);
}

int	main(int ac, char *av[])
{
	t_game	root;

	if (ac != 2)
		ft_close(&root, ARGS_MSG);
	else
	{
		root.maps = NULL;
		ft_init(&root, av[1]);
		ft_check(&root);
		ft_start_game(&root);
	}
}
