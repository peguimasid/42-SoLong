/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:40:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/10 20:29:50 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (throw_error("Usage: ./so_long maps/<map>.ber"));
	game.map = generate_map(&game, argv[1]);
	if (!game.map)
		return (0);
	if (!is_valid_map(&game))
	{
		map_free(game.map);
		return (throw_error("Please provide a valid map"));
	}
	set_game_config(&game);
	print_map(&game);
	mlx_hook(game.win, E_KEYPRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, E_CLOSE_WINDOW, 1L << 2, close_game, &game);
	mlx_loop_hook(game.mlx, &print_map, &game);
	mlx_loop(game.mlx);
	return (0);
}
