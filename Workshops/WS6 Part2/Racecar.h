// Workshop 6
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <istream>
#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster{};
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
		~Racecar() {};
	};
}

#endif // !SDDS_RACECAR_H
