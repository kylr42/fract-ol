#include "fractol.h"

int	ft_close(int code)
{
	if (code == 0)
		ft_putstr_fd(RED
			"ERROR!!!\nEx.: ./fractol [Julia / Mandelbrot]\n"RESET, 1);
	else if (code == 1)
		ft_putstr_fd(RED"ERROR!!!\nNot valid fractal name!\n"RESET, 1);
	else if (code == 53)
	{
		ft_putstr_fd(MAG"Close window! Bye-bye!!"RESET, 1);
		exit(0);
	}
	exit(1);
}

void	ft_motion(int keycode, t_settings *settings, double	tmp)
{
	if (keycode == 124)
	{
		tmp = fabs(settings->re.max - settings->re.min);
		settings->re.min += tmp * 0.01;
		settings->re.max += tmp * 0.01;
	}
	else if (keycode == 123)
	{
		tmp = fabs(settings->re.max - settings->re.min);
		settings->re.min -= tmp * 0.01;
		settings->re.max -= tmp * 0.01;
	}
	else if (keycode == 125)
	{
		tmp = fabs(settings->im.max - settings->im.min);
		settings->im.min -= tmp * 0.01;
		settings->im.max -= tmp * 0.01;
	}
	else if (keycode == 126)
	{
		tmp = fabs(settings->im.max - settings->im.min);
		settings->im.min += tmp * 0.01;
		settings->im.max += tmp * 0.01;
	}
}

int	ft_keymouse(int key, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (key == 4)
		ft_keypress(47, all);
	else if (key == 5)
		ft_keypress(43, all);
	return (0);
}

int	ft_keypress(int keycode, t_all *all)
{
	if (keycode == 53)
		ft_close(keycode);
	else if (keycode == 15)
		ft_init_params(&all->settings);
	else if (keycode == 43)
	{
		all->settings.re.factor += 0.00013;
		all->settings.im.factor += 0.00013;
	}
	else if (keycode == 47)
	{
		all->settings.re.factor -= 0.00013;
		all->settings.im.factor -= 0.00013;
	}
	else if (keycode > 122 && keycode < 127)
		ft_motion(keycode, &all->settings, 0);
	else if (keycode == 24)
		all->settings.k += 0.1;
	else if (keycode == 27)
		all->settings.k -= 0.1;
	mlx_clear_window(all->mlx.mlx, all->mlx.win);
	ft_draw_fractal(&all->settings, &all->mlx);
	return (0);
}
