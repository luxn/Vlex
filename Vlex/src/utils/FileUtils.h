#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


namespace vlex {
	namespace utils {

		static std::string readFileAsString(const std::string &pathToFile) {
			
			FILE* file = fopen(pathToFile.c_str(), "r");			
		
			if (file == nullptr) {
				std::cerr << "Could not open or find file at: " << pathToFile << std::endl;
				return ""; //todo
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



