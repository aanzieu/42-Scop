/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:28:54 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 13:54:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

int		add_element(void **vec, int *curr, int *mem, size_t s)
{
	int		m;
	void	*v;

	m = (*mem > 0) ? *mem * 2 : 2;
	if (*mem > *curr)
		return (*curr)++;
	else if ((v = realloc(*vec, s * m)))
	{
		*vec = v;
		*mem = m;
		return (*curr)++;
	}
	else
		return (-1);
}

int		add_vertex(t_obj *obj)
{
	return (add_element((void **)&obj->v_vertex, &obj->vv_curr, &obj->vm,
			sizeof(struct s_vec3)));
}

int		add_texture(t_obj *obj)
{
	return (add_element((void **)&obj->v_texture, &obj->vt_curr, &obj->tm,
			sizeof(struct s_vec2)));
}

int		add_normal(t_obj *obj)
{
	return (add_element((void **)&obj->v_normal, &obj->vn_curr, &obj->nm,
			sizeof(struct s_vec3)));
}

int		add_indice(t_obj *obj)
{
	return (add_element((void **)&obj->v_indice, &obj->vi_curr, &obj->im,
			sizeof(struct s_iset)));
}
