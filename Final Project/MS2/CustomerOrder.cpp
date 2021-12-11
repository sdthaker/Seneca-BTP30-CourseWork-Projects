// Name: Soham Thaker
// Seneca Student ID: 011-748-159
// Seneca email: sdthaker1@myseneca.ca
// Date of completion: 28/10/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <iostream>
#include <iomanip>

#include "Station.h"
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	size_t CustomerOrder::m_widthField{};

	CustomerOrder::CustomerOrder(const string& record) {

		Utilities util;
		bool more = true;
		size_t pos = 0u;

		m_name = util.extractToken(record, pos, more);
		m_product = util.extractToken(record, pos, more);

		while (more) {
			Item** lstItem = new Item * [m_cntItem + 1];

			for (size_t i = 0; i < m_cntItem; i++) {
				lstItem[i] = m_lstItem[i];
			}

			lstItem[m_cntItem] = 
							new Item(util.extractToken(record, pos, more));

			delete[] m_lstItem;
			m_cntItem++;
			m_lstItem = lstItem;
		}

		if (m_widthField < util.getFieldWidth()) {
			m_widthField = util.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept{
		*this = std::move(other);
	}

	CustomerOrder& CustomerOrder::operator=
		(CustomerOrder&& other) noexcept{
		if (this != &other) {
			m_name = other.m_name;
			other.m_name = "";

			m_product = other.m_product;
			other.m_product = "";

			if (m_cntItem) {
				for (size_t i = 0; i < m_cntItem; i++) {
					delete m_lstItem[i];
				}
				delete[] m_lstItem;
			}

			m_cntItem = other.m_cntItem;
			other.m_cntItem = 0;

			m_lstItem = other.m_lstItem;
			other.m_lstItem = nullptr;

		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << setw(6) << setfill('0') 
				<< m_lstItem[i]->m_serialNumber << "] "
				<< setw(m_widthField) << left << setfill(' ') 
				<< m_lstItem[i]->m_itemName << right << " - " 
				<< (m_lstItem[i]->m_isFilled ? "FILLED\n" : "TO BE FILLED\n");
		}
	}

	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				return false;
			}
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName 
				&& !m_lstItem[i]->m_isFilled) {
				return false;
			}
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, ostream& os) {

		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity()) {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product
						<< " [" << m_lstItem[i]->m_itemName << "]\n";
				}
				if (!m_lstItem[i]->m_isFilled && !station.getQuantity()) {
					os << "    Unable to fill " << m_name << ", " << m_product
						<< " [" << m_lstItem[i]->m_itemName << "]\n";
				}
			}
		}
	}
}