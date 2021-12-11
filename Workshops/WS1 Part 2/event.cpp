// Workshop 1 part 2
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/10
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <cstring>

#include "event.h"

using namespace std;

unsigned int g_sysClock;

namespace sdds {

	void Event::alloc(const char* desc) {
		if (desc) {

			delete[] m_eventDesc;

			m_eventDesc = new char[strlen(desc) + 1];
			strcpy(m_eventDesc, desc);
		}
	}

	Event::Event(const Event& other) {
		*this = other;
	}

	Event& Event::operator=(const Event& other) {
		
		if (this != &other) {

			m_sysClock = other.m_sysClock;

			if (other.m_eventDesc)
				alloc(other.m_eventDesc);
		}
		return *this;
	}

	Event::~Event() {
		delete[] m_eventDesc;
	}

	void Event::display() const {
		static int count = 1;
		unsigned int hour = 0, minutes = 0, seconds = 0;

		cout << setw(2) << count << ". ";

		if (strcmp(m_eventDesc, "No Event")) {

			findTime(hour, minutes, seconds, m_sysClock);
			cout << setfill('0') << setw(2) << hour << ":" 
				 << setw(2) << minutes << ":" << setw(2) << seconds
				 << " => " << m_eventDesc << endl << setfill(' ');
		}
		else {
			cout << "| " << m_eventDesc << " |\n";
		}

		count++;
	}

	void Event::findTime(unsigned int& hour, unsigned int& minutes,
		                 unsigned int& seconds, unsigned int sec) const {
		hour = sec / 3600u;
		sec = sec % 3600u;
		minutes = sec / 60u;
		seconds = sec % 60u;
	}


	void Event::set(const char* eventDesc) {
		if (eventDesc && eventDesc[0] != '\0') {
			m_sysClock = ::g_sysClock;
			alloc(eventDesc);
		}
		else {
			m_sysClock = 0;
			alloc("No Event");
		}
	}

}