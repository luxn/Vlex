#include "Texture.h"
#include "../utils/ImageUtils.h"

namespace vlex {
	namespace graphics {


		Texture::Texture(const std::string& path)
			:m_Path(path)
		{
			m_TextureID = load();
		}


		Texture::~Texture() {

		}


		void Texture::bind() const {

		}


		void Texture::unbind() const {

		}


		GLuint Texture::load() {
			return 0;
		}
	}
}