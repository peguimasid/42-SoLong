/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:35:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/13 17:12:53 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	handle_keypress(int keycode, t_game *game)
{
	int	px;
	int	py;

	px = game->player.x_pos;
	py = game->player.y_pos;
	if (keycode == ESC)
		close_game(game);
	if (keycode == KEY_UP)
	{
		game->map[px][py] = '0';
		px--;
		game->map[px][py] = 'P';
	}
	if (keycode == KEY_DOWN)
	{
		game->map[px][py] = '0';
		px++;
		game->map[px][py] = 'P';
	}
	if (keycode == KEY_LEFT)
	{
		game->map[px][py] = '0';
		py--;
		game->map[px][py] = 'P';
	}
	if (keycode == KEY_RIGHT)
	{
		game->map[px][py] = '0';
		py++;
		game->map[px][py] = 'P';
	}
	return (0);
}
