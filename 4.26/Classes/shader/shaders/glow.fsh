// ���̂�T���v��
// https://qiita.com/isaoeka/items/dee8159e2a0c2a37a662

//��̂�̐������u
//http://brbranch.jp/blog/201607/cocos2d-x/shader/

// �o�[�e�b�N�Xshader�Őݒ肳�ꂽ�F���
varying vec4 v_fragmentColor;	
// �o�[�e�B�b�N�Xshader�Őݒ肳�ꂽ�e�N�X�`�����
varying vec2 v_texCoord;

uniform float u_ctime;
uniform float u_threshold;
uniform float u_radius;
uniform float u_outlineColor;

void main()
{
	float radius = u_radius;

	vec4 accum  = vec4(0.0);
	vec4 normal = vec4(0.0);

	noemal = texture2D(CC_Texture0,v_texCoord);
}