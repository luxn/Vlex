#include "VertexBuffer.h"

namespace vlex {
	namespace graphics {

		VertexBuffer::VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount)
			: m_ComponentCount(componentCount)
		{

			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}


		VertexBuffer::~VertexBuffer()
		{
		}

		void VertexBuffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		}

		void VertexBuffer::unbind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		GLuint VertexBuffer::getComponentCount() const {
			return m_ComponentCount;
		}

	}
}