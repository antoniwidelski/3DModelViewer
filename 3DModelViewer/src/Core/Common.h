#pragma once

#ifndef V_COMMON
#define V_COMMON

#include <vector>
#include "glad/glad.h"

#include <iostream>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern std::vector<float> vertices;
extern std::vector<unsigned int> indices;

extern const char* vSource;
extern const char* fSource;

extern void CheckGLError(const char* stmt, const char* fname, int line);

#define GL_CHECK(stmt) do { \
        stmt; \
        CheckGLError(#stmt, __FILE__, __LINE__); \
    } while (0)

#define GL_CHECK_ERROR() \
    { GLenum err; while((err = glGetError()) != GL_NO_ERROR) { std::cout << "OpenGL Error: " << err << " at line " << __LINE__ << std::endl; } }

#endif