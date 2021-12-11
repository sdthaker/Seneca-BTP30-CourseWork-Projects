// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <vector>
#include <string>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

namespace sdds {

	template <class T>
	class Card {
		std::vector<T> m_cards{
		"SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK",
			"HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
		"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
			"CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK"
		};
		static int m_idx;
	public:
		Card() {}
		void shuffleCard();
		int remaining() const;
		T nextCard();
		void display() const;
	};

	template<class T>
	int Card<T>::m_idx = 0;

	template <class T>
	void Card<T>::shuffleCard() {
		std::random_device rd;
		std::mt19937 g(rd());
		shuffle(m_cards.begin(), m_cards.end(), g);
	}

	template <class T>
	int Card<T>::remaining() const {
		return m_cards.size();
	}

	template <class T>
	T Card<T>::nextCard() {
		T temp = move(m_cards[m_idx]);
		m_cards.erase(m_cards.begin());
		return move(temp); 
		//m_cards.emplace_back();
	}
	
	template <class T>
	void Card<T>::display() const{
		copy(m_cards.begin(), m_cards.end(), ostream_iterator<T>(cout, " "));
	}
}