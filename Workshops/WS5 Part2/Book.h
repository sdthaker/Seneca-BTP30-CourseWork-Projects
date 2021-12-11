// Workshop 5
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/09
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>

namespace sdds
{
	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_desc{};
		void trim(const std::string& res, std::string& local) const;
	public:
		Book() {};
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<<(std::ostream& os,
			const Book& res);
		template<typename T> void fixSpelling(T& spellChecker);
	};

	template<typename T>
	void Book::fixSpelling(T& spellChecker) {
		spellChecker(m_desc);
	}
}
#endif
