/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:39:11 by lifan             #+#    #+#             */
/*   Updated: 2025/06/27 14:34:16 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_error(char *str)
{
	ft_putstr_fd(RED "ERROR\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n" RESET, 2);
}

//* Close when enconter an error.
void	ft_error_close(t_game *game, char *str)
{
	ft_error(str);
	ft_clean(game);
	exit (FAIL);
}

//* without error, exit when click the X.
int	ft_close(t_game *game)
{
	ft_clean(game);
	exit (0);
}
