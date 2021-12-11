// Name: Soham Thaker
// Seneca Student ID: 011-748-159
// Seneca email: sdthaker1@myseneca.ca
// Date of completion: 29/10/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <deque>
#include <iostream>
#include <algorithm>

#include "Workstation.h"

using namespace std;

namespace sdds {

	std::deque<sdds::CustomerOrder> pending{};
	std::deque<sdds::CustomerOrder> completed{};
	std::deque<sdds::CustomerOrder> incomplete{};

	void Workstation::fill(ostream& os) {
		if (!m_orders.empty() && !m_orders.front().isFilled()) {
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder() {

		bool moved = false;

		if (m_orders.empty())
			return moved;

		if (m_orders.front().isItemFilled(getItemName()) 
									|| !getQuantity()) { 
			if (m_pNextStation) {
				*m_pNextStation += std::move(m_orders.front());
			}
			else if (m_orders.front().isFilled()) {
				completed.push_back(std::move(m_orders.front()));
			}
			else {
				incomplete.push_back(std::move(m_orders.front()));
			}
			m_orders.pop_front();
			moved = true;
		}
		return moved;
	}

	void Workstation::setNextStation(Workstation* station) {
		if (station) {
			m_pNextStation = station;
		}
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

	void Workstation::display(std::ostream& os) const {
		os << getItemName() << " --> "
			<< (m_pNextStation ? 
				m_pNextStation->getItemName() : "End of Line");
		os << endl;
	}

	//not in use, just for practise
	//std::ostream& operator<<(std::ostream& os, const Workstation& ws) {
	//	ws.display(os);
	//	return os;
	//}
}
