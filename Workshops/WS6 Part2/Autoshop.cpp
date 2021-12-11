// Workshop 6
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <vector>
#include <iostream>
#include "Autoshop.h"

using namespace std;

namespace sdds {

	Autoshop::~Autoshop() {
		/*for (const auto& vehicle : m_vehicles) {
			delete vehicle;
		}*/
		for (auto iter = m_vehicles.cbegin();
			iter != m_vehicles.cend(); iter++) {
			delete* iter;
		}
	}

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------\n" <<
			"| Cars in the autoshop!        |" <<
			"\n--------------------------------\n";
		
		/*for (const auto& vehicle : m_vehicles) {
			vehicle->display(out);
			out << endl;
		}*/
		for (auto vehicle = m_vehicles.cbegin();
			vehicle != m_vehicles.cend(); vehicle++) {
			(*vehicle)->display(out);
			out << endl;
		}

		out << "--------------------------------\n";
	}
}
