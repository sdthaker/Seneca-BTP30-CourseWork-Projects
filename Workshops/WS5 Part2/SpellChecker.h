// Workshop 5
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/09
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <map>

namespace sdds {
	constexpr size_t size = 6;
	
	class SpellChecker {
		std::map<std::string, size_t>kvPair{};
		size_t m_size{};
		std::string m_badWords[size]{};
		std::string m_goodWords[size]{};
		void trim(const std::string& res, std::string& local) const;
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif