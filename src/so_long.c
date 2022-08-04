#include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	build_square(t_data img)
{
	int	i;
	int	j;
	int	mask;

	i = 0;
	j = 0;
	mask = 225;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, i + mask, j + mask, 0xFF0000);
		i++;
	}
	while (j < 100)
	{
		my_mlx_pixel_put(&img, i + mask, j + mask, 0xFFFF00);
		j++;
	}
	while (i >= 0)
	{
		my_mlx_pixel_put(&img, i + mask, j + mask, 0x00FF00);
		i--;
	}
	while (j >= 0)
	{
		my_mlx_pixel_put(&img, i + mask, j + mask, 0x00FF);
		j--;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 900, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 900, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	build_square(img);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
