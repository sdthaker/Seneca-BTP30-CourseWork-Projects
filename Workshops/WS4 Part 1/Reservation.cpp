#include <iostream>
#include <string>
#include <iomanip>

#include "Reservation.h"

using namespace std;

namespace sdds {

	void Reservation::beginTrim(string& str) const {
		str.erase(0, str.find_first_not_of(' '));
	}

	void Reservation::endTrim(string& str) const {
		str.erase(str.find_last_not_of(' ') + 1);
	}

	void Reservation::alloc(const string& other) {
		size_t i;
		delete[] m_resId;

		m_resId = new char[other.size() + 1];
		for (i = 0; i < other.size(); i++) {
			m_resId[i] = other[i];
		}
		m_resId[i] = '\0';
	}

	void Reservation::extResId(const std::string& res){
		string local{};
		size_t pos;

		if (res[res.find(':') - 1] != ' ') {
			pos = res.find(':');
			local = res.substr(0, pos);

			beginTrim(local);
			endTrim(local);

			alloc(local);
		}
		else {
			pos = res.find(':') - 1;
			local = res.substr(0, pos);

			beginTrim(local);
			endTrim(local);

			alloc(local);
		}
	}

	size_t Reservation::extName(const std::string& res) {

		size_t pos, count, prev;

		pos = res.find(':') + 1;
		count = res.find(',') - pos;
		prev = res.find(',') + 1;

		m_name = res.substr(pos, count);

		beginTrim(m_name);
		endTrim(m_name);

		return prev;
	}

	size_t Reservation::extEmail(size_t prev, const std::string& res) {
		size_t pos, count;

		pos = prev;
		count = res.find_first_of(',', prev) - prev;
		prev = res.find_first_of(',', prev) + 1;

		m_email = res.substr(pos, count);

		beginTrim(m_email);
		endTrim(m_email);

		m_email.insert(0, 1, '<');
		m_email.insert(m_email.size(), 1, '>');

		return prev;
	}

	size_t Reservation::extNbPeople(size_t prev, const std::string& res) {

		string local{};
		size_t pos, count;

		pos = prev;
		count = res.find_first_of(',', prev) - prev;
		prev = res.find_first_of(',', prev) + 1;

		local = res.substr(pos, count);

		beginTrim(local);
		endTrim(local);

		m_nbOfPeople = stoi(local);

		return prev;
	}

	size_t Reservation::extDay(size_t prev, const std::string& res) {
		
		string local{};
		size_t pos, count;

		pos = prev;
		count = res.find_first_of(',', prev) - prev;
		prev = res.find_first_of(',', prev) + 1;

		local = res.substr(pos, count);

		beginTrim(local);
		endTrim(local);

		m_day = stoi(local);

		return prev;
	}

	void Reservation::extTime(size_t prev, const std::string& res) {

		string local{};

		local = res.substr(prev, res.size());

		beginTrim(local);
		endTrim(local);

		m_hour = stoi(local);
	}

	Reservation::Reservation(const std::string& res) {

		size_t prev{};

		extResId(res);
		prev = extName(res);
		prev = extEmail(prev, res);
		prev = extNbPeople(prev, res);
		prev = extDay(prev, res);
		extTime(prev, res);
	}

	Reservation::~Reservation() {
		delete[] m_resId;
	}


	void Reservation::update(int day, int time) {
		m_day = day;
		m_hour = time;
	}

	void Reservation::display(size_t num, std::ostream& os, const Reservation& res) const {

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

	std::ostream& operator<<(std::ostream& os,const Reservation& res) {

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