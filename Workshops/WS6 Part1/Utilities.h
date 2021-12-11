#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <istream>
#include "Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}

#endif // !SDDS_UTILITIES_H
