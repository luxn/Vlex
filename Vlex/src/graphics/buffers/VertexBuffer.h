#pragma once

#include <GL/glew.h>

namespace vlex {
	namespace graphics {


		class VertexBuffer
		{
		private:

			GLuint m_BufferID;

			GLuint m_ComponentCount;

		public:
			VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount);
			~VertexBuffer();


			void bind() const;
			void unbind() const;

			GLuint getComponentCount() const;
		};


	}
}


