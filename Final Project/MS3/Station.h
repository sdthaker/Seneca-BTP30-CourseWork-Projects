// Name: Soham Thaker
// Seneca Student ID: 011-748-159
// Seneca email: sdthaker1@myseneca.ca
// Date of completion: 26/10/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>
#include <iostream>

namespace sdds {

	class Station {
		int m_id{};
		std::string m_itemName{};
		std::string m_desc{};
		size_t m_serialnum{};
		size_t m_qty{};
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station() {};
		Station(const std::string& record);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif
