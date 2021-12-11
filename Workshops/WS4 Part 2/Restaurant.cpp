// Workshop 4
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/02
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Restaurant.h"

using namespace std;

namespace sdds {

	Restaurant::Restaurant(const Reservation* reservations[],
							size_t cnt) {
		m_cnt = cnt;
		delete[] m_res;

		m_res = new Reservation[m_cnt];

		for (size_t i = 0; i < m_cnt; i++) {
			m_res[i] = *reservations[i];
		}
	}

	Restaurant::Restaurant(const Restaurant& other) {
		*this = other;
	}

	Restaurant& Restaurant::operator=(const Restaurant& other) {
		if (this != &other) {
			m_cnt = other.m_cnt;

			delete[] m_res;

			m_res = new Reservation[m_cnt];

			for (size_t i = 0; i < m_cnt; i++) {
				m_res[i] = other.m_res[i];
			}
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& other) {
		*this = std::move(other);
	}

	Restaurant& Restaurant::operator=(Restaurant&& other) {

		if (this != &other) {
			m_cnt = other.m_cnt;

			delete[] m_res;
			m_res = other.m_res;
			other.m_res = nullptr;
		}
		return *this;
	}

	Restaurant::~Restaurant() {
		delete[] m_res;
	}

	size_t Restaurant::size() const {
		return m_cnt;
	}

	std::ostream& operator<<(std::ostream& os, 
					const Restaurant& res) {
		static size_t CALL_CNT = 1;

		os << "--------------------------\n";
		os << "Fancy Restaurant (" << CALL_CNT++ << ")\n";
		os << "--------------------------\n";

		if (res.m_res) {
			for (size_t i = 0; i < res.m_cnt; i++) {
				os << res.m_res[i];
			}
		}
		else {
			os << "This restaurant is empty!\n";
		}
		return os << "--------------------------\n";
	}
}