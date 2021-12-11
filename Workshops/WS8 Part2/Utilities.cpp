// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Workshop 8
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/11/15
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* p = new Product(desc[i].desc, price[j].price);
					p->validate();
					priceList += p;
					delete p;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					unique_ptr<Product> product
									(new Product(desc[i].desc, price[j].price));
					product->validate();
					priceList += product;
				}
			}
		}
		return priceList;
	}
}