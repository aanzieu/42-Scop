/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:39:31 by aanzieu           #+#    #+#             */
/*   Updated: 2018/06/11 16:32:40 by aanzieu          ###   ########.fr       */
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

   	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // Ouvre une fenêtre et crée son contexte OpenGL
    GLFWwindow* window; // (Dans le code joint, cette variable est globale)

    // GLuint VertexArrayID; 
    // glGenVertexArrays(1, &VertexArrayID); 
    // glBindVertexArray(VertexArrayID);
    // glBindVertexArray(0);

    window = glfwCreateWindow( HEIGHT, WIDTH, "Tutorial 01", NULL, NULL); 
    if( window == NULL ){ 
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" ); 
        glfwTerminate(); 
        return -1; 
    }
    
    /*------------------*/

   

    /*------------------*/

    glfwMakeContextCurrent(window); 
    
    // Initialise GLEW 
    glewExperimental= 1; // Nécessaire pour le profil core
    if (glewInit() != GLEW_OK) { 
        fprintf(stderr, "Failed to initialize GLEW\n"); 
        return -1; 
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    /*------------------*/

    // Un tableau de trois vecteurs qui représentent trois sommets
    static const GLfloat g_vertex_buffer_data[] = { 
        -1.0f, -1.0f, 0.0f, 
        1.0f, -1.0f, 0.0f, 
        0.0f,  1.0f, 0.0f, 
    };


    GLuint VertexArrayID; 
    glGenVertexArrays(1, &VertexArrayID); 
    glBindVertexArray(VertexArrayID);
    // Ceci identifiera notre tampon de sommets
    GLuint vertexbuffer;
    // Génère un tampon et place l'identifiant dans 'vertexbuffer'
    glGenBuffers(1, &vertexbuffer); 
    // Les commandes suivantes vont parler de notre tampon 'vertexbuffer'
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 
    // Fournit les sommets à OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    /*------------------*/

    dprintf(1, "%s\n", "toto");
    
    GLuint programID = loadshaders();
    dprintf(1, "%u\n", programID);
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 )
    {
        glfwPollEvents();
        glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);
        // glBindVertexArray(VertexArrayID);
        // premier tampon d'attributs : les sommets
        glEnableVertexAttribArray(0); 
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 
        glVertexAttribPointer( 
            0,                  // attribut 0. Aucune raison particulière pour 0, mais cela doit correspondre au « layout » dans le shader 
        3,                  // taille
        GL_FLOAT,           // type 
        GL_FALSE,           // normalisé ? 
        0,                  // nombre d'octets séparant deux sommets dans le tampon
        (void*)0            // décalage du tableau de tampon
        ); 
    
    // Dessine le triangle ! 
        glDrawArrays(GL_TRIANGLES, 0, 3); // Démarre à partir du sommet 0; 3 sommets au total -> 1 triangle 
    
        glDisableVertexAttribArray(0);

        /*------------------*/

        // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // glUseProgram(programID);
        glfwSwapBuffers(window); 
    }
    glfwTerminate();
}