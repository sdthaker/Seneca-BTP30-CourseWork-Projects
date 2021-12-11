// Workshop 2 part 2
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include <fstream>
#include <string>
#include "StringSet.h"

using namespace std;

namespace sdds {
	
	void StringSet::alloc(const string* s) {

		delete[] m_word;
		m_word = new string[m_size];

		if (!s) {
			for (size_t i = 0; i < m_size; i++) {
				m_word[i] = {};
			}
		}
		else {
			for (size_t i = 0; i < m_size; i++) {
				m_word[i] = s[i];
			}
		}
	}

	StringSet::StringSet(const char* filename) {

		ifstream in(filename);
		string str{};
		size_t count{};

		if (in.is_open()) {

			while (getline(in, str, ' '))
				++m_size;

			alloc();

			in.clear();
			//in.close(); //we could either close the file and open it again 
						  //or set the current position of the cursor from last to first
			//in.open(filename);
			in.seekg(0, ios::beg);

			while (getline(in, str, ' '))
				m_word[count++] = str;

		}
		in.close();
	}

	StringSet::StringSet(const StringSet& other) {
		*this = other;
	}

	StringSet& StringSet::operator=(const StringSet& other) {
		
		if (this != &other) {
			m_size = other.m_size;

			if (other.m_word)
				alloc(other.m_word);
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& other) noexcept{
		*this = std::move(other);
	}

	StringSet& StringSet::operator=(StringSet&& other) noexcept{
		
		if (this != &other) {

			m_size = other.m_size;

			delete[] m_word;
			m_word = other.m_word;

			other.m_size = {};
			other.m_word = nullptr;
		}
		return *this;
	}


	StringSet::~StringSet() {
		delete[] m_word;
	}

	size_t StringSet::size() const {
		return m_size;
	}

	string StringSet::operator[](size_t idx) const {
		if (!m_word || idx >= m_size)
			return string{};

		return m_word[idx];
	}
}