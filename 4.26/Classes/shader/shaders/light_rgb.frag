const GLchar* LightRgbShaderFrag = STRINGIFY
(
                                           
	\n#ifdef GL_ES\n
	precision mediump float;
	\n#endif\n

	// varing : ﾊﾞｰﾃｯｸｽｼｪｰﾀﾞｰがﾌﾗｸﾞﾒﾝﾄｼｪｰﾀﾞｰに渡す変数
	// uniform: ﾌﾗｸﾞﾒﾝﾄｼｪｰﾀﾞｰでも設定/使用できる変数

	// バーテックスシェーダで設定された色情報
	varying vec4 v_fragmentColor;
	// バーテックスシェーダで設定されたテクスチャ情報
	varying vec2 v_texCoord;
	// shader使用されるときに値を入れられる変数
	uniform vec3 u_color;

	void main(void)
	{
		vec4 c = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
		c.r = clamp(c.r + u_color.x , 0.0, 1.0) * c.a;
		c.g = clamp(c.g + u_color.y , 0.0, 1.0) * c.a;
		c.b = clamp(c.b + u_color.z , 0.0, 1.0) * c.a;
		// 指定した色にする
		gl_FragColor = c;
	}
);