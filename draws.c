#include "fractol.h"

int	get_color(float t)
{
	int r;
	int g;
	int b;

	r = (int)(t * 100);
	g = (int)(t * 250);
	b = (int)(t * 405);
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
	float f;
	float re2;
	float im2;
	int iteration;

	settings->re.c = 4 * ((float )(x - 200) / settings->width - 0.5);
	settings->im.c = 4 * ((float )(settings->height - y - 200) / (settings->height - 0.5));
	settings->re.z = settings->re.c;
	settings->im.z = settings->im.c;
	iteration = 0;
	re2 = settings->re.z * settings->re.z;
	im2 = settings->im.z * settings->im.z;
	while (re2 + im2 <= 4
		   && iteration < settings->max_iter)
	{
		f = settings->re.z;
		settings->re.z = re2 - im2 + settings->re.c;
		settings->im.z = 2.0 * f * settings->im.z + settings->im.c;
		re2 = settings->re.z * settings->re.z;
		im2 = settings->im.z * settings->im.z;
		iteration++;
	}
	return (iteration);
}

int		ft_mandelbrot(t_settings *settings)
{
	float f;
	float re2;
	float im2;
	int iteration;

	iteration = 0;
	settings->re.z = settings->re.c;
	settings->im.z = settings->im.c;
	re2 = settings->re.z * settings->re.z;
	im2 = settings->im.z * settings->im.z;
	while (re2 + im2 <= 4
		   && iteration < settings->max_iter)
	{
		f = settings->re.z;
		settings->re.z = re2 - im2 + settings->re.c;
		settings->im.z = 2.0 * f * settings->im.z + settings->im.c;
		re2 = settings->re.z * settings->re.z;
		im2 = settings->im.z * settings->im.z;
		iteration++;
	}
	return (iteration);
}

void	ft_draw_fractal(t_all *all)
{
	int		x;
	int		y;
	float	t;

	y = -1;
	while (++y < all->settings.height)
	{
		x = -1;
		all->settings.im.c = all->settings.im.max - y * all->settings.im.factor;
		while (++x < all->settings.width)
		{
			all->settings.re.c = all->settings.re.min + x * all->settings.re.factor;
//			if (all->settings.fractol == 0)
//				t = (float)ft_julia(&all->settings, x, y);
//			else if (all->settings.fractol == 1)
				t = (float)ft_mandelbrot(&all->settings);
			t /= (float)all->settings.max_iter;
			my_mlx_pixel_put(&all->mlx, x, y, get_color(t));
		}
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}
