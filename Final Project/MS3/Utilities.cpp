// Name: Soham Thaker
// Seneca Student ID: 011-748-159
// Seneca email: sdthaker1@myseneca.ca
// Date of completion: 26/10/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include "Utilities.h"

using namespace std;

namespace sdds {

	char Utilities::m_delimiter{};

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const string& str, 
										size_t& next_pos, bool& more) {
		string token{};
		size_t prev_pos = next_pos;

		if (str[prev_pos] == getDelimiter()) {
			more = false;
			throw 1;
		}

		next_pos = str.find(getDelimiter(), next_pos);
		token = str.substr(prev_pos, next_pos - prev_pos);

		if (token.size() >= 1) {
			if (next_pos == string::npos) {
				more = false;
			}
			next_pos += 1;
		}

		if (m_widthField < token.size()) {
			m_widthField = token.size();
		}

		return token;
	}

	void Utilities::setDelimiter(char newDelimiter){
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}