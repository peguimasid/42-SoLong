#include "../mlx/mlx.h"

int	main(void)
{
	void *mlx = mlx_init();
	mlx_new_window(mlx, 900, 500, "Tutorial Window");
	mlx_loop(mlx);
	return (0);
}