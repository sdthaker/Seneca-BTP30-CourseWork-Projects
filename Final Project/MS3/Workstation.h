// Name: Soham Thaker
// Seneca Student ID: 011-748-159
// Seneca email: sdthaker1@myseneca.ca
// Date of completion: 29/10/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include <string>
#include <iostream>

#include "CustomerOrder.h"
#include "Station.h"


namespace sdds {

	extern std::deque<sdds::CustomerOrder> pending;
	extern std::deque<sdds::CustomerOrder> completed;
	extern std::deque<sdds::CustomerOrder> incomplete;

	class Workstation: public Station{
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{};
	public:
		Workstation() {};
		Workstation(const std::string& record) : Station(record) {};
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

		Workstation(const Workstation& other) = delete;
		Workstation& operator=(const Workstation& other) = delete;
		Workstation(Workstation&& other) = delete;
		Workstation& operator=(Workstation&& other) = delete;
	};
	//not in use, just for practise
	/*std::ostream& operator<<(std::ostream& os, 
							const Workstation& ws);*/
}

#endif
