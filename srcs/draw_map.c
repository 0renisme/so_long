/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:32:53 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/24 14:37:32 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] == '0')
				draw_on_img(&data->mlx, &data->floor, y * 64, x * 64);
			else if (data->map.map[x][y] == 'C')
				draw_on_img(&data->mlx, &data->collectible.screen_c,
					y * 64, x * 64);
			else if (data->map.map[x][y] == 'E')
				draw_on_img(&data->mlx, &data->exit.screen_e, y * 64, x * 64);
			else
				draw_on_img(&data->mlx, &data->wall, y * 64, x * 64);
			y++;
		}
		x++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win,
		data->mlx.img, 0, 0);
}

void	draw_on_img(t_screen *img, t_screen *s_img, int startX, int startY)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < 64)
	{
		draw.y = 0;
		while (draw.y < 64)
		{
			draw.r_x = (float)draw.x / (float)64;
			draw.r_y = (float)draw.y / (float)64;
			draw.pos_x = draw.r_x * s_img->width;
			draw.pos_y = draw.r_y * s_img->height;
			draw.color = get_pixel(s_img, draw.pos_x, draw.pos_y);
			draw.p_data_x = startX + draw.x;
			draw.p_data_y = startY + draw.y;
			if (draw.color != 0x0)
				set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}

void	init_player(t_data *data)
{
	data->player.right1 = load_image(data->mlx.init,
			"assets/textures/mario1.xpm");
	data->player.right2 = load_image(data->mlx.init,
			"assets/textures/mario2.xpm");
	data->player.right3 = load_image(data->mlx.init,
			"assets/textures/mario3.xpm");
	if (!data->player.right1.img || !data->player.right2.img
		|| !data->player.right3.img)
	{
		error(FAIL, "Error during image loading.");
		free_all(data);
	}
}

void	draw_player(t_data *data)
{
	if (data->time % 3 == 0)
		draw_on_img(&data->mlx, &(data->player.right1),
			data->player.pos.y * 64, data->player.pos.x * 64);
	else if (data->time % 2 == 0)
		draw_on_img(&data->mlx, &(data->player.right2),
			data->player.pos.y * 64, data->player.pos.x * 64);
	else
		draw_on_img(&data->mlx, &(data->player.right2),
			data->player.pos.y * 64, data->player.pos.x * 64);
}
