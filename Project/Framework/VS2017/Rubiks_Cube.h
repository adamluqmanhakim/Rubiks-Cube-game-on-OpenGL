#pragma once
#include "Cube.h"
#include <array>
#include <vector>

using namespace glm;
using namespace std;

class Rubiks_Cube {
private:
	array<array<array<Cube, 3>, 3>, 3> cubeArray;
	vec3 position;
	vector<GLuint> texturePack;

public:
	Rubiks_Cube();
	Rubiks_Cube(vec3 pos, vector<GLuint> texture);

	void generateCube(Shader S);
	void setShader(Shader S);
	void drawModel();
};