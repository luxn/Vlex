#include "Settings.h"

#include <RapidXML\rapidxml.hpp>
#include <RapidXML\rapidxml_utils.hpp>
#include "FileUtils.h"


namespace vlex {
	namespace utils {


		Settings::Settings(std::string settingsXMLPath) {
			
			
			rapidxml::file<> xmlFile(settingsXMLPath.c_str());

			rapidxml::xml_document<> doc;
			rapidxml::xml_node<> * root_node;
			doc.parse<0>(xmlFile.data());


			root_node = doc.first_node("vlex-engine-settings");


			for (rapidxml::xml_node<> * setting_node = root_node->first_node(); setting_node; setting_node = setting_node->next_sibling())
			{
				printf("settings.xml -> %s: %s\n", setting_node->name(), setting_node->value());

				if (strcmp(setting_node->name(), "window-title") == 0) {
					windowTitle = setting_node->value();
				}
				else if (strcmp(setting_node->name(), "window-width") == 0) {
					windowWidth = std::stoi(setting_node->value());
				}
				else if (strcmp(setting_node->name(), "window-height") == 0) {
					windowHeight = std::stoi(setting_node->value());
				}
				else if (strcmp(setting_node->name(), "window-framecap") == 0) {
					windowFramecap = std::stoi(setting_node->value());
				}
				else if (strcmp(setting_node->name(), "window-fullscreen") == 0) {
					if (strcmp(setting_node->value(), "true") == 0) {
						windowFullscreen = true;
					}
					else {
						windowFullscreen = false;
					}
				}
				else if (strcmp(setting_node->name(), "sf-depth-buffer-bits") == 0) {
					sfDepthBufferBits = (unsigned int)std::stoi(setting_node->value());
				}
				else if (strcmp(setting_node->name(), "sf-stencil-buffer-bits") == 0) {
					sfStencilBufferBits = (unsigned int)std::stoi(setting_node->value());
				}
				else if (strcmp(setting_node->name(), "sf-antialiasing") == 0) {
					sfAntialiasing = (unsigned int)std::stoi(setting_node->value());
				}
				else if (strcmp(setting_node->name(), "sf-opengl-major-version") == 0) {
					sfOpenGLMajorVersion = (unsigned int)std::stoi(setting_node->value());
				}
				else if (strcmp(setting_node->name(), "sf-opengl-minor-version") == 0) {
					sfOpenGLMinorVersion = (unsigned int)std::stoi(setting_node->value());
				}
				else if (strcmp(setting_node->name(), "path-resources") == 0) {
					resourcepath = setting_node->first_attribute()->value();
				}

			}


		}

	}
}