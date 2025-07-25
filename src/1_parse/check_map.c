/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yren <yren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:29:12 by lifan             #+#    #+#             */
/*   Updated: 2025/07/11 16:45:46 by yren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//* To be sure that the O and NWES are not on the boders
//* Or they are not connected to an espace.
static	void	ft_check_wall(t_game *game, char **map, int y, int x)
{
	int	reso;

	reso = 0;
	if (y == 0 || (y > 0 && map[y - 1][x] == 'V'))
		reso = FAIL;
	if (!map[y + 1] || (map[y + 1] && map[y + 1][x] == 'V'))
		reso = FAIL;
	if (x == 0 || (x > 0 && map[y][x - 1] == 'V'))
		reso = FAIL;
	if (map[y][x + 1] == '\0' || map[y][x + 1] == 'V')
		reso = FAIL;
	if (reso == FAIL)
		ft_error_close(game, "Wall of the map is not closed");
}

//* Must have, and only have one player.
//* take the east as start of the circle, ESWN, clock.
static	void	ft_set_player(t_game *game, char c, int y, int x)
{
	if (game->player->dir || game->player->init_x != -1 \
		|| game->player->init_y != -1)
		ft_error_close(game, "There are more than one player position.");
	else
	{
		game->player->init_x = x;
		game->player->init_y = y;
		if (game->player->init_x < 0 || game->player ->init_y < 0)
			ft_error_close(game, "No valide player.");
		game->player->dir = c;
		if (c == 'E')
			game->player->angle = 0;
		if (c == 'W')
			game->player->angle = PI;
		if (c == 'N')
			game->player->angle = 3 * PI / 2;
		if (c == 'S')
			game->player->angle = PI / 2;
		game->cub->copy[y][x] = '0';
		ft_check_wall(game, game->cub->copy, y, x);
	}
}

//* Check that all walls are closed (No free '0' or 'NWES')
//* Only have valide characters.
int	ft_check_map(t_game *game, char **map)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				ft_check_wall(game, map, y, x);
			else if (ft_find(map[y][x], "NEWS") == 1)
				ft_set_player(game, map[y][x], y, x);
			else if (map[y][x] != 'V' && map[y][x] != '1')
				return (ft_error("There are invalid symbols in the map."), \
							FAIL);
			x++;
		}
		y++;
	}
	if (game->player->init_x == -1 || game->player->init_y == -1 \
		|| game->player->dir == '\0')
		return (ft_error("Can't set the player's position."), FAIL);
	return (0);
}
