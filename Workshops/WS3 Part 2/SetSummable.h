// Workshop 3
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/25
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <string>
#include "Set.h"

namespace sdds {

	template <int N, typename T>
	class SetSummable: public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const;
	};

	template <int N, typename T>
	T SetSummable<N, T>::accumulate(const std::string& filter) const {
		
		T local(filter);
		bool flag = false;

		for (size_t i = 0; i < this->size(); i++) {
			if(this->get(i).isCompatibleWith(local)) {
				local += this->get(i);
				flag = true;
			}
		}

		if (!flag) {
			return T({}, {});
		}

		return local;
	}

}

#endif