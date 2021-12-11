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
