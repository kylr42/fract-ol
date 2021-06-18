#include "fractol.h"

int	get_color(double t)
{
	int r;
	int g;
	int b;

	r = (int)(10 * (1 - t) * pow(t, 2) * 255);
	g = (int)(15 * pow((1 - t), 3) * pow(t, 3) * 255);
	b = (int)(7 * pow((1 - t), 2) * t * 180);
	return ((int)t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_julia(t_settings *settings, int x, int y)
{
	double f;
	int iteration;

	settings->re.c = ((double)x/ settings->width - 0.5);
	settings->im.c = ((double)(settings->height - y) / (settings->height - 0.5));
	settings->re.z = settings->re.c;
	settings->im.z = settings->im.c;
	iteration = 0;
	while (pow(settings->re.z, 2.0) + pow(settings->im.z, 2.0) <= 5
		   && iteration < settings->max_iter)
	{
		f = settings->re.z;
		settings->re.z = pow(settings->re.z, 2.0) - pow(settings->im.z, 2.0) + settings->re.c;
		settings->im.z = 2.0 * f * settings->im.z + settings->im.c;
		iteration++;
	}
	return (iteration);
}

int		ft_mandelbrot(t_settings *settings)
{
	double f;
	int iteration;

	iteration = 0;
	settings->re.z = settings->re.c;
	settings->im.z = settings->im.c;
	while (pow(settings->re.z, 2.0) + pow(settings->re.z, 2.0) <= 4
		   && iteration < settings->max_iter)
	{
		f = settings->re.z;
		settings->re.z = pow(settings->re.z, 2.0) - pow(settings->im.z, 2.0) + settings->re.c;
		settings->im.z = 2.0 * f * settings->im.z + settings->im.c;
		iteration++;
	}
	return (iteration);
}

void	ft_draw_fractal(t_all *all)
{
	int		x;
	int		y;
	double	t;

	y = -1;
	while (++y < all->settings.height)
	{
		x = 0;
		all->settings.im.c = all->settings.im.max - y * all->settings.im.factor;
		while (x < all->settings.width)
		{
			all->settings.re.c = all->settings.re.min + x * all->settings.re.factor;
			t = (double)ft_julia(&all->settings, x, y);
//			t = (double)ft_mandelbrot(&all->settings);
			t /= (double)all->settings.max_iter;
			my_mlx_pixel_put(&all->mlx, x++, y, get_color(t));
		}
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}
