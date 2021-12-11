// Workshop 4
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/02
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** m_res = nullptr;
		size_t m_cnt{};
	public:
		ConfirmationSender() {};
		ConfirmationSender(const ConfirmationSender& other);
		ConfirmationSender& operator=
			(const ConfirmationSender& other);
		ConfirmationSender(ConfirmationSender&& other);
		ConfirmationSender& operator=(ConfirmationSender&& other);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		~ConfirmationSender();
		friend std::ostream& operator<<(std::ostream& os,
							const ConfirmationSender& res);
	};
}

#endif