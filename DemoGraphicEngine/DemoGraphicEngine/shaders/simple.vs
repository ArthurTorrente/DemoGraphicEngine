attribute vec3 a_position;

uniform vec3 u_color;
uniform mat4 u_proj;
uniform mat4 u_view;
uniform mat4 u_world;

varying vec4 v_color;

void main(void)
{
	gl_Position = u_proj * u_view * u_world * vec4(a_position, 1.0);
	
	v_color = vec4(u_color, 1.0);
}