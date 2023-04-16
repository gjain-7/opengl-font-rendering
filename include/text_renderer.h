#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <map>
#include <string>
#include <shader.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void RenderText(Shader& shader, std::string text, float x, float y, float scale,
                glm::vec3 color);
int loadFont(const char* fontPath);
void loadShader(Shader& shader, int SCR_WIDTH, int SCR_HEIGHT);

/// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    unsigned int TextureID;  // ID handle of the glyph texture
    glm::ivec2 Size;         // Size of glyph
    glm::ivec2 Bearing;      // Offset from baseline to left/top of glyph
    unsigned int Advance;    // Horizontal offset to advance to next glyph
};

extern std::map<GLchar, Character> Characters;
extern unsigned int VAO, VBO;