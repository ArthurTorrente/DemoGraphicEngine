varying vec2 v_texCoord;
varying vec4 v_color;

uniform sampler2D u_sampler;

void main(void)
{
	vec4 colorT = texture2D(u_sampler, v_texCoord);
	gl_FragColor = colorT;
}