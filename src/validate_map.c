/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:30:31 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/10 20:29:57 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	contains_invalid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_strchr("PEC01", game->map[i][j]))
				return (throw_error("Invalid character found"));
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_rectangle(t_game *game)
{
	int	start_row_cols;
	int	i;
	int	current_row_cols;

	i = 0;
	start_row_cols = game->map_num_cols / SPRITE_SIZE;
	while (i < (game->map_num_rows / SPRITE_SIZE))
	{
		current_row_cols = ft_strlen(game->map[i]);
		if (current_row_cols != start_row_cols)
		{
			throw_error("Map should be rectangle");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_surrounded_by_walls(t_game *game)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	i = 0;
	j = 0;
	rows = (game->map_num_rows / SPRITE_SIZE) - 1;
	cols = (game->map_num_cols / SPRITE_SIZE) - 1;
	while (game->map[i][0] == '1' && game->map[i][cols] == '1' && i < rows)
		i++;
	while (game->map[0][j] == '1' && game->map[rows][j] == '1' && j <= cols)
		j++;
	if (i != rows || j - 1 != cols)
	{
		throw_error("Map must be surrounded by walls");
		return (0);
	}
	return (1);
}

int	has_valid_path(t_game *game, int i, int j)
{
	if (game->map_copy[i][j] == '1')
		return (0);
	if (game->map_copy[i][j] == 'E')
		return (1);
	game->map_copy[i][j] = '1';
	if (has_valid_path(game, i + 1, j))
		return (1);
	if (has_valid_path(game, i - 1, j))
		return (1);
	if (has_valid_path(game, i, j + 1))
		return (1);
	if (has_valid_path(game, i, j - 1))
		return (1);
	return (0);
}

int	is_valid_map(t_game *game)
{
	init_vars(game);
	count_map_elements(game);
	if (!is_rectangle(game))
		return (0);
	if (contains_invalid_char(game))
		return (0);
	if (!map_respect_num_of_elements(game))
		return (0);
	if (!is_surrounded_by_walls(game))
		return (0);
	if (!has_valid_path(game, game->player_x_pos, game->player_y_pos))
		return (0);
	return (1);
}
