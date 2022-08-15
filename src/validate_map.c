/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:30:31 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/15 15:11:20 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game *game)
{
	game->player.coins = 0;
	game->finish_game = 0;
	game->collectibles_count = 0;
	game->players_count = 0;
	game->exits_count = 0;
	game->moves_count = 0;
}

void	count_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collectibles_count++;
			if (game->map[i][j] == 'E')
				game->exits_count++;
			if (game->map[i][j] == 'P')
				game->players_count++;
			j++;
		}
		i++;
	}
}

int	map_respect_num_of_specific_elements(t_game *game)
{
	if (game->players_count != 1 || game->exits_count != 1
		|| game->collectibles_count < 1)
	{
		throw_error("Exactly one exit and player and at least one coin");
		return (0);
	}
	return (1);
}

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
			if (game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != '0'
				&& game->map[i][j] != '1')
			{
				return (throw_error("Invalid character found"));
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_map(t_game *game)
{
	init_vars(game);
	if (contains_invalid_char(game))
		return (0);
	count_map_elements(game);
	if (!map_respect_num_of_specific_elements(game))
		return (0);
	return (1);
}
