const GLChar* TestFrag = 
STRINGIFY(
\n#ifdef GL_ES\n
precision mediump float;
\n#endif\n
// バーテックスシェーダで設定された色情報
varying vec4 v_fragmentColor;
// バーテックスシェーダで設定されたテクスチャ情報
// こちら側で独自に定義した変数
varying vec2 v_texCoord;
 
uniform vec4 u_color;
void main(void)
{
    gl_FlagColor = u_color;
});