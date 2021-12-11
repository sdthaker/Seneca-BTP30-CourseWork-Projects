// Workshop 3
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/25
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

namespace sdds {

	template<typename V, typename K>
	class Pair {
		K m_key{};
		V m_value{};
	public:
		Pair();
		Pair(const K& key, const V& value);
		const K& key() const;
		const V& value() const;
		virtual void display(std::ostream& os) const;
	};

	template<typename V, typename K>
	Pair<V, K>::Pair() {}

	template<typename V, typename K>
	Pair<V, K>::Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;
	}

	template<typename V, typename K>
	const V& Pair<V, K>::value() const {
		return m_value;
	}

	template<typename V, typename K>
	const K& Pair<V, K>::key() const {
		return m_key;
	}

	template<typename V, typename K>
	void Pair<V, K>::display(std::ostream& os) const {
		os << m_key << " : " << m_value << std::endl;
	}

	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}
}

#endif