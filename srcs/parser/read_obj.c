/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:57:47 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/12 10:24:49 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

int					obj_add_surf(t_obj *obj)
{
	int si;

	if ((si = add_element((void **)&obj->sv,
					&obj->surface_count,
					&obj->surface_mem,
					sizeof(struct s_obj_surf))) >= 0)
	{
		memset(obj->sv + si, 0, sizeof(struct s_obj_surf));
	}
	return (si);
}

static void			read_vt(const char *line, t_obj *obj)
{
	int ti;

	if ((ti = add_texture(obj)) >= 0)
	{
		sscanf(line, "%f %f",
				obj->v_texture[ti].v + 0, obj->v_texture[ti].v + 1);
		obj->v_texture[ti].index_v2 = -1;
	}
}

static void			read_v(const char *line, t_obj *obj)
{
	int vi;

	if ((vi = add_vertex(obj)) >= 0)
	{
		sscanf(line, "%f %f %f",
				obj->v_vertex[vi].v + 0,
				obj->v_vertex[vi].v + 1,
				obj->v_vertex[vi].v + 2);
		obj->v_vertex[vi].index_vec3 = -1;
	}
}

void				read_open(t_obj *obj, FILE *fin)
{
	int			si;
	char		buf[MAXSTR];
	char		key[MAXSTR];
	int			n;
	const char	*c;

	si = obj_add_surf(obj);
	while (fgets(buf, MAXSTR, fin))
	{
		if (sscanf(buf, "%s%n", key, &n) >= 1)
		{
			c = buf + n;
			if (!strcmp(key, "f"))
				read_f(c, obj, si);
			if (!strcmp(key, "vt"))
				read_vt(c, obj);
			if (!strcmp(key, "v"))
				read_v(c, obj);
		}
	}
}

int					read_obj(t_obj *obj, const char *filename)
{
	FILE *fin;

	if ((fin = fopen(filename, "r")))
	{
		read_open(obj, fin);
		obj->tview = 1;
		fclose(fin);
	}
	else
	{
		dprintf(1, "Wrong File name, PLease Enter a good repo\n");
		return (0);
	}
	return (1);
}
