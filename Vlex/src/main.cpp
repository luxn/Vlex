#include <iostream>
#include "graphics/Window.h"

int main() {

	std::string title = "VlexEngine";
	vlex::graphics::Window window(title, 960, 540);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << "GL_VERSION:    " << glGetString(GL_VERSION)  << std::endl;
	std::cout << "GL_RENDERER:   " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "GL_VENDOR:     " << glGetString(GL_VENDOR)   << std::endl;


	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed()) {
		window.clear();

#if 0
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 1.0f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#endif

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);


		window.update();
	}
	return 0;
}