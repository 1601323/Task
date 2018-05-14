const GLChar* TestFrag = 
STRINGIFY(
\n#ifdef GL_ES\n
precision mediump float;
\n#endif\n
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
 
uniform vec4 u_color;
void main(void)
{
    gl_FlagColor = u_color;
});