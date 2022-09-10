/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:35:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/10 20:29:26 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_player_image(t_game *game, char *new_image)
{
	mlx_destroy_image(game->mlx, game->person);
	game->person = load_img(game, new_image);
}

int	can_move(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		return (0);
	if (game->map[x][y] == 'E' && game->collectibles_count != 0)
		return (0);
	return (1);
}

void	move_player(t_game *game, int new_x_pos, int new_y_pos)
{
	int	prev_x_pos;
	int	prev_y_pos;

	prev_x_pos = game->player.x_pos;
	prev_y_pos = game->player.y_pos;
	if (!can_move(game, new_x_pos, new_y_pos))
		return ;
	if (game->map[new_x_pos][new_y_pos] == 'C')
		game->collectibles_count--;
	if (game->map[new_x_pos][new_y_pos] == 'E')
		game->finish_game = 1;
	game->player.x_pos = new_x_pos;
	game->player.y_pos = new_y_pos;
	game->map[prev_x_pos][prev_y_pos] = '0';
	if (!game->finish_game)
		game->map[new_x_pos][new_y_pos] = 'P';
	print_steps(game);
	if (game->finish_game)
		display_finish_game_message();
}

void	move(int keycode, t_game *game)
{
	if (game->finish_game)
		return ;
	if (keycode == KEY_UP)
	{
		change_player_image(game, PERSON_BACK);
		move_player(game, game->player.x_pos - 1, game->player.y_pos);
	}
	if (keycode == KEY_DOWN)
	{
		change_player_image(game, PERSON_FRONT);
		move_player(game, game->player.x_pos + 1, game->player.y_pos);
	}
	if (keycode == KEY_LEFT)
	{
		change_player_image(game, PERSON_LEFT);
		move_player(game, game->player.x_pos, game->player.y_pos - 1);
	}
	if (keycode == KEY_RIGHT)
	{
		change_player_image(game, PERSON_RIGHT);
		move_player(game, game->player.x_pos, game->player.y_pos + 1);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		return (close_game(game));
	move(keycode, game);
	return (0);
}
