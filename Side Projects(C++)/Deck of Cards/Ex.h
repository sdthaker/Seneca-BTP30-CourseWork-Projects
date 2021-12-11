// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <exception>

namespace sdds {
	
	class E : public std::exception {
		const char* m_s;
		E();
	public:
		E(const char* s) noexcept(true) : m_s{ s } {}
		const char* what() const noexcept(true) {return m_s;}
	};
}