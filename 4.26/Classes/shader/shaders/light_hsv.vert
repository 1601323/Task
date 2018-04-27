const GLchar* LightHsvShaderVert = STRINGIFY(
                                          
attribute vec4 a_position;	// 頂点情報
attribute vec2 a_texCoord;	// テクスチャマッピング
attribute vec4 a_color;		// 色情報(bindingしてる変数)
   
\n#ifdef GL_ES\n
// varying:ﾌﾗｸﾞﾒﾝﾄｼｪｰﾀﾞｰを渡す
// lopw/mediump:値の精度(float/double同様)
// vec4 v fragmentColor:色所法

varying lowp vec4 v_fragmentColor;	
varying mediump vec2 v_texCoord;	
\n#else\n		
varying vec4 v_fragmentColor;		
varying vec2 v_texCoord;			
\n#endif\n

void main() {
	// ﾎﾟｼﾞｼｮﾝ情報に座標調整の変数代入
    gl_Position = CC_PMatrix * a_position;	
    v_fragmentColor = a_color;
    v_texCoord = a_texCoord;
} );
