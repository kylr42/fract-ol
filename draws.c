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

void	ft_draw_fractal(t_all *all)
{
	int x;
	int y;
	int iteration;

	double f;
	double t;

	y = 0;
	while (y < all->settings.height)
	{
		all->settings.im.c = all->settings.im.max - y * all->settings.im.factor;
		x = 0;
		while (x < all->settings.width)
		{
			all->settings.re.c = 4 * ((double)(x + 100) / all->settings.width - 0.5);
			all->settings.im.c = 4 * ((double)(all->settings.height - y - 600) / (all->settings.height - 0.5));
			all->settings.re.z = all->settings.re.c;
			all->settings.im.z = all->settings.im.c;
			iteration = 0;
			while (pow(all->settings.re.z, 2.0) + pow(all->settings.im.z, 2.0) <= 5
				&& iteration < all->settings.max_iter)
			{
				f = all->settings.re.z;
				all->settings.re.z = pow(all->settings.re.z, 2.0) - pow(all->settings.im.z, 2.0) + all->settings.re.c;
				all->settings.im.z = 2.0 * f * all->settings.im.z + all->settings.im.c;
				iteration++;
			}

			t = (double)iteration / (double)all->settings.max_iter;

			my_mlx_pixel_put(&all->mlx, x, y, get_color(t));
			x++;
		}

		y++;
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}

//void	ft_draw_fractal(t_all *all)
//{
//	int x;
//	int y;
//	int iteration;
//	int	color;
//
//	double f;
//	int r;
//	int g;
//	int b;
//	double t;
//
//	y = 0;
//	while (y < all->settings.height)
//	{
//		all->settings.im.c = all->settings.im.max - y * all->settings.im.factor;
//		x = 0;
//		while (x < all->settings.width)
//		{
//			all->settings.re.c = all->settings.re.min + x * all->settings.re.factor;
//			all->settings.re.z = all->settings.re.c;
//			all->settings.im.z = all->settings.im.c;
//			iteration = 0;
//			while (all->settings.re.z * all->settings.re.z + all->settings.im.z * all->settings.im.z <= 4
//				   && iteration < all->settings.max_iter)
//			{
//				f = all->settings.re.z;
//				all->settings.re.z = pow(all->settings.re.z, 2.0) - pow(all->settings.im.z, 2.0) + all->settings.re.c;
//				all->settings.im.z = 2.0 * f * all->settings.im.z + all->settings.im.c;
//				iteration++;
//			}
//
//			t = (double)iteration / (double)all->settings.max_iter ;
//
//			r = (int)(10 * (1 - t) * pow(t, 2) * 255);
//			g = (int)(15 * pow((1 - t), 3) * pow(t, 3) * 255);
//			b = (int)(7 * pow((1 - t), 2) * t * 180);
//
//			color = get_color((int) t, r, g, b);
//			my_mlx_pixel_put(&all->mlx, x, y, color);
//
//
//			x++;
//		}
//		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
//		y++;
//	}
//}