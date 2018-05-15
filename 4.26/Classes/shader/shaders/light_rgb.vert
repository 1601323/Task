const GLchar* LightRgbShaderVert = STRINGIFY
(
	// cocos2d-x���Ŏ����œ���Ă������
	// attribute:�ްï������ް�ł̂ݐݒ�/�g�p�ł���ϐ�                      
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
		// ���_�f�[�^�̐ݒ�
		gl_Position = CC_PMatrix * a_position;
		// �t���O�����g�V�F�[�_�ɓn���F��� (setColor�Őݒ肵���l)
		v_fragmentColor = a_color;
		// �t���O�����g�V�F�[�_�ɓn���e�N�X�`���̏��
		v_texCoord = a_texCoord;
	}
);
