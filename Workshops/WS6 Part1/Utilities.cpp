#include <istream>
#include <string>
#include <fstream>
#include <sstream>

#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"

using namespace std;

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		
		if (in.good()) {
			char s{};
			in >> s;

			if (s == 'c' || s == 'C' || s == 'r' || s == 'R') {
				in >> s;
				Car* c = new Car(in);
				return c;
			}
			else {
				return nullptr;
			}
		}
		else {
			in.setstate(ios::badbit);
			return nullptr;
		}
	}
}