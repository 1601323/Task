const GLchar* BlurShaderFrag =
STRINGIFY(
                                           
	// blur.vert 
	// attribute:�ްï������ް�ł̂ݐݒ�/�g�p�ł���ϐ�                      
	// attribute:���_���̂��Ƃ�,�ʒu��UV�l������

	// �ʒu��񂪓���
	attribute vec4 a_position;
	// UV�l��񂪓���
	attribute vec2 a_texCoord;
	// 
	attribute vec4 a_color;
	// �o�[�e�b�N�X�V�F�[�_�Őݒ肳�ꂽ�F���
	varying vec4 v_fragmentColor;
	// �o�[�e�b�N�X�V�F�[�_�Őݒ肳�ꂽ�e�N�X�`�����
	varying vec2 v_texCoord;

	void main()
	{
		gl_Position		= CC_MVPMatrix * a_position;
		v_fragmentColor = a_color;
		v_texCoord		= a_texCoord;
	}
);


