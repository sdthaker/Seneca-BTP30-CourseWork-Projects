// Workshop 4
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/02
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
		Reservation* m_res = nullptr;
		size_t m_cnt;
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& other);
		Restaurant& operator=(const Restaurant& other);
		Restaurant(Restaurant&& other);
		Restaurant& operator=(Restaurant&& other);
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os,
										const Restaurant& res);
	};
}

#endif