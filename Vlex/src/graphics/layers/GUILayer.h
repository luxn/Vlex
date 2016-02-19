#pragma once
#include "ILayer.h"

namespace vlex {
	namespace graphics {

		class GUILayer : public ILayer
		{
		public:
			GUILayer(Shader* shader);


			~GUILayer();


		};
	}
}