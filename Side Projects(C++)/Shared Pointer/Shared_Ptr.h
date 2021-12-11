#ifndef Shared_Ptr
#define Shared_Ptr

#include <cassert>
#include <cstddef>

namespace sdds {

	template<class T>
	class Shared_ptr {
		T* m_ptr{};
		int* m_cnt{};
	public:
		Shared_ptr(T* ptr);
		Shared_ptr(const Shared_ptr& other);
		Shared_ptr(Shared_ptr&& other);
		Shared_ptr& operator=(const Shared_ptr& other);
		Shared_ptr& operator=(Shared_ptr&& other);
		~Shared_ptr();

		T& operator*();
		T* operator->();
	};

	template<class T>
	Shared_ptr<T>::Shared_ptr(T* ptr) {
		m_ptr = ptr;
		m_cnt = new int{ 1 };
	}

	template<class T>
	Shared_ptr<T>::Shared_ptr(const Shared_ptr<T>& other) {
		if (other.m_ptr && other.m_cnt) {
			m_ptr = other.m_ptr;
			m_cnt = other.m_cnt;
			++(*m_cnt);
		}
	}

	template<class T>
	Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr<T>& other) {
		if (this != &other)
		{
			if (m_ptr != other.m_ptr) {
				if (m_ptr) {
					--(*m_cnt);
					if (!(*m_cnt)) {
						delete m_ptr;
						m_ptr = nullptr;
						delete m_cnt;
						m_cnt = nullptr;
					}
				}
				m_ptr = other.m_ptr;
				m_cnt = other.m_cnt;
				if(other.m_ptr)
					++(*m_cnt);
			}
		}
		return *this;
	}

	template<class T>
	Shared_ptr<T>::Shared_ptr(Shared_ptr<T>&& other) {
		if (other.m_ptr && other.m_cnt) {
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;

			m_cnt = other.m_cnt;
			other.m_cnt = nullptr;
		}
	}

	template<class T>
	Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr<T>&& other) {
		if (this != &other)
		{
			if (m_ptr != other.m_ptr) {
				if (m_ptr) {
					--(*m_cnt);
					if (!(*m_cnt)) {
						delete m_ptr;
						m_ptr = nullptr;
						delete m_cnt;
						m_cnt = nullptr;
					}
				}
				m_ptr = other.m_ptr;
				other.m_ptr = nullptr;
				m_cnt = other.m_cnt;
				other.m_cnt = nullptr;
			}
		}
		return *this;
	}

	template<class T>
	Shared_ptr<T>::~Shared_ptr() {

		assert((!m_ptr && !m_cnt) || (m_ptr && m_cnt));

		if (m_ptr && m_cnt) {
			--(*m_cnt);
			if (!(*m_cnt)) {
				delete m_ptr;
				m_ptr = nullptr;
				delete m_cnt;
				m_cnt = nullptr;
			}
		}
	}

	template<class T>
	T& Shared_ptr<T>::operator*() {
		return *m_ptr;
	}

	template<class T>
	T* Shared_ptr<T>::operator->() {
		return m_ptr;
	}
}

#endif
