#include <istream>
#include <string>
#include <iomanip>
#include <iostream>

#include "Car.h"

using namespace std;

namespace sdds {

	void Car::trim(const string& res, string& local) const {
		size_t start{}, end{};

		for (size_t i = 0; i < res.size(); i++) {
			if (res[i] != ' ') {
				start = i;
				break;
			}
		}

		for (size_t i = res.size() - 1; i >= 0u; i--) {
			if (res[i] != ' ') {
				end = i;
				break;
			}
		}

		for (size_t i = start; i < end + 1; i++) {
			local += res[i];
		}
	}

	Car::Car(istream& is) {
		string s;

		std::getline(is, s, ',');
		trim(s, m_maker);

		char c{};
		while (c != ',' && !m_condition) {
			is >> c; 
			if (c != ',')
				m_condition = c;
		}

		if (!m_condition)
			m_condition = 'n';

		if (m_condition != 'b' || m_condition != 'n' || m_condition != 'u') {
			throw "Invalid record!";
		}

		is >> c; //to extract ,
		is >> m_speed;

		if (!is.good()) {
			is.clear();
			throw "Invalid record!";
		}
	}

	double Car::topSpeed() const {
		return m_speed;
	}

	void Car::display(ostream& os) const {
		os << "| " << setw(10) << m_maker << " | "
			<< left << setw(6) << condition() << " | "
			<< fixed << setprecision(2) << setw(6) << m_speed
			<< " |\n" << right;
	}

	std::string Car::condition() const {
		return m_condition == 'n' ? "new"
			: m_condition == 'u' ? "used"
			: m_condition == 'b' ? "broken"
			: "";
	}

}