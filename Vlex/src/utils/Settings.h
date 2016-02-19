#pragma once

#include <string>

typedef unsigned int uint;

namespace vlex {
	namespace utils {
		
		class Settings
		{
		public:
			std::string windowTitle; // = "VlexEngine";
			int windowWidth; // = 800;
			int windowHeight; // = 640;
			int windowFramecap; // = 120;
			bool windowFullscreen; // = false;

			uint sfDepthBufferBits; // = 0;
			uint sfStencilBufferBits; // = 0;
			uint sfAntialiasing; // = 0;
			uint sfOpenGLMajorVersion; // = 1;
			uint sfOpenGLMinorVersion; // = 1;

			std::string resourcepath; // "{execubatle}/res"

		public:
			Settings(std::string settingsXMLPath);
			
				
			
		};


		
		
	}
}