// Workshop 2 part 2
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/09/17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <string>

namespace sdds {
	
	class StringSet {
		size_t m_size{};
		std::string* m_word{};
		void alloc(const std::string* s = nullptr);
	public:
		StringSet() {};
		StringSet(const char* filename);
		StringSet(const StringSet& other);
		StringSet(StringSet&& other) noexcept;
		StringSet& operator=(StringSet&& other) noexcept;
		StringSet& operator=(const StringSet& other);
		~StringSet();
		size_t size() const;
		std::string operator[](size_t idx) const;
	};
}

#endif // ! SDDS_STRINGSET_H
