#include "ILayer.h"


namespace vlex {
	namespace graphics {

		ILayer::ILayer(IRenderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix) 
			:m_Renderer(renderer), m_Shader(shader), m_ProjectionMatrix(projectionMatrix)
		{
						


			m_Shader->enable();
			m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
			m_Shader->disable();
		}

		ILayer::~ILayer() {
			delete m_Shader;
			delete m_Renderer;

			
			for (int i = 0; i < m_Renderables.size(); i++)
			{
				delete m_Renderables[i];
			}
			
		}

		void ILayer::add(Renderable2D* renderable) {
			m_Renderables.push_back(renderable);
		}

		void ILayer::render() {
			m_Shader->enable();


			m_Renderer->begin();
			for (Renderable2D* renderable : m_Renderables) {
				m_Renderer->submit(renderable);
			}
			m_Renderer->end();

			m_Renderer->flush();
			m_Shader->disable();
		}

	}
}