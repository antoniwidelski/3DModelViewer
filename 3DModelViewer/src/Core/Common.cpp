#include "Common.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

float vertices[] = {
	0.0f, 1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	-1.0, -1.0f, 0.0f
};

unsigned int indices[] = {
	0, 1, 2
};


const char* vSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";