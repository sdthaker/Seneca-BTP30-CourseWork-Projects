// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <iostream>
#include <string>
#include "Card.h"
#include "Ex.h"

using namespace std;

namespace sdds {

	template <class T>
	class Deck {
		Card<T>* m_card = nullptr;
		int m_size = 0;
		void alloc(int n = 1);
	public:
		Deck();
		Deck(int n);
		~Deck();
		void shuffle_deck() const;
		int remaining() const; 
		int deck_size() const;
		T deal_card() const;
		void display() const;
		//const Card<T>* deck();//returns a pointer to the array of cards
	};

	template <class T>
	void Deck<T>::alloc(int n) {
		/*if (n >= 1 && n <= 10) {
			m_card = new Card<T>[n];
			m_size = n;
		}
		else {
			cout << "Can only create a max of 10 Decks currently";
			m_card = new Card<T>[10];
			m_size = 10;
		}*/
		if (n > 10 || n <= 0) throw E("Too many decks (Max:10)");
		m_card = new Card<T>[n];
		m_size = n;
	}

	template <class T>
	Deck<T>::Deck() {
		alloc();
	}

	template <class T>
	Deck<T>::Deck(int n) {
		alloc(n);
	}

	template <class T>
	Deck<T>::~Deck() {
		delete[] m_card;
	}

	template <class T>
	void Deck<T>::shuffle_deck() const {
		for (size_t i = 0; i < m_size; i++)
			m_card[i].shuffleCard();
	}

	template <class T>
	int Deck<T>::remaining() const {
		for (size_t i = 0; i < m_size; i++)
			cout << "The remaining cards in deck " << i + 1 << " are: " << m_card[i].remaining() << endl;
		return 0;
	}

	template <class T>
	int Deck<T>::deck_size() const {
		for (size_t i = 0; i < m_size; i++)
			cout << "The remaining cards in deck " << i + 1 << " are: " << m_card[i].remaining() << endl;
		return 0;
	}

	template <class T>
	T Deck<T>::deal_card() const{
		if (m_size > 1) {
			int deck{};
			cout << "Total deck: " << m_size << endl;
			cout << "Which deck's next card would you like to see: ";
			cin >> deck;
			/*if (deck > 10) {
				cout << "You chose invalid number, displaying next card of 10th deck.";
				return move(m_card[9].nextCard());
			}
			else if (deck < 1) {
				cout << "You chose invalid number, displaying next card of 1st deck.";
				return move(m_card[0].nextCard());
			}*/
			if (deck > 10 || deck <= 0) throw E("Deck out of range (Max:10)");
			return move(m_card[deck - 1].nextCard());
		}
		else {
			return move(m_card[0].nextCard());
		}
	}

	template <class T>
	void Deck<T>::display() const {
		for (size_t i = 0; i < m_size; i++) {
			cout << "Deck " << i + 1 << ": ";
			m_card[i].display();
			cout << endl << endl;
		}
	}
	 
	/*template <class T>
	const Card<T>* Deck<T>::deck() {

	}*/
}