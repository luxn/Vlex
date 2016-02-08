#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace vlex {
	namespace graphics {

		class Window {
		private:
			int m_Width;
			int m_Height;
			std::string m_Title;
			
			GLFWwindow* m_Window;

		public:
			Window(std::string title, int width, int height);
			~Window();

			bool closed() const;
			void update();
			void clear() const;

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

		private:
			bool init();

		};


	}
}

