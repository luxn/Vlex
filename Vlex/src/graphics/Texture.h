#pragma once
#include <GL/glew.h>
#include <string>

namespace vlex {
	namespace graphics {


		class Texture {

		private:
			std::string m_Path;
			GLuint m_TextureID;
			unsigned int m_Width;
			unsigned int m_Height;

		public:
			Texture(const std::string& path);
			~Texture();

			void bind() const;
			void unbind() const;

			inline unsigned int getWidth() const { return m_Width; }
			inline unsigned int getHeight() const { return m_Height; }

		private:
			GLuint load();


		};

	}
}