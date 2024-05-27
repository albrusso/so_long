/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:21:34 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/18 14:43:18 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_width(char *path, t_game *root)
{
	int		width;
	int		fd;
	char	*buff;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_close(root, FD_MSG);
	width = 0;
	while (1)
	{
		buff = ft_calloc(2, 1);
		read(fd, buff, 1);
		if (buff[0] == '\n')
			break ;
		width++;
		free(buff);
	}
	free(buff);
	close(fd);
	return (width);
}

int	ft_height(char *path, t_game *root)
{
	int		height;
	int		fd;
	char	*buff;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_close(root, FD_MSG);
	height = 0;
	while (1)
	{
		buff = ft_calloc(2, 1);
		read(fd, buff, 1);
		if (buff[0] == '\n')
			height++;
		if (buff[0] == '\0')
		{
			height++;
			break ;
		}
		free(buff);
	}
	free(buff);
	close(fd);
	return (height);
}

int	ft_check_exit(t_game *root, char c)
{
	int	x;
	int	y;

	x = root->minotaur_x;
	y = root->minotaur_y;
	if (c == 'a' && root->maps[y][x - 1] == 'E' &&
			(root->collected != root->max_collect))
		return (0);
	if (c == 's' && root->maps[y + 1][x] == 'E' &&
			(root->collected != root->max_collect))
		return (0);
	if (c == 'd' && root->maps[y][x + 1] == 'E' &&
			(root->collected != root->max_collect))
		return (0);
	if (c == 'w' && root->maps[y - 1][x] == 'E' &&
			(root->collected != root->max_collect))
		return (0);
	return (1);
}

void	ft_set_zero(t_game *root, int y, int x)
{
	root->maps[y][x] = '0';
	root->collected++;
}
