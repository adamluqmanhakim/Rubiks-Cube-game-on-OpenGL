#include "Cube.h"
Cube::Cube() {

}

Cube::Cube(vec3 basePos, Shader S) {
	//setting base scaling, translation and rotation
	currentShader = S;
	basePosition = basePos;
	this->update();
}

//update the cube 
void Cube::update() {
	modelMatrix = rotate(mat4(1.0f), radians(baseRotation), vec3(0.0f, 0.0f, 1.0f)) * scale(mat4(1.0f), size * currentScaleFactor);

	modelMatrix = translate(mat4(1.0f), (basePosition) * currentScaleFactor) * modelMatrix;

	//setting custom rotation
	modelMatrix = customRotation * modelMatrix;

	//setting custom translation 
	modelMatrix = customTranslation * modelMatrix;
}

void Cube::setDefaultSize(vec3 s) {
	size = s;
	this->update();
}

void Cube::setDefaultRotation(float angle) {
	baseRotation = angle;
	this->update();
}

void Cube::setDefaultPosition(vec3 position) {
	basePosition = position;
	this->update();
}

void Cube::setCustomScaling(float scaleFactor) {
	currentScaleFactor = scaleFactor;
}

void Cube::setCustomRotation(mat4 rotationMatrix) {
	customRotation = rotationMatrix;
}

void Cube::setCustomTranslation(vec3 offSet) {
	customTranslation = translate(mat4(1.0f), offSet);
}

void Cube::drawModel() {
	this->drawBotFace();
	this->drawLeftFace();
	this->drawRightFace();
	this->drawFrontFace();
	this->drawBackFace();
	this->drawTopFace();
}

void Cube::drawLeftFace() {
	currentShader.setMat4("worldMatrix", modelMatrix);
	glDrawArrays(GL_TRIANGLES, 0, 6); // left face
}

void Cube::drawBackFace() {
	currentShader.setMat4("worldMatrix", modelMatrix);
	glDrawArrays(GL_TRIANGLES, 6, 6); // back face
}

void Cube::drawBotFace() {
	currentShader.setMat4("worldMatrix", modelMatrix);
	glDrawArrays(GL_TRIANGLES, 12, 6); // bottom face
}

void Cube::drawFrontFace() {
	currentShader.setMat4("worldMatrix", modelMatrix);
	glDrawArrays(GL_TRIANGLES, 18, 6); // front face
}

void Cube::drawRightFace() {
	currentShader.setMat4("worldMatrix", modelMatrix);
	glDrawArrays(GL_TRIANGLES, 24, 6); // right face
}

void Cube::drawTopFace() {
	currentShader.setMat4("worldMatrix", modelMatrix);
	glDrawArrays(GL_TRIANGLES, 30, 6); // top face
}


void Cube::setCurrentShader(Shader S) {
	currentShader = S;
	this->update();
}

void Cube::setDepthMap(mat4 lightProjMatrix, mat4 lightViewMatrix) {
	//currentShader.setVec3("position", vec3(0.0f, 1.0f, 30.0f));
	currentShader.setMat4("transform_in_light_space", lightProjMatrix * lightViewMatrix * modelMatrix);
	this->update();
}