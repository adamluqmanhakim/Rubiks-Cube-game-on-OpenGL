#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/common.hpp>
#include "shader_compile.h"

#pragma once

using namespace glm;

class Cube
{
private:
	vec3 position;
	vec3 size = vec3(1.0f);
	vec3 baseTranslation;
	vec3 basePosition;

	float baseRotation = 0.0f;

	mat4 customRotation = rotate(mat4(1.0f), radians(0.0f), vec3(0.0f, 1.0f, 0.0f));
	mat4 customTranslation = mat4(1.0f);

	mat4 modelMatrix;

	float currentScaleFactor = 1.0f;

	Shader currentShader;

	int modelMode;

public: 
	Cube();
	Cube(vec3 basePos, Shader S);

	void setDefaultSize(vec3 s);
	void setDefaultRotation(float angle);
	void setDefaultPosition(vec3 pos);

	void update();
	void setCustomRotation(mat4 rotationMatrix);
	void setCustomTranslation(vec3 offset);
	void setCustomScaling(float scaleFactor);

	void setCurrentShader(Shader S);

	void setDepthMap(mat4 lightProjMatrix, mat4 lightViewMatrix);
	void drawLeftFace();
	void drawRightFace();
	void drawFrontFace();
	void drawBackFace();
	void drawTopFace();
	void drawBotFace();
	void drawModel();
};