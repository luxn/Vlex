#pragma once

#include "../Renderable2D.h"
#include <GL/glew.h>

namespace vlex {
	namespace graphics {


		class IRenderer2D
		{
		protected:
			virtual void submit(Renderable2D* renderable) = 0;
			virtual void flush() = 0;		
		};

	}
}