#pragma once

#include "../Renderable2D.h"
#include "../renderer/IRenderer2D.h"


namespace vlex {
	namespace graphics {
	
		class Group //: public Renderable2D
		{
		private:
			std::vector<Renderable2D*> m_Renderables;
			glm::mat4 m_TransformationMatrix;

		public:
			Group(const glm::mat4& transform);
			~Group();
			void add(Renderable2D* renderable);
			//void submit(IRenderer2D* renderer) const override; todo

			glm::mat4& GetTransformReference() { return m_TransformationMatrix; }

		};

		
	
	
	}
}