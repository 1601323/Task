const GLchar* LightHsvShaderVert = STRINGIFY(
                                          
attribute vec4 a_position;	// ���_���
attribute vec2 a_texCoord;	// �e�N�X�`���}�b�s���O
attribute vec4 a_color;		// �F���(binding���Ă�ϐ�)
   
\n#ifdef GL_ES\n
// varying:�׸���ļ���ް��n��
// lopw/mediump:�l�̐��x(float/double���l)
// vec4 v fragmentColor:�F���@

varying lowp vec4 v_fragmentColor;	
varying mediump vec2 v_texCoord;	
\n#else\n		
varying vec4 v_fragmentColor;		
varying vec2 v_texCoord;			
\n#endif\n

void main() {
	// �߼޼�ݏ��ɍ��W�����̕ϐ����
    gl_Position = CC_PMatrix * a_position;	
    v_fragmentColor = a_color;
    v_texCoord = a_texCoord;
} );
