/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:16:11 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 13:59:14 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void		obj_get_vert_v(t_obj *obj, int vi, float *v)
{
	v[0] = obj->vv[vi].v[0];
	v[1] = obj->vv[vi].v[1];
	v[2] = obj->vv[vi].v[2];
}

void		obj_get_vert_t(t_obj *obj, int vi, float *t)
{
	t[0] = obj->vv[vi].t[0];
	t[1] = obj->vv[vi].t[1];
}

void		obj_get_vert_n(t_obj *obj, int vi, float *n)
{
	n[0] = obj->vv[vi].n[0];
	n[1] = obj->vv[vi].n[1];
	n[2] = obj->vv[vi].n[2];
}
