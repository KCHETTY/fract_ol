/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:10:01 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/04 08:20:23 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int mouse_move)
{
	printf("%d\n", mouse_move);

	if (mouse_move == SCROLL_UP)
		g->fract.zoom += 0.1;
	if (mouse_move == SCROLL_DOWN)	
		g->fract.zoom -= 0.1;

	return (0);
}
