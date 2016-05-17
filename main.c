/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:57:26 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/17 15:50:30 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "limits.h"

void my_pixel_put_image(char *data, int size_line, int bpp, int x, int y)
{
	data[x * bpp / 8 + size_line * y] = 200;
}

int main()
{
	void *mlx;
	void *win;
	void *img;
	char *data;
	int	 bpp = 1;
	int		size_line = 400;
	int		endian = 1;

	mlx = mlx_init();
	win = mlx_new_window(mlx, size_line, size_line, "mlx 42");
	img = mlx_new_image(mlx, size_line, size_line);
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

	int x = 0;
	int y = 0;
	while (y < size_line)
	{
		while (x < size_line)
		{
			my_pixel_put_image(data, size_line, bpp, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img, 200 , 200);
	mlx_loop(mlx);
	return (0);
}
