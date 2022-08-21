/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:41:52 by mimarque          #+#    #+#             */
/*   Updated: 2022/08/20 00:16:25 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keypress1(int key, t_allvars *a)
{
	if (key == XK_S_I)
		a->mode = 'i';
	else if (key == XK_S_O)
		a->mode = 'o';
	else if (key == XK_S_P)
		a->mode = 'p';
	else if (key == XK_S_C)
	{
		if (a->mode == 'p')
			a->mode = 'c';
		else
			a->mode = 'p';
	}
	else if (key == XK_S_A)
		a->tlx -= 1;
	else if (key == XK_S_D)
		a->tlx += 1;
	else if (key == XK_S_S)
		a->tly -= 1;
	else if (key == XK_S_W)
		a->tly += 1;
	else
		return (0);
	return (1);
}

int	keypress2(int key, t_allvars *a)
{
	if (key == XK_UP)
		a->scale += 0.1;
	else if (key == XK_DOWN)
		a->scale -= 0.1;
	else if (key == XK_LEFT)
		a->brange += 0.005;
	else if (key == XK_RIGHT)
		a->brange -= 0.005;
	else if (key == XK_S_F)
		a->rz -= 5;
	else if (key == XK_S_G)
		a->rz += 5;
	else if (key == XK_S_H)
		a->ry -= 5;
	else if (key == XK_S_J)
		a->ry += 5;
	else if (key == XK_S_K)
		a->rx -= 5;
	else if (key == XK_S_L)
		a->rx += 5;
	else
		return (0);
	return (1);
}

int	keypress3(int key, t_allvars *a)
{
	if (key == XK_S_Z)
	{
		if (a->mode != 'p')
			a->zoom += 0.5;
		else
			a->fov -= 10;
	}
	else if (key == XK_S_X)
	{
		if (a->mode != 'p')
			a->zoom -= 0.5;
		else
			a->fov += 10;
	}
	else if (key == XK_S_M)
	{
		if (a->menu == 0)
			a->menu = 1;
		else
			a->menu = 0;
	}
	return (0);
}

//for keypresses macOS uses Carbon.HIToolbox.Events.h
//and in Linux it uses X11's X11/keysymdef.h
//Note that for example "5" and "ESC"
//create the same value in X11 or Cocoa
//So using something like
//keysym == kVK_Escape || keysym == XK_Escape
//is not a good idea
//I did something unconventional here because I didn't want 
//it to go through all if elses;
int	keypress(int key, t_allvars *a)
{
	if (key == XK_ESCAPE)
		quit(a, 0);
	if (keypress1(key, a) == 0)
		if (keypress2(key, a) == 0)
			keypress3(key, a);
	return (0);
}
