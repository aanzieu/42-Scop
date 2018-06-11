# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vertex.glsl                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 09:47:38 by aanzieu           #+#    #+#              #
#    Updated: 2018/06/11 09:48:41 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

void main(){
    gl_Position.xyz = vertexPosition_modelspace; 
    gl_Position.w = 1.0; 
}