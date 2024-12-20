#include "Common.h"


const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

std::vector<float> vertices = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right      0
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right   1
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left    2
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,  // top left      3

    0.5f,  0.5f, -1.0f,   1.0f, 0.0f, 0.0f,   0.0f, 1.0f, // top right      4
     0.5f, -0.5f, -1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f, // bottom right  5
    -0.5f, -0.5f, -1.0f,   0.0f, 0.0f, 1.0f,   1.0f, 0.0f, // bottom left   6
    -0.5f,  0.5f, -1.0f,   1.0f, 1.0f, 0.0f,   1.0f, 1.0f  // top left      7
};

std::vector<unsigned int> indices = {
	0, 1, 2,
	0, 2, 3,

    4, 5, 6,
    4, 6, 7,

    0, 4, 5,
    0, 5, 1,

    7, 3, 2,
    7, 2, 6,

    0, 7, 4,
    0, 3, 7,

    1, 6, 5,
    1, 2, 6
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

void CheckGLError(const char* stmt, const char* fname, int line)
{
    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
    {
        std::cerr << "OpenGL error " << err << " at " << stmt << " in " << fname << ":" << line << std::endl;
        exit(1);
    }
}