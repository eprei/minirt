/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:46:00 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/20 10:09:45 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	check_input_pos(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '.' || (s[i] >= '0' && s[i] <= '9') || s[i] == ',' || \
					s[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	check_input_p_p(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '.' || (s[i] >= '0' && s[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	check_input_col(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == ',' || (s[i] >= '0' && s[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}
