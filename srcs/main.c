/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:39:31 by aanzieu           #+#    #+#             */
/*   Updated: 2018/06/11 10:24:14 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"
// # include "../frameworks/SDL2.framework/Headers/SDL.h"
// # include "../frameworks/glew/include/GL/glew.h"
// # include "../frameworks/glfw/include/GLFW/glfw3.h"



int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    if(!glfwInit())
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

   	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // Ouvre une fenêtre et crée son contexte OpenGL
    GLFWwindow* window; // (Dans le code joint, cette variable est globale) 
    window = glfwCreateWindow( HEIGHT, WIDTH, "Tutorial 01", NULL, NULL); 
    if( window == NULL ){ 
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" ); 
        glfwTerminate(); 
        return -1; 
    } 

    glfwMakeContextCurrent(window); 
    
    // Initialise GLEW 
    glewExperimental= 1; // Nécessaire pour le profil core
    if (glewInit() != GLEW_OK) { 
        fprintf(stderr, "Failed to initialize GLEW\n"); 
        return -1; 
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLuint programID = loadshaders( "../shaders/vertex.glsl", "../shaders/fragment.glsl" );
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 )
    {
        glfwPollEvents();
    }
    glfwTerminate();
}