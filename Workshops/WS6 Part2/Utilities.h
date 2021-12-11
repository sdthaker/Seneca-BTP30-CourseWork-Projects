// Workshop 6
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <istream>
#include "Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}

#endif // !SDDS_UTILITIES_H
