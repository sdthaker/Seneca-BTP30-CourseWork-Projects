#include <vector>
#include <iostream>
#include "Autoshop.h"

using namespace std;

namespace sdds {

	Autoshop::~Autoshop() {
		for (const auto& vehicle : m_vehicles) {
			delete vehicle;
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
		
		for (const auto& vehicle : m_vehicles) {
			vehicle->display(out);
		}

		out << "--------------------------------\n";
	}
}
