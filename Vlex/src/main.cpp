#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> //ortho ist hierdrin
#include <glm/gtc/type_ptr.hpp>

#include "graphics/Window.h"
#include "graphics/shader/Shader.h"
#include "utils/Timer.h"
#include "utils/FileUtils.h"


int main() {

	std::string title = "VlexEngine";
	vlex::graphics::Window window(title, 960, 540);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << "GL_VERSION:    " << glGetString(GL_VERSION)  << std::endl;
	std::cout << "GL_RENDERER:   " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "GL_VENDOR:     " << glGetString(GL_VENDOR)   << std::endl;




		

	/*vlex::utils::Timer time; 
	float timer = 0.0f;
	int frames = 0;*/


	GLfloat vertices[] = {
		-0.5f, -0.5f,  0.0f,
		-0.5f,  0.5f,  0.0f,
		 0.5f,  0.5f,  0.0f,
		 0.5f,  0.5f,  0.0f,
		 0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};

	GLuint vbo;	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);


	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);	



	vlex::graphics::Shader shader("D:\\VS15Projects\\Vlex\\Vlex\\src\\graphics\\shader\\src\\basic.vert", "D:\\VS15Projects\\Vlex\\Vlex\\src\\graphics\\shader\\src\\basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", glm::rotate(glm::mat4(1.0f), 90.0f,glm::vec3(0,0,1)));

	shader.setUniform4f("color", glm::vec4(0.2f, 0.9f, 0.0f, 1.0f));

	while (!window.closed()) {
		window.clear();

		 

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();



		/*frames++;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}*/


	}

	return 0;
}