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

			double m_Frequency;
			LARGE_INTEGER m_Start;


		public:
			Timer();			

			void reset();

			float elapsed();
		};
	}
}


