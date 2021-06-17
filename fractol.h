#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define RESET "\x1B[0m"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_complex
{
	double	c;
	double	z;
	double	min;
	double	max;
	double	factor;
}	t_complex;

typedef struct s_settings
{
	t_complex		re;
	t_complex		im;
	int				width;
	int				height;
	int				fractol;
	int 			max_iter;
}	t_settings;

typedef struct s_all
{
	t_mlx		mlx;
	t_settings	settings;
}	t_all;


void	ft_close(int code);
void	ft_draw_fractal(t_all *all);
int		ft_keypress(int keycode, t_all *all);


#endif //FRACTOL_H
