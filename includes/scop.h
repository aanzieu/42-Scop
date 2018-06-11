/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:59:17 by aanzieu           #+#    #+#             */
/*   Updated: 2018/06/11 15:12:29 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/glew/include/GL/glew.h"
# include "../frameworks/glfw/include/GLFW/glfw3.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

# define HEIGHT 1024
# define WIDTH  768

# define BUFFER_SIZE 128

GLuint loadshaders();

#endif