/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadshaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:47:12 by aanzieu           #+#    #+#             */
/*   Updated: 2018/06/11 11:19:22 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"
# include "../libft/libft.h"

GLuint loadshaders(const char * vertex_file_path, const char * fragment_file_path){ 
 
    // Crée les shaders 
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER); 
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER); 
    int		fd_Vertex;
    int		fd_Fragment;
	int		ret;
	char	buffer[BUFFER_SIZE];
	char	*VertexShaderStream;
	char	*FragmentShaderStream;
	char	*del;

	VertexShaderStream = ft_strnew(BUFFER_SIZE);
	if ((fd_Vertex = open(vertex_file_path, O_RDONLY)) == -1)
		ft_putstr("shader source file opening failed.");
	while ((ret = read(fd_Vertex, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		del = VertexShaderStream;
		VertexShaderStream = ft_strjoin(VertexShaderStream, buffer);
		ft_strdel(&del);
	}
	close(fd_Vertex);


    FragmentShaderStream = ft_strnew(BUFFER_SIZE);
	if ((fd_Fragment = open(vertex_file_path, O_RDONLY)) == -1)
		ft_putstr("shader source file opening failed.");
	while ((ret = read(fd_Fragment, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		del = FragmentShaderStream;
		FragmentShaderStream = ft_strjoin(FragmentShaderStream, buffer);
		ft_strdel(&del);
	}
	close(fd_Fragment);





    // Lit le code du vertex shader à partir du fichier
    std::string VertexShaderCode; 
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in); 
    if(VertexShaderStream.is_open()) 
    { 
        std::string Line = ""; 
        while(getline(VertexShaderStream, Line)) 
            VertexShaderCode += "\n" + Line; 
        VertexShaderStream.close(); 
    } 
 
    // Lit le code du fragment shader à partir du fichier
    std::string FragmentShaderCode; 
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in); 
    if(FragmentShaderStream.is_open()){ 
        std::string Line = ""; 
        while(getline(FragmentShaderStream, Line)) 
            FragmentShaderCode += "\n" + Line; 
        FragmentShaderStream.close(); 
    } 
 
    GLint Result = GL_FALSE; 
    int InfoLogLength; 
 
    // Compile le vertex shader 
    printf("Compiling shader : %s\n", vertex_file_path); 
    char const * VertexSourcePointer = VertexShaderCode.c_str(); 
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL); 
    glCompileShader(VertexShaderID); 
 
    // Vérifie le vertex shader 
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result); 
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength); 
    std::vector<char> VertexShaderErrorMessage(InfoLogLength); 
    glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]); 
    fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]); 
 
    // Compile le fragment shader 
    printf("Compiling shader : %s\n", fragment_file_path); 
    char const * FragmentSourcePointer = FragmentShaderCode.c_str(); 
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL); 
    glCompileShader(FragmentShaderID); 
 
    // Vérifie le fragment shader 
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result); 
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength); 
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength); 
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]); 
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]); 
 
    // Lit le programme
    fprintf(stdout, "Linking program\n"); 
    GLuint ProgramID = glCreateProgram(); 
    glAttachShader(ProgramID, VertexShaderID); 
    glAttachShader(ProgramID, FragmentShaderID); 
    glLinkProgram(ProgramID); 
 
    // Vérifie le programme
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result); 
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength); 
    std::vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) ); 
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]); 
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]); 
 
    glDeleteShader(VertexShaderID); 
    glDeleteShader(FragmentShaderID); 
 
    return ProgramID; 
}