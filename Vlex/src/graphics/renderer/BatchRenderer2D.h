#pragma once

#include "IRenderer2D.h"
#include "../buffers/Buffers.h"

namespace vlex {
	namespace graphics {

#define RENDERER_MAX_SPRITES	70000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)	//28 bytes
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6
		
#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1

		class BatchRenderer2D : public IRenderer2D
		{
		private:
			GLuint m_VAO;
			GLuint m_VBO;
			IndexBuffer* m_IBO;
			GLsizei m_IndexCount;

			VertexData* m_Buffer;
						
		public:
			BatchRenderer2D();
			~BatchRenderer2D();

			void begin();
			void submit(Renderable2D* renderable) override;
			void end();
			void flush() override;

		private:
			void init();
		};
		



	}
}