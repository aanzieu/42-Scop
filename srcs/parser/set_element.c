/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:34:29 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 14:33:55 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void	obj_set_vert_v(t_obj *obj, int vi, const float v[3])
{
	obj->vv[vi].v[0] = v[0];
	obj->vv[vi].v[1] = v[1];
	obj->vv[vi].v[2] = v[2];
}

void	obj_set_vert_t(t_obj *obj, int vi, const float t[2])
{
	obj->vv[vi].t[0] = t[0];
	obj->vv[vi].t[1] = t[1];
}

void	obj_set_vert_n(t_obj *obj, int vi, const float n[3])
{
	obj->vv[vi].n[0] = n[0];
	obj->vv[vi].n[1] = n[1];
	obj->vv[vi].n[2] = n[2];
}
