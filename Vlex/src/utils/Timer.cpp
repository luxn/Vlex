#include "Timer.h"

namespace vlex {
	namespace utils {

		Timer::Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_frequency = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&m_start);
		}
		

		void Timer::reset()
		{
			QueryPerformanceCounter(&m_start);
		}

		float Timer::elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - m_start.QuadPart;
			//m_start = current;
			
			return (float) (cycles * m_frequency);
		}

	}
}