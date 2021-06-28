#include "fractol.h"

static	int	ft_julia(t_settings *settings)
{
	int		i;
	double	f;
	double	re2;
	double	im2;

	settings->re.z = settings->re.c;
	settings->im.z = settings->im.c;
	i = 0;
	re2 = settings->re.z * settings->re.z;
	im2 = settings->im.z * settings->im.z;
	while (re2 + im2 <= 4
		   && i < settings->max_iter)
	{
		f = settings->re.z;
		settings->re.z = re2 - im2 + settings->k - 1;
		settings->im.z = 2.0 * f * settings->im.z + settings->k;
		re2 = settings->re.z * settings->re.z;
		im2 = settings->im.z * settings->im.z;
		i++;
	}
	return (i);
}

static	int	ft_mandelbrot(t_settings *settings)
{
	int		i;
	double	f;
	double	re2;
	double	im2;

	i = 0;
	settings->re.z = settings->re.c;
	settings->im.z = settings->im.c;
	re2 = settings->re.z * settings->re.z;
	im2 = settings->im.z * settings->im.z;
	while (re2 + im2 <= 4
		   && i < settings->max_iter)
	{
		f = settings->re.z;
		settings->re.z = re2 - im2 + settings->re.c;
		settings->im.z = 2.0 * f * settings->im.z + settings->im.c;
		re2 = settings->re.z * settings->re.z;
		im2 = settings->im.z * settings->im.z;
		i++;
	}
	return (i);
}

static	int	ft_mandelbar(t_settings *settings)
{
	int		i;
	double	f;
	double	re2;
	double	im2;

	i = 0;
	settings->re.z = settings->re.c;
	settings->im.z = settings->im.c;
	re2 = settings->re.z * settings->re.z;
	im2 = settings->im.z * settings->im.z;
	while (re2 + im2 <= 4
		   && i < settings->max_iter)
	{
		f = settings->re.z;
		settings->re.z = re2 - im2 + settings->re.c;
		settings->im.z = -2.0 * f * settings->im.z + settings->im.c;
		re2 = settings->re.z * settings->re.z;
		im2 = settings->im.z * settings->im.z;
		i++;
	}
	return (i);
}

void	ft_draw_fractal(t_settings *settings, t_mlx *mlx)
{
	int		x;
	int		y;
	double	t;

	y = -1;
	while (++y < settings->height)
	{
		x = -1;
		settings->im.c = settings->im.max - (y + settings->zoom) * \
		settings->im.factor;
		while (++x < settings->width)
		{
			settings->re.c = settings->re.min + (x + settings->zoom) * \
			settings->re.factor;
			if (settings->fractol == 0)
				t = (double)ft_julia(settings);
			else if (settings->fractol == 1)
				t = (double)ft_mandelbrot(settings);
			else if (settings->fractol == 2)
				t = (double)ft_mandelbar(settings);
			t /= (double)settings->max_iter;
			my_mlx_pixel_put(mlx, x, y, get_color(t));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
