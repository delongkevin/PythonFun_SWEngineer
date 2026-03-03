#!/bin/bash
python3 make_glsl_header.py \
    primitive.vert \
    pbr.frag \
	animation.glsl \
	brdf.glsl \
	functions.glsl \
	ibl.glsl \
	punctual.glsl \
	textures.glsl \
	tonemapping.glsl \
    pbr-shaders.h
