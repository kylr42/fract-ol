#include "fractol.h"

static	int		ft_parse(t_all *all, char *arg)
{
	if (ft_strncmp("Julia", arg, 100) == 0 ||
			ft_strncmp("julia", arg, 100) == 0)
		all->settings.fractol = 0;
	else if (ft_strncmp("Mandelbrot", arg, 100) == 0 ||
			 ft_strncmp("Mandelbrot", arg, 100) == 0)
		all->settings.fractol = 1;
	else
		return (-1);
	return (0);
}

static	void	ft_init_params(t_settings *settings)
{
	settings->width = 1000;
	settings->height = 1000;
	settings->max_iter = 32;
	settings->re.min = -2.0;
	settings->re.max = 2.0;
	settings->im.min = -2.0;
	settings->im.max = settings->im.min + (settings->re.max - settings->re.min) *
										  settings->height / settings->width;
	settings->re.factor = (settings->re.max - settings->re.min) / (settings->width - 1);
	settings->im.factor = (settings->im.max - settings->im.min) / (settings->height - 1);
}


static	void	ft_init_window(t_all *all)
{
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx,
								  all->settings.width, all->settings.height, "Fractol");
	all->mlx.img = mlx_new_image(all->mlx.mlx, 1000, 1000);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img, &all->mlx.bits_per_pixel, &all->mlx.line_length,
								 &all->mlx.endian);
	mlx_hook(all->mlx.win, 2, 1L<<0, ft_keypress, all);
}

int main(int argc, char *argv[])
{
	t_all all;

	if (argc != 2)
		ft_close(0);
	else if (ft_parse(&all, argv[1]))
		ft_close(1);
	ft_init_params(&all.settings);
	ft_init_window(&all);
	ft_draw_fractal(&all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
