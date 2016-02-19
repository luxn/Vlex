#include <iostream>
#include <vector>
#include <ctime>

#include "graphics/Window.h"
#include "graphics/shader/Shader.h"
#include "utils/Timer.h"
#include "utils/FileUtils.h"
#include "math/Math.h"
#include "graphics/renderer/BatchRenderer2D.h"
#include "graphics/Sprite.h"
#include "utils/Settings.h"


int main() {


	vlex::utils::Settings settings("D:\\VS15Projects\\Vlex\\Vlex\\src\\settings.xml");
	
		
	vlex::graphics::Window window(&settings);

	

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	//std::cout << "GL_VERSION:    " << glGetString(GL_VERSION)  << std::endl;
	//std::cout << "GL_RENDERER:   " << glGetString(GL_RENDERER) << std::endl;
	//std::cout << "GL_VENDOR:     " << glGetString(GL_VENDOR)   << std::endl;

	
	vlex::utils::Timer time; 
	float timer = 0.0f;
	int frames = 0;


	vlex::graphics::BatchRenderer2D batchRenderer;



	vlex::graphics::Sprite sprite1(0, 0, 2, 4, glm::vec4(1, 0, 0, 1));
	vlex::graphics::Sprite sprite2(4, 4, 4, 4, glm::vec4(0.5f, 0.5f, 1, 1));


	std::vector<vlex::graphics::Renderable2D*> sprites;

	srand(std::time(NULL));

	/*
	for (float y = 0; y < 16.0f; y+=0.1f) {
		for (float x = 0; x < 16.0f; x+=0.1f) {
			sprites.push_back(new vlex::graphics::Sprite(x, y, 0.08f, 0.08f, glm::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}	
	}
	*/

	
	for (float y = 0; y < 16.0f; y+=0.3f) {
		for (float x = 0; x < 16.0f; x+=0.3f) {
			sprites.push_back(new vlex::graphics::Sprite(x, y, 0.2f, 0.2f, glm::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
	




	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);	


	
	vlex::graphics::Shader shader("D:\\VS15Projects\\Vlex\\Vlex\\src\\graphics\\shader\\src\\basic.vert", "D:\\VS15Projects\\Vlex\\Vlex\\src\\graphics\\shader\\src\\basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(1.0), glm::vec3(0,0,0)));

	shader.setUniform4f("colour", glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

	while (!window.closed()) {
		window.clear();



		batchRenderer.begin();
		for (int i = 0; i < sprites.size(); i++) {
			batchRenderer.submit(sprites.at(i));
		}
		//batchRenderer.submit(&sprite1);
		//batchRenderer.submit(&sprite2);
		batchRenderer.end();

		batchRenderer.flush();




		window.update();

		frames++;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}


	}


	return 0;
}