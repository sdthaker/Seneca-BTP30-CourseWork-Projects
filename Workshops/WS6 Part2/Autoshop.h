// Workshop 6
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles{};
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) 
			const;
	};

	template<typename T>
	void Autoshop::select
					(T test, std::list<const Vehicle*>& vehicles) const{
		/*for (const auto& v : m_vehicles) {
			if (test(v)) {
				vehicles.push_back(v);
			}
		}*/
		for (auto v = m_vehicles.cbegin(); v!= m_vehicles.cend(); ++v)
		{
			if (test(*v)) {
				vehicles.push_back(*v);
			}
		}
	}
}

#endif

