#pragma once

//#include <chrono>
#include <Windows.h>

namespace vlex {
	namespace utils {


		class Timer
		{
		private:
			//clock_t m_start;
			//clock_t m_timeLast;

			double m_frequency;
			LARGE_INTEGER m_start;


		public:
			Timer();			

			void reset();

			float elapsed();
		};
	}
}


