/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:33:41 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 13:56:56 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

void	initialize_obj_shader(t_obj *obj)
{
	obj->vv_curr = 0;
	obj->vt_curr = 0;
	obj->vn_curr = 0;
	obj->vi_curr = 0;
	obj->uloc = -1;
	obj->nloc = -1;
	obj->tloc = -1;
	obj->vloc = -1;
}

t_obj	*obj_create(const char *filename)
{
	t_obj *obj;

	if ((obj = (t_obj *)calloc(1, sizeof(t_obj))))
	{
		if (filename)
		{
			if (read_obj(obj, filename))
			{
				obj_mini(obj);
				return (obj);
			}
		}
	}
	return (NULL);
}
