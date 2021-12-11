#include <string>
#include <iostream>
#include <iomanip>

#include "Book.h"

using namespace std;

namespace sdds {

	void Book::trim(const string& res, string& local) const{
		size_t start{}, end{};

		for (size_t i = 0; i < res.size(); i++) {
			if (res[i] != ' ') {
				start = i;
				break;
			}
		}

		for (size_t i = res.size() - 1; i >= 0u; i--) {
			if (res[i] != ' ') {
				end = i;
				break;
			}
		}

		for (size_t i = start; i < end + 1; i++) {
			local += res[i];
		}
	}

	Book::Book(const std::string& strBook) {

		string local{};

		auto posS = strBook.find(',');
		auto author = strBook.substr(0, posS);
		trim(author, m_author);

		auto posE = strBook.find(',', posS + 1);
		auto title = strBook.substr(posS + 1, posE - posS - 1);
		trim(title, m_title);

		posS = posE;
		posE = strBook.find(',', posE + 1);
		auto country = strBook.substr(posS + 1, posE - posS - 1);
		trim(country, m_country);

 		posS = posE;
		posE = strBook.find(',', posE + 1);
		auto price = strBook.substr(posS + 1, posE - posS - 1);
		trim(price, local);
		m_price = stod(local);

		posS = posE;
		posE = strBook.find(',', posE + 1);
		auto year = strBook.substr(posS + 1, posE - posS - 1);
		local = {};
		trim(year, local);
		m_year = stoi(local);

		posS = posE;
		posE = strBook.find('.', posE + 1);
		auto desc = strBook.substr(posS + 1, posE - posS);
		trim(desc, m_desc);
	}

	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_country;
	}

	const size_t& Book::year() const {
		return m_year;
	}

	double& Book::price() {
		return m_price;
	}

	std::ostream& operator<<(std::ostream& os,
		const Book& res) {
		return os << setw(20) << res.m_author << " | " << setw(22) << res.m_title << " | " << setw(5) << res.m_country << " | " << setw(4) << res.m_year << " | " << setw(6) << fixed << setprecision(2) << res.m_price << " | " << res.m_desc;
	}
}