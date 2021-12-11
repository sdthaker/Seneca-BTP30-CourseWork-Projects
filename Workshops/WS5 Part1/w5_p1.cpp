// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	size_t cnt{};
	sdds::Book library[7];
	if (argc == 2) {

		std::ifstream file(argv[1]);
		if (!file) {
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			exit(AppErrors::CannotOpenFile);
		}

		std::string book;
		do {
			std::getline(file, book);
			
			if (file)
			{
				if (book[0] != '#') {
					library[cnt++] = book;
				}
			}
		} while (file);
		file.close();
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto libLmabda = [=](Book& b) {
		if (b.country() == "US") {
			b.price() *= usdToCadRate;
		}
		if (b.country() == "UK" && (b.year() >= 1990 && b.year() <= 1999)) {
			b.price() *= gbpToCadRate;
		}
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";

	for (size_t i = 0; i < cnt; i++) {
		std::cout << library[i] << std::endl;
	}

	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (size_t i = 0; i < cnt; i++) {
		libLmabda(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (size_t i = 0; i < cnt; i++) {
		std::cout << library[i] << std::endl;
	}

	std::cout << "-----------------------------------------\n";

	return 0;
}
