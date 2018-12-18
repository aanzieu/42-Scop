#version 410 core

in      vec2            TexCoord;
in      vec3            ourColor;

uniform sampler2D       ourTexture;
uniform float		    ourTextureLvl;

out     vec4            FragColor;

void main()
{
    // FragColor = vec4(1.0, 1.0 , 1.0, 1.0);
    vec4 Color;
    if (gl_PrimitiveID% 2 == 0){
        Color = vec4(0.75,0.75,0.75,1);
    }
    else{
    // ourColor = vec3(5, 5, 5);
        Color = vec4(0.25,0.25,0.25,1);
    }
    // else {
        // FragColor = vec4(4, 0.5, 255, 1);
    // }
    
    FragColor = mix(Color, texture(ourTexture, TexCoord), ourTextureLvl);
    // FragColor = vec4(FragColor, 1);
}