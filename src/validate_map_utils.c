/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:35:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/15 19:37:49 by gmasid           ###   ########.fr       */
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
