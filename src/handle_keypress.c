/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:35:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/17 12:16:12 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	print_steps(t_game *game)
{
	game->moves_count++;
	printf("Steps: %d\n", game->moves_count);
}

int	can_move(t_game *game, int x, int y)
{
	int	collect_all_coins;

	collect_all_coins = game->player.coins == game->collectibles_count;
	if (game->map[x][y] == '1')
		return (0);
	if (game->map[x][y] == 'E' && !collect_all_coins)
		return (0);
	return (1);
}

void	move(int keycode, t_game *game)
{
	int	px;
	int	py;

	px = game->player.x_pos;
	py = game->player.y_pos;
	if (keycode == KEY_UP)
	{
		if (!can_move(game, px - 1, py))
			return ;
		print_steps(game);
		game->map[px][py] = '0';
		px--;
		game->map[px][py] = 'P';
	}
	if (keycode == KEY_DOWN)
	{
		if (!can_move(game, px + 1, py))
			return ;
		print_steps(game);
		game->map[px][py] = '0';
		px++;
		game->map[px][py] = 'P';
	}
	if (keycode == KEY_LEFT)
	{
		if (!can_move(game, px, py - 1))
			return ;
		print_steps(game);
		mlx_destroy_image(game->mlx, game->person);
		game->person = load_img(game, PERSON_LEFT);
		game->map[px][py] = '0';
		py--;
		game->map[px][py] = 'P';
	}
	if (keycode == KEY_RIGHT)
	{
		if (!can_move(game, px, py + 1))
			return ;
		print_steps(game);
		mlx_destroy_image(game->mlx, game->person);
		game->person = load_img(game, PERSON_RIGHT);
		game->map[px][py] = '0';
		py++;
		game->map[px][py] = 'P';
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		return (close_game(game));
	move(keycode, game);
	return (0);
}
