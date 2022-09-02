/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:12:48 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/02 12:39:35 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	create_rgb(int r, int g, int b)
{
	return (255 << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	printf("RED = %x\n", create_rgb(0, 125, 0));
	return (0);
}
