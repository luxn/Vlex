#pragma once
#include <GL/glew.h>

namespace vlex {
	namespace graphics {


		class IndexBuffer
		{
		private:

			GLuint m_BufferID;
			GLuint m_Count;

		public:
			IndexBuffer(GLushort* data, GLsizei count);
			~IndexBuffer();


			void bind() const;
			void unbind() const;

			GLuint getCount();
		};


	}
}


