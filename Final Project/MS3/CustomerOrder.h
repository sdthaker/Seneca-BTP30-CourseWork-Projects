// Name: Soham Thaker
// Seneca Student ID: 011-748-159
// Seneca email: sdthaker1@myseneca.ca
// Date of completion: 28/10/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include <iostream>
#include "Station.h"

namespace sdds {

	class CustomerOrder {

		struct Item {
			std::string m_itemName{};
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};

		static size_t m_widthField;

	public:

		CustomerOrder() {};
		CustomerOrder(const std::string& record);
		CustomerOrder(const CustomerOrder& other) {
			throw 1;
		};
		CustomerOrder& operator=(const CustomerOrder& other) = delete;
		CustomerOrder(CustomerOrder&& other) noexcept;
		CustomerOrder& operator=(CustomerOrder&& other) noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif