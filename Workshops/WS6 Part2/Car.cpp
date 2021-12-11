// Workshop 6
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <istream>
#include <string>
#include <iomanip>
#include <sstream>
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
		string record;
		char comma{};

		std::getline(is, record, ',');
		trim(record, m_maker);

		is >> m_condition;

		if (m_condition == ',' || !m_condition) {
			m_condition = 'n';
		}
		else {
			is >> comma;
		}
		
		if (m_condition != 'b' && 
				m_condition != 'n' && m_condition != 'u') {
			throw "Invalid record!";
		}

		is >> m_speed;

		if (is.fail()) {
			throw "Invalid record!";
		}
	}

	double Car::topSpeed() const {
		return m_speed;
	}

	void Car::display(ostream& os) const {
		os << "| " << setw(10) << m_maker << " | "
			<< left << setw(6) << condition() << " | "
			<< fixed << setprecision(2) << setw(6) << topSpeed()
			<< " |" << right;
	}

	std::string Car::condition() const {
		return m_condition == 'n' ? "new"
			: m_condition == 'u' ? "used"
			: m_condition == 'b' ? "broken"
			: "";
	}
}