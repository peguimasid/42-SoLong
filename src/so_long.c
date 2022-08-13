/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:40:12 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/13 19:58:39 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	*load_img(t_game *game, char *path)
{
	int		x;
	int		y;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &x, &y);
	if (img == NULL)
	{
		ft_printf("Error\nImage not found\n");
		exit(1);
	}
	return (img);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

int	print_usage(void)
{
	ft_printf("\033[0;31m\n");
	ft_printf("Error\nUsage: ./so_long maps/<map>.ber\n");
	ft_printf("\033[0m");
	return (1);
}

// TODO: Get num of rows and cols dinamically when generating map
int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_num_cols,
			game->map_num_rows, "so_long");
	game->person = load_img(game, PERSON_RIGHT);
	game->floor = load_img(game, FLOOR);
	game->wall = load_img(game, WALL);
	game->coin = load_img(game, COIN);
	game->exit = load_img(game, EXIT);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_usage());
	game.map = generate_map(&game, argv[1]);
	if (!game.map)
		return (0);
	init_game(&game);
	print_map(&game);
	mlx_hook(game.win, E_KEYPRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, E_CLOSE_WINDOW, 1L << 2, close_game, &game);
	mlx_loop_hook(game.mlx, &print_map, &game);
	mlx_loop(game.mlx);
	return (0);
}
