// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

struct Vector3 {
	float x=0.0f, y=0.0f, z=0.0f;
	int* m_data = nullptr;

	~Vector3() {
		delete[] m_data;
	}
	Vector3() {
		m_data = new int[5];
	}
	Vector3(float scalar) : x{ scalar }, y{ scalar }, z{ scalar } { m_data = new int[5]; }
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {
		m_data = new int[5];
	}

	Vector3(const Vector3& other) = delete;/*: x{ other.x }, y{ other.y }, z{other.z} {
		std::cout << "Copy constructor\n"; 
	}*/

	Vector3(Vector3&& other): x{ other.x }, y{ other.y }, z{ other.z } {
		//delete[] m_data;
		m_data = other.m_data;

		other.m_data = nullptr;
		std::cout << "Move constructor\n";
	}

	Vector3& operator=(const Vector3& other) = delete; /*{
		x = other.x;
		y = other.y;
		z = other.z;
		
		std::cout << "Copy Assignment\n";
		return *this;
	}*/

	Vector3& operator=(Vector3&& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		m_data = other.m_data;
		other.m_data = nullptr;
		std::cout << "Move Assignment\n";
		return *this;
	}
};

template <class T>
void printVector(const Vector<T>& other) {
	for (size_t i = 0; i < other.size(); i++)
		std::cout << other[i] << std::endl;
	std::cout << "--------------------\n" << std::endl;
}

template <>
void printVector(const Vector<Vector3>& other) {
	for (size_t i = 0; i < other.size(); i++)
		std::cout << other[i].x << ", " << other[i].y << ", " << other[i].z << std::endl;
	std::cout << "--------------------\n" << std::endl;
}

int main() {
	//Vector<std::string> vector;
	//vector.pushBack("Cherno");
	//vector.pushBack("C++");
	//vector.pushBack("Vector");
	//vector.pushBack("Vector");
	//vector.pushBack("Vector");
	//vector.pushBack("Vector");
	//vector.pushBack("Vector");
	//vector.pushBack("Vector");
	//
	//vector.display(); //OR
	//printVector(vector);

	//{
	//Vector<Vector3> vector;

	//commented out purposely to display the usage of emplace_back
	//vector.pushBack(Vector3(1.0f));
	//vector.pushBack(Vector3(2,3,4));
	//vector.pushBack(Vector3());

	/*vector.emplaceBack(1.0f);
	vector.emplaceBack(2, 3, 4);
	vector.emplaceBack(1, 10, 9);
	vector.emplaceBack();
	printVector(vector);
	vector.popBack();
	vector.popBack();
	printVector(vector);
	vector.emplaceBack(4.5f, 3.4f, 4.3f);
	vector.emplaceBack(1, 2, 3);
	printVector(vector);
	vector.clear();
	printVector(vector);
	vector.emplaceBack(4.5f, 3.4f, 4.3f);
	vector.emplaceBack(1, 2, 3);*/
	//vector.display();
	//printVector(vector);
	//}


	//vector + iterators
	//Vector<int> value;
	//value.emplaceBack(1);
	//value.emplaceBack(2);
	//value.emplaceBack(3);
	//value.emplaceBack(4);
	//value.emplaceBack(5);

	//cout << "Not using iterators:\n";
	//for (size_t i = 0; i < value.size(); i++) {
	//	cout << value[i] << endl;
	//}
	//
	//cout << "Using range based for loop:\n";
	//for (int val : value) {
	//	cout << val << endl;
	//}

	//using vecType = Vector<int>;
	//cout << "Using Iterators:\n";
	//for (vecType::iterator it = value.begin(); it != value.end();) {
	//	cout << *it << endl;
	//}

	Vector<std::string> value;
	value.emplaceBack("Soham");
	value.emplaceBack("Soham");
	value.emplaceBack("Dharit");
	value.emplaceBack("Dhruvil");
	value.emplaceBack("Soham");

	cout << "Not using iterators:\n";
	for (size_t i = 0; i < value.size(); i++) {
		cout << value[i] << endl;
	}

	cout << "Using range based for loop:\n";
	for (auto& val : value) {
		cout << val << endl;
	}

	using vecType = Vector<std::string>;
	cout << "Using Iterators:\n";
	for (vecType::iterator it = value.begin(); it != value.end();) {
		cout << *it << endl;
	}

	return 0;
}