#include <iostream>
#include <string>
#include "list.h"

int main() {
	
	list<std::string> l = {};

	//testing ! operator for iterator
	/*if (!l.begin())
		std::cout << "it works";*/
	
	//testing LIFO
	l.push_front("Soham");
	l.push_front("Dhruven");
	l.push_front("Aesha bhabhi");
	l.push_front("Dolly");
	l.push_front("Riki");

	//std::cout << std::endl;

	//testing FIFO
	l.push_back("Samuel");
	l.push_back("Dank");
	l.push_back("Danny");
	l.push_back("Dolce");
	l.push_back("Jimmy");

	/*testing range based for loops for iterator, beginand end, postfixand prefix increment operators
	for (auto const& name : l) {
	std::cout << name << std::endl;
	}

	for(auto i = l.begin(); i != l.end(); i++)
		std::cout << *i << std::endl;*/
	

	//testing + operator for iterator struct
	//auto i = l.begin();
	//i = i + 5;
	//std::cout << *i;



	//testing [] operator overload, at member function, and exception handling 
	//try {
	//	//std::cout << l[11];
	//	std::cout << l[5];
	//	std::cout << l.at(5);
	//}
	//catch (std::exception& e) {
	//	std::cout << e.what();
	//}



	//tesing binary search function
	/*if (l.search("Dolly"))
		std::cout << "is present";
	else
		std::cout << "is absent";

	if (l.search("Sam"))
		std::cout << "is present";
	else
		std::cout << "is absent";*/



	//testing erase and remove functionality
	auto i = l.begin() + 9;
	l.erase(i);

	i = l.begin();
	l.erase(i);
	
	i = l.begin() + 5;
	l.erase(i);

	l.remove("Samuel");

	for (auto const& name : l) {
		std::cout << name << std::endl;
	}


	//testing inserting elements at a given index or at a given iterator position
	l.insert("Daniel", 4);

	/*auto it = l.begin()+5;*/
	auto it = l.begin()+1;
	l.insert(it, "Jim");

	for (auto const& name : l) {
		std::cout << name << std::endl;
	}

	list<std::string> li{};
	
	li.push_front("Dog");
	li.push_front("Cat");
	li.push_front("Pup");
	li.push_front("Cub");
	li.push_front("Tiger");

	//li = l;
	l = li;

	for (auto const& name : l) {
		std::cout << name << std::endl;
	}

	return 0;
}