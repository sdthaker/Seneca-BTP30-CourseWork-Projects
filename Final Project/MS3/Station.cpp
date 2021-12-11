// Name: Soham Thaker
// Seneca Student ID: 011-748-159
// Seneca email: sdthaker1@myseneca.ca
// Date of completion: 26/10/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <iostream>
#include <iomanip>

#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	size_t Station::m_widthField{};

	size_t Station::id_generator{};

	Station::Station(const string& record) {
		
		m_id = ++id_generator;
		Utilities util;
		bool more = true;
		size_t pos = 0u;

		m_itemName = util.extractToken(record, pos, more);
		m_serialnum = stoi(util.extractToken(record, pos, more));
		m_qty = stoi(util.extractToken(record, pos, more));

		if (m_widthField < util.getFieldWidth()) {
			m_widthField = util.getFieldWidth();
		}

		m_desc = util.extractToken(record, pos, more);
	}

	const string& Station::getItemName() const{
		return m_itemName;
	}

	size_t Station::getNextSerialNumber() {
		size_t current = m_serialnum++;
		return current;
	}

	size_t Station::getQuantity() const {
		return m_qty;
	}

	void Station::updateQuantity() {
		if (m_qty) {
			--m_qty;
		}
	}

	void Station::display(ostream& os, bool full) const {
		if (full) {
			os << "[" << setw(3) << setfill('0') << m_id << "]"
				<< " Item: " << setfill(' ') << setw(m_widthField)
				<< left << m_itemName << " [" << setw(6) << setfill('0') 
				<< right << m_serialnum << "]" << " Quantity: "
				<< setw(m_widthField) << setfill(' ') << left
				<< m_qty << " Description: " << m_desc << right;
		}
		else {
			os << "[" << setw(3) << setfill('0') << m_id << "]"
				<< " Item: " << setfill(' ') << setw(m_widthField)
				<< left << m_itemName << " [" << setw(6) << setfill('0') 
				<< right << m_serialnum << "]";
		}
		os << endl;
	}

}