// Workshop 4
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/02
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

#include "Reservation.h"

using namespace std;

namespace sdds {

	Reservation::Reservation(const Reservation& other) {
		*this = other;
	}

	Reservation& Reservation::operator=(const Reservation& other) {
		if (this != &other) {
			m_name = other.m_name;
			m_email = other.m_email;
			m_nbOfPeople = other.m_nbOfPeople;
			m_day = other.m_day;
			m_hour = other.m_hour;

			alloc(other.m_resId);
		}
		return *this;
	}

	Reservation::Reservation(Reservation&& other) {
		*this = std::move(other);
	}

	Reservation& Reservation::operator=(Reservation&& other) {
		if (this != &other) {
			m_name = other.m_name;
			m_email = other.m_email;
			m_nbOfPeople = other.m_nbOfPeople;
			m_day = other.m_day;
			m_hour = other.m_hour;

			delete[] m_resId;
			m_resId = other.m_resId;
			other.m_resId = nullptr;

			other.m_name = "";
			other.m_email = "";
			other.m_nbOfPeople = 0;
			other.m_day = 0;
			other.m_hour = 0;
		}
		return *this;
	}

	void Reservation::beginTrim(string& str) const {
		str.erase(0, str.find_first_not_of(' '));
	}

	void Reservation::endTrim(string& str) const {
		str.erase(str.find_last_not_of(' ') + 1);
	}

	void Reservation::alloc(const char* other) {
		delete[] m_resId;
		m_resId = new char[strlen(other) + 1];
		strcpy(m_resId, other);
	}

	void Reservation::tokenResId(const std::string& res) {
		string local{};
		size_t pos;

		pos = res.find(':');
		local = res.substr(0, pos);

		beginTrim(local);
		endTrim(local);

		alloc(local.c_str());
	}

	size_t Reservation::tokenName(const std::string& res) {

		size_t pos, count, prev;

		pos = res.find(':') + 1;
		count = res.find(',') - pos;
		prev = res.find(',') + 1;

		m_name = res.substr(pos, count);

		beginTrim(m_name);
		endTrim(m_name);

		return prev;
	}

	size_t Reservation::tokenEmail(size_t prev, 
						const std::string& res) {
		size_t pos, count;

		pos = prev;
		count = res.find(',', prev) - prev;
		prev = res.find(',', prev) + 1;

		m_email = res.substr(pos, count);

		beginTrim(m_email);
		endTrim(m_email);

		m_email.insert(0, 1, '<');
		m_email.insert(m_email.size(), 1, '>');

		return prev;
	}

	size_t Reservation::tokenNbPeople(size_t prev, 
						const std::string& res) {

		string local{};
		size_t pos, count;

		pos = prev;
		count = res.find(',', prev) - prev;
		prev = res.find(',', prev) + 1;

		local = res.substr(pos, count);

		beginTrim(local);
		endTrim(local);

		m_nbOfPeople = stoi(local);

		return prev;
	}

	size_t Reservation::tokenDay(size_t prev, 
						const std::string& res) {
		
		string local{};
		size_t pos, count;

		pos = prev;
		count = res.find(',', prev) - prev;
		prev = res.find(',', prev) + 1;

		local = res.substr(pos, count);

		beginTrim(local);
		endTrim(local);

		m_day = stoi(local);

		return prev;
	}

	void Reservation::tokenTime(size_t prev, 
					  const std::string& res) {

		string local{};

		local = res.substr(prev, res.size());

		beginTrim(local);
		endTrim(local);

		m_hour = stoi(local);
	}

	Reservation::Reservation(const std::string& res) {

		size_t prev{};

		tokenResId(res);
		prev = tokenName(res);
		prev = tokenEmail(prev, res);
		prev = tokenNbPeople(prev, res);
		prev = tokenDay(prev, res);
		tokenTime(prev, res);
	}

	Reservation::~Reservation() {
		delete[] m_resId;
	}

	void Reservation::update(int day, int time) {
		m_day = day;
		m_hour = time;
	}

	void Reservation::display(size_t num, std::ostream& os, 
					const Reservation& res) const {

		if (num == 1) {
			os << "Reservation " << right << setw(10) << res.m_resId << ": "
				<< setw(20) << res.m_name << "  " << left << setw(20) << res.m_email;
		}
		else {
			if (res.m_nbOfPeople == 1) {
				os << " on day " << res.m_day
					<< " @ " << res.m_hour << ":00 for "
					<< res.m_nbOfPeople << " person.";
			}
			else {
				os << " on day " << res.m_day
					<< " @ " << res.m_hour << ":00 for "
					<< res.m_nbOfPeople << " people.";
			}
		}
	}

	std::ostream& operator<<(std::ostream& os, 
					const Reservation& res) {

		if (res.m_hour >= 6 && res.m_hour <= 9) {
			res.display(1, os, res);
			os << "    Breakfast";
			res.display(2, os, res);
		}
		else if (res.m_hour >= 11 && res.m_hour <= 15) {
			res.display(1, os, res);
			os << "    Lunch";
			res.display(2, os, res);
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21) {
			res.display(1, os, res);
			os << "    Dinner";
			res.display(2, os, res);
		}
		else {
			res.display(1, os, res);
			os << "    Drinks";
			res.display(2, os, res);
		}
		return os << endl;
	}

}