#pragma once

#include <string>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

namespace vlex {
	namespace utils {

		static std::string readFileAsString(const std::string &pathToFile) {
			FILE* file;

			errno_t err = fopen_s(&file, pathToFile.c_str(), "rt");
		
			if (err == 0 || file == nullptr) {
				std::cerr << "Could not open or find file at: " << pathToFile << std::endl;
				return  "Could not open or find file at: " + pathToFile;
			}
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);

			char* data = new char[length + 1];
			memset(data, 0, length + 1);

			fseek(file, 0, SEEK_SET);

			fread(data, 1, length, file);

			fclose(file);


			std::string res(data);
			delete[] data;
			return res;
		}

	}
}



