#version 410 core

layout (location = 0) in vec3   vPosition;
layout (location = 1) in vec3   aColor;
layout (location = 2) in vec2   vTexCoord;
layout (location = 3) in vec3   vNormal;

uniform mat4                    ModelMatrix;
uniform mat4                    ProjectionMatrix;
uniform mat4                    ViewMatrix;

out vec2                        TexCoord;
out vec3                        ourColor;

void main()
{
    gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(vPosition, 1);
    TexCoord = vTexCoord;
    ourColor = aColor;
}