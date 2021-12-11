// Workshop 6
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <istream>
#include <string>
#include <sstream>

#include "Racecar.h"
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"

using namespace std;

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		
		Vehicle* result{};

		char type{}, comma{};
		string record{};
		getline(in, record);

		stringstream ss(record);
		ss >> type >> comma;

		if (ss) {
			if (type == 'c' || type == 'C') {
				result = new Car(ss);
			}
			else if (type == 'r' || type == 'R') {
				result = new Racecar(ss);
			}
			else {
				throw std::string("Unrecognized record type: [") + type + "]";
			}
		}
		return result;
	}
}