#pragma once

#include <SFML/Graphics/Image.hpp>
#include <string>
#include <iostream>
#include <iomanip> //test
#include <sstream> //test

typedef unsigned char byte;
typedef unsigned int uint;

namespace vlex {
	namespace utils {

		static byte* loadImageAsByteArray(const std::string& path, uint* width, uint* height) {

			sf::Image image;
			if (!image.loadFromFile(path)) {
				std::cout << "Error: loadImageAsByteArray()" << std::endl;
			}

			*width = image.getSize().x;
			*height = image.getSize().y;

			int length = image.getSize().x * image.getSize().y;

			byte* res = new byte[length];

			for (uint y = 0; y < image.getSize().y; y++) {
				for (uint x = 0; x < image.getSize().x; x++) {

					//test
					std::stringstream stream;
					stream << std::hex << image.getPixel(x, y).toInteger();

					std::cout << stream.str() << std::endl;
					//---

					res[(x + (y * (*width)))] = image.getPixel(x, y).toInteger();
				}
			}

			return res;
			
		}

	}
}