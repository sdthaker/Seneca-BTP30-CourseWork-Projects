// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <string>
#include <exception>
#include <chrono>
#include "Deck.h"

using namespace sdds;
using namespace std;

int main() {
	try {
		auto start = std::chrono::high_resolution_clock::now();
		Deck<const char*> d;
		d.shuffle_deck();
		d.display();
		cout << "The next card in the deck is: " << d.deal_card() << endl;
		//d.display();
		d.remaining();
		d.deck_size();
		auto end = std::chrono::high_resolution_clock::now();

		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		cout << "Total time took to complete the opeartion: " << dur.count() << "ms\n\n";
	}
	catch (E& e) {
		cout << e.what();
	}

	try {
		auto start = std::chrono::high_resolution_clock::now();
		Deck<string> d;
		d.shuffle_deck();
		d.display();
		cout << "The next card in the deck is: " << d.deal_card() << endl;
		//d.display();
		d.remaining();
		d.deck_size();
		auto end = std::chrono::high_resolution_clock::now();

		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		cout << "Total time took to complete the opeartion: " << dur.count() << "ms\n\n";
	}
	catch (E& e) {
		cout << e.what();
	}

	//try {
	//	Deck<const char*> d(11);
	//	d.shuffle_deck();
	//	d.display();
	//	cout << "The next card in the deck is: " << d.deal_card() << endl;
	//	//d.display();
	//	d.remaining();
	//	d.deck_size();
	//}
	//catch (E& e) {
	//	cout << e.what();
	//}
	return 0;
}