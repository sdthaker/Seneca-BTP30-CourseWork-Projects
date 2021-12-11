#ifndef LIST_H
#define LIST_H

#include <stdexcept>

template <typename T>
class list
{
	// list component [PRIVATE STRUCTURE]
	struct list_element
	{
		T m_data{};							// element data
		list_element* m_next{ nullptr };	// pointer to next element
		list_element* m_prev{ nullptr };	// pointer to previous element

		// base constructor
		list_element() = default;
	};

	list_element* m_head;					// pointer to the first element
	size_t m_cnt;							// keeps track of number of elements

public:
	// iterator [PUBLIC STRUCTURE]
	struct iterator
	{
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;

		list_element* m_current;			// current position of iterator

		// proceeds to the following list_element
		iterator& operator++()
		{
			if (this->m_current)
				this->m_current = this->m_current->m_next;
			return *this;
		}

		// suffix incrementing operator
		iterator operator++(int)
		{
			/*iterator it{};
			it.m_current = this->m_current;*/
			iterator it = *this;

			//this->m_current = this->m_current->m_next;
			++(*this);
			return it;
		}

		// regresses to the previous list_element
		iterator& operator--()
		{
			if (this->m_current)
				this->m_current = this->m_current->m_prev;
			else
				this->m_current = nullptr;
			return *this;
		}

		// suffex decrementing operator
		iterator operator--(int)
		{
			iterator it = *this;
			--(*this);
			return it;
		}

		// query checking if iterator pointers are equal
		bool operator==(const iterator& it) const
		{
			return this->m_current == it.m_current;
		}

		// query checking if iterator pointers are not equal
		bool operator!=(const iterator& it) const
		{
			return this->m_current != it.m_current;
		}

		// moves forward a parameter number of steps
		iterator operator+(size_t i) const
		{
			iterator it = *this;
			size_t count = 0;

			for (; count != i && it.m_current; ++it) {
				++count;
				/*if (count == i)
					break;*/
			}
			return it;
		}

		// dereference
		T& operator*()
		{
			return this->m_current->m_data;
		}

		// -> operator
		T* operator->()
		{
			return &(this->m_current->m_data);
		}

		bool operator!() {
			return m_current == nullptr;
		}
	};

	// query returning an iterator to the first element of a list
	iterator begin() const
	{
		iterator it;
		it.m_current = this->m_head;
		return it;
	}

	// query returning an iterator to the last element of a list
	iterator end() const
	{
		iterator it;
		it.m_current = nullptr;
		return it;
	}

	// base constructor
	list()
	{
		m_head = nullptr;
		m_cnt = 0;
	}

	// destructor
	~list()
	{
		list_element* li = this->m_head;
		while (li) {
			li = this->m_head->m_next;
			delete this->m_head;
			this->m_head = li;
		}
		this->m_cnt = 0;
	}

	// copy constructor
	list(const list& li)
	{
		*this = li;
	}

	// copy assignment operator
	list& operator=(const list& li)
	{
		if (this != &li) {
			this->~list();

			this->m_head = new list_element;
			auto thisObj = this->m_head;
			auto otherObj = li.m_head;

			for (size_t i = 0; i < li.m_cnt && otherObj; i++) {

				thisObj->m_data = otherObj->m_data;
				if (this->m_cnt != li.m_cnt - 1) {
					thisObj->m_next = new list_element;
					thisObj->m_next->m_prev = thisObj;
				}

				thisObj = thisObj->m_next;
				otherObj = otherObj->m_next;

				++this->m_cnt;
			}
			/*for (size_t i = 0; i < li.m_cnt; i++) {
				this->push_front(li[i]);
			}*/
		}
		return *this;
	}

	// query returning the size of the list
	size_t size() const
	{
		return this->m_cnt;
	}

	// adds an item to the front of the list
	void push_front(const T& val)
	{
		list_element* node = new list_element;
		node->m_data = val;
		if (this->m_head)
			this->m_head->m_prev = node;
		node->m_next = this->m_head;
		this->m_head = node;
		++this->m_cnt;
	}

	// adds an item at the end of the list
	void push_back(const T& val)
	{
		list_element* node = new list_element;
		node->m_data = val;
		if (this->m_head) {
			list_element* it = this->m_head;
			while (it->m_next)
				it = it->m_next;
			it->m_next = node;
			node->m_prev = it;
		}
		else {
			this->m_head = node;
		}
		++this->m_cnt;
	}

	// adds an item at the given position [starts at 0]
	void insert(const T& val, size_t idx)
	{
		if (idx < 0 || idx > this->m_cnt - 1)
			throw std::out_of_range("Invalid index");

		iterator it = this->begin();
		it = it + idx;

		list_element* node = new list_element;
		node->m_data = val;

		if (this->begin() != this->end()) {
			it.m_current->m_prev->m_next = node;
			node->m_next = it.m_current;
			node->m_prev = it.m_current->m_prev;
			it.m_current->m_prev = node;
		}
		else {
			this->m_head = node;
		}

		++this->m_cnt;
	}

	// adds an item to the location before the iterator
	void insert(iterator& it, const T& val)
	{
		if (it == this->begin()) {
			this->push_front(val);
		}
		else if (it.m_current) {
			list_element* node = new list_element;
			node->m_data = val;

			it.m_current->m_prev->m_next = node;
			node->m_next = it.m_current;
			node->m_prev = it.m_current->m_prev;
			it.m_current->m_prev = node;

			++this->m_cnt;
		}
	}

	// erases the item at the location of the iterator
	void erase(iterator& it)
	{
		iterator local{};
		/*local.m_current = this->m_head;
		while (local.m_current->m_next)
			local.m_current = local.m_current->m_next;*/

		if (it.m_current) {
			if (it.m_current == this->begin().m_current) {	//if the iter passed is head
				local.m_current = it.m_current;
				this->m_head = it.m_current->m_next;
			}
			//else if (it.m_current == /*[*this]() -> list_element* { 
			//		list_element* it = this->m_head;
			//		while (it->m_next)
			//			it = it->m_next;
			//		return it;
			//	}*/ local.m_current) { 
			//	it.m_current->m_prev->m_next = this->end().m_current;
			//}
			else if (!it.m_current->m_next) { //if the iter passed is the tail
				local.m_current = it.m_current;
				it.m_current->m_prev->m_next = it.m_current->m_next;
			}
			else {						//if the iter passed is somewhere in the middle
				for (local = this->begin(); local != this->end(); local++) {
					if (local.m_current == it.m_current) {
						it.m_current->m_prev->m_next = it.m_current->m_next;
						it.m_current->m_next->m_prev = it.m_current->m_prev;
						break;
					}
				}
			}
			delete local.m_current;
			local.m_current = nullptr;
			--this->m_cnt;
		}
	}

	// removes first element with a certain value from the list
	void remove(const T val)
	{
		for (auto it = this->begin(); it != this->end(); ++it) {
			if (*it == val) {
				this->erase(it);
				break;
			}
		}
	}

	// query returning if a value is in the list
	bool search(const T& val) const
	{
		for (auto it = this->begin(); it != this->end(); it++) {
			if (*it == val)
				return true;
		}
		return false;
	}

	// query returning the element at a position [starts at 0]
	T& at(size_t idx) const
	{
		if (idx < 0 || idx > this->m_cnt - 1)
			//throw std::invalid_argument("Invalid index");
			throw std::out_of_range("Invalid index");
		else {
			//return (*this)[idx];
			iterator it = this->begin();
			return (it + idx).m_current->m_data;
		}
	}

	// [] operator overload
	T& operator[](size_t idx) const
	{
		//iterator it = this->begin();
		//return (it + idx).m_current->m_data;
		return this->at(idx);
	}
};
#endif