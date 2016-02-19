#include "Window.h"
#include <iostream>

namespace vlex {
	namespace graphics {

		Window::Window(utils::Settings* settings)
			: m_Settings(settings) 
		{						
			m_Running = true;

			if (!init())
				std::cout << "Could not Create and Init SFMLWindow" << std::endl;
		}

		Window::~Window() {
			delete m_Window;			
		}

		void Window::update() {

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

		bool Window::init() {
			
			sf::ContextSettings contextSettings(	m_Settings->sfDepthBufferBits,
													m_Settings->sfStencilBufferBits,
													m_Settings->sfAntialiasing,
													m_Settings->sfOpenGLMajorVersion,
													m_Settings->sfOpenGLMinorVersion);

			unsigned int windowStyle = sf::Style::Default;
			if (m_Settings->windowFullscreen)
				windowStyle = sf::Style::Fullscreen;					

			sf::VideoMode videoMode(m_Settings->windowWidth, m_Settings->windowHeight);


			m_Window = new sf::Window(videoMode, m_Settings->windowTitle, windowStyle, contextSettings);
				
			
			if (!m_Window) {
				std::cout << "Failed: new sf::Window()" << std::endl;
				return false;
			}			

			m_Window->setFramerateLimit(m_Settings->windowFramecap);			

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed: glewInit()" << std::endl;
				return false;
			}

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

			return true;

		}

		bool Window::closed() const {
			return !m_Running;
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
				

	}
}