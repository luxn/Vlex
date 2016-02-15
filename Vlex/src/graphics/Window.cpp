#include <iostream>
#include "Window.h"

namespace vlex {
	namespace graphics {

		/*void windowResize(GLFWwindow* window, int width, int height);
		

		//----GLFW---
		GlfwWindow::GlfwWindow(std::string title, int width, int height) {
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!init())
				glfwTerminate();
		}

		GlfwWindow::~GlfwWindow() {
			glfwTerminate();
		}

		void GlfwWindow::update() {

			//GLenum err = glGetError();
			//if (err != GL_NO_ERROR)
			//	std::cout << "OpenGL Err: " << err << std::endl;

			glfwPollEvents();

			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glViewport(0, 0, m_Width, m_Height);
			glfwSwapBuffers(m_Window);

		}

		bool GlfwWindow::init() {

			
			if (!glfwInit()) {
				std::cout << "Failed: glfwInit()" << std::endl;
				return false;
			}
			
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);

			if (!m_Window) {
				glfwTerminate();
				std::cout << "Failed: glfwCreateWindow()" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, windowResize);

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed: glewInit()" << std::endl;
				return false;
			}

			return true;

		}

		bool GlfwWindow::closed() const {
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void GlfwWindow::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		*/

		//---SFML----
		
		SfmlWindow::SfmlWindow(std::string title, int width, int height) {
			m_Title = title;
			m_Width = width;
			m_Height = height;
			m_Running = true;

			if (!init())
				std::cout << "Could not Create and Init SFMLWindow" << std::endl;
		}

		SfmlWindow::~SfmlWindow() {
			delete m_Window;
		}

		void SfmlWindow::update() {

			//GLenum err = glGetError();
			//if (err != GL_NO_ERROR)
			//	std::cout << "OpenGL Err: " << err << std::endl;


			sf::Event event;
			while (m_Window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					// end the program
					m_Running = false;
				}
				else if (event.type == sf::Event::Resized)
				{
					// adjust the viewport when the window is resized
					glViewport(0, 0, event.size.width, event.size.height);
				}
			}

			
			m_Window->display();

		}

		bool SfmlWindow::init() {

		
			m_Window = new sf::Window(sf::VideoMode(m_Width, m_Height), m_Title);
				

			if (!m_Window) {
				std::cout << "Failed: new sf::Window()" << std::endl;
				return false;
			}			

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed: glewInit()" << std::endl;
				return false;
			}

			return true;

		}

		bool SfmlWindow::closed() const {
			return !m_Running;
		}

		void SfmlWindow::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		








		/*void windowResize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}*/
	}
}