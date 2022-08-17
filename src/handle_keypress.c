/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:35:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/17 13:28:38 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	print_steps(t_game *game)
{
	game->moves_count++;
	ft_printf("Steps: %d\n", game->moves_count);
}

int	collect_all_coins(t_game *game)
{
	return (game->collectibles_count == 0);
}

int	can_move(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		return (0);
	if (game->map[x][y] == 'E' && !collect_all_coins(game))
		return (0);
	if (game->map[x][y] == 'C')
		game->collectibles_count--;
	if (game->map[x][y] == 'E' && collect_all_coins(game))
		game->finish_game = 1;
	return (1);
}

void	move(int keycode, t_game *game)
{
	int	px;
	int	py;

	px = game->player.x_pos;
	py = game->player.y_pos;
	if (game->finish_game)
		return ;
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
