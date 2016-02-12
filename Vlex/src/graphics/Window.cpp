#include <iostream>
#include "Window.h"

namespace vlex {
	namespace graphics {

		void windowResize(GLFWwindow* window, int width, int height);
				
		Window::Window(std::string title, int width, int height) {
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!init())
				glfwTerminate();
		}

		Window::~Window() {
			glfwTerminate();
		}

		void Window::update() {

			//GLenum err = glGetError();
			//if (err != GL_NO_ERROR)
			//	std::cout << "OpenGL Err: " << err << std::endl;

			glfwPollEvents();

			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glViewport(0, 0, m_Width, m_Height);
			glfwSwapBuffers(m_Window);

		}

		bool Window::init() {

			
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

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void windowResize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}