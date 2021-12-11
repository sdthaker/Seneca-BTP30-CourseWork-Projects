// Workshop 1 part 2
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/10
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;

namespace sdds {
	
	class Event {
		char* m_eventDesc = nullptr;
		unsigned int m_sysClock = 0;
		void alloc(const char* desc);
		void findTime(unsigned int& hour, unsigned int& minutes,
			          unsigned int& seconds, unsigned int sec) const;
	public:
		Event() {}
		Event(const Event& other);
		Event& operator=(const Event& other);
		~Event();
		void display() const;
		void set(const char* eventDesc = nullptr);
	};
}

#endif // !SDDS_EVENT_H
