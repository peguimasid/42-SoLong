/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:35:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/15 15:03:05 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->person);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	map_free(game->map);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	px;
	int	py;

	px = game->player.x_pos;
	py = game->player.y_pos;
	if (keycode == ESC)
		return (close_game(game));
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
		mlx_destroy_image(game->mlx, game->person);
		game->person = load_img(game, PERSON_LEFT);
		game->map[px][py] = '0';
		py--;
		game->map[px][py] = 'P';
	}
	if (keycode == KEY_RIGHT)
	{
		mlx_destroy_image(game->mlx, game->person);
		game->person = load_img(game, PERSON_RIGHT);
		game->map[px][py] = '0';
		py++;
		game->map[px][py] = 'P';
	}
	// TODO: Make this happen just when press "ASWD" keys
	game->moves_count++;
	ft_printf("Steps = %d\n", game->moves_count);
	return (0);
}
