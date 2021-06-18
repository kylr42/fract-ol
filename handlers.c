#include "fractol.h"

void	ft_close(int code)
{
	if (code == 0)
		ft_putstr_fd(RED"ERROR!!! \nEx.: ./fractol [Julia / Mandelbrot]\n"RESET, 1);
	else if (code == 1)
		ft_putstr_fd(RED"ERROR!!!\nNot valid fractal name!\n"RESET, 1);
	else if (code == 53)
	{
		ft_putstr_fd(MAG"Close window! Bye-bye!!"RESET, 1);
		exit(0);
	}
	exit(1);
}


int		ft_keypress(int keycode, t_all *all)
{
	double tmp;

	printf("%d\n", keycode);
	if (keycode == 53) // Esc
		ft_close(keycode);
	else if (keycode == 123) // <
	{
		tmp = fabs(all->settings.re.max - all->settings.re.min);
		all->settings.re.min -= tmp * 0.05;
		all->settings.re.max -= tmp * 0.05;
	}
	else if (keycode == 124) // >
	{
		tmp = fabs(all->settings.re.max - all->settings.re.min);
		all->settings.re.min += tmp * 0.05;
		all->settings.re.max += tmp * 0.05;
	}
	else if (keycode == 126) // ^
	{
		tmp = fabs(all->settings.im.max - all->settings.im.min);
		all->settings.im.min += tmp * 0.05;
		all->settings.im.max += tmp * 0.05;
	}
	else if (keycode == 125) // !^
	{
		tmp = fabs(all->settings.im.max - all->settings.im.min);
		all->settings.im.min -= tmp * 0.05;
		all->settings.im.max -= tmp * 0.05;
	}
	mlx_clear_window(all->mlx.mlx, all->mlx.win);
	ft_draw_fractal(all);
	return (0);
}
