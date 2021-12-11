// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#ifndef VECTOR_H
#define VECTOR_H
//#include <iostream>

template <class vector>
class vectorIterator {
public:
	using valueType = typename vector::valueType;
	using pointerType = valueType*;
	using referenceType = valueType&;
	vectorIterator(pointerType ptr) : m_ptr(ptr) {	}
	vectorIterator<vector>& operator++();
	vectorIterator<vector> operator++(int);
	vectorIterator<vector>& operator--();
	vectorIterator<vector> operator--(int);
	referenceType operator[](size_t val);
	pointerType operator->();
	referenceType operator*();
	bool operator==(const vectorIterator<vector>& other) const;
	bool operator!=(const vectorIterator<vector>& other) const;
private:
	pointerType m_ptr;
};

template <class vector>
bool vectorIterator<vector>::operator==(const vectorIterator<vector>& other) const {
	return m_ptr == other.m_ptr;
}

template <class vector>
bool vectorIterator<vector>::operator!=(const vectorIterator<vector>& other) const {
	return m_ptr != other.m_ptr;
	//return !(*this == other);
}

template <class vector>
typename vectorIterator<vector>::referenceType vectorIterator<vector>::operator*() {
	return *m_ptr;
}

template <class vector>
typename vectorIterator<vector>::pointerType vectorIterator<vector>::operator->() {
	return m_ptr;
}

template <class vector>
typename vectorIterator<vector>::referenceType vectorIterator<vector>::operator[](size_t val) {
	return *(m_ptr[val]);
	//return *(m_ptr + val);
}

template <class vector>
vectorIterator<vector>& vectorIterator<vector>::operator++() {
	m_ptr++;
	return *this;
}

template <class vector>
vectorIterator<vector> vectorIterator<vector>::operator++(int) {
	vectorIterator tmp = *this;
	++(*this);
	return tmp;
}

template <class vector>
vectorIterator<vector>& vectorIterator<vector>::operator--() {
	m_ptr--;
	return *this;
}

template <class vector>
vectorIterator<vector> vectorIterator<vector>::operator--(int) {
	vectorIterator tmp = *this;
	--(*this);
	return tmp;
}


//vector class
template <class T>
class Vector {
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0; 
	void reAlloc(size_t newCapacity);
public:
	using valueType = T;
	using iterator = vectorIterator<Vector<T>>;
	Vector();
	void pushBack(const T& value);
	void pushBack(const T&& value);
	template<class... Args>
	T& emplaceBack(Args&&... args);
	size_t size() const;
	const T& operator[](size_t idx) const;
	T& operator[](size_t idx);
	//void display() const;
	void popBack();
	void clear();
	iterator/*vectorIterator<Vector<T>>*/ begin();
	iterator/*vectorIterator<Vector<T>>*/ end();
	~Vector();
};

template <class T>
/*vectorIterator<Vector<T>>*/ typename Vector<T>::iterator Vector<T>::begin() {
	return Vector<T>::iterator(m_data);
}

template <class T>
/*vectorIterator<Vector<T>>*/typename Vector<T>::iterator Vector<T>::end() {
	return Vector<T>::iterator(m_data + m_size);
}

template <class T>
void Vector<T>::popBack() {
	if (m_size > 0) {
		m_size--;
		m_data[m_size].~T();
	}
}

template <class T>
void Vector<T>::clear() {
	for (size_t i = 0; i < m_size; i++)
		m_data[i].~T();
	m_size = 0;
}

template <class T>
Vector<T>::~Vector() {
	clear();
	::operator delete(m_data, m_capacity * sizeof(T));
}

//template <class T>
//void Vector<T>::display() const {
//	for (size_t i = 0; i < m_size; i++)
//		std::cout << m_data[i] << std::endl;
//
//	std::cout << "-----------------------\n" << std::endl;
//}

template <class T>
const T& Vector<T>::operator[](size_t idx) const {
	//if(idx >= m_size) check to see if user is trying to access the elements out of bounds try throw catch block
	return m_data[idx];
}

template <class T>
T& Vector<T>::operator[](size_t idx) {
	return m_data[idx];
}

template <class T>
size_t Vector<T>::size() const {
	return m_size;
}

template <class T>
void Vector<T>::pushBack(const T& value) {
	if (m_size >= m_capacity)
		reAlloc(m_capacity + m_capacity / 2);
	m_data[m_size++] = /*std::move*/(value);
}

template <class T>
void Vector<T>::pushBack(const T&& value) {
	if (m_size >= m_capacity)
		reAlloc(m_capacity + m_capacity / 2);
	m_data[m_size++] = std::move(value);
}

template <class T>
template <class... Args>
T& Vector<T>::emplaceBack(Args&&... args) {
	if (m_size >= m_capacity)
		reAlloc(m_capacity + m_capacity / 2);
	new(&m_data[m_size]) T(std::forward<Args>(args)...);
	//m_data[m_size] = T(std::forward<Args>(args)...);
	return m_data[m_size++];
}

template <class T>
Vector<T>::Vector() {
	reAlloc(2);
}

template <typename T>
void Vector<T>::reAlloc(size_t newCapacity) {

	T* newBlock = (T*)::operator new (newCapacity * sizeof(T));

	if (newCapacity < m_size) m_size = newCapacity;

	for (size_t i = 0; i < m_size; i++)
		newBlock[i] = std::move(m_data[i]);
		//new(&newBlock[i]) T(std::move(m_data[i]));

	for (size_t i = 0; i < m_size; i++)
		m_data[i].~T();

	::operator delete(m_data, m_capacity * sizeof(T));
	m_data = newBlock;
	m_capacity = newCapacity;
	newBlock = nullptr;
}

#endif