// Workshop 6
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <istream>
#include "Racecar.h"

namespace sdds {
	
	Racecar::Racecar(std::istream& in) : Car(in) {
		char c{};
		in >> c >> m_booster;
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}	
}
