#include <iostream>
#include "graphics/Window.h"
#include "utils/Timer.h"
#include "utils/FileUtils.h"


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



	vlex::utils::Timer time; 
	float timer = 0.0f;
	int frames = 0;


	while (!window.closed()) {
		window.clear();

		glBegin(GL_QUADS);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.0f, 1.0f);
			glVertex2f(0.25f, 0.75f);
			glVertex2f(0.5f, -0.5f);
		glEnd();


		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window.update();



		frames++;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}


	}

	std::string res = vlex::utils::readFileAsString("main.cpp");

	std::cout << res << std::endl;
	return 0;
}