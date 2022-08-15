/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:30:31 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/15 14:26:15 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game)
{
	game->player.coins = 0;
	game->finish_game = 0;
	game->moves = 0;
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
	init_map(game);
	if (contains_invalid_char(game))
		return (0);
	return (1);
}
