/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:38:46 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/18 14:42:33 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_read_utils(t_game *root, char *buffer, int fd, int y)
{
	static int	x;

	while (1)
	{
		buffer = ft_calloc(2, 1);
		read(fd, buffer, 1);
		if (buffer[0] == '\0')
		{
			root->maps[y][x] = '\0';
			break ;
		}
		if (buffer[0] == '\n')
		{
			root->maps[y][x] = '\0';
			x = 0;
			y++;
		}
		else
		{
			root->maps[y][x] = buffer[0];
			x++;
		}
		free(buffer);
	}
	free(buffer);
}

char	**ft_read_map(char *path, t_game *root)
{
	int		fd;
	int		y;
	char	*buffer;

	y = 0;
	buffer = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_close(root, FD_MSG);
	ft_read_utils(root, buffer, fd, y);
	return (root->maps);
}

void	ft_init_maps(t_game *root, char *path)
{
	root->width = ft_width(path, root);
	root->height = ft_height(path, root);
	root->maps = ft_alloc_maps(root);
}

char	**ft_alloc_maps(t_game *root)
{
	int		x;
	int		y;
	char	**map;

	x = root->width;
	y = root->height;
	map = malloc(sizeof(char *) * y);
	y--;
	while (y >= 0)
	{
		map[y] = malloc(sizeof(char) * x + 1);
		y--;
	}
	return (map);
}

void	ft_free_maps(int height, char **maps)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(maps[i]);
		i++;
	}
	free(maps);
	maps = NULL;
}
