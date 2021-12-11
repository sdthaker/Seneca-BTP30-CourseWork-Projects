#ifndef SDDS_VECTOR_H
#define SDDS_VECTOR_H

#include <string>

namespace sdds {

	//template class that accepts 1 value at any given time resizes as needed
	template <typename T>
	class Vector {
		int m_size = 0;
		T* m_arr = nullptr;
	public:
		Vector(const T& val, int& size);
		const T* pushBack(const T& val, int& size);
		~Vector();
	};


	template <typename T>
	Vector<T>::Vector(const T& val, int& size) {
		pushBack(val, size);
	}

	template <typename T>
	Vector<T>::~Vector() {
		delete[] m_arr;
	}

	template <typename T>
	const T* Vector<T>::pushBack(const T& val, int& size) {

		T* temp = nullptr;
		temp = new T[m_size+1];

		for (int i = 0; i < m_size; i++)
			temp[i] = m_arr[i];

		temp[m_size] = val;

		delete[] m_arr;
		m_arr = temp;
		temp = nullptr;

		++m_size;
		size = m_size;
		return m_arr;
	}

	template <>
	const std::string* Vector<std::string>::pushBack(const std::string& val, int& size) {

		std::string* temp = nullptr;
		temp = new std::string[m_size + 1];

		for (int i = 0; i < m_size; i++)
			temp[i] = m_arr[i];

		temp[m_size] = val;

		m_arr = temp;
		temp = nullptr;

		++m_size;
		size = m_size;
		return m_arr;
	}
}

#endif