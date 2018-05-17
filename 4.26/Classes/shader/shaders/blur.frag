const GLchar* BlurShaderFrag =
STRINGIFY(
                                           
	// blur.vert 
	// attribute:ﾊﾞｰﾃｯｸｽｼｪｰﾀﾞｰでのみ設定/使用できる変数                      
	// attribute:頂点情報のやりとり,位置とUV値が入る

	// 位置情報が入る
	attribute vec4 a_position;
	// UV値情報が入る
	attribute vec2 a_texCoord;
	// 
	attribute vec4 a_color;
	// バーテックスシェーダで設定された色情報
	varying vec4 v_fragmentColor;
	// バーテックスシェーダで設定されたテクスチャ情報
	varying vec2 v_texCoord;

	void main()
	{
		gl_Position		= CC_MVPMatrix * a_position;
		v_fragmentColor = a_color;
		v_texCoord		= a_texCoord;
	}
);


