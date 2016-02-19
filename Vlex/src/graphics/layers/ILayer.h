#pragma once

#include "../Renderable2D.h"
#include "../renderer/IRenderer2D.h"
#include "../shader/Shader.h"
#include "../../math/Math.h"

namespace vlex {
	namespace graphics {


		class ILayer
		{
		public:
			IRenderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;

			glm::mat4 m_ProjectionMatrix;
					
		protected:
			ILayer(IRenderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix);
			ILayer();
		public:
			virtual ~ILayer();
			virtual void add(Renderable2D* renderable);
			virtual void render();
		
		};


	}
}