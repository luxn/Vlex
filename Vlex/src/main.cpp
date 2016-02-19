#include "graphics/Window.h"
#include "graphics/layers/GUILayer.h"
#include "graphics/shader/Shader.h"
#include "graphics/Sprite.h"
#include "math/Math.h"
#include "utils/Timer.h"
#include "utils/Settings.h"

#include "utils/ImageUtils.h"


int main() {
		
#if 0
	vlex::utils::Settings settings("D:\\VS15Projects\\Vlex\\Vlex\\src\\settings.xml");
	
	vlex::graphics::Window window(&settings);
	

		
	vlex::utils::Timer time; 
	float timer = 0.0f;
	int frames = 0;




	
	vlex::graphics::Shader* shader = new vlex::graphics::Shader("D:\\VS15Projects\\Vlex\\Vlex\\src\\graphics\\shader\\src\\basic.vert", "D:\\VS15Projects\\Vlex\\Vlex\\src\\graphics\\shader\\src\\basic.frag");
	
	vlex::graphics::GUILayer layer(shader);
	layer.add(new vlex::graphics::Sprite(0, 0, 4, 4, glm::vec4(1, 1, 0, 1)));
	

	while (!window.closed()) {
		window.clear();


		layer.render();


		window.update();

		frames++;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}


	}

#endif

	std::string s = "C:\\Users\\Lux\\Desktop\\test.png";
	uint imagewidth = 0;
	uint imageheight = 0;

	byte* imageData = vlex::utils::loadImageAsByteArray(s, &imagewidth, &imageheight);



	std::cin.get();

	return 0;
}