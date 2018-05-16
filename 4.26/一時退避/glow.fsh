// ���̂�T���v��
// https://qiita.com/isaoeka/items/dee8159e2a0c2a37a662

//��̂�̐�����
//http://brbranch.jp/blog/201607/cocos2d-x/shader/

const GLchar* GlowFsh =
STRINGIFY(

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

		for(float i = 1.0;i <= radius; i+= 1.0)
		{
			accum += texture2D(CC_Texture0, vec2(v_texCoord.x - 0.01 * i, v_texCoord.y - 0.01 * i));
			accum += texture2D(CC_Texture0, vec2(v_texCoord.x + 0.01 * i, v_texCoord.y - 0.01 * i));
			accum += texture2D(CC_Texture0, vec2(v_texCoord.x + 0.01 * i, v_texCoord.y + 0.01 * i));
			accum += texture2D(CC_Texture0, vec2(v_texCoord.x - 0.01 * i, v_texCoord.y + 0.01 * i));
		}

		accum.rgb = u_outlineColor.rgb * u_outlineColor.a * accum.a * 0.95;

		float opacity = ((1.0 + normal.a) / radius) * (u_ctime / u_threshold);

		normal = (accum * opacity) + (normal * nomal.a);

		g1_FragColor = v_fragmentColor * normal;
	}
);

