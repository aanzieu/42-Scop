/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_indices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:10:43 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 14:30:34 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static int	read_poly_indices(const char *line, int *vertex_i,
		int *texture_i, int *normal_i)
{
	int n;

	*vertex_i = 0;
	*texture_i = 0;
	*normal_i = 0;
	if (sscanf(line, "%d/%d/%d%n", vertex_i, texture_i, normal_i, &n) >= 3)
		return (n);
	if (sscanf(line, "%d/%d%n", vertex_i, texture_i, &n) >= 2)
		return (n);
	if (sscanf(line, "%d//%d%n", vertex_i, normal_i, &n) >= 2)
		return (n);
	if (sscanf(line, "%d%n", vertex_i, &n) >= 1)
		return (n);
	return (0);
}

static void	set_poly_types_indices(t_obj *obj, const int i[3], int vi)
{
	int ti;

	if (0 <= i[0] && i[0] < obj->vv_curr)
		obj_set_vert_v(obj, vi, obj->v_vertex[i[0]].v);
	if (0 <= i[2] && i[2] < obj->vn_curr)
		obj_set_vert_n(obj, vi, obj->v_normal[i[2]].v);
	if (0 <= i[1] && i[1] < obj->vt_curr)
		obj_set_vert_t(obj, vi, obj->v_texture[i[1]].v);
	if (i[1] < 0)
	{
		if ((ti = add_texture(obj)) >= 0)
		{
			random_vt(obj, vi, obj->v_texture[ti].v);
			obj->v_texture[ti].index_v2 = -1;
		}
	}
}

static int	set_poly_indices(t_obj *obj, const int i[3])
{
	int x;
	int y;
	int vi;

	if ((x = add_indice(obj)) >= 0)
	{
		obj->v_indice[x].vertex_i = i[0];
		obj->v_indice[x].texture_i = i[1];
		obj->v_indice[x].normal_i = i[2];
		y = search_index_set(obj, i, x);
		if ((y < 0) && (vi = obj_add_vert(obj)) >= 0)
		{
			obj->v_vertex[i[0]].index_vec3 = x;
			obj->v_indice[x].ii = -1;
			obj->v_indice[x].vi = vi;
			set_poly_types_indices(obj, i, vi);
		}
		return (1);
	}
	return (0);
}

static int	read_poly_vertices(const char *line, t_obj *obj)
{
	int indice[3];
	int dc;
	int ic;

	ic = 0;
	while ((dc = read_poly_indices(line, &indice[0], &indice[1], &indice[2])))
	{
		indice[0] += (indice[0] < 0) ? obj->vv_curr : -1;
		indice[1] += (indice[1] < 0) ? obj->vt_curr : -1;
		indice[2] += (indice[2] < 0) ? obj->vn_curr : -1;
		ic += set_poly_indices(obj, indice);
		line += dc;
	}
	return (ic);
}

void		read_f(const char *line, t_obj *obj, int si)
{
	int index;
	int ic;

	index = obj->vi_curr;
	ic = read_poly_vertices(line, obj);
	triangulate_indices(obj, ic, index, si);
}
