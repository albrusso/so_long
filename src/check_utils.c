/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:52:19 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/18 14:39:43 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_flood_fill(int x, int y, char **maps)
{
	maps[y][x] = '1';
	if (maps[y][x + 1] != '1')
		ft_flood_fill((x + 1), y, maps);
	if (maps[y][x - 1] != '1')
		ft_flood_fill((x - 1), y, maps);
	if (maps[y + 1][x] != '1')
		ft_flood_fill(x, (y + 1), maps);
	if (maps[y - 1][x] != '1')
		ft_flood_fill(x, (y - 1), maps);
	return (maps);
}

void	ft_max_collect(t_game *root)
{
	int	x;
	int	y;

	y = 0;
	while (y < root->height)
	{
		x = 0;
		while (x < root->width)
		{
			if (root->maps[y][x] == 'C')
				root->max_collect++;
			x++;
		}
		y++;
	}
	if (root->max_collect < 1)
		ft_close(root, OBJ_MSG);
}

void	ft_check_wall(t_game *root)
{	
	ft_check_wall_up_down(root);
	ft_check_wall_left_right(root);
}

void	ft_check_nbr(t_game *root, char p, char e)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	j = 0;
	while (y < root->height)
	{
		x = 0;
		while (x < root->width)
		{
			if (root->maps[y][x] == p)
				i++;
			if (root->maps[y][x] == e)
				j++;
			x++;
		}
		y++;
	}
	if (i != 1 || j != 1)
		ft_close(root, OBJ_MSG);
}

void	ft_check_utils(t_game *root, int x, int y, char **dup_maps)
{
	while (y < root->height)
	{
		x = 0;
		while (x < root->width)
		{
			if (dup_maps[y][x] != '1')
				ft_close(root, PATH_MSG);
			x++;
		}
		y++;
	}
}
