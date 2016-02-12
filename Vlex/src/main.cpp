#include <iostream>


#include "graphics/Window.h"
#include "graphics/shader/Shader.h"
#include "utils/Timer.h"
#include "utils/FileUtils.h"
#include "math/Math.h"
#include "graphics/buffers/VertexBuffer.h"
#include "graphics/buffers/VertexArray.h"
#include "graphics/buffers/IndexBuffer.h"

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

#if 0
	GLfloat vertices[] = {
		 8.0f,  4.0f,  0.0f,
		 4.0f,  0.0f,  0.0f,
		 8.0f,  6.0f,  0.0f,	
		 4.0f,  6.0f,  0.0f
	};

	GLuint vbo;	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

#else
	GLfloat vertices[] = {
		0,0,0,
		0,3,0,
		8,3,0,
		8,0,0
	};

	GLushort indices[] = {
		0,1,2,
		2,3,0
	};

	GLfloat colorsA[] = {
		1,0,1,1,
		1,0,1,1,
		1,0,1,1,
		1,0,1,1

	};

	GLfloat colorsB[] = {
		0,1,1,1,
		0,1,1,1,
		0,1,1,1,
		0,1,1,1
	};



	vlex::graphics::VertexArray sprite1, sprite2;
	vlex::graphics::IndexBuffer ibo(indices, 6);

	sprite1.addBuffer(new vlex::graphics::VertexBuffer(vertices, 4 * 3, 3), 0);
	sprite1.addBuffer(new vlex::graphics::VertexBuffer(colorsA, 4 * 4, 4), 1);

	sprite2.addBuffer(new vlex::graphics::VertexBuffer(vertices, 4 * 3, 3), 0);
	sprite2.addBuffer(new vlex::graphics::VertexBuffer(colorsB, 4 * 4, 4), 1);

#endif




	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);	


	
	vlex::graphics::Shader shader("D:\\VS15Projects\\Vlex\\Vlex\\src\\graphics\\shader\\src\\basic.vert", "D:\\VS15Projects\\Vlex\\Vlex\\src\\graphics\\shader\\src\\basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(1.0), glm::vec3(4,3,0)));

	shader.setUniform4f("colour", glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

	while (!window.closed()) {
		window.clear();

		 
#if 0
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
#else
		sprite1.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(1.0), glm::vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);		
		ibo.unbind();
		sprite1.unbind();

		sprite2.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(1.0), glm::vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite2.unbind();


#endif
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