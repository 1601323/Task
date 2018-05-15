const GLchar* LightRgbShaderVert = STRINGIFY
(
	// cocos2d-x側で自動で入れてくれる情報
	// attribute:ﾊﾞｰﾃｯｸｽｼｪｰﾀﾞｰでのみ設定/使用できる変数                      
	attribute vec4 a_position;
	attribute vec2 a_texCoord;
	attribute vec4 a_color;
   
	\n#ifdef GL_ES\n
	varying lowp vec4 v_fragmentColor;
	varying mediump vec2 v_texCoord;
	\n#else\n
	varying vec4 v_fragmentColor;
	varying vec2 v_texCoord;
	\n#endif\n

	void main() 
	{
		// 頂点データの設定
		gl_Position = CC_PMatrix * a_position;
		// フラグメントシェーダに渡す色情報 (setColorで設定した値)
		v_fragmentColor = a_color;
		// フラグメントシェーダに渡すテクスチャの情報
		v_texCoord = a_texCoord;
	}
);
