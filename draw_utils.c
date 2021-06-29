#include "fractol.h"

int	get_color(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(t * 100);
	g = (int)(t * 250);
	b = (int)(t * 405);
	return (0 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
