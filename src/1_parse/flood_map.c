/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu <liyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:15:53 by lifan             #+#    #+#             */
/*   Updated: 2025/06/14 00:43:22 by liyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static	void	ft_fill_space(t_game *game, char **map, int y, int x)
{
	int	h;
	int	w;

	h = game->cub->height;
	w = game->cub->width;
	if (y < 0 || y >= h || x < 0 || x >= w)
		return ;
	if (map[y][x] != ' ')
		return ;
	map[y][x] = 'V';
	ft_fill_space(game, map, y + 1, x);
	ft_fill_space(game, map, y - 1, x);
	ft_fill_space(game, map, y, x + 1);
	ft_fill_space(game, map, y, x - 1);
}

static	void	ft_flood_updown(t_game *game, char **map, int h, int w)
{
	int	x;

	x = 0;
	while (x < w)
	{
		if (map[0][x] == ' ')
			ft_fill_space(game, map, 0, x);
		if (map[h - 1][x] == ' ')
			ft_fill_space(game, map, h - 1, x);
		x++;
	}
}

static	void	ft_flood_side(t_game *game, char **map, int h, int w)
{
	int	y;

	y = 0;
	while (y < h)
	{
		if (map[y][0] == ' ')
			ft_fill_space(game, map, y, 0);
		if (map[y][w - 1] == ' ')
			ft_fill_space(game, map, y, w -1);
		y++;
	}
}

//* flood the map to change the ' ' inside the wall as '1'.
void	ft_flood_map(t_game *game, char **map)
{
	int	y;
	int	x;
	int	h;
	int	w;

	h = game->cub->height;
	w = game->cub->width;
	ft_flood_updown(game, map, h, w);
	ft_flood_side(game, map, h, w);
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (map[y][x] == ' ')
				map[y][x] = '1';
			x++;
		}
	y++;
	}
}
