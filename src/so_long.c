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

void	put_img(int x, int y, t_game *game, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

// TODO: Get num of rows and cols dinamically when generating map
int	init_game(t_game *game)
{
	game->person = load_img(game, PERSON);
	game->floor = load_img(game, FLOOR);
	game->wall = load_img(game, WALL);
	game->coin = load_img(game, COIN);
	game->exit = load_img(game, EXIT);
	game->map_num_cols = 13;
	game->map_num_rows = 5;
	return (0);
}

static void	print_map_aux(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		put_img(y * 32, x * 32, game, game->wall);
	if (game->map[x][y] == '0')
		put_img(y * 32, x * 32, game, game->floor);
	if (game->map[x][y] == 'P')
	{
		game->x_pos = x;
		game->y_pos = y;
		put_img(y * 32, x * 32, game, game->person);
	}
	if (game->map[x][y] == 'E')
		put_img(y * 32, x * 32, game, game->exit);
	if (game->map[x][y] == 'C')
		put_img(y * 32, x * 32, game, game->coin);
}

int	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			print_map_aux(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("\033[0;31m\n");
		ft_printf("Error\nUsage: ./so_long maps/<map>.ber\n");
		ft_printf("\033[0m");
		return (1);
	}
	game.map = generate_map(argv[1]);
	if (!game.map)
		return (0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 13 * 32, 5 * 32, "so_long");
	mlx_hook(game.win, E_KEYPRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, E_CLOSE_WINDOW, 1L << 2, close_game, &game);
	mlx_hook(game.win, 9, 1L << 21, &print_map, &game);
	mlx_loop_hook(game.mlx, &print_map, &game);
	init_game(&game);
	print_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
