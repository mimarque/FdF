/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:23:46 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/06 04:24:15 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//instead of doing any math it pushes the values to their positions
//		int t = 00000000 00000000 000000000 aaaaaaaa
//		int r = 00000000 00000000 000000000 00rrrrrr
//		int g = 00000000 00000000 000000000 gggggggg
//		int b = 00000000 00000000 000000000 000000bb
//		t<<24 = aaaaaaaa 00000000 000000000 00000000
//		r<<16 = 00000000 00rrrrrr 000000000 00000000
//	  	g<<8  = 00000000 00000000 ggggggggg 00000000
//	  t|r|g|b = aaaaaaaa 00rrrrrr ggggggggg 000000bb
//
//the x = x & 0xFF; caps x value to a max of 255 so it doesnt overflow
int	create_trgb(int t, int r, int g, int b)
{
	r = r & 0xFF;
	g = g & 0xFF;
	b = b & 0xFF;
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
