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
	if (keycode == 53)
		ft_close(keycode);
	return (0);
}
