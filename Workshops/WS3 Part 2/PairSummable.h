// Workshop 3
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/25
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Pair.h"

namespace sdds {

	template <typename V, typename K>
	class PairSummable: public Pair<V,K> {
		static V m_summation;
		static size_t m_width;
	public:
		PairSummable();
		PairSummable(const K& key, 
					const V& value = PairSummable<V, K>::m_summation);
		bool isCompatibleWith(const PairSummable<V, K>& b) const;
		PairSummable& operator+= (const PairSummable& other);
		void display(std::ostream& os) const override;
	};

	template<typename V, typename K>
	V PairSummable<V, K>::m_summation{};

	template<typename V, typename K>
	size_t PairSummable<V, K>::m_width{};

	template<typename V, typename K>
	PairSummable<V, K>::PairSummable() {}

	template<typename V, typename K>
	PairSummable<V, K>::PairSummable(const K& key, const V& value) 
		: Pair<V, K>(key, value) {
		if (PairSummable<V, K>::m_width < key.size()) {
			PairSummable<V, K>::m_width = key.size();
		}
	}

	template<typename V, typename K>
	bool PairSummable<V, K>::
		isCompatibleWith(const PairSummable<V, K>& b) const {
		return this->key() == b.key();
	}

	template<typename V, typename K>
	PairSummable<V, K>& PairSummable<V, K>::operator+= 
		(const PairSummable<V, K>& other) 
	{
		//static std::string lookup {};

		//if (this->key() != lookup) {
		//	PairSummable<V, K>::m_summation = 0;
		//	lookup = this->key();
		//}

		//*this = PairSummable(this->key(),
		//	PairSummable<V, K>::m_summation +
		//	other.value());

		//PairSummable<V, K>::m_summation
		//	+= other.value();

		//	return *this;
		*this = PairSummable(other.key(), this->value() + other.value());
		return *this;
	}

	template<>
	PairSummable<std::string, std::string>& 
		PairSummable<std::string, std::string>::operator+=
		(const PairSummable<std::string, std::string>& other) {

		//static std::string lookup {};

		//if (this->key() != lookup) {
		//	PairSummable<std::string, std::string>::m_summation = "";
		//	lookup = this->key();
		//}

		//*this = PairSummable(this->key(),
		//	PairSummable<std::string, std::string>::m_summation
		//	+ other.value());

		//PairSummable<std::string, std::string>::m_summation
		//	+= other.value() + ", ";

		//return *this;
		if (this->value().empty())
			*this = PairSummable(other.key(), other.value());
		else
			*this = PairSummable(other.key(), this->value() + ", " + other.value());
		return *this;
	}

	template<typename V, typename K>
	void PairSummable<V, K>::display(std::ostream& os) const {
		os << std::left << std::setw(PairSummable<V, K>::m_width);
		Pair<V, K>::display(os);
		os << std::right;
	}
}

#endif // !SDDS_PAIRSUMMABLE_H
