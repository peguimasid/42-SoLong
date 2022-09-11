/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:35:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/11 10:24:59 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_vars(t_game *game)
{
	game->finish_game = 0;
	game->collectibles_count = 0;
	game->reachable_collectibles_count = 0;
	game->players_count = 0;
	game->exits_count = 0;
	game->reachable_exits_count = 0;
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
			{
				game->player.x_pos = i;
				game->player.y_pos = j;
				game->players_count++;
			}
			j++;
		}
		i++;
	}
}

int	map_respect_num_of_elements(t_game *game)
{
	if (game->players_count != 1 || game->exits_count != 1
		|| game->collectibles_count < 1)
	{
		throw_error("Exactly one exit and player and at least one coin");
		return (0);
	}
	return (1);
}

void	count_map_reachable_elements(t_game *game, int px, int py)
{
	if (game->map_copy[px][py] == '1')
		return ;
	if (game->map_copy[px][py] == 'E')
		game->reachable_exits_count++;
	if (game->map_copy[px][py] == 'C')
		game->reachable_collectibles_count++;
	game->map_copy[px][py] = '1';
	count_map_reachable_elements(game, px + 1, py);
	count_map_reachable_elements(game, px - 1, py);
	count_map_reachable_elements(game, px, py + 1);
	count_map_reachable_elements(game, px, py - 1);
}
