#version 330 core

uniform sampler2D sprite;
uniform sampler2D normal_map;

uniform vec2 resolution;

uniform float time;

vec4 tone_shift(float brightness) {
	float r = brightness;
	float g = brightness*0.9 + 0.1;
	float b = brightness*0.3 + 0.6;

	float intensity = 0.7;

	vec3 tone = vec3(r, g, b)*intensity + vec3(1-intensity);
	return vec4(tone, 1);
}

void main() {
	vec2 uv = gl_FragCoord.xy / resolution;
	uv.y = 1.0 - uv.y;

        vec4 sprite_color = texture(sprite, uv);

	float light_x = cos(time);
	float light_z = sin(time);
        vec3 light_pos = vec3(light_x, 0.5, light_z);

	vec3 normal = texture(normal_map, uv).xyz*2 - vec3(1);
	float brightness = dot(normal, light_pos);

	gl_FragColor = sprite_color * tone_shift(brightness);
}
