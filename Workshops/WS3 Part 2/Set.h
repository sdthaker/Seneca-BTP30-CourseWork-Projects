// Workshop 3
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/25
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {

	template<size_t N, typename T>
	class Set {
		T m_collection[N];
		size_t m_count{};
	public:
		Set();
		size_t size() const;
		const T& get(size_t idx) const;
		void operator+=(const T& item);
	};

	template<size_t N, typename T>
	Set<N, T>::Set() {}

	template<size_t N, typename T>
	size_t Set<N, T>::size() const {
		return m_count;
	}

	template<size_t N, typename T>
	const T& Set<N, T>::get(size_t idx) const {
		return m_collection[idx];
	}

	template<size_t N, typename T>
	void Set<N, T>::operator+=(const T& item) {
		if (m_count < N) {
			m_collection[m_count++] = item;
		}
	}
}

#endif
