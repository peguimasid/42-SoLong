#include <mlx.h>
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

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 900, 500, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
