#include "so_long.h"
#include <stdio.h>

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
	return (0);
}

int	mouse_event(int button)
{
	// Whenever the event is triggered, print the value of button to console.
	ft_putnbr_fd(button, 1);
	return (0);
}

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

int	init_person(t_game *game)
{
	game->person = load_img(game, PERSON);
	return (0);
}

void	put_img(int x, int y, t_game *game, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 900, 500, "Hello world!");
	mlx_hook(game.win, E_KEYPRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, E_CLOSE_GAME, 1L << 2, close_game, &game);
	mlx_mouse_hook(game.win, mouse_event, 0);
	init_person(&game);
	put_img(50, 50, &game, game.person);
	mlx_loop(game.mlx);
	return (0);
}
