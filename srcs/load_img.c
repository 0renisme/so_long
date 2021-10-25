/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:44:23 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/24 14:46:51 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_screen	load_image(void *mlx, char *path)
{
	t_screen	screen;

	screen.img = mlx_xpm_file_to_image(mlx, path,
			&(screen.width), &(screen.height));
	if (!screen.img)
		return (screen);
	screen.addr = mlx_get_data_addr(screen.img, &screen.bits_per_pixel,
			&screen.line_length, &screen.endian);
	return (screen);
}

void	init_collectibles(t_data *data)
{
	data->collectible.screen_c = load_image(data->mlx.init,
			"assets/textures/piece.xpm");
	if (!data->collectible.screen_c.img)
	{
		error(FAIL, "Error during image loading.");
		free_all(data);
	}
}

void	init_exits(t_data *data)
{
	data->exit.screen_e = load_image(data->mlx.init,
			"assets/textures/flag.xpm");
	if (!(data->exit.screen_e.img))
	{
		error(FAIL, "Error during image loading.");
		free_all(data);
	}
}

void	init_wall(t_data *data)
{
	data->wall = load_image(data->mlx.init,
			"assets/textures/block.xpm");
	if (!data->wall.img)
	{
		error(FAIL, "Error during image loading.");
		free_all(data);
	}
}

void	init_floor(t_data *data)
{
	data->floor = load_image(data->mlx.init,
			"assets/textures/blue.xpm");
	if (!data->floor.img)
	{
		error(FAIL, "Error during image loading.");
		free_all(data);
	}
}
