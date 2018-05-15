const GLchar* LightRgbShaderFrag = STRINGIFY
(
                                           
	\n#ifdef GL_ES\n
	precision mediump float;
	\n#endif\n

	// varing : �ްï������ް���׸���ļ���ް�ɓn���ϐ�
	// uniform: �׸���ļ���ް�ł��ݒ�/�g�p�ł���ϐ�

	// �o�[�e�b�N�X�V�F�[�_�Őݒ肳�ꂽ�F���
	varying vec4 v_fragmentColor;
	// �o�[�e�b�N�X�V�F�[�_�Őݒ肳�ꂽ�e�N�X�`�����
	varying vec2 v_texCoord;
	// shader�g�p�����Ƃ��ɒl��������ϐ�
	uniform vec3 u_color;

	void main(void)
	{
		vec4 c = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
		c.r = clamp(c.r + u_color.x , 0.0, 1.0) * c.a;
		c.g = clamp(c.g + u_color.y , 0.0, 1.0) * c.a;
		c.b = clamp(c.b + u_color.z , 0.0, 1.0) * c.a;
		// �w�肵���F�ɂ���
		gl_FragColor = c;
	}
);