/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:54:57 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/12 07:59:07 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "opengl.h"

/*
** Render
*/

void			glfw_initialisation();
void			glfw_window(t_glenv *master);
void			glfw_matrix_init(t_glenv *master);
void			glfw_render(t_glenv *master);
void			glfw_controls(t_glenv *master);

/*
** Load And Create Programme
*/

GLuint			create_shader(char *filename, int shader_type);
GLuint			loadshaders(GLuint vertexshader, GLuint fragmentshader);

/*
**  Operation Matrice
*/

void			matrix_debug(float const *matrix);
GLfloat			*mat3();
GLfloat			*mat4();
GLfloat			*mat4_clone(GLfloat *matrix);
GLfloat			*mat4_rotate_x(GLfloat *dest, GLfloat amount);
GLfloat			*mat4_rotate_y(GLfloat *dest, GLfloat amount);
GLfloat			*mat4_rotate_z(GLfloat *dest, GLfloat amount);
GLfloat			*normalize_mat4(GLfloat *matrix);
GLfloat			*mat4_perspective(float fov, float aspect, float n, float f);
GLfloat			*mat4_mult(GLfloat *dest, GLfloat *left, GLfloat *right);
GLfloat			*mat4_scale(GLfloat *dest, float amount);
GLfloat			*mat4_translate(GLfloat *dest, GLfloat amount[3]);

/*
**   Operation Vector
*/

GLfloat			*vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLfloat			*vec3_to_vec4(const GLfloat *vec3, GLfloat a);

/*
**  Texture
*/

void			active_texture(t_glenv *master);
t_bmp_header	*load_texture(t_glenv *master);

/*
** Parsing
*/

t_obj			*obj_create(const char *filename);
int				read_obj(t_obj *obj, const char *filename);

/*
** Surface empty and unreferecended material
*/

void			obj_mini(t_obj *obj);

/*
** Operation *float
*/

void			cross(float *z, const float *x, const float *y);
void			normal(float *n, const float *a, const float *b,
				const float *c);
void			normalize(float *v);

/*
** Del function
*/

void			obj_del_surf(t_obj *obj, int si);
void			glfw_delete_buffer(t_obj *obj);

/*
** Add displaye
*/

void			display_command();
int				display_usage();

/*
** Key Input Elem
*/

void			handle_keys_moov(t_glenv *tmp_master, int button,
				float i[3]);
void			handle_keys_options(t_glenv *tmp_master, int button,
				float i[3]);

/*
** Vertix set
*/

void			obj_set_vert_v(t_obj *obj, int vi, const float v[3]);
void			obj_set_vert_t(t_obj *obj, int vi, const float t[2]);
void			obj_set_vert_n(t_obj *obj, int vi, const float n[3]);
void			obj_set_poly(t_obj *obj, int si, int pi, const int vi[3]);
/*
** vertix get
*/
void			obj_get_vert_v(t_obj *obj, int vi, float *v);
void			obj_get_vert_t(t_obj *obj, int vi, float *t);
void			obj_get_vert_n(t_obj *obj, int vi, float *n);
void			glfw_get_uniforms(t_glenv *master);

/*
** vertix read and add
*/
void			triangulate_indices(t_obj *obj, int ic, int index, int si);
void			random_vt(t_obj *obj, const int vi, float t[2]);
void			read_no_vt(t_obj *obj);
void			read_f(const char *line, t_obj *obj, int si);
int				obj_add_vert(t_obj *obj);
int				obj_add_poly(t_obj *obj, int si);

/*
** add other from parse
*/

int				add_element(void **v, int *c, int *m, size_t s);
int				add_vertex(t_obj *obj);
int				add_texture(t_obj *obj);
int				add_indice(t_obj *obj);
int				add_normal(t_obj *obj);

/*
** vertix
*/

int				search_index_set(t_obj *obj, const int i[3], int x);

/*
** vertix
*/

float			deg_to_rad(float deg);
void			find_point_max(float v, float *mm);
void			find_point_min(float v, float *mm);
void			find_center_parse(t_glenv *master);

#endif
