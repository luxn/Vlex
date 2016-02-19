#pragma once

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <string>
#include "../utils/Settings.h"

namespace vlex {
	namespace graphics {

		class Window
		{
		private:
			
			sf::Window* m_Window;
			bool m_Running;		
			utils::Settings* m_Settings;

		public:
			Window(utils::Settings* settings);
			~Window();

			bool closed() const;
			void update();
			void clear() const;

			inline int getWidth() const { return m_Settings->windowWidth; }
			inline int getHeight() const { return m_Settings->windowHeight; }

		private:
			bool init();

		};


	}
}

