#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {

	class Reservation {
		char* m_resId = nullptr;
		std::string m_name{};
		std::string m_email{};
		size_t m_nbOfPeople{};
		size_t m_day{};
		size_t m_hour{};
		void alloc(const std::string& other);
		void beginTrim(std::string& str) const;
		void endTrim(std::string& str) const;
		void extResId(const std::string& res);
		size_t extName(const std::string& res);
		size_t extEmail(size_t prev, const std::string& res);
		size_t extNbPeople(size_t prev, const std::string& res);
		size_t extDay(size_t prev, const std::string& res);
		void extTime(size_t prev, const std::string& res);
		void display(size_t num, std::ostream& os, const Reservation& res) const;
	public:
		Reservation() {};
		Reservation(const std::string& res);
		~Reservation();
		void update(int day, int time);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};

}

#endif