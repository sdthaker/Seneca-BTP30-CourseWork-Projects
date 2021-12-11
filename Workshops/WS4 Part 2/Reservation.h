// Workshop 4
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/02
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {

	class Reservation {
		char* m_resId = nullptr;		//string
		std::string m_name{};
		std::string m_email{};
		size_t m_nbOfPeople{};
		size_t m_day{};
		size_t m_hour{};
		void alloc(const char* other);
		void beginTrim(std::string& str) const;
		void endTrim(std::string& str) const;
		void tokenResId(const std::string& res); //unnecessary
		size_t tokenName(const std::string& res);
		size_t tokenEmail(size_t prev, const std::string& res);
		size_t tokenNbPeople(size_t prev, const std::string& res);
		size_t tokenDay(size_t prev, const std::string& res);
		void tokenTime(size_t prev, const std::string& res);
		void display(size_t num, std::ostream& os, 
					const Reservation& res) const;
	public:
		Reservation() {};
		Reservation(const std::string& res);
		Reservation(const Reservation& other);
		Reservation& operator=(const Reservation& other);
		Reservation(Reservation&& other);
		Reservation& operator=(Reservation&& other);
		~Reservation();
		void update(int day, int time);
		friend std::ostream& operator<<(std::ostream& os, 
										const Reservation& res);
	};

}

#endif