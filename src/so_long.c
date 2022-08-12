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
		printf("Error\nImage not found\n");
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
	game->map_num_cols = 28;
	game->map_num_rows = 16;
	game->x_pos = 1;
	game->y_pos = 1;
	return (0);
}

// TODO: Make function to get map send as param and build it
void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 16)
	{
		put_img(i * 32, j * 32, game, game->wall);
		j++;
	}
	j = 0;
	while (i < game->map_num_cols)
	{
		put_img(i * 32, j * 32, game, game->wall);
		i++;
	}
	i = 27;
	while (j < game->map_num_rows)
	{
		put_img(i * 32, j * 32, game, game->wall);
		j++;
	}
	j = 15;
	i = 0;
	while (i < game->map_num_cols)
	{
		put_img(i * 32, j * 32, game, game->wall);
		i++;
	}
	i = 1;
	j = 1;
	while (i < game->map_num_cols - 1)
	{
		j = 1;
		while (j < 15)
		{
			put_img(i * 32, j * 32, game, game->floor);
			j++;
		}
		i++;
	}
	put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

int	main(void)
{
	t_game	game;
	int		fd;

	fd = open("maps/map1.ber", O_RDONLY);
	printf("%s", get_next_line(fd));
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 28 * 32, 16 * 32, "so_long");
	mlx_hook(game.win, E_KEYPRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, E_CLOSE_WINDOW, 1L << 2, close_game, &game);
	init_game(&game);
	print_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
