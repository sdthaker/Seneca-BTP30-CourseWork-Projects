#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <ostream>

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
	};
}
#endif
