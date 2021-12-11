// Workshop 2 part 2
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <chrono>
#include <string>

namespace sdds {
	
	class TimedEvents {
		size_t m_recordCount{};
		std::chrono::steady_clock::time_point m_start{};
		std::chrono::steady_clock::time_point m_end{};
		struct {
			std::string m_eventName{};
			std::string m_unitsOfTime{};
			std::chrono::steady_clock::duration m_duration{};
		} m_event[10];
	public:
		TimedEvents() {};
		void startClock();
		void stopClock();
		void addEvent(const char* event);
		friend std::ostream& operator<< 
			(std::ostream& os, const TimedEvents& other);
	};

}

#endif