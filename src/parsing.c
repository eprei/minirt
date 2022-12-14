/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:22:34 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/21 10:25:32 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_a_light(t_scene *scene)
{
	if (scene->l_amb.type != -1)
		ft_error("Ambiant light already configured", scene, 5);
	if (tablen(scene->line) != 3)
		ft_error("Ambiant light arguments not correct", scene, 5);
	scene->l_amb.type = 0;
	scene->res = NULL;
	if (!check_input_p_p(scene->line[1]))
		ft_error("Ambiant light ratio not correct", scene, 5);
	scene->l_amb.intensity = atod(scene->line[1], scene, 0, 1);
	if (!check_input_col(scene->line[2]))
		ft_error("Ambiant light color not correct", scene, 5);
	scene->l_amb.color = atod_vc(scene->line[2], scene, 0, 255);
}

void	parse_elem(t_scene *scene)
{
	if (ft_strncmp(scene->line[0], "A", 2) == 0)
		init_a_light(scene);
	else if (ft_strncmp(scene->line[0], "C", 2) == 0)
		init_camera(scene);
	else if (ft_strncmp(scene->line[0], "L", 2) == 0)
		init_light(scene);
	else if (ft_strncmp(scene->line[0], "sp", 3) == 0)
		init_sphere(scene);
	else if (ft_strncmp(scene->line[0], "pl", 3) == 0)
		init_plan(scene);
	else if (ft_strncmp(scene->line[0], "cy", 3) == 0)
		init_cyl(scene);
	else
		ft_error("Unknown element in the file !", scene, 5);
}

void	read_file(t_scene *scene)
{
	size_t	n;

	scene->l = get_next_line(scene->fd);
	n = ft_strlen(scene->l);
	if (n > 0 && scene->l[n - 1] == '\n')
		scene->l[n - 1] = '\0';
	while (n != 0)
	{
		if (n > 1)
		{
			scene->line = ft_split(scene->l, ' ');
			if (scene->line)
				parse_elem(scene);
			tab_free_full(&scene->line);
		}
		free(scene->l);
		scene->l = get_next_line(scene->fd);
		n = ft_strlen(scene->l);
		if (n > 0 && scene->l[n - 1] == '\n')
			scene->l[n - 1] = '\0';
	}
	close(scene->fd);
}
