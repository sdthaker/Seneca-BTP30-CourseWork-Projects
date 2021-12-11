// Workshop 4
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/02
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {

	ConfirmationSender::ConfirmationSender
				(const ConfirmationSender& other) {
		*this = other;
	}

	ConfirmationSender& ConfirmationSender::operator=
				(const ConfirmationSender& other) {
		if (this != &other) {
			m_cnt = other.m_cnt;

			delete[] m_res;

			m_res = new const Reservation * [m_cnt];

			for (size_t i = 0; i < m_cnt; i++) {
				m_res[i] = other.m_res[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender
					(ConfirmationSender&& other) {
		*this = std::move(other);
	}

	ConfirmationSender& ConfirmationSender::operator=
						(ConfirmationSender&& other) {
		if (this != &other) {
			m_cnt = other.m_cnt;
			other.m_cnt = 0;

			delete[] m_res;
			m_res = other.m_res;
			other.m_res = nullptr;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=
						(const Reservation& res) {

		bool flag = true;

		for (size_t i = 0; i < m_cnt; i++) {
			if (m_res[i] == &res) {
				flag = false;
				break;
			}
		}

		if (flag) {
			const Reservation** local = 
					new const Reservation * [m_cnt + 1];

			for (size_t i = 0; i < m_cnt; i++) {
				local[i] = m_res[i];
			}

			local[m_cnt] = &res;
			delete[] m_res;

			m_res = local;
			++m_cnt;
		}

		return* this;
	}

	ConfirmationSender& ConfirmationSender::operator-=
						(const Reservation& res) {
		if (m_cnt) {
			size_t foundElemIdx{};
			bool flag = false;

			for (size_t i = 0; i < m_cnt; i++) {
				if (m_res[i] == &res) {
					foundElemIdx = i;
					flag = true;
					break;
				}
			}

			if (flag) {

				const Reservation** local = 
						new const Reservation * [m_cnt - 1];

				for (size_t i = 0; i < foundElemIdx; ++i) {
					local[i] = m_res[i];
				}

				for (size_t i = foundElemIdx + 1; i < m_cnt; ++i) {
					local[i - 1] = m_res[i];
				}
				delete[] m_res;

				m_res = local;
				local = nullptr;
				m_cnt -= 1;
			}
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] m_res;
	}

	std::ostream& operator<<(std::ostream& os, 
					const ConfirmationSender& res) {
		
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";

		if (res.m_res) {
			for (size_t i = 0; i < res.m_cnt; i++) {
				cout << *res.m_res[i];
			}
		}
		else {
			os << "There are no confirmations to send!\n";
		}
		return os << "--------------------------\n";
	}
}