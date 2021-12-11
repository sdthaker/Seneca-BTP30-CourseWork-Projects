// Workshop 6
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <istream>
#include <string>
#include <iostream>
#include "Vehicle.h"

namespace sdds {

	class Car: public Vehicle {
		std::string m_maker{};
		char m_condition{};
		double m_speed{};
		void trim(const std::string& res, std::string& local) const;
	public:
		Car(std::istream& is);
		double topSpeed() const;
		void display(std::ostream& os) const;
		std::string condition() const;
		~Car() {};
	};
}

#endif // !SDDS_CAR_H
