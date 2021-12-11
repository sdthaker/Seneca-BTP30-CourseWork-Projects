// Workshop 2 part 2
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace sdds {
	void TimedEvents::startClock() {
		m_start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		m_end = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* event) {
		if (m_recordCount < 10) {
			m_event[m_recordCount].m_eventName = event;
			m_event[m_recordCount].m_unitsOfTime = "nanoseconds";
			m_event[m_recordCount].m_duration = 
				std::chrono::duration_cast
				<std::chrono::nanoseconds>(m_end - m_start);
			m_recordCount++;
		}
	}

	ostream& operator<<(ostream& os, const TimedEvents& other) {
		os << setfill('-') << setw(26) << "" << "\n" 
			<< "Execution Times:\n" << setfill('-')
			<< setw(26) << "" << setfill(' ') << "\n";

		for (size_t i = 0; i < other.m_recordCount; i++) {
			os << setw(21) << left << other.m_event[i].m_eventName
				<< setw(13) << right << other.m_event[i].m_duration.count()
				<< " " << other.m_event[i].m_unitsOfTime << "\n";
		}

		os << setfill('-') << setw(26) << "" << "\n";

		return os;
	}
}