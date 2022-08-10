/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:35:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/10 15:04:12 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	handle_keypress(int keycode, t_game *game)
{
	printf("<%d>", keycode);
	if (keycode == 53)
		close_game(game);
	if (keycode == KEY_UP)
	{
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->floor);
		if (game->y_pos > 1)
			game->y_pos--;
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	}
	if (keycode == KEY_DOWN)
	{
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->floor);
		if (game->y_pos < 14)
			game->y_pos++;
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	}
	if (keycode == KEY_LEFT)
	{
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->floor);
		if (game->x_pos > 1)
			game->x_pos--;
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	}
	if (keycode == KEY_RIGHT)
	{
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->floor);
		if (game->x_pos < 26)
			game->x_pos++;
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	}
	return (0);
}