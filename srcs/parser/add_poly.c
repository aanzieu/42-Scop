/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_poly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:12:12 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 14:16:38 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void	obj_set_poly(t_obj *obj, int si, int pi, const int vi[3])
{
	obj->sv[si].poly_vertx[pi].vertex_indices[0] = (unsigned int)vi[0];
	obj->sv[si].poly_vertx[pi].vertex_indices[1] = (unsigned int)vi[1];
	obj->sv[si].poly_vertx[pi].vertex_indices[2] = (unsigned int)vi[2];
}

int		obj_add_poly(t_obj *obj, int si)
{
	int pi;

	if ((pi = add_element((void **)&obj->sv[si].poly_vertx,
					&obj->sv[si].poly_count,
					&obj->sv[si].pm,
					sizeof(struct s_obj_poly))) >= 0)
		memset(obj->sv[si].poly_vertx + pi, 0, sizeof(struct s_obj_poly));
	return (pi);
}

int		obj_add_vert(t_obj *obj)
{
	int vi;

	if ((vi = add_element((void **)&obj->vv,
					&obj->poly_count,
					&obj->poly_mem, sizeof(struct s_obj_vert))) >= 0)
		memset(obj->vv + vi, 0, sizeof(struct s_obj_vert));
	return (vi);
}
