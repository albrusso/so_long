/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 07:18:15 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/18 14:38:33 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_size(t_game *root)
{
	int	i;
	int	len;

	i = 0;
	if (root->height == root->width)
		ft_close(root, MAP_MSG);
	while (i < root->height)
	{
		len = ft_strlen(root->maps[i]);
		if (len != root->width)
			ft_close(root, MAP_MSG);
		i++;
	}
}

void	ft_check_wall_up_down(t_game *root)
{
	int	i;

	i = 0;
	while (i < root->width)
	{
		if (root->maps[0][i] != '1' || root->maps[root->height - 1][i] != '1')
			ft_close(root, WALL_MSG);
		else
			i++;
	}
}

void	ft_check_wall_left_right(t_game *root)
{
	int	i;

	i = 0;
	while (i < root->height)
	{
		if (root->maps[i][0] != '1' || root->maps[i][root->width - 1] != '1')
			ft_close(root, WALL_MSG);
		else
			i++;
	}
}

void	ft_check_path(t_game *root)
{
	int		x;
	int		y;
	char	**dup_maps;

	x = 0;
	y = 0;
	dup_maps = malloc(sizeof(char *) * root->height);
	while (x < root->height)
	{
		dup_maps[x] = ft_strdup(root->maps[x]);
		x++;
	}
	x = 0;
	dup_maps = ft_flood_fill(root->minotaur_x, root->minotaur_y, dup_maps);
	ft_free_maps(root->height, dup_maps);
}

void	ft_check(t_game *root)
{
	ft_check_size(root);
	ft_check_wall(root);
	ft_check_nbr(root, 'P', 'E');
	ft_check_path(root);
}
