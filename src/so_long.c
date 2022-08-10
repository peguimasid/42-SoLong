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

int	init_img(t_game *game)
{
	game->person = load_img(game, PERSON);
	game->floor = load_img(game, FLOOR);
	game->x_pos = 0;
	game->y_pos = 0;
	for (int i = 0; i < 28; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			put_img(i * 32, j * 32, game, game->floor);
		}
	}
	put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	printf("<%d>", keycode);
	if (keycode == 53)
		close_game(game);
	if (keycode == KEY_UP)
	{
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->floor);
		if (game->y_pos > 0)
			game->y_pos--;
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	}
	if (keycode == KEY_DOWN)
	{
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->floor);
		if (game->y_pos < 15)
			game->y_pos++;
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	}
	if (keycode == KEY_LEFT)
	{
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->floor);
		if (game->x_pos > 0)
			game->x_pos--;
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	}
	if (keycode == KEY_RIGHT)
	{
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->floor);
		if (game->x_pos < 27)
			game->x_pos++;
		put_img(game->x_pos * 32, game->y_pos * 32, game, game->person);
	}
	return (0);
}

int	mouse_event(int button)
{
	ft_putnbr_fd(button, 1);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 895, 510, "Hello world!");
	mlx_hook(game.win, E_KEYPRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, E_CLOSE_GAME, 1L << 2, close_game, &game);
	mlx_mouse_hook(game.win, mouse_event, 0);
	init_img(&game);
	mlx_loop(game.mlx);
	return (0);
}
