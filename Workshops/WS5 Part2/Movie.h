// Workshop 5
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/10/09
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds {
	
	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};
		void trim(const std::string& res, std::string& local) const;
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T> void fixSpelling(T& spellChecker);
		friend std::ostream& operator<<(std::ostream& os,
			const Movie& res);
	};

	template <typename T>
	void Movie::fixSpelling(T& spellChecker) {
		spellChecker(m_title);
		spellChecker(m_desc);
	}
}

#endif
