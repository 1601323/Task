const GLChar* TestFrag = 
STRINGIFY(
\n#ifdef GL_ES\n
precision mediump float;
\n#endif\n
// �o�[�e�b�N�X�V�F�[�_�Őݒ肳�ꂽ�F���
varying vec4 v_fragmentColor;
// �o�[�e�b�N�X�V�F�[�_�Őݒ肳�ꂽ�e�N�X�`�����
// �����瑤�œƎ��ɒ�`�����ϐ�
varying vec2 v_texCoord;
 
uniform vec4 u_color;
void main(void)
{
    gl_FlagColor = u_color;
});