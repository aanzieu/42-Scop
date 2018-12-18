/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:59:17 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 12:11:55 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_H
# define OPENGL_H

# include "/Users/aanzieu/.brew/Cellar/glew/2.1.0/include/GL/glew.h"
# include "/Users/aanzieu/.brew/Cellar/glfw/3.2.1/include/GLFW/glfw3.h"

typedef struct			s_grid
{
	GLint				projection_matrix;
	GLint				model_matrix;
	GLint				view_matrix;
	GLint				texture_matrix;
	GLint				texture_level;
	GLint				color_matrix;
}						t_grid;

struct					s_vec2
{
	float				v[2];
	int					index_v2;
};

struct					s_vec3
{
	float				v[3];
	int					index_vec3;
};

struct					s_vec4
{
	float				v[4];
	int					ii;
};

struct					s_mat3
{
	struct s_vec3		vec[3];
};

struct					s_mat4
{
	struct s_vec4		vec[4];
};

struct					s_iset
{
	int					vi;
	int					vertex_i;
	int					texture_i;
	int					normal_i;
	int					ii;
};

struct					s_obj_vert
{
	float				c[3];
	float				n[3];
	float				t[2];
	float				v[3];
};

struct					s_obj_poly
{
	unsigned int		vertex_indices[3];
};

struct					s_obj_surf
{
	int					poly_count;
	int					pm;
	unsigned int		pibo;
	struct s_obj_poly	*poly_vertx;
};

typedef struct			s_obj
{
	unsigned int		vao;
	unsigned int		vbo;
	struct s_vec3		*v_vertex;
	int					vv_curr;
	int					vm;
	struct s_vec2		*v_texture;
	int					vt_curr;
	int					tm;
	struct s_vec3		*v_normal;
	int					vn_curr;
	int					nm;
	struct s_iset		*v_indice;
	int					vi_curr;
	int					im;
	int					poly_count;
	int					poly_mem;
	int					surface_count;
	int					surface_mem;
	int					uloc;
	int					nloc;
	int					tloc;
	int					cloc;
	int					vloc;
	int					tview;
	float				tlvl;
	struct s_obj_vert	*vv;
	struct s_obj_surf	*sv;
}						t_obj;

typedef struct			s_bmp_header
{
	unsigned char		header[54];
	unsigned int		datapos;
	unsigned int		width;
	unsigned int		height;
	unsigned int		imagesize;
	unsigned char		*image_bmp;
	unsigned char		*tmp_image_bmp;
	GLuint				texture_id;
}						t_bmp_header;

typedef struct			s_glenv
{
	GLFWwindow			*win;
	GLuint				shader_program;
	struct s_grid		uniform;
	GLfloat				*model;
	GLfloat				*translation;
	GLfloat				*rotation;
	GLfloat				*scalling;
	struct s_vec3		center;
	GLfloat				*view;
	GLfloat				*normal;
	GLfloat				*projection;
	GLfloat				*light;
	struct s_vec3		cam_position;
	struct s_vec3		cam_velocity;
	struct s_vec2		cam_rotation;
	t_obj				*parser;
	t_bmp_header		*bmp_data;
	int					texturing;
	int					rotate;
	int					polygon_mode;
	int					mouse_mov;
	struct s_vec2		mouse_pos;
	char				*file_bmp;
	char				*file_obj;
}						t_glenv;

#endif
