#include "so_long.h"
#include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	handle_keypress(int keycode, t_vars *vars)
{
	printf("<%d>", keycode);
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	close_game(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

int	mouse_event(int button)
{
	// Whenever the event is triggered, print the value of button to console.
	ft_putnbr_fd(button, 1);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 900, 500, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_hook(vars.win, 17, 1L << 2, close_game, &vars);
	mlx_mouse_hook(vars.win, mouse_event, 0);
	mlx_loop(vars.mlx);
	return (0);
}
