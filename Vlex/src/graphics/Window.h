#pragma once

#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include <SFML/Window.hpp>
#include <string>

namespace vlex {
	namespace graphics {

		class IWindow
		{
		private:
			int m_Width;
			int m_Height;
			std::string m_Title;

		public:
			
			virtual bool closed() const = 0;
			virtual void update() = 0;
			virtual void clear() const = 0;

			virtual int getWidth() const = 0;
			virtual int getHeight() const = 0;
			

		private:
			virtual bool init() = 0;

		};

		


		/*class GlfwWindow : public IWindow {
		private:
			int m_Width;
			int m_Height;
			std::string m_Title;
			
			GLFWwindow* m_Window;

		public:
			GlfwWindow(std::string title, int width, int height);
			~GlfwWindow();

			bool closed() const;
			void update();
			void clear() const;

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

		private:
			bool init();

		};*/

		class SfmlWindow : public IWindow
		{
		private:
			int m_Width;
			int m_Height;
			std::string m_Title;

			sf::Window* m_Window;
			bool m_Running;

		public:
			SfmlWindow(std::string title, int width, int height);
			~SfmlWindow();

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

