#ifndef VECTORPRAC_H
#define VECTORPRAC_H

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


#include <iostream>
//#include <memory>
#include <vector>
//#include <utility>
//#include <functional>
#include <string>
//#include <string_view>
//#include <array>
//#include <typeinfo>
//#include <cstdlib>
//#include <random>
#include <algorithm>
//#include <iterator>
//#include <iomanip>
#include <exception>
//#include <numeric>
//#include <chrono>
//#include <deque>
//#include <list>
//#include <forward_list>
//#include <set>
#include <map>
//#include <stack>
//#include <queue>

using namespace std;

//template <typename T, typename A = allocator<T>>
//class vector {
//	int sz;
//	T* elem;
//	int space;
//
//	A a;
//public:
//	vector() : sz(0), elem(0), space(0) {}
//	
//	vector(int s) : sz(s), elem(new T[s]), space(s) {
//		for (int i = 0; i < sz; i++) {
//			elem[i] = 0;
//		}
//	}
//
//	T& at(int n);
//	const T& at(int n) const;
//
//	vector(const vector&);
//	vector& operator=(const vector& v);
//
//	~vector() {
//		delete[] elem;
//	}
//
//	T& operator[](int n);
//	const T& operator[](int n) const;
//
//	int size() const {
//		return sz;
//	}
//	
//	int capacity() const {
//		return space;
//	}
//
//	void reserve(int alloc_size);
//	void resize(int resize_size, T val = T());
//	void push_back(T d);
//};
//
//template <typename T, typename A>
//void vector<T, A>::reserve(int alloc_size) {
//	if (alloc_size <= space) return;
//	
//	//T* p = new T[alloc_size];
//	T* p = a.allocate(alloc_size);
//	
//	//for (int i = 0; i < sz; i++) 
//	//	p[i] = elem[i];
//	//delete[] elem;
//	for (int i = 0; i < sz; i++) a.construct(&p[i] , elem[i]);
//	for (int i = 0; i < sz; i++) a.destroy(&elem[i]);
//	a.deallocate(elem, space);
//
//	elem = p;
//	space = alloc_size;
//}
//
//template <typename T, typename A>
//T& vector<T, A>::operator[](int n) {
//	return elem[n];
//}
//
//template <typename T, typename A>
//const T& vector<T, A>::operator[](int n) const {
//	return elem[n];
//}
//
//template <typename T, typename A>
//T& vector<T, A>::at(int n) {
//	if (n < 0 || sz <= n) throw out_of_range("Out of range");
//	return elem[n];
//}
//
//template <typename T, typename A>
//const T& vector<T, A>::at(int n) const{
//	if (n < 0 || sz <= n) throw out_of_range("Out of range");
//	return elem[n];
//}
//
//template <typename T, typename A>
//vector<T, A>::vector(const vector<T,A>& v) {
//	*this = v;
//}
//
//template <typename T, typename A>
//vector<T, A>& vector<T, A>::operator=(const vector<T, A>& v) {
//	if (this == &v) return *this;
//
//	if (v.sz <= space) {
//		for (int i = 0; i < v.sz; i++)
//			elem[i] = v.elem[i];
//		sz = v.sz;
//		return *this;
//	}
//
//	//T* p = new T[v.sz];
//	T* p = a.allocate(v.sz);
//
//	//for (int i = 0; i < v.sz; i++) p[i] = v.elem[i];
//	for (int i = 0; i < v.sz; i++) a.construct(&p[i], v.elem[i]);
//	for (int i = 0; i < v.sz; i++) a.destroy(&elem[i]);
//
//	//delete[] elem;
//	a.deallocate(elem, space);
//
//	elem = p;
//	space = sz = v.sz;
//	return *this;
//}
//
//template <typename T, typename A>
//void vector<T, A>::resize(int resize_size, T val) {
//	reserve(resize_size);
//	/*for (int i = 0; i < resize_size; i++) 
//		elem[i] = 0;*/
//	for (int i = 0; i < resize_size; i++) a.construct(&elem[i], val);
//	for (int i = 0; i < resize_size; i++) a.destroy(&elem[i]);
//	
//	sz = resize_size;
//}
//
//template <typename T, typename A>
//void vector<T, A>::push_back(T d) {
//	if (space == 0)
//		reserve(10);
//	else if (sz == space)
//		reserve(2 * space);
//	elem[sz] = d;
//	++sz;
//}
//
//
//int main()
//{
//	vector<double> dv(3);
//	dv.resize(5);
//	for (int i = 0; i < dv.size(); ++i) {
//		cout << dv[i] << " ";      //0 0 0 0 0
//	}
//	return 0;
//	vector<double> cv(5);
//
//	dv = cv;
//}



//partial template specialization
//template <class T, class U>
//class Pair {
//	T m_x;
//	U m_y;
//public:
//	Pair(const T& x, const U& y)
//		: m_x(x), m_y(y) {
//	}
//	Pair(const U& x, const T& y)
//		: m_x(x), m_y(y) {
//	}
//	const T& first() const {
//		return m_x;
//	}
//	const U& second() const {
//		return m_y;
//	}
//};
//
//template<class T>
//class StringValuePair : public Pair<std::string, T> {
//public:
//	StringValuePair(const std::string& str, const T& val) : Pair<std::string, T>(str, val) {}
//};
//
//int main() {
//	StringValuePair<int> svp("Hello", 5);
//	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
//	return 0;
//}




//Aggregation using manual memory handling, using dynamic resize
//#include <iostream>
//#include <string>
//
//class Teacher
//{
//    std::string m_name{};
//public:
//    Teacher() {}
//    Teacher(const std::string& name)
//        : m_name{ name }
//    {
//    }
//    const std::string& getName() const {
//        return m_name;
//    }
//};
//
//class Department
//{
//    Teacher* m_teacher = nullptr;
//    int m_size = 0;
//public:
//    Department() {}
//    Department(const Teacher& teacher) {
//        *m_teacher = teacher;
//    }
//    void add(const Teacher& teacher) {
//
//        Teacher* temp = nullptr;
//        temp = new Teacher[m_size + 1];
//
//        for (int i = 0; i < m_size; i++)
//            temp[i] = m_teacher[i];
//
//        temp[m_size] = teacher;
//
//        delete[] m_teacher;
//        m_teacher = temp;
//        temp = nullptr;
//
//        ++m_size;
//    }
//    ~Department() {
//        delete[] m_teacher;
//    }
//    const int getSize() const {
//        return m_size;
//    }
//    ostream& getTeacher() const{
//        cout << "Department: ";
//        for (int i = 0; i < m_size; i++) {
//            cout << m_teacher[i].getName() << " ";
//        }
//        return cout << endl;
//    }
//};
//
//ostream& operator<<(ostream& os, const Department& other) {
//     return other.getTeacher();
//}



//Aggregation using vector and reference wrapper
//#include <iostream>
//#include <string>
//
//class Teacher
//{
//    std::string m_name{};
//public:
//    Teacher() {}
//    Teacher(const std::string& name)
//        : m_name{ name }
//    {
//    }
//    const std::string& getName() const {
//        return m_name;
//    }
//};
//
////ostream& operator<<(ostream& os, const Teacher& other) {
////    return cout << other.getName();
////}
//
//class Department
//{
//    std::vector<reference_wrapper<const Teacher>> m_teacher;
//    int m_size = 0;
//public:
//    Department() {}
//    Department(const Teacher& teacher) {
//        m_teacher.push_back(teacher);
//    }
//    void add(const Teacher& teacher) {
//        m_teacher.push_back(teacher);
//    }
//    ostream& getTeacher() const {
//        cout << "Department: ";
//        for (int i = 0; i < m_teacher.size(); i++) {
//            cout << m_teacher[i].get().getName() << " ";
//        }
//        return cout << endl;
//    }
//};
//
//ostream& operator<<(ostream& os, const Department& other) {
//    return other.getTeacher();
//}
//
//int main()
//{
//    // Create a teacher outside the scope of the Department
//    Teacher t1{ "Bob" };
//    Teacher t2{ "Frank" };
//    Teacher t3{ "Beth" };
//    {
//        // Create a department and add some Teachers to it
//        Department department{}; // create an empty Department
//
//        department.add(t1);
//        department.add(t2);
//        department.add(t3);
//
//        std::cout << department;
//
//    } // department goes out of scope here and is destroyed
//
//    std::cout << t1.getName() << " still exists!\n";
//    std::cout << t2.getName() << " still exists!\n";
//    std::cout << t3.getName() << " still exists!\n";
//
//    return 0;
//}




//function pointers
//#include <functional>
//
//using ArithmeticFunction = std::function<int(int, int)>;
//
//int add(int a, int b) {
//	return a + b;
//}
//
//int subtract(int a, int b) {
//	return a - b;
//}
//
//int multiply(int a, int b) {
//	return a * b;
//}
//
//int divide(int a, int b) {
//	return a / b;
//}
//
//void getInteger(int& a, int& b) {
//	cout << "a: ";
//	cin >> a;
//
//	cout << "b: ";
//	cin >> b;
//}
//
//void getOperation(char& c) {
//	do {
//		cout << "arithmetic: ";
//		cin >> c;
//	}while (c != '+' && c != '-' && c != '*' && c != '/');
//}
//
////auto getArithmeticFunction(const char& c) {
////	
////	int (*foo) (int, int) = nullptr;
////
////	if (c == '+') {
////		return foo = add;
////	}
////	else if (c == '-') {
////		return foo = subtract;
////	}
////	else if (c == '*') {
////		return foo = multiply;
////	}
////	else {
////		return foo = divide;
////	}
////}
//
//ArithmeticFunction getArithmeticFunction(const char& c) {
//	if (c == '+') {
//		return add;
//	}
//	else if (c == '-') {
//		return subtract;
//	}
//	else if (c == '*') {
//		return multiply;
//	}
//	else if (c == '/') {
//		return divide;
//	}
//	else {
//		return nullptr;
//	}
//}
//
//int main() {
//
//	int i, j;
//	char c;
//
//	getInteger(i, j);
//	getOperation(c);
//
//	ArithmeticFunction fn = getArithmeticFunction(c);
//	cout << i << ' ' << c << ' ' << j << " = " << fn(i, j) << endl;
//	//cout << (getArithmeticFunction(c))(i, j);
//
//	return 0;
//}



//function pointer
//typedef void (*printVal)(int);
//
//void printValue(int value) {
//	cout << "Value: " << value << endl;
//}
//
//void forEach(const vector<int>* values, /*const vector<int>& values, */ /*printVal pV*/ void(*func)(int)) {
//	for (int value : *values /*values*/) {
//		//pV(value);
//		func(value);
//	}
//}
//
//int main(int argc, char* argv[]) {
//	
//	//printVal pV = printValue;
//	//forEach(values, pV);
//
//	vector<int> values = { 1,2,3,4,5 };
//	forEach(&values, printValue);
//	//forEach(values, printValue);
//}

//class Line {
//	double a;
//	double b;
//public:
//	Line(double slope = 1, double yintercept = 1) : a(slope), b(yintercept) {}
//	double operator()(double x) {
//		return a*x + b;
//	}
//};
//
//
//int main()
//{
//	Line fa;
//	Line fb(5.0, 10.0);
//
//	double y1 = fa(20.0);
//	double y2 = fb(3.0);
//
//	cout << "y1= " << y1 << " y2= " << y2 << endl;
//	return 0;
//}



//functor
//#include <iostream>
//#include <vector>
////#include <algorithm>
//using namespace std;
//
//template<class Iterator, class Function>
//Function for_each(Iterator first, Iterator last, Function f) {
//	while (first != last) {
//		f(*first);
//		++first;
//	}
//	return f;
//}
//
//template <typename T>
//class Add {
//	T x;
//public: 
//	Add(T xx) : x(xx) {}
//	void operator() (T& e) const {
//		e += x;
//	}
//};
//
//template <typename T>
//class PrintElements
//{
//public:
//	void operator()(T& elm) const {
//		cout << elm << ' ';
//	}
//};
//
//int main()
//{
//	int size = 5;
//	vector<int> v;
//	for (int i = 0; i < size; i++) v.push_back(i);
//	PrintElements<int> print_it;
//	for_each(v.begin(), v.end(), print_it);
//	for_each(v.begin(), v.end(), Add<int>(10));
//	for_each(v.begin(), v.end(), print_it);
//	for_each(v.begin(), v.end(), Add<int>(*v.begin()));
//	for_each(v.begin(), v.end(), print_it);
//	return 0;
//}



//functor
//struct Dog {
//	Dog(int age, int weight) : m_age{ age }, m_weight{weight} {}
//	int m_age;
//	int m_weight;
//
//	bool operator<(const Dog& other) const {
//		return m_age < other.m_age;
//	}
//
//	bool operator==(int age) const {
//		return m_age == age;
//	}
//};
//
//struct SortByWeight {
//	bool operator() (const Dog& one, const Dog& sec) const {
//		return one.m_weight < sec.m_weight;
//	}
//};
//
//struct FindByWeight {
//	FindByWeight(int weight) : m_weight{ weight } {}
//
//	bool operator()(const Dog& other) const {
//		return m_weight == other.m_weight;
//	}
//
//	int m_weight;
//};

//template <typename T>
//struct MatchFirst {
//	MatchFirst(T const& i) : m_i{ i } {}
//
//	template <typename U>
//	bool operator()(/*pair<int, bool>*/U const& pair) {
//		return pair.first == m_i;
//	}
//
//	T m_i;
//};
//
//int main() {
//
//	//vector<Dog> v = { Dog(3, 40), Dog(1, 50), Dog(5, 60), Dog(2, 20), Dog(4, 10) };
//	////sort(begin(v), end(v)); //sort using comparator provided in Dog class
//	//sort(begin(v), end(v), SortByWeight()); // sort using function object provided in SortByWeight
//	//find(begin(v), end(v), 3); //find by age
//	//find_if(begin(v), end(v), FindByWeight(20)); //find by weight
//	
//	vector<pair<int, bool>> v1 = {make_pair(1,true), make_pair(2, false)};
//	vector<pair<bool, float>> v2 = { make_pair(true,1.f), make_pair(false,2.f) };
//	find(begin(v1), end(v1), make_pair(2, true));
//	find_if(begin(v1), end(v1), MatchFirst<int>(2));
//	find_if(begin(v2), end(v2), MatchFirst<bool>(true));
//	return 0;
//}



//functor and predicates using std::sort function
//struct KeyValue {
//	int m_key;
//	std::string m_value;
//	public:
//	KeyValue(int key, string value) : m_key{ key }, m_value{ value } {}
//
//	/*bool operator<(const KeyValue& sec) const {
//		return m_key < sec.m_key;
//	}*/
//
//	bool operator>(const KeyValue& sec) const {
//		return m_key > sec.m_key;
//	}
//};

//struct less_than {
//	bool operator()(const KeyValue& one, const KeyValue& sec) const {
//		return one.m_key < sec.m_key;
//	}
//};

//int main() {
//	vector<KeyValue> vec;
//
//	vec.push_back(KeyValue(2, "is"));
//	vec.push_back(KeyValue(3, "a"));
//	vec.push_back(KeyValue(1, "This"));
//	vec.push_back(KeyValue(4, "test"));
//
//	//sort(vec.begin(), vec.end(), less_than()); // optional predicate
//	//sort(vec.begin(), vec.end()); // uses member function of KeyValue class to compare the objects
//	sort(vec.begin(), vec.end(), std::greater<KeyValue>());
//	return 0;
//}




//std::sort + vector + custom types
//struct Person {
//	
//	Person(string name, int age, string favColor) : m_name{name}, m_age {
//		age
//	}, m_favColor{ favColor }{}
//
//	string m_name;
//	int m_age;
//	string m_favColor;
//};
//
//bool nameGreaterThan(const Person& one, const Person& sec) {
//	return one.m_name > sec.m_name;
//}
//
//bool ageGreaterThan(const Person& one, const Person& sec) {
//	return one.m_age > sec.m_age;
//}
//
//bool favColorGreaterThan(const Person& one, const Person& sec) {
//	return one.m_favColor > sec.m_favColor;
//}
//
//ostream& operator<<(ostream& os, const Person& other) {
//	return cout << other.m_name << " " << other.m_age << " " << other.m_favColor << " | ";
//}
//
//template <typename T>
//bool wayToSort(T i, T j) {
//	return i > j;
//}
//
//void main() {
//
//	vector<Person> p = { Person("Soham", 24, "Red"), Person("Dharit", 26, "Blue"), Person("Dhruvil", 13, "Orange") };
//
//	bool (*intFunctor) (int, int) = wayToSort;
//	bool (*stringFunctor) (string, string) = wayToSort;
//
//	vector<int> iv = { 56, 32, -43, 23, 12, 132, -154 };
//	vector<string> sv = { "John", "Bob", "Joe", "Zack", "Randy" };
//
//	//sort(begin(iv), end(iv));
//	//sort(iv.begin(), iv.end());
//	//sort(iv.begin(), iv.end(), intFunctor);
//	sort(iv.begin(), iv.end(), std::greater<int>());
//	
//	sort(p.begin(), p.end(), ageGreaterThan);
//	/*for (vector<Person>::size_type i = 0; i != p.size(); i++) 
//		cout << p[i] << " ";*/
//	for (const Person& pv : p)
//		cout << pv << " ";
//	cout << endl;
//
//	//for (vector<int>::size_type i = 0; i != iv.size(); i++) cout << iv[i] << " ";
//	for (int vi: iv) 
//		cout << vi << " ";
//	cout << endl;
//
//	//sort(sv.begin(), sv.end());
//	//sort(sv.begin(), sv.end(), stringFunctor);
//	sort(sv.begin(), sv.end(), std::greater<string>());
//
//	for (string& s : sv) 
//		cout << s << " ";
//	cout << endl;
//}

//int main() {
//	string s = "spaces in text";
//
//	cout << s << endl;
//
//	auto new_end = remove_if(s.begin(), s.end(), bind2nd(equal_to<char>(), ' '));
//
//	for (size_t i = 0; i < 2; i++){
//		cout << new_end[i];
//	}
//
//	s.erase(new_end, s.end());
//
//	for (size_t i = 0; i < 2; i++) {
//			cout << new_end[i];
//	}
//
//	cout << endl << s;
//}



//lambda expression
//void printVector(vector<int> v) {
//	// lambda expression to print vector
//	for_each(v.begin(), v.end(), [](int i)
//		{
//			std::cout << i << " ";
//		});
//	cout << endl;
//}
//
//int main() {
//
//    vector<int> v1 = { 3, 1, 7, 9 };
//    vector<int> v2 = { 10, 2, 7, 16, 9 };
//
//    auto pushinto = [&](int m)
//    {
//        v1.push_back(m);
//        v2.push_back(m);
//    };
//
//    pushinto(20);
//
//    auto v = [v1]()
//    {
//        for (auto p = v1.begin(); p != v1.end(); p++) {
//            cout << *p << " ";
//        }
//    };
//
//    int N = 5;
//    string s1 = "Soham";
//
//    signed count_N = count_if(v1.begin(), v1.end(), bind2nd(greater_equal<int>(), 5)/*[=](int a) -> bool {
//        return (a >= N);
//    }*/);
//
//    cout << "The number count in v1 that are greater than 5 are: " << count_N;
//}


//lambda expression
//class AddressBook {
//public:
//    template <typename Func>
//    std::string findMatchingAddress(Func func) {
//        
//        std::string results;
//            if (func(_addresses)) {
//                results+=_addresses;
//            }
//        return results;
//    }
//
//    AddressBook(const char* other) {
//        _addresses.assign(static_cast<string>(other));
//    }
//
//    const std::string& getString() const {
//        return _addresses;
//    }
//
//private:
//    std::string _addresses;
//};
//
//
//int main() {
//    std::vector<AddressBook> ad = { "Bayfield", "Bayfield", "Timberwolf", "Tommy"};
//
//    std::string result;
//
//    for (auto i = 0; i < (ad.size()-1); i++) {
//        result.operator+=(ad[i].findMatchingAddress ([=](auto itr) /*-> bool*/ {
//            return itr.compare(ad[i+1].getString()) == 0;
//        }));
//    }
//    cout << result;
//}

//int main()
//{
//    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
//
//    // std::find_if takes a pointer to a function
//    const auto found{ std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
//        return str.find("nut") != std::string_view::npos;
//        }) 
//    };
//
//    if (found == arr.end())
//    {
//        std::cout << "No nuts\n";
//    }
//    else
//    {
//        std::cout << "Found " << *found << '\n';
//    }
//
//    return 0;
//}



//using std::function and lambdas
//int main() {
//
//	double (*addNumbers1)(double, double) = [](double a, double b) {
//		return a + b;
//	};
//
//	addNumbers1(1, 2);
//
//	std::function addNumbers2{
//		[](double a, double b) {
//			return a + b;
//		}
//	};
//
//	std::function<double(double, double)> addNumbers3 = [](double a, double b) {
//		return a + b;
//	};
//
//	cout << addNumbers1(1.4, 2.4) << endl;
//	cout << addNumbers2(2.4, 3.4) << endl;
//	cout << addNumbers3(3.4, 4.4) << endl;
//}



//using lamdba function's const reference and using the standard lib's function class template
//void repeat(int reps, const std::function<void(int)>& fn) {
//	for (int i = 0; i < reps; i++) fn(i);
//}
//
//int main() {
//	repeat(3, [](int i) {
//		cout << i << " ";
//	});
//}

//lambdas and std library classes and functions
//int main() {
//    constexpr std::array months{
//        "January",
//        "February",
//        "March",
//        "April",
//        "May",
//        "June",
//        "July",
//        "August",
//        "September",
//        "October",
//        "November",
//        "December"
//    };
//
//    const auto sameLetter = std::adjacent_find(months.begin(), months.end(), [](const auto& a, const auto& b) {
//        return a[0] == b[0];
//    });
//
//    if (sameLetter != months.end()) {
//        cout << *sameLetter << " and " << *std::next(sameLetter) << " start with same letter\n";
//    }
//}


//lambdas with custom types
//struct Student {
//	string name;
//	int points;
//
//    const int operator<(const Student& other) const{
//        return points < other.points;
//    }
//
//    ostream& write(ostream& os) const{
//        return os << name << "is the best student with points: " << points;
//    }
//};
//
//ostream& operator<<(ostream& os, const Student& other) {
//    return other.write(os);
//}
////template <class T, size_t N>
////ostream& operator<<(ostream& os, const std::array<T, N>& arr) {
////    copy(arr.begin(), arr.end(), ostream_iterator<T>(os, " "));
////    return 0;
////}
//
//int main() {
//    std::array<Student, 8> arr{
//        {{ "Albert", 3 },
//        { "Ben", 5 },
//        { "Christine", 2 },
//        { "Dan", 8 }, // Dan has the most points (8).
//        { "Enchilada", 4 },
//        { "Francis", 1 },
//        { "Greg", 3 },
//        { "Hagrid", 5 }}
//    };
//
//    auto/*std::_Array_iterator<Student, 8>*/ max = std::max_element(arr.begin(), arr.end(), [](const Student& a, const Student& b) {
//        return a < b;
//    });
//    
//    //std::cout << max->name << " is the best student\n";
//    cout << *max;
//
//    cout << typeid(max).name();
//}


//lambda practise
//struct Season
//{
//    std::string_view name{};
//    double averageTemperature{};
//
//    bool operator<(const Season& other) const{
//        return averageTemperature < other.averageTemperature;
//    }
//};
//
//int main()
//{
//    std::array<Season, 4> seasons{ 
//      { { "Spring", 285.0 },
//        { "Summer", 296.0 },
//        { "Fall", 288.0 },
//        { "Winter", 263.0 } }
//    };
//
//    int comp = 0;
//
//    sort(seasons.begin(), seasons.end(), [&comp](const Season& a, const Season& b) {
//        //return a < b;
//        ++comp;
//        return a.averageTemperature < b.averageTemperature;
//        });
//
//    for (const auto& season : seasons)
//    {
//        std::cout << season.name << "\n";
//    }
//
//    cout << "Total comparison made: " << comp;
//
//    return 0;
//}


//using stl + lambdas to find a solution
//void generateNumber(vector<int>& v, int start, int num) {
//	for (size_t i = 0; i < num; i++){
//		v.push_back(start * start);
//		++start;
//	}
//}
//void guess(int rand, int num, vector<int>& v) {
//	int userInput, flag = 1;
//
//	cout << "I generated " << num << " square numbers. Do you know what each number is after multiplying it by " << rand << "?\n";
//
//	while (flag) {
//		cout << "> ";
//		cin >> userInput;
//
//		auto found = std::find(v.begin(), v.end(), userInput);
//
//		if (found != v.end()) {
//			v.erase(found);
//			if (v.size() != 0)
//				cout << "Nice! " << v.size() << " numbers left.\n";
//			else 
//				flag = 0;
//		}
//		else {
//
//			auto smallest = std::min_element(v.begin(), v.end(), [=](const auto& a, const auto& b) {
//				
//				if ((userInput >= (a - 4) && userInput <= (a + 4)) /*|| (userInput >= (b - 4) && userInput <= (b + 4))*/)
//					return true;
//				else
//					return false;
//				//a represents the 2nd element in the vector, and traverses through the whole vector until it hits the last element
//				//if the lambda returns false always then the smallest will be the first element in the vector. so for that reason we must check again in the below if, whether the "smallest" variable is in the range of +- 4;
//			});
//
//			if (userInput >= (*smallest - 4) && userInput <= (*smallest + 4)) //to check if the 1st element was the closest
//				cout << userInput << " is wrong! Try " << *smallest << " next time.\n";
//			else
//				cout << userInput << " is wrong!";
//
//			flag = 0;
//		}
//	}
//
//	if (v.size() == 0) {
//		cout << "Nice! You found all numbers, good job!";
//	}
//}
//
//void generateRandomAndSquare(vector<int>& v, int num) {
//	int randomNum;
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<> distr(2, 4);
//
//	randomNum = distr(gen)/*2 + (rand() % (4 - 2 + 1))*/;
//	
//	//auto j = v.begin();
//	//for (size_t i = 0; i < num; i++) {
//	//	v[i] = (*j) * randomNum;
//	//	++j;
//	//}
//
//	std::transform(v.begin(), v.end(), v.begin(), [randomNum](int i) {
//		return randomNum * i;
//	});
//
//	guess(randomNum, num, v);
//}
//
//int main() {
//	int start = 0;
//	int num = 0;
//
//	cout << "Start where? ";
//	cin >> start;
//
//	cout << "How many? ";
//	cin >> num;
//
//	vector<int> v;
//	generateNumber(v, start, num);
//	generateRandomAndSquare(v, num);
//	//std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
//	
//	return 0;
//}

//struct OrderPairsByFirstValue {
//	
//	template <class T>
//	bool operator()(T const& lhs, T const& rhs) const{
//		return lhs.first < rhs.first;
//	} 
//};
//
//int main() {
//	vector<pair<int, double>> v1 = {make_pair(1,3.2),make_pair(2,4.2), make_pair(3,5.2)};
//	vector<pair<bool, char>> v2 = { make_pair(true,'a'), make_pair(false,'b') };
//	//sort(begin(v1), end(v1), OrderPairsByFirstValue());
//	//sort(begin(v2), end(v2), OrderPairsByFirstValue());
//
//	auto lambda = [](auto const& lhs, auto const& rhs) {
//		return lhs.first < rhs.first;
//	};
//
//	sort(begin(v2), end(v2), lambda);
//}

//void ForEach(const vector<int>& v, const function<void(int)>& func) {
//	for (int val : v)
//		func(val);
//}
//
//int main() {
//	vector<int> v = { 1,2,3,4,5 };
//
//	int a = 5;
//
//	auto lambda = [=](int value) {cout << "Value: " << value << a << endl; };
//	
//	//
//	ForEach(v, lambda);
//}

//error handling
//int main() {
//
//	bool flag = true;
//
//	while(flag)
//	try {
//		vector<int> v = { 1,2,3,4,5 };
//
//		int i = 0;
//
//		cout << "What element would you like to view: ";
//		cin >> i;
//
//		if (i > v.size()) throw v;
//
//		cout << "The element's value that you selected is: " << v[i - 1] << ". Thanks good bye!";
//		flag = false;
//	}
//	catch (const vector<int>& v) {
//		cout << "You tried to access an element that is out of bounds/doesnt exist." << "The last element in the vector is: " << v.back() << " Try again." << endl;
//	}
//}




//randim stuff
//vector<int> Range(int start, int max, int step);
//
//int main() {
//
//	//verison 1
//	//int tree = 0, count = 0, width = 0;
//	//cout << "How tall is the tree: ";
//	//cin >> tree;
//
//	//width = tree;
//
//	//for (int i = 0; i < tree; i++) {
//	//	for (int j = 0; j < count+1; j++) {
//	//		if (i == 0) {
//	//			cout << setw(width) << "#";
//	//			break;
//	//		}
//	//		else {
//	//			if(j == 0) cout << setw(width) << "#";
//	//			else cout << "#";
//	//		}
//	//	}
//	//	--width;
//	//	count += 2;
//	//	cout << endl;
//	//}
//	//cout << setw(tree+1) << "#\n";
//
//	
//	//version 2
//	//cout << "How tall is the tree: ";
//	//int treeHeight = 0, spaces = 0, hashes = 1, stumpSpaces = 0;
//	//cin >> treeHeight;
//	//spaces = treeHeight - 1;
//	//stumpSpaces = treeHeight - 1;
//
//	//while (treeHeight != 0) {
//	//	for (auto x : Range(1, spaces, 1))
//	//		cout << ' ';
//
//	//	for (auto x : Range(1, hashes, 1))
//	//		cout << '#';
//
//	//	cout << endl;
//	//	--spaces;
//	//	hashes += 2;
//	//	--treeHeight;
//	//}
//
//	//for (auto x : Range(1, stumpSpaces, 1))
//	//	cout << ' ';
//	//cout << '#';
//
//	return 0;
//}
//
//vector<int> Range(int start, int max, int step) {
//	
//	int i = start;
//
//	vector<int> range;
//
//	while (i <= max) {
//		range.push_back(i);
//		i += step;
//	}
//	return range;
//}



//custom classes error handling and inheriting from exception class
//class OverSpeed: public exception {
//	int m_speed;
//public:
//	OverSpeed(int speed) : m_speed{ speed } {}
//	
//	const char* what() const{
//		return "Check your car speed.\nYou are in the car, not an aeroplane!!!!!!!\n";
//	}
//
//	void getSpeed() const{
//		cout << "You car speed is " << m_speed << endl;
//	}
//};
//
//class Car {
//	int m_speed = 0;
//public:
//	Car() {
//		cout << "Speed is: " << m_speed << endl;
//	}
//
//	void accelerate() {
//		for (;;) {
//			m_speed += 10;
//			cout << "Speed is: " << m_speed << endl;
//
//			if (m_speed >= 250) {
//				OverSpeed s(m_speed);
//				throw s;
//			}
//		}
//	}
//};
//
//int main() { 
//	Car c;
//
//	try {
//		c.accelerate();
//	}
//	catch(const OverSpeed& err){
//		cout << err.what();
//		err.getSpeed();
//	}
//}


//template + inheritance + pure virtual functions
//class iCar {
//public:
//	virtual void speed() = 0;
//	virtual ~iCar() {}
//};
//
//template <class T>
//class Car : public iCar {
//	//T* car;
//public:
//	void getName() {
//		cout << typeid(T).name() << endl;
//	}
//	//void speed() {
//	//	car->speed();
//	//}
//	//Car() {
//	//	car = new T;
//	//}
//	//~Car() {
//	//	delete car;
//	//}
//};
//
//class Ford : public Car<Ford> /*iCar*/{
//public:
//	void speed() override {
//		cout << "My speed is 250kph\n";
//	}
//};
//
//class Kia : public Car<Kia> /*iCar*/{
//public:
//	void speed() override {
//		cout << "My speed is 210kph\n";
//	} 
//};
//
//int main() {
//
//	//Car<Ford> f;
//	//f.speed();
//
//	//Car<Kia> k;
//	//k.speed();
//
//	Car<Ford>* f = new Ford;
//	f->speed();
//	f->getName();
//	delete f;
//
//	Car<Kia>* k = new Kia;
//	k->speed();
//	k->getName();
//	delete k;



//binary search algo
//int binarySearch(const int* array, int target, int min, int max)
//{
//    int mp = std::midpoint(min, max);
//    do {
//        if (array[mp] > target) {
//            max = mp - 1;
//        }
//        else if (array[mp] < target) {
//            min = mp + 1;
//        }
//        else {
//            return mp;
//        }
//        mp = std::midpoint(min, max);
//    } while (min <= max);
//    return -1;
//}
//
//int main()
//{
//
//    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
//    //constexpr int array[]{ 3, 6, 7, 9, 12, 15, 18, 21, 24 };
//
//    // We're going to test a bunch of values to see if they produce the expected results
//    constexpr int numTestValues{ 9 };
//    // Here are the test values
//    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
//    // And here are the expected results for each value
//    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };
//
//    // Loop through all of the test values 
//    for (int count{ 0 }; count < numTestValues; ++count)
//    {
//        // See if our test value is in the array
//        int index = binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1);
//        //int index = binarySearch(array, 7, 0, static_cast<int>(std::size(array)) - 1);
//        // If it matches our expected value, then great!
//         if (index == expectedValues[count])
//            cout << "test value " << testValues[count] << " passed!\n";
//        else // otherwise, our binarySearch() function must be broken
//            cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
//    }
//    return 0;
//}



//error handling in a class
//class A
//{
//public:
//    A(int n) : i(n) {
//        cout << i;
//    }
//
//    ~A() {
//        cout << i;
//    }
//
//private:
//    int i;
//};
//
//int f(int n)
//{
//    if (n == 1) {
//        throw std::logic_error("0");
//        cout << "7" << endl;
//    }
//    A a(n);
//    return f(n - 1);
//} 
//
//int main()
//{
//    try {
//        int ret = f(3);
//        A a(ret);
//    }
//    catch (const std::exception& e) {
//        cout << e.what()  << endl;
//    }
//
//    return 0;
//}




//int add(int x) {
//    
//    try {
//        if (!x) {
//            throw "0 found\n";
//        }
//    }
//    catch (const char* e) {
//        cout << e;
//        throw;
//    }
//}
//
//int main() {
//
//    try {
//        add(0);
//    }
//    catch (const char* e) {
//        cout << e;
//    }
//    catch (...)
//    {
//        cout << "all other execeptions";
//    }
//}


//error handling with the use of std::exception class objects
//class Fraction {
//	int numerator;
//	int denominator;
//public:
//	Fraction(int n, int d) : numerator{ n }, denominator{ d } {
//		if (d == 0) {
//			throw runtime_error("Invalid denominator\n");
//		}
//	}
//};
//
//void main() {
//	int n, d;
//
//	cout << "Enter numerator: ";
//	cin >> n;
//	cout << "Enter denominator: ";
//	cin >> d;
//
//	try {
//		Fraction f(n, d);
//	}
//	catch (runtime_error& e /*exception& e*/) {
//		cout << e.what();
//	}
//}


//implementing copy and move semantics for a template class that has resources

//class Resource {
//	int m_data;
//public:
//	Resource() {
//		m_data = 0;
//	}
//	~Resource() {}
//};
//
//template <class T>
//class Auto_ptr {
//	T* m_data;
//public:
//	Auto_ptr(T* data = nullptr) : m_data{ data } {}
//	Auto_ptr(const Auto_ptr<T>& other);
//	Auto_ptr(Auto_ptr<T>&& other);
//	~Auto_ptr() {
//		delete m_data;
//	}
//	T& operator*() const {
//		return *m_data;
//	}
//	T* operator->() const{
//		return m_data;
//	}
//	Auto_ptr<T>& operator=(const Auto_ptr<T>& other);
//	Auto_ptr<T>& operator=(Auto_ptr<T>&& other);
//};
//
//template <class T>
//Auto_ptr<T>::Auto_ptr(const Auto_ptr<T>& other): Auto_ptr(){
//	*this = other;
//}
//
//template <class T>
//Auto_ptr<T>::Auto_ptr(Auto_ptr<T>&& other) : Auto_ptr() {
//	*this = move(other);
//}
//
//template <class T>
//Auto_ptr<T>& Auto_ptr<T>::operator=(Auto_ptr<T>&& other) {
//	if (this != &other) {
//		//delete m_data;
//		delete this->operator->();
//		m_data = other.operator->();
//		other.m_data = nullptr;
//	}
//	return *this;
//}
//
//template <class T>
//Auto_ptr<T>& Auto_ptr<T>::operator=(const Auto_ptr<T>& other) {
//	
//	if (this != &other) {
//		delete this->operator->();
//		if (other.operator->()) {
//			m_data = new T();
//			//this->operator->() = new T();
//			this->operator*() = other.operator*();
//		}
//	}
//	return *this;
//}
//
//int add(const int& a, const int& b) {
//	return a + b;
//}
//
//int main() {
//	Auto_ptr<Resource> res1(new Resource());
//	Auto_ptr<Resource> res2(res1);
//
//	Auto_ptr<Resource> res3(move(Auto_ptr<Resource>(new Resource)));
//	res3 = move(Auto_ptr<Resource>(new Resource));
//	//Auto_ptr<Resource>&& res3(Auto_ptr<Resource>(new Resource));
//	//an rvalue reference or a const lvalue reference can extend the 
//	//life time of the object from expression scope to the block scope
//	//that they are defined within
//
//	//all the named objects are lvalues regardless whether they are created using && or & or a normal variable
//	//all the nameless objects are rvalues 
//
//	//int x = 1;
//	//int y = 2;
//
//	////int& b = x; //non modifiable lvalue can only be initialized with a lvalue 
//	//const int& b = move(x); //modifiable lvalue can be initialized with a lvalue or an rvalue
//
//	////const lvalue reference as function parameter allows us to pass lvalue or rvalue 
//	////so that we can use the move semantics for custom types
//	//cout << add(x, y);
//	//cout << add(move(x), move(y));
//}




//testing std::chrono
//void swap(int* xp, int* yp) {
//    int temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}
//
//int main() {
//
//    /*std::chrono::high_resolution_clock::time_point*/ auto start =
//        std::chrono::high_resolution_clock::now();
//
//    int* arr = new int[10000];
//    for (size_t i = 0; i < 10000; i++)
//    { 
//        arr[i] = i * 2;
//    }
//
//    int i, j, min_idx, n = 10000;
//    for (i = 0; i < n - 1; i++)
//    {
//        min_idx = i;
//        for (j = i + 1; j < n; j++)
//            if (arr[j] < arr[min_idx])
//                min_idx = j;
//
//        swap(&arr[min_idx], &arr[i]);
//    }
//
//    /*std::chrono::high_resolution_clock::time_point*/ auto end =
//        std::chrono::high_resolution_clock::now(); //a time point is a point in time, and now() return the current system time 
//
//    std::chrono::duration<float> runtime = end - start; //end and start are of type time_point, time_point has - operator overloaded, so when you do a subtraction, that operator returns an object of time_point 
//    //a durartion is the time interval/time elapsed since the start to the end 
//
//    cout << "Loop runtime duration: " << runtime.count() << endl;
//    float durationSecond = runtime.count(); //".count" returns a type equal to the type declared when creating the duration object, the value that it returns would be the time in seconds
//    //cout << durationSecond;
//
//
//
//	//using timer = std::chrono::high_resolution_clock;
//	//using dur = std::chrono::duration<double, std::ratio<1>>;
//
//	//std::chrono::time_point<timer> m_beg = timer::now();
//
//	//cout << std::chrono::duration_cast<dur>(timer::now() - m_beg).count();
//}


//tesing std::chrono
//class Dog {
//	std::chrono::steady_clock::time_point last;
//public:
//	Dog();
//	float Mark();
//	~Dog();
//};
//
//float Dog::Mark() {
//	const auto old = last;
//	last = std::chrono::steady_clock::now();
//	const std::chrono::duration<float> time = last - old;
//	return time.count();
//}
//
//Dog::Dog() {
//	last = std::chrono::steady_clock::now();
//}
//
//Dog::~Dog() {
//	cout << "Object deletion took: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::duration<float>(std::chrono::steady_clock::now() - last)).count() << " microseconds\n"; //casting the returned float from now() to the desired type, here the desired type is microseconds
//	cout << "Object deletion took: " << std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count() << " seconds";
//}
//
//int main() {
//	Dog a;
//	return 0;
//}



//error handling
//class MoveClass
//{
//private:
//    int* m_resource{};
//
//public:
//    MoveClass() = default;
//
//    MoveClass(int resource)
//        : m_resource{ new int{ resource } }
//    {}
//
//    // Copy constructor
//    MoveClass(const MoveClass& that)
//    {
//        // deep copy
//        if (that.m_resource != nullptr)
//        {
//            m_resource = new int{ *that.m_resource };
//        }
//    }
//
//    // Move constructor
//    MoveClass(MoveClass&& that) noexcept
//        : m_resource{ that.m_resource }
//    {
//        that.m_resource = nullptr;
//    }
//
//    ~MoveClass()
//    {
//        std::cout << "destroying " << *this << '\n';
//
//        delete m_resource;
//    }
//
//    friend std::ostream& operator<<(std::ostream& out, const MoveClass& moveClass)
//    {
//        out << "MoveClass(";
//
//        if (moveClass.m_resource == nullptr)
//        {
//            out << "empty";
//        }
//        else
//        {
//            out << *moveClass.m_resource;
//        }
//
//        out << ')';
//
//        return out;
//    }
//};
//
//
//class CopyClass
//{
//public:
//    bool m_throw{};
//
//    CopyClass() = default;
//
//    // Copy constructor throws an exception when copying from a CopyClass object where its m_throw is 'true'
//    CopyClass(const CopyClass& that)
//        : m_throw{ that.m_throw }
//    {
//        if (m_throw)
//        {
//            throw std::runtime_error{ "abort!" };
//        }
//    }
//};
//
//int main()
//{
//    // We can make a std::pair without any problems:
//    std::pair my_pair{ MoveClass{ 13 }, CopyClass{} };
//
//    std::cout << "my_pair.first: " << my_pair.first << '\n';
//
//    // But the problem arises when we try to move that pair into another pair.
//    try
//    {
//        my_pair.second.m_throw = true; // To trigger copy constructor exception
//
//        // The following line will throw an exception
//        std::pair moved_pair{ std::move(my_pair) }; // We'll comment out this line later
//        // std::pair moved_pair{std::move_if_noexcept(my_pair)}; // We'll uncomment this line later
//
//        std::cout << "moved pair exists\n"; // Never prints
//    }
//    catch (const std::exception& ex)
//    {
//        std::cerr << "Error found: " << ex.what() << '\n';
//    }
//
//    std::cout << "my_pair.first: " << my_pair.first << '\n';
//
//    return 0;
//}



//smart pointer/unique_ptr exercise
//class Resource {
//public:
//	int m_data;
//	Resource(int data = 0) : m_data{data} {
//		cout << "Resource acquired\n";
//	}
//	Resource& operator=(Resource&& other) {
//		m_data = other.m_data;
//		other.m_data = -1;
//		return *this;
//	}
//	~Resource() {
//		cout << "Resource deleted\n";
//	}
//	Resource& operator[](int i) {
//		m_data = i * 2;
//		return *this;
//	}
//};
//
//ostream& operator<<(ostream& os, const Resource& other) {
//	return cout << other.m_data << endl;
//}
//
//int main() {
//	//std::unique_ptr<Resource[]> res(new Resource[5]);
//	std::unique_ptr<Resource> res(new Resource(1));
//	std::unique_ptr<Resource> res2(new Resource(2));
//	/*for(int i = 0; i < 5; i++)*/
//	cout << *res/*[i]*/;
//
//	res.swap(res2);
//
//	res = std::move(res2);
//
//	cout << *res; //when unique ptr deletes the object it will delete the class that it manages, its data members' value. However if you still query *res, it still has the information like what kind of object it is pointing to so the above call will go to the overloaded the << operator
//	//cout << res2->m_data;	//this will however cause a runtime failure and program will terminate wice we tried to access the smart pointer's data member which is now deleted. 
//
//	Resource* r1 = new Resource[5];
//
//	for (size_t i = 0; i < 5; i++) {
//		(*r1)[i];
//	}
//
//	auto res4 = make_unique<Resource>(4); //make_unique returns a pointer of type unique_ptr<Resource>, where res4 is allocated on the heap as a single object rather than an array. If a single object it will run the ong arg constructor of Resource, if an array like below, then it will create that many objects on heap, all of them constructed will default ctor
//	cout << *res4;
//	auto res5 = make_unique<Resource[]>(5);
//	for (size_t i = 0; i < 5; i++) {
//		//res5[i].operator[](i);
//		res5[i][i];
//	}
//	cout << res5[0];
//
//
//	//create a member dynamic variable inside the class and dont delete that variable, see if the unique_ptr automatically deletes that object's dynamically allocated data member
//	//create a unique ptr as a member variable inside a class and see its deletion behaviour and play around with it 
//}

//smart pointer/unique_ptr exercise
//class Fraction
//{
//private:
//	int m_numerator{ 0 };
//	int m_denominator{ 1 };
//
//public:
//	Fraction(int numerator = 0, int denominator = 1) :
//		m_numerator{ numerator }, m_denominator{ denominator }
//	{
//	}
//
//	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
//	{
//		out << f1.m_numerator << '/' << f1.m_denominator;
//		return out;
//	}
//
//	~Fraction() {
//		cout << "deleted the fraction\n";
//	}
//};
//
//void printFraction(const Fraction* ptr)
//{
//	if (ptr)
//		std::cout << *ptr << '\n';
//}
//
//int main()
//{
//	auto var = unique_ptr<Fraction>(new Fraction(3, 5));
//	//auto var = make_unique<Fraction>( 3, 5 );
//
//	printFraction(var.get());
//
//	//auto* normalPtr = new unique_ptr<Fraction>(new Fraction(4,6));
//	//normalPtr->;
//
//	//unique_ptr<Fraction>* makeUniquePtr = &make_unique<Fraction>(3, 5);
//	//auto* makeUniquePtr = &make_unique<Fraction>(3, 5);
//	//makeUniquePtr->;
//	//not able to create a pointer which is assigned a value from "make_unique"
//
//	//auto* ptrArr = new unique_ptr<Fraction[]>(new Fraction[5]);
//	//for (size_t i = 0; i < 5; i++) {
//	//	(*ptrArr)[i] = Fraction(4, 6);
//	//}
//	//for (size_t i = 0; i < 5; i++) { 
//	//	//proof that a pointer to unique_ptr which 
//	//	//holds a dynamic array has been successfully initialized
//	//	cout << (*ptrArr)[i] << endl;
//	//}
//
//	//unique_ptr<Fraction>* ptrArr = new unique_ptr<Fraction[]>(new Fraction[5])[5];
//	//upper expression didnt work but internet says there is 
//	//no use of created a dynamically allocated pointer to unique_ptr
//
//	//delete all the local dynamically allocated object if they must to deleted. Check on matrix for memory leaks
//
//	return 0;
//}



//chrono + vector + move + copy sementics
//class Int {
//	int m_num;
//public:
//	Int(int num) : m_num{ num } {}
//	~Int() {}
//	bool operator>=(const Int& other) const;
//	friend ostream& operator<<(ostream& os, const Int& other);
//	Int(Int&& other);
//	Int& operator=(Int&& other);
//	Int(const Int& other);
//	Int& operator=(const Int& other);
//};
//
//Int::Int(Int&& other){
//	*this = move(other);
//}
//Int& Int::operator=(Int&& other) {
//	m_num = other.m_num;
//	other.m_num = -1;
//	return *this;
//}
//Int::Int(const Int& other) {
//	*this = other;
//}
//Int& Int::operator=(const Int& other) {
//	m_num = other.m_num;
//	return *this;
//}
//
//bool Int::operator>=(const Int& other) const{
//	return m_num >= other.m_num;
//}
//
//ostream& operator<<(ostream& os, const Int& other) {
//	return cout << other.m_num;
//}
//
//template <typename T>
//std::vector<T> genVector(int numOfNums, int min, int max) {
//	std::vector<T> vecValues;
//	srand((unsigned)time(0));
//	int i = 0, randVal = 0;
//
//	while (i < numOfNums) {
//		randVal = (rand() % max) + 1;
//		vecValues.push_back(randVal);
//		i++;
//	}
//	return vecValues;
//}
//
//template <class T>
//void bubbleSort(vector<T>& v) {
//	int i = v.size() - 1;
//	while (i >= 1) {
//		int j = 0;
//		while (j < i) {
//			cout << endl << v[j] << " is > " << v[j + 1] << " ?\n";
//
//			if (v[j] >= v[j + 1]) {
//				cout << "Switch\n";
//				T temp = std::move(v[j]);
//				v[j] = std::move(v[j + 1]);
//				v[j + 1] = std::move(temp);
//			}
//			else {
//				cout << "Dont switch\n";
//			}
//			++j;
//
//			//this will always call copy constructor for 
//			//custom types so its better to avoid range based for loops
//			/*for (auto k : v) { 
//				cout << k << ", ";
//			}*/
//
//			for (int i = 0; i < v.size(); i++) cout << v[i] << ", ";
//		}
//		cout << "\nEnd of round\n";
//		--i;
//	}
//}
//
//template <class T>
//void bubbleSortCC(vector<T>& v) {
//	int i = v.size() - 1;
//	while (i >= 1) {
//		int j = 0;
//		while (j < i) {
//			cout << endl << v[j] << " is > " << v[j + 1] << " ?\n";
//
//			if (v[j] >= v[j + 1]) {
//				cout << "Switch\n";
//				T temp = v[j];
//				v[j] = v[j + 1];
//				v[j + 1] = temp;
//			}
//			else {
//				cout << "Dont switch\n";
//			}
//			++j;
//
//			//this will always call copy constructor for 
//			//custom types so its better to avoid range based for loops
//			/*for (auto k : v) {
//				cout << k << ", ";
//			}*/
//
//			for (int i = 0; i < v.size(); i++) cout << v[i] << ", ";
//		}
//		cout << "\nEnd of round\n";
//		--i;
//	}
//}
//
//
//int main() { 
//
//	//vector<int> v = genVector<int>(10, 1, 50);
//	//bubbleSort<int>(v);
//	//
//	//cout << endl << "Printing the contents: ";
//	//for (auto x : v) {
//	//	cout << x << endl;
//	//}
//	//use the chrono lib to see the difference in time
//
//	//using move semantics
//	vector<Int> v = genVector<Int>(10, 1, 20);
//
//	std::chrono::time_point start = std::chrono::high_resolution_clock::now();
//	bubbleSort<Int>(v);
//
//	cout << "\nTook: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - start)).count() << " milliseconds\n";
//
//
//	//using copy semantics
//	vector<Int> vCC = genVector<Int>(10, 1, 20);
//
//	std::chrono::time_point startCC = std::chrono::high_resolution_clock::now();
//	bubbleSortCC<Int>(v);
//
//	cout << "\nTook: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - startCC)).count() << " milliseconds\n";
//	
//
//	cout << endl << "Printing the contents: ";
//	for (int i = 0; i < v.size(); i++) cout << v[i] << ", ";
//
//	cout << endl << "Printing the contents: ";
//	for (int i = 0; i < vCC.size(); i++) cout << vCC[i] << ", ";
//
//	return 0;
//}



//storing functions in a vector
//double MultBy2(double num) {
//	return num * 2;
//}
//
//double DoMath(function<double(double)> func, double number) {
//	return func(number);
//}
//
//double MultBy3(double num) {
//	return num * 3;
//}
//
//int main() {
//	auto times2 = MultBy2;
//
//	cout << times2(5) << endl;
//
//	cout << DoMath(times2, 6) << endl;
//
//	vector<function<double(double)>> funcs(2);
//	funcs[0] = MultBy2;
//	funcs[1] = MultBy3;
//
//	cout << funcs[0](10) << endl;
//	cout << funcs[1](20) << endl;
//}



//using vector class member "erase" to update the existing vector to all odd numbers + using a functor
//bool isOdd(const int i) {
//	return i % 2 == 1;
//}
//
//const vector<int>& listV(vector<int>& listofNums, function<bool(const int)> func) {
//	bool flag = false;
//
//	for (auto i = listofNums.begin(); i != listofNums.end();) {
//		if (func(*i))
//			++i;
//		else
//			i = listofNums.erase(i);		
//	}
//	return listofNums;
//}
//
//int main() {
//	vector<int> v = { 1,3,5,6,3,4,5,6,5,7,8};
//	listV(v, isOdd);
//}




//using vectors
//vector<char>& GetHAndTList(vector<char>& v, int idx) {
//	srand(time(0));
//
//	for (int i = 0; i < idx; i++) {
//		int randIndex = rand() % 2;
//		v.push_back(v[randIndex]);
//	}
//	return v;
//}
//
//int GetNumberOfMatches(vector<char> v, char c) {
//	int count = 0;
//	//if (c == 'H') {
//	//	for (auto i = v.begin(); i != v.end(); i++)
//	//		if (*i == c) 
//	//			++count;
//	//}
//	//else {
//	//	for (auto i = v.begin(); i != v.end(); i++)
//	//		if (*i == c) 
//	//			++count;
//	//}
//	for (char val : v)
//		if (val == c)
//			++count;
//	return count;
//}
//
//int main() {
//	vector<char> listC = { 'H', 'T' };
//	vector<char> hAndTList = GetHAndTList(listC, 100);
//
//	cout << GetNumberOfMatches(hAndTList, 'H') << endl;
//	cout << GetNumberOfMatches(hAndTList, 'T') << endl;
//} 



//using iterators and iterator adaptors
//int main() {
//
//	std::vector<int> nums2 = { 1,2,3,4 };
//	std::vector<int>::iterator itr;
//	for (itr = nums2.begin(); itr < nums2.begin(); itr++) 
//		cout << *itr <<endl;
//	
//	vector<int>::iterator itr2 = nums2.begin();
//	advance(itr2, 2);
//	cout << *itr2 << endl;
//
//	auto itr3 = next(itr2, 1);
//	cout << *itr3 << endl;
//
//	auto itr4 = prev(itr3, 1);
//	cout << *itr4 << endl;
//
//	vector<int> nums3 = { 1,4,5,6 };
//	vector<int> nums4 = { 2,3 };
//	auto itr5 = nums3.begin();
//	//advance(itr5, 1);
//	itr5 = next(itr5, 1);
//	copy(nums4.begin(), nums4.end(), inserter(nums3, itr5));
//	for (int& i : nums3)
//		cout << i << ' ';
//}



//smart pointers/unique_ptr
//int main() {
//
//	auto j = make_unique<int>(5);	//constructs j's int data member with initial value of 5, dynamically 
//	cout << *j;
//
//	auto i = make_unique<int[]>(5);	//constructs i where its data member is a dynamically allocated array.
//	for (int k = 0; k < 5; k++) {
//		i[k] = k + 1;
//		cout << i[k] << ' ';
//	}
//	return 0;
//}




//polymorphic templates + vector.emplace_back + nested tamplates
//class Pizza {
//public:
//	virtual void MakePizza() = 0;
//	~Pizza() {}
//};
//
//class NYStyleCrust {
//public:
//	string AddIngredient() {
//		return "Curst so thin you can see through it\n\n";
//	}
//	~NYStyleCrust() {
//		cout << "~NYStyleCrust\n";
//	}
//};
//
//class DeepDishCrust {
//public:
//	string AddIngredient() {
//		return "Super awesome Chicago deep dish\n\n";
//	}
//	~DeepDishCrust() {
//		cout << "~DeepDishCrust\n";
//	}
//};
//
//template <class T>
//class LotsOfMeat : public T {
//public:
//	string AddIngredient() {
//		return "Lots of random meat, " + T::AddIngredient();
//	}
//	~LotsOfMeat() {
//		cout << "~LotsOfMeat\n";
//	}
//};
//
//template <class T>
//class Vegan: public T {
//public:
//	string AddIngredient() {
//		return "Vegan Cheese, Veggies, " + T::AddIngredient();
//	}
//	~Vegan() {
//		cout << "~Vegan()\n";
//	}
//};
//
//template <class T>
//class MeatNYStyle : public T, public Pizza {
//public:
//	void MakePizza() {
//		cout << "Meat NY Style Pizza: " << T::AddIngredient();
//	}
//	~MeatNYStyle() {
//		cout << "~MeatNYStyle()\n";
//	}
//};
//
//template <class T>
//class VeganDeepDish : public T, public Pizza {
//public:
//	void MakePizza() {
//		cout << "Vegan Deep Dish: " << T::AddIngredient();
//	}
//	~VeganDeepDish() {
//		cout << "~VeganDeepDish()\n";
//	}
//};
//
//int main() {
//	vector<unique_ptr<Pizza>> pizzaOrders;
//	pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
//	pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());
//
//	for (auto& pizza : pizzaOrders)
//		pizza->MakePizza();
//	return 0;
//}




//deque and its functions (sequential containers)
//bool isEven(const int& val) {
//	return (val % 2) == 0;
//}
//
//int main() {
//
//	std::deque<int> deq1;
//
//	deq1.assign({ 11,12 });
//	deq1.push_back(5);
//	deq1.push_front(1);
//	cout << "Size: " << deq1.size() << endl;
//	cout << deq1[0] << endl;
//	cout << deq1.at(1) << endl;
//
//	deque<int>::iterator it = deq1.begin() + 1;
//	deq1.insert(it, 3); //insert value 3 at the current position of it which is deq1[1]
//
//	//for (auto& i : deq1)
//	//	cout << i << endl;
//
//	int tempArr[5] = { 6,7,8,9,10 };
//	deq1.insert(deq1.end(), tempArr, tempArr+5);
//	deq1.erase(deq1.end()-1);
//	deq1.erase(deq1.begin(), deq1.begin() + 2);
//	deq1.pop_front();
//	deq1.pop_back();
//	deque<int> deq2(2, 50);
//	deq1.swap(deq2);
//	//deq1.clear();
//
//	for (auto& i : deq1)
//		cout << i << endl;
//	//deq1.assign({ 11,12 });	//assign overwrites the previous values
//}




//lists and it functions (sequential containers)
//bool isEven(const int& val) {
//	return (val % 2) == 0;
//}
//
//int main() {
//
//	int arr[5] = { 1,2,3,4,5 };
//	list<int> list1;
//	list1.insert(list1.begin(), arr, arr + 5);
//	//list1.assign({ 10, 20, 30 });
//	list1.push_back(5);
//	list1.push_front(1);
//	cout << "Size: " << list1.size() << endl;
//
//	//list doesnt have the [] operator overloaded so the workaround for that is to use the iterator to access the elements stored into the list
//	list<int>::iterator itr = list1.begin();
//	advance(itr, 1);
//	cout << "2nd index: " << *itr << endl;
//	itr = list1.begin();
//	list1.insert(itr, 8);
//	list1.erase(list1.begin());
//	itr = list1.begin();
//	list<int>::iterator itr2 = list1.begin();
//	advance(itr2, 2);
//	list1.erase(itr, itr2);
//	list1.pop_front();
//	list1.pop_back();
//	int arr2[] = { 10,9,8,7,6,6 };
//	list<int> list2;
//	list2.insert(list2.begin(), arr2, arr2 + 6);
//	list2.sort();
//	list2.reverse();
//	list2.unique();
//	list2.remove(6);
//	list2.remove_if(isEven);
//	list2.sort();
//	list1.merge(list2); //merge needs the argument sorted in ascending order
//
//	for (auto& i : list1)
//		cout << i << endl;
//
//	cout << "\n";
//
//	for (auto& i : list2)
//		cout << i << endl;
//}



//set container
//int main() {
//	std::set<int> set1{ 5,4,3,2,1,1 }; //removes the last 1 at the very end, since it only stores unique values
//	cout << "Sizeof: " << set1.size() << endl;
//
//	set1.insert(0);
//	set<int>::iterator itr = set1.begin();
//	itr++;
//	cout << "2nd: " << *itr << endl;
//	set1.erase(5);
//	itr = set1.end();
//	advance(itr, -2);
//	set1.erase(itr, set1.end());
//	int arr[] = { 6,7,8,9 };
//	set1.insert(arr, arr + 4);
//	auto val = set1.find(6);
//	cout << "Found: " << *val << endl;
//	auto eight = set1.lower_bound(8);
//	cout << "8: " << *eight << endl;
//	auto nine = set1.upper_bound(9);
//	cout << "9: " << *nine<< endl;
//	set<int> set2{ 10,11 };
//	set1.swap(set2);
//
//	if (!set1.empty()) {
//		for (int i : set1)
//			cout << i << endl;
//	}
//	return 0;
//}


//multiset
//int main() {
//only diff between set and multiset is that multiset is allowed to have non-unique/duplicate values into its elements
//its operations are exaclty similar to the set container
//}



//map container
//int main() {
//	//cannot have duplicate/non-unique keys
//
//	map<int, string> map1;
//	map1.insert(make_pair<int, string>(1, "Bart"));
//	map1.insert(make_pair<int, string>(2, "Lisa"));
//	map1.insert(make_pair<int, string>(3, "Marge"));
//	map1.insert(make_pair<int, string>(4, "Homer"));
//
//	auto match = map1.find(1);
//	cout << match->second << endl;
//
//	auto bart = map1.lower_bound(1);
//	cout << "LB: " << bart->second << endl;
//	auto lisa = map1.upper_bound(1);
//	cout << "UB: " << lisa->second << endl;
//
//	map<int, string>::iterator itr;
//	for (itr = map1.begin(); itr != map1.end(); itr++) {
//		cout << "Key: " << itr->first << endl;
//		cout << "Value: " << itr->second<< endl;
//	}
//}


//multi-map
//int main(){
//can have duplicate keys as long as the values are different
//}


//Stack container (LIFO)
//int main() {
//	stack<string> custs;
//	custs.push("George");
//	custs.push("Louise");
//	custs.push("Florence");
//	int size = custs.size();
//
//	if (!custs.empty()) {
//		for (int i = 0; i < size; i++) {
//			cout << custs.top() << endl;
//			custs.pop();
//		}
//	}
//}


//queue container (FIFO)
//int main() {
//	queue<string> custs;
//	custs.push("Zoidberg");
//	custs.push("Bender");
//	custs.push("Leela");
//	int size = custs.size();
//
//	if (!custs.empty()) {
//		for (int i = 0; i < size; i++) {
//			cout << custs.front() << endl;
//			custs.pop();
//		}
//	}
//}


//priority queue vs queue, "prio qu" orders from greates element to the smallest
//int main() {
//    priority_queue<int> nums;2
//	nums.push(4);
//	nums.push(8);
//	nums.push(5);
//	int size = nums.size();
//
//	if (!nums.empty()) {
//		for (int i = 0; i < size; i++) {
//			cout << nums.top() << endl;
//			nums.pop();
//		}
//	}
//}


//strings manipulation with vector 
//int main() {
//
//	string sSetence = "This is a random stuff";
//	vector<string> vecsWords;
//	stringstream ss(sSetence);
//	string sIndividual;
//	char cSpac = ' ';
//
//	while(getline(ss, sIndividual, cSpac)) {
//		vecsWords.push_back(sIndividual);
//	}
//
//	for (int i = 0; i < vecsWords.size(); i++) {
//		cout << vecsWords[i] << endl;
//	}
//}



//template specialization
//template <class T, class U>
//void add(T a, U b) {
//	cout << "templated\n";
//}
//
//template<>
//void add(int a, char b) {
//	cout << "specialized";
//}
//
//int main() {
//	add(1, 2);
//	add('a', 'b');
//	add(1, 'b');
//}



////template class + template(class) member function
//template <class T>
//class class_a {
//public:
//	void fun(T a) {}
//};
//
////member function template in a non template class
//class class_b {
//public:
//	template<class T>
//	void fun(T a) {}
//};
//
////template class + member funciton template (with different type than template class' decl type) 
//template <class T>
//class class_c {
//public:
//	template<class U>
//	void fun(T a, Ub) {}
//};



//partial/explicit template specialization
//template <typename T, typename U>
//struct example_class { //base template as a reference for specialized templates 
//	example_class() {
//		std::cout << "example_class <T, U>\n";
//	}
//};
//
//template <typename T>   	//specialize so that both are same datatype
//struct example_class <T, T> {
//	example_class() {
//		std::cout << "example_class<T, T>\n";
//	}
//};
//
//template <typename T>   	//specialize so that both are same datatype
//struct example_class <T*, T*> {
//	example_class() {
//		std::cout << "example_class<T*, T*>\n";
//	}
//};
//
//template <typename T>   	//specialize so that second datatype is int
//struct example_class <T, int> {
//	example_class() {
//		std::cout << "example_class<T, int>\n";
//	}
//};
//
//template <typename T, typename U>   // both are now pointers
//struct example_class <T*, U*> {
//	example_class() {
//		std::cout << "example_class<T*, U*>\n";
//	}
//};
//
//template <>
//struct example_class <int, int> {
//  example_class () { std::cout << "example_class<int, int>\n"; }
//};
//
//int main() {
//	example_class<int, double> a;     // prints "example_class<T, U>"
//	example_class<double, double> b;  // prints "example_class<T, T>"
//	example_class<double, int> c;     // prints "example_class<T, int>"
//	example_class<int*, double*> d; // prints "example_class<T*, U*>"
//	example_class<int, int> e;
//	example_class<int*, int*> f; 
//
//	return 0;
//}



//function template with default template type are not allowed since the default would always be overridden by the deduced value.
//struct myclass {
//	int a;
//	myclass(int b) : a{ b } {}
//	friend ostream& operator<<(ostream& os, const myclass& other) {
//		return os << ' ';
//	}
//};
//
//template <class T = int>
//ostream& fun(T a) {
//	cout << a << endl;
//	return cout << typeid(T).name() << endl;
//}
//
//int main() {
//	myclass a(2);
//	fun("Soham");
//	fun<int>(1);
//	fun<myclass>(a);
//}


//template template paramater, class templates & creating a std container as a data member of a class 
//example of how to define, declare and use a container that is a container to the stl containers
//VERY IMPORTANT
//template <typename T,
//	template <typename T> class container = deque>
//class stackk {
//public:
//	void push(const T& t) {
//		s.push_back(t);
//	}
//	void pop() {
//		s.pop_back();
//	}
//	T top() {
//		return s.back();
//	}
//	// ...
//	ostream& name()
//	{
//		return cout << typeid(s).name() << endl;
//	}
//
//private:
//	container<T> s;
//};
//
//int main() {
//	stackk<string> a_deque_stack_of_strings; // defaults to deque
//	stackk<int, list> a_list_stack_of_ints;
//
//	a_deque_stack_of_strings.name();
//	a_list_stack_of_ints.name();
//
//
//	a_deque_stack_of_strings.push("hello");
//	string s = a_deque_stack_of_strings.top();
//	cout << s << endl;
//	a_deque_stack_of_strings.pop();
//
//	a_list_stack_of_ints.push(42);
//	int i = a_list_stack_of_ints.top();
//	cout << i << endl;
//	a_list_stack_of_ints.pop();
//
//	return 0;
//}
//
//
//template <class T, template <typename T>
//class Container = deque>
//void fun() {
//	//here container is defaulted to deque and container is another name of deque or any other stl container when passed a stl container like vector or a list or any other stl container. The "template <typename T>" before declaring Container is the type of deque and thus Container must also be initialized in a similar manner or else it will report an error saying types dont match...
//}




//variadic templates
//template <class T>
//T adder(T first) {
//	cout << __FUNCSIG__ << endl;
//	return first;
//}
//
//template <class T, class... Args>
//T adder(T first, Args... args) {
//	cout << __FUNCSIG__ << endl;
//	return first + adder(args...);
//}
//
//int main() {
//	long sum = adder(1, 2, 3, 8, 7);
//	cout << "sum= " << sum << endl;
//
//	string s1 = "C++", s2 = " ", s3 = "is", s4 = "cool!";
//	string strSum = adder(s1, s2, s3, s4);
//
//	cout << "strSum= " << strSum << endl;
//}



//using variadic templates with different containers, std::map print_iterator/print_container implementation 
//VERY IMPORTANT
//template <class T, class U>
//ostream& operator<<(ostream& os,const pair<T, U>& p) {
//	return os << p.first << ", " << p.second;
//}
//
//template <class input_iterator>
//void print_iterator(ostream& os, input_iterator start, input_iterator end) {
//	//cout << __FUNCSIG__ << endl;
//
//	cout << typeid(start).name() << endl << endl << typeid(end).name() << endl;
//
//	while (start != end)
//		os << *start++ << ' ';  
//	os << endl;
//} 
//
////the call to this function comes to this function because this function template is more specific since creating another object of Map needs exactly 4 arguments. Here objs is an object that is a reference to mm defined in main()
//template<template <class, class, class, class> class container, class valueType, class Args, class T, class M>
//void print_container(ostream& os, const container<valueType, Args, T, M>& objs) {
//
//	//here valueType is the value that the containers hold... for example float for vector, etc..
////Args's type is the second argument that the container like vectors need for example allocator class for vector...
////Args must either be variadic or you must define 4 different template aruments for this function in order for the compiler to deduce the type of std::map, namely type Key, type T, type Compare & type Allocator as defined in the STL.
//	cout << __FUNCSIG__ << endl << endl;
//	cout << typeid(container).name() << endl << endl;
//	cout << typeid(valueType).name() << endl << endl; 
//	cout << typeid(Args).name() << endl << endl;
//	cout << typeid(T).name() << endl << endl;
//	cout << typeid(M).name() << endl << endl;
//	cout << typeid(objs).name() << endl << endl;
//
//	for (auto const& obj : objs) {
//		cout << obj << ' ';
//	}
//	cout << endl;
//}
//
//
////either use variadic templates for Map or use a function that explicitly defines a template that accepts 4 different types as it template argument
//template<template <class, class...> class container, class valueType, class... Args>
//void print_container(ostream& os, const container<valueType, Args...>& objs) {
//
//	//here valueType is the value that the containers hold... for example float for vector, etc..
//	//Args's type is the second argument that the container like vectors need for example allocator class for vector...
//	//Args must either be variadic or you must define 4 different template aruments for this function in order for the compiler to deduce the type of std::map, namely type Key, type T, type Compare & type Allocator as defined in the STL.
//
//	cout << __FUNCSIG__ << endl << endl;
//	cout << typeid(container).name() << endl << endl;
//	cout << typeid(valueType).name() << endl << endl;
//	//cout << typeid(Args).name() << endl;
//	cout << typeid(objs).name() << endl << endl;
//
//	for (auto const& obj : objs) {
//		cout << obj << ' ';
//	}
//	cout << endl;
//}
//
//void main() {
//	vector<float> vf{ 1.1,2.2,3.3,4.4 };
//	print_iterator(cout, vf.begin(), vf.end());
//	print_container(cout, vf);
//
//	list<char> lc{ 'a', 'b', 'c', 'd' };
//	print_iterator(cout, lc.begin(), lc.end());
//	print_container(cout, lc);
//
//	deque<int> di{ 1,2,3,4 };
//	print_iterator(cout, di.begin(), di.end());
//	print_container(cout, di);
//
//	map<string, int, std::greater<string>> mm{ { "larry", 100 }, { "curly", 90}, { "moe", 110 } };
//	print_iterator(cout, mm.begin(), mm.end());
//	print_container(cout, mm);
//}



//2D vectors, a vector within a vector....
//int main(){
//	vector<vector<int>> vec2D;
//	vector<int> oneVec, twoVec;
//
//	oneVec.push_back(1); oneVec.push_back(2); oneVec.push_back(3);
//	twoVec.push_back(4); twoVec.push_back(5); twoVec.push_back(6);
//
//	vec2D.push_back(oneVec);
//	vec2D.push_back(twoVec);
//
//	for (vector<vector<int>>::iterator itr = vec2D.begin(); itr != vec2D.end(); itr++) {
//		for (vector<int>::iterator itrIn = itr->begin(); itrIn != itr->end(); itrIn++) {
//			cout << *itrIn << ' ';
//		}
//	}
//	cout << endl;
//
//	for (int i = 0; i < vec2D.size(); i++) {
//		for (int j = 0; j < vec2D[i].size(); j++) {
//			cout << vec2D[i][j] << ' ';
//		}
//	}
//
//	cout << endl;
//
//	for (const auto& i : vec2D) {
//		for (const auto& j : i) {
//			cout << j << ' ';
//		}
//	}
//}




//list by-default iterator type is bi-directional iterator who doesnt have + or - overloaded operators
// only random access iterators support those operations
//int main() {
//	list<int> l;
//
//	l.push_back(1);
//	l.push_front(0);
//
//	l.insert(l.begin() + 2, 3);
//
//	vector<int> v = { 1,2 };
//	v.insert(v.begin() + 2, 2);
//}



//int argc and argv
//int main(int argc, char* argv[]) {
//	vector<string> str;
//
//	for (int i = 0; i < argc; i++)
//		str.emplace_back(string (argv[i]));
//
//	/*for (const auto& i : str)
//		cout << i;*/
//
//	for (vector<string>::const_iterator itr = str.cbegin(); itr != str.cend(); itr++)
//		cout << *itr;
//}




//multiple ways to access a vector of unique_ptr of a class
//class Arr {
//public:
//	void getArr() {
//		cout << "getArr()";
//	}
//};
//
//int main() {
//	vector<unique_ptr<Arr>> v;
//	v.emplace_back(make_unique<Arr>());
//	v.push_back(make_unique<Arr>()); //push_back also works fine but for any custom type of a vector, emplace back is the most efficient of the two...
// 
//	//fix this... try to init a vector with the use of {} or ()
//	vector<unique_ptr<Arr>> v (1, make_unique<Arr>());	  //ERROR!! copy constructor deleted
//	vector<unique_ptr<Arr>> v = make_unique<Arr>();	  //ERROR!! trying to copy assign a unique_ptr type to a vector type... not possible... can only do a vector to a vector
//	vector<unique_ptr<Arr>> v = { make_unique<Arr>() }; //ERROR copy construtor deleted
//	vector<unique_ptr<Arr>> v { make_unique<Arr>() };   //ERROR copy construtor deleted
// 	vector<unique_ptr<Arr>> v = { unique_ptr<Arr>(new Arr()) };	//ERROR!!
//	
//	v.front()->getArr();
//	v[0]->getArr();
//	v.begin()->get()->getArr();
//	(*v.begin()).operator*().getArr(); //same
//	(*(*v.begin())).getArr(); //same
//	(*v.begin())->getArr();
//
//	unique_ptr<int> i = make_unique<int>();
//
//	cout << *i << endl;
//	cout << *(i.operator->()) << endl;
//
//	unique_ptr<Arr> arr = make_unique<Arr>();
//
//	(*arr).getArr();
//	arr.operator->()->getArr();
//	arr->getArr();
//}


//int main() {
//	vector<int> v;
//
//	copy(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, "->"));
//
//}
//create your own class... have a data member that is an object to std::iterator class and finally test the range based for loops onto that.....




//throwing exception without leaking any memory(cleans up by itself) in the copy ctor or copy = operator, if something goes wrong while copy the contents from rhs to lhs
//struct throw_exception {
//	throw_exception& operator=(const throw_exception& other) {
//		if (++i_ == 10)
//			throw std::out_of_range("index out of range");
//	}
//	static int i_;
//};
//
//int throw_exception::i_ = 0;
//
//template <typename T>
//class Array {
//public:
//    explicit Array(int size)
//        : size_(size),
//        array_(new T[size]) {
//    }
//
//    ~Array() = default;
//
//    Array(const Array<T>& rhs)
//        : size_(rhs.size_),
//        array_(new T[rhs.size_]) {
//            for (int i = 0;
//                i < rhs.size_;
//                ++i)
//                // If T.operator=() throws exception, we've got problems singe
//                // the destructor is not called and array_ will leak memory!
//                array_[i] = rhs.array_[i];
//    }
//
//    Array<T>& operator= (const Array<T>& rhs) {
//        if (this != &rhs) { // Check for self-assignment.
//            T* temp = new T[rhs.size_];
//            for (int i = 0;
//                i < rhs.size_;
//                ++i)
//                // If T.operator=() throws exception, we've got problems singe
//                // the destructor is not called and temp will leak memory!
//                temp[i] = rhs.array_[i];
//
//            delete[] array_;
//            array_ = temp;
//        }
//
//        return *this;
//    }
//
//private:
//    int size_;
//    unique_ptr<T[]> array_;
//};
//
//int main() {
//    try {
//        Array<throw_exception> a1(1000);
//        Array<throw_exception> a2(10);
//        Array<throw_exception> a3(a1); // Copy constructor.
//
//        a2 = a1; // Assignment operator.
//        a1 = a2;
//    }
//    catch (std::out_of_range& range_error) {
//        cout << "caught range error" << endl;
//    }
//    return 0;
//}



//using custom comparator for set's 2nd argument, class Compare
//#include <set>
//#include <functional>
//class Arr {
//	int m_i;
//	static int m_count;
//public:
//	Arr(int i = 0) : m_i{ i } {
//		++m_count;
//	}
//	friend ostream& operator<<(ostream& os, const Arr& a);
//	int getter() const;
//	bool operator>(const Arr& b) const{
//		return m_i > b.m_i;
//	}
//	bool operator()(const Arr& lhs, const Arr& rhs) const{
//		return lhs.m_i > rhs.m_i;
//	}
//};
//
//int Arr::m_count = 0;
//
//int Arr::getter() const {
//	return m_i;
//}
//
//ostream& operator<<(ostream& os, const Arr& a){
//	 return os << a.m_i;
//}
//
//bool grth(const Arr& lhs, const Arr& rhs) {
//		return lhs.getter() > rhs.getter();
//}
//
//template <typename T>
//struct grthh {
//	bool operator()(const T& lhs, const T& rhs) const{
//		return lhs.getter() > rhs.getter();
//	}
//};

//int main() {

	//initializing class Compare of set with function pointer

	//ctor 1
	//vector<int> v{1, 2, 3, 4, 5};
	//set<Arr, bool(*)(const Arr& lhs, const Arr& rhs)> s(v.begin(), v.end(), grth);

	//ctor 2
	//set<Arr, bool(*)(const Arr& lhs, const Arr& rhs)> s({1,2,3,4,5}, grth);

	//ctor 3 but set is empty rn, you only initialized the class Compare with a functor
	//set<Arr, bool(*)(const Arr& lhs, const Arr& rhs)> s(grth);

	//std::set filters out any duplicate keys... use multiset instead to have duplicate keys...

	//initializing comparator using a lambda function/unnamed functor/function object
	//set < Arr, decltype([](const auto& a, const auto& b) {return a.getter() > b.getter(); } )> s{ 5,2,1,4,8 };

	//set<Arr, grthh<Arr>> s{ 5,2,1,4,8 }; //for grthh struct functor

	//set<Arr, greater<Arr>> s{ 5,2,1,4,8,1 }; //built-in algorithm lib functor, in order to use built-in functor, you must implement '>' operator overload as the class definition

	//set<Arr, Arr> s{ 5,2,1,4,8,1 }; //using the class as an underlying data structure + defining a functor as a class member

	//for (const auto& i : s)
		//cout << i;

	/*for (auto itr = s.begin(); itr != s.end(); itr++)
		cout << *itr;*/
		//}




		//std::set
		//int main() {
		//	// Implicitly use less<int>.
		//	set<int> myset;
		//
		//	for (int i = 1; i <= 5; i++)
		//		myset.insert(i * 10);    // set: 10 20 30 40 50
		//
		//	  // auto is pair<set<int>::iterator,bool>.
		//	//auto ret = myset.insert(25);
		//	auto ret = myset.insert(20);
		//	//insert returns pair, if insert was successful in inserting the value, it sets the ret.second to true or else sets the ret.second to false and the ret.first would point to the element that we were trying to insert...
		//
		//	// No new element inserted.
		//	if (!ret.second) {
		//		// auto is set<int>::iterator
		//		auto it = ret.first;  // "it" now points to element 20
		//
		//		myset.insert(it, 25); // max efficiency inserting
		//		myset.insert(it, 24); // max efficiency inserting
		//		myset.insert(it, 26); // no max efficiency inserting
		//
		//		// 10 is already in set, not inserted.
		//		myset.insert({ 5, 10, 15 });
		//
		//		cout << "myset contains:" << endl;
		//		copy(myset.begin(),
		//			myset.end(),
		//			ostream_iterator<int>(cout, " "));
		//
		//		cout << endl;
		//	}
		//	return 0;
		//}




		//std::map + functor/lambda
		//int main() {
		//    std::vector<std::string> word_list{ "now", "is", "the", "time",
		//                                        "for", "all", "good", "people",
		//                                        "to", "come", "to", "the",
		//                                        "aid", "of", "their", "party" };
		//
		//    typedef std::map<std::string, int> WORD_MAP;
		//    WORD_MAP word_map; // Map of words and their frequencies.
		//
		//    // Use range-based for loop to count the number of times each word
		//    // appears in the word_list.
		//   for (auto const& word : word_list)
		//        ++word_map[word];
		// 
		//     //Use an explicit iterator to count the number of times each word
		//     //appears in the word_list.
		//   /*for (std::vector<std::string>::const_iterator word_iter = word_list.cbegin();
		//        word_iter != word_list.cend();
		//        ++word_iter)
		//        ++word_map[*word_iter];*/
		//
		//     //Use an auto iterator to count the number of times each word
		//     //appears in the word_list.
		//  //for (vector<string>::iterator word_iter = word_list.begin();
		//  //      word_iter != word_list.end();
		//  //      ++word_iter)
		//  //      ++word_map[*word_iter];
		//
		//    // Print out the word_map.
		//    for (auto const& i : word_map)
		//        std::cout << i.second << " " << i.first << std::endl;
		//
		//    // Create a functor.
		//    class total_it {
		//    public:
		//        explicit total_it(int i) : i_(i) {}
		//
		//        void operator()(const WORD_MAP::value_type& p) {
		//            i_ += p.second;
		//        }
		//
		//        int count() const {
		//            return i_;
		//        }
		//    private:
		//        int i_;
		//    };
		//
		//    auto total = 0;
		//
		//    // Count the total number of words in the map.
		//    total_it it = for_each(word_map.begin(),
		//        word_map.end(),
		//        // Use a functor.
		//        total_it(total));
		//    total = it.count();
		//
		//    std::cout << "total number of words = " << total << std::endl;
		//
		//    total = 0;
		//
		//    // Count the total number of words in the map. 
		//    for_each(word_map.begin(),
		//        word_map.end(),
		//        // Use a lambda function.
		//        [&total] (const WORD_MAP::value_type& p) {
		//            total += p.second;
		//        });
		//
		//    std::cout << "total number of words = " << total << std::endl;
		//
		//    return 0;
		//}




		//std::map iterators
		//int main() {
		//    map<string, int> word = { {"Is", 1}, {"You", 2}, {"Two", 3} };
		//
		//    //when you dereference a map iterator, it will return a std::pair<T,U> class object
		//    map<string, int>::const_iterator wr = word.begin();
		//    pair<string, int> /*auto*/ /*map<string, int>::value_type*/ w = *wr;
		//
		//    //declaring a map::<Key, T>::value_type will declare an object of type "pair<Key, T>"  
		//}




		//a hash table of std::list initialized with a std::pair of int and string
		//#include <iostream>
		//#include <list>
		//#include <cstring>
		//
		//class HashTable {
		//private:
		//	static const int hashGroups = 10;
		//	list<pair<int, string>> table[hashGroups]; //List 1...Index 0, List 2...Index 1
		//public:
		//	bool isEmpty() const;
		//	int hashFunction(int key);
		//	void insertItem(int key, string value);
		//	void removeItem(int key);
		//	const string& searchTable(int key);
		//	void printTable();
		//};
		//
		//bool HashTable::isEmpty() const{
		//	int sum{};
		//	for (int i = 0; i < hashGroups; i++)
		//		sum += table[i].size();
		//	if (!sum)
		//		return true;
		//	return false; 
		//
		//	table[0].front().first;
		//}
		//
		//int HashTable::hashFunction(int key) {
		//	return key % hashGroups; //Key: 905, in return this function, will spit out 5
		//}
		//
		//const string& HashTable::searchTable(int key) {
		//	int hashValue = hashFunction(key);
		//	auto& cell = table[hashValue];
		//	auto bItr = begin(cell);
		//
		//	if (bItr != end(cell))
		//		return bItr->second;
		//	else
		//		return "[WARNING] Key not found\n";
		//}
		//
		////insertItem makes sure that no duplicate key exists in the table, if it does, 
		////then the existing key's "value" is updated to the latest "value"
		//void HashTable::insertItem(int key, string value) { 
		//	int hashValue = hashFunction(key);
		//	list<pair<int, string>>& cell = table[hashValue];
		//	auto bItr = begin(cell);
		//	bool keyExists = false;
		//	//cout << cell.front().first << " " << cell.front().second;
		//
		//	for (; bItr != end(cell); bItr++) {
		//		if (bItr->first == key) {
		//			keyExists = true;
		//			bItr->second = value;
		//			cout << "[WARNING] Key exists. Value replaced." << endl;
		//			break;
		//		}
		//	}
		//
		//	if (!keyExists)
		//		cell.emplace_back(key, value);
		//
		//	return;
		//}
		//
		//void HashTable::removeItem(int key) {
		//	
		//	int hashValue = hashFunction(key);
		//	auto& cell = table[hashValue];
		//	auto bItr = begin(cell);
		//	bool keyExists = false;
		//
		//	for (; bItr != end(cell); bItr++) {
		//		if (bItr->first == key) {
		//			keyExists = true;
		//			bItr = cell.erase(bItr);
		//			cout << "[INFO] Item removed."<< endl;
		//			break;
		//		}
		//	}
		//
		//	if (!keyExists)
		//		cout << "[WARNING] Key not found. Pair not removed" << endl;
		//
		//	return;
		//}
		//
		//void HashTable::printTable() {
		//	for (int i = 0; i < hashGroups; i++) {
		//		if (table[i].size() == 0) continue;
		//		
		//		auto bItr = table[i].begin();
		//		for (; bItr != table[i].end(); bItr++)
		//			cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
		//	}
		//	return;
		//}
		//
		//int main() {
		//	HashTable HT;
		//
		//	if (HT.isEmpty())
		//		cout << "Correct answer. Good job\n";
		//	else
		//		cout << "Uh Uh. We need to check our code\n";
		//
		//	HT.insertItem(905, "Jim");
		//	HT.insertItem(201, "Tom");
		//	HT.insertItem(332, "Bob");
		//	HT.insertItem(124, "Sally");
		//	HT.insertItem(107, "Sandy");
		//	HT.insertItem(929, "Barb");
		//	HT.insertItem(928, "Rob");
		//	HT.insertItem(928, "Rick");
		//
		//	HT.printTable();
		//
		//	HT.removeItem(332);
		//	HT.removeItem(100);
		//
		//	if (HT.isEmpty())
		//		cout << "Uh Uh. We need to check our code\n";
		//	else
		//		cout << "Correct answer. Good job\n";
		//
		//	cout << "Key: " << 929 << " Value: " << HT.searchTable(929) << endl;
		//	cout << "Key: " << 100 << " Value: " << HT.searchTable(100) << endl;
		//
		//	return 0;
		//}



		//using algorithm lib to copy/reverse copy a deque
		//#include <deque>
		//int main() {
		//	deque<int> aDeck{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		//
		//	//you must allocate enough memory to the deque's object 
		//	//either through ctor, like giving a range or manually 
		//	//initalizing the object of deque or else, using the resize 
		//	//method on that object
		//	
		//	//deque<int> r(aDeck.begin(), aDeck.end());
		//	//deque<int> r{1,2,3,4,5,6,7,8,9,10,11,12};
		//	deque<int> r;
		//	//r.resize(aDeck.size());
		//
		//	//reverse_copy(aDeck.begin(),
		//	//	aDeck.end(),
		//	//	r.begin());
		//	reverse_copy(aDeck.begin(),
		//		aDeck.end(),
		//		back_inserter(r));
		//
		//	copy(r.begin(), r.end(), ostream_iterator<int>(cout, "\n"));
		//
		//	return 0;
		//}




		//function pointers as members of a class defined outside
		//the class and accessing the underlying functions that they point to
		//class example_class {
		//int i_;
		//public:
		//	explicit example_class(int i = 0) : i_(i) {}
		//	float aFun(float a, char b, char c) {
		//		return i_ += a + b + c;
		//	}
		//	float bFun(float a, char b, char c) {
		//		return i_ += a - b + c;
		//	}
		//	float anotherFun(float a, char b, char c) const {
		//		return i_ + a - b + c;
		//	}
		//	static float aStaticFun(float a, char b, char c) {
		//		return a + b + c;
		//	}
		//};
		//
		//int main(int argc, char* argv[]) {
		//	
		//	float(*pt2Function)(float, char, char) = nullptr;
		//
		//	//declaring the next 2 functions are a 
		//	//member function pointers to example_class
		//	float(example_class:: *pt2Member)(float, char, char) = nullptr;
		//	float(example_class:: *pt2ConstMember)(float, char, char) const = nullptr;
		//	
		//	pt2ConstMember = /*&*/example_class::anotherFun;
		//
		//	if (argc > 1)
		//		pt2Member = /*&*/example_class::aFun;
		//	else
		//		pt2Member = /*&*/example_class::bFun;
		//
		//	pt2Function = /*&*/example_class::aStaticFun;
		//
		//	example_class obj(10);
		//
		//	//since pt2Member and pt2ConstMember were declared above
		//	//as a member function pointer they must be accessed/called
		//	//from an object of example_class, and then dereferencing them
		//	//to obtain underlying function that it points to...
		//	 
		//	//the paranthesis "(obj.*pt2Member)"(args...) are needed so 
		//	//that the member selection and 
		//	//dereferencing are done properly to make a call to the 
		//	//actual function and pass the correct parameters
		//	cout << (obj.*pt2Member)(12.5, 'a', 'b');
		//	cout << (obj.*pt2ConstMember)(24.5, 'c', 'd');
		//	cout << pt2Function(13.2,'e','f');
		//
		//	unique_ptr<example_class> obj2(make_unique<example_class>());
		//	//unique_ptr<example_class> obj2(new example_class());
		//
		//	cout << (obj2.get()->*pt2Member)(12.5, 'a', 'b');
		//	cout << (obj2.get()->*pt2ConstMember)(24.5, 'c', 'd');
		//}




		//passing function pointer as an argument to a function and
		//returning a function pointer from a function
		//float Plus(float a, float b) {
		//	return a + b;
		//}
		//float Minus(float a, float b) {
		//	return a - b;
		//}
		//
		//void pass_ptr(float (*pt)(float, char, char)) {
		//	float abc = (*pt)(12.5, 'a', 'b');
		//	cout << abc << endl;
		//}
		//
		//float func(float a, char b, char c) {
		//	return a + b + c;
		//}

		////1st way to do is to type define the return type and give an identifier to the function
		//typedef float(*pt2Func)(float, float);
		//pt2Func pt(char code) { 
		//	if (code == '+') {
		//		return Plus;
		//	}
		//	else if (code == '-') {
		//		return Minus;
		//	}
		//}

		////2nd way is to explicitly provide the return type (viz a funcion pointer) 
		////along with giving the function a name and its parameters "getFunc(char code)", 
		////so that we can call this function in main...
		//float(*getFunc(char code))(float, float) {
		//	if (code == '+') {
		//		return Plus;
		//	}
		//	else if (code == '-'){
		//		return Minus;
		//	}
		//}
		//
		//int main() {
		//	/*pass_ptr(func);*/
		//
		//	float(*pt2Fun)(float, float);
		//
		//	//pt2Fun = pt('+');
		//	pt2Fun = getFunc('+');
		//	cout << pt2Fun(2.5, 2.3) << endl;
		//
		//	//pt2Fun = pt('-');
		//	pt2Fun = getFunc('+');
		//	cout << pt2Fun(3.4, 3.6) << endl;
		//
		//	//getFunc('+') returns an address to Plus function 
		//	//and then the Plus function is called 
		//	//and the 2 args (2.5, 2,3 )are passed into it...
		//	float num = getFunc('+')(2.5, 2.3);
		//	cout << num << endl;
		//}



		//using STL function adapters -> bind() to adapt to the 
		//functor passed into it as its first argument followed by N number of arguments
		//#include <functional>
		//int main() {
		//	auto itr = bind(multiplies<int>(), placeholders::_1, 10);
		//	cout << itr(10);
		//}




		//non-mutating algorithms
		//#include <algorithm>
		//#include <iostream>
		//#include <deque>
		//#include <functional>
		//#include <memory>
		//#include <span>
		//
		//template <class T>
		//class is_greater_than {
		//	const T& val;
		//public:
		//	is_greater_than(const T& n) : val(n) {}
		//
		//	bool operator() (const T& element) const {
		//		return element > val;
		//	}
		//
		//};
		//
		//static void find_with_deque();
		//static void find_with_array();
		//
		//int main() {
		//	//find_with_deque();
		//	find_with_array();
		//	return 0;
		//}

		//static void find_with_deque() {
		//	deque<int> values{ 10, 20, -30, 40, -50, 60, 20, -40 };
		//	auto value = 20;
		//	
		//	// Use custom functor to find first value > 20.
		//	auto itr = find_if(values.begin(), values.end(), bind(greater<int>(), placeholders::_1, value));
		//	//auto itr = find_if(values.begin(), values.end(), is_greater_than(value));
		//	//auto itr = find_if(values.begin(), values.end(), [=](const int& val) {return val > value; });
		//	
		//	if (itr != values.end())
		//	cout << "First value >20 is: " << *itr << endl;
		//	
		//	value = 40;
		//	
		//	// Use C++ lambda function to first value that's *not* >= 40.
		//	//itr = find_if(values.begin(), values.end(), [=](const int& val) {return !(val >= value); });
		//	itr = find_if_not(values.begin(), values.end(), [=](const int& val) {return val >= value; });
		//	
		//	if (itr != values.end())
		//	cout << "First value !>=40 is: " << *itr << endl;
		//	
		//	value = 20;
		//	// Use bind() and greater<> functor to find last value > 20.
		//	auto itrr = find_if(values.rbegin(), values.rend(), bind(greater<int>(), placeholders::_1, value));
		//	
		//	if (itrr != values.rend())
		//	cout << "Last value >20 is: " << *itrr << endl;
		//}

		//static void find_with_array() {
			//const int size = 8;
			//unique_ptr<int[]> v1{ new int[size] {10, 20, -30, 40, -50, 60, 20, -40} };
			//unique_ptr<int[]> v2/*{ new int[size] {} }*/ = make_unique<int[]>(size);

			//span s(v1.get(), v1.get() + size);

			//copy(s.begin(), s.end(), v2.get());
			////copy(v2.get(), v2.get() + size, ostream_iterator<int>(cout, " "));

			//auto value = 20;

			//// Use custom functor to find first value > 20.
			//auto itr1 = find_if(v1.get(), v1.get() + size, is_greater_than(value));

			//if(itr1 != v1.get() + size)
			//	cout << "First value >20 is: " << *itr1 << endl;

			//vector<int> v{ 10, 20, -30, 40, 10, -40, 60, -10 };

			//auto itr = count_if(v.begin(), v.end(), [](auto i) {return abs(i) == 10; });

			//cout << "Total number of occurences of value 10 in v are: " << itr;
		//}





		// making sure the distance of 2 containers are the same, 
		// if the distance are same, then check if they have equal(exact value at every index) elements,
		// if not then find the mismatches 
		// of individual elements in both the containers
		//#include <iostream>
		//#include <algorithm>
		//#include <functional>
		//#include <vector>
		//#include <deque>
		//
		//using namespace std;
		//
		//template <class init1, class init2>
		//static void find_mismatches(init1 begin1, init1 last1, init2 begin2, init2 last2);
		//
		//int main() {
		//
		//	vector<int> v1{ 10, 20, 30, 40, 50 };
		//	deque<int> d1(v1.begin(), v1.end());
		//
		//	find_mismatches(v1.begin(), v1.end(), d1.begin(), d1.end());
		//
		//	int a[] = { 10, 40, 60, 80, 50 };
		//	
		//	//a_end is a number past the end of array a
		//	int* a_end = a + sizeof(a) / sizeof(*a);
		//
		//	find_mismatches(v1.begin(), v1.end(), begin(a), end(a));
		//	return 0;
		//}
		//
		//template <class init1, class init2>
		//static void find_mismatches(init1 begin1, init1 last1, init2 begin2, init2 last2) {
		//	std::cout << __FUNCTION__ << "()\n";
		//
		//	if (distance(begin1, last1) == distance(begin2, last2)) {
		//		if (equal(begin1, last1, begin2)) {
		//			cout << "ranges are equal\n";
		//		}
		//		else {
		//			auto t1 = begin1;
		//			auto t2 = begin2;
		//
		//			while (t1 != last1) {
		//				auto p = mismatch(t1, last1, t2);
		//
		//				if (p.first != last1) {
		//					cout << "mismatching elements: " << *p.first << " and " << *p.second << endl;
		//					t1 = ++p.first;
		//					t2 = ++p.second;
		//				}
		//				else {
		//					t1 = last1;
		//				}
		//			}
		//		}
		//	}
		//}




		//multithreading
		//#include <thread>
		//#include <chrono>
		//
		//void chef_olivia() {
		//	printf("Olivia started & waiting for sausage to thaw...\n");
		//	std::this_thread::sleep_for(std::chrono::seconds(3));
		//	printf("Olivia is done cutting sausage.\n");
		//}
		//
		//int main() {
		//	printf("Barron requests Olivia's help.\n");
		//	std::thread olivia(chef_olivia);
		//	printf("  Olivia is active? %s\n", olivia.joinable() ? "true" : "false");
		//
		//	printf("Barron continues cooking soup.\n");
		//	std::this_thread::sleep_for(std::chrono::seconds(1));
		//	printf("  Olivia is active? %s\n", olivia.joinable() ? "true" : "false");
		//
		//	printf("Barron patiently waits for Olivia to finish and join...\n");
		//	olivia.join(); //join blocks current thread(main() thread) and waits until the local olivia thread is done exectuing. Once a thread is done executing its function, it will destroy/de-activate the thread and thus not able to join or not active anymore...
		//	printf("  Olivia is active? %s\n", olivia.joinable() ? "true" : "false");
		//	
		//	printf("Barron and Olivia are both done!\n");
		//}



		//multithreading
		//#include <thread>
		//#include <chrono>
		//
		//void kitchen_cleaner() {
		//	while (true) {
		//		printf("Olivia cleaned the kitchen.\n");
		//		std::this_thread::sleep_for(std::chrono::seconds(1));
		//	}
		//}
		//
		//int main() {
		//	std::thread olivia(kitchen_cleaner);
		//	olivia.detach();
		//	for (int i = 0; i < 3; i++) {
		//		printf("Barron is cooking...\n");
		//		std::this_thread::sleep_for(std::chrono::seconds(9));
		//	}
		//	printf("Barron is done!\n");
		//	//olivia.join();
		//}



		//multithreading
		//#include <future>
		//#include <cstdio>
		//
		//unsigned long long recursive_sum(unsigned int lo, unsigned int hi) {
		//	if (hi - lo <= 100 ) { // base case threshold
		//		unsigned long long sum = 0;
		//		for (auto i = lo; i < hi; i++) {
		//			sum += i;
		//		}
		//		return sum;
		//	}
		//	else { // divide and conquer
		//		auto mid = (hi + lo) / 2; // middle index for splitting
		//		auto left = recursive_sum(lo, mid);
		//		auto right = recursive_sum(mid, hi);
		//		return left + right;
		//	}
		//}
		//
		//int main() {
		//	unsigned long long total = recursive_sum(0, 1000000000/2);
		//	std::future<unsigned long long> total_future = std::async(recursive_sum, ((1000000000 / 2)+1), 1000000000);
		//	printf("Total: %lld\n", total + total_future.get());
		//}


		//multithreading
		//#include <cstdlib>
		//#include <iostream>
		//#include <string>
		//#include <vector>
		//#include <ctime>
		//#include <numeric>
		//#include <cmath>
		//#include <sstream>
		//#include <thread>
		//#include <chrono>
		//#include <ctime>
		//#include <mutex>
		//
		////int GetRandom(int max) {
		////	srand(time(NULL));
		////	return rand() % max;
		////}
		//std::mutex vectLock;
		//std::vector<size_t> primeVect;
		//
		//void findPrimes(size_t start, size_t end) {
		//	for (size_t x = start; x < end; x += 2) {
		//		for (size_t y = 2; y < x; y++) {
		//			if ((x % y) == 0)
		//				break;
		//			else if ((y + 1) == x) {
		//				vectLock.lock();
		//				primeVect.push_back(x);
		//				vectLock.unlock();
		//			}
		//		}
		//	}
		//}
		//
		//void findPrimesWithThreads(size_t start, size_t end, size_t numThreads) {
		//	std::vector<std::thread> threadVect;
		//	size_t threadSpread = end / numThreads;
		//	size_t newEnd = start + threadSpread - 1;
		//	for (size_t i = 0; i < numThreads; i++) {
		//		threadVect.emplace_back(findPrimes, start, newEnd);
		//		start += threadSpread;
		//		newEnd += threadSpread;
		//	}
		//	for (auto& t : threadVect) {
		//		t.join();
		//	}
		//}
		//
		////std::string getTime() {
		////	auto nowTime = std::chrono::system_clock::now();
		////	std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
		////	return std::ctime(&sleepTime);
		////}
		////
		////double acctBalance = 100;
		////std::mutex acctLock;
		////void getMoney(int id, double withdrawal) {
		////	std::lock_guard<std::mutex> Lock(acctLock);
		////	std::this_thread::sleep_for(std::chrono::seconds(3));
		////	std::cout << id << " tries to withdraw $" << withdrawal << " on " << getTime();
		////
		////	if ((acctBalance - withdrawal) >= 0) {
		////		acctBalance -= withdrawal;
		////		std::cout << "New Account balance is $" << acctBalance << std::endl;
		////	}
		////	else {
		////		std::cout << "Not enough money un the account\n";
		////		std::cout << "Current balance is $" << acctBalance << endl;
		////	}
		////}
		// 
		////void ExecuteThread(int id) {
		////	auto nowTime = std::chrono::system_clock::now();
		////	std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
		////	tm myLocalTime = *localtime(&sleepTime);
		////
		////	std::cout << "Thread " << id << " Sleep Time : " << std::ctime(&sleepTime) << std::endl;
		////
		////	std::cout << "Month : " <<
		////		myLocalTime.tm_mon << "\n";
		////	std::cout << "Day : " <<
		////		myLocalTime.tm_mday << "\n";
		////	std::cout << "Year : " <<
		////		myLocalTime.tm_year + 1900 << "\n";
		////	std::cout << "Hours : " <<
		////		myLocalTime.tm_hour << "\n";
		////	std::cout << "Minutes : " <<
		////		myLocalTime.tm_min << "\n";
		////	std::cout << "Seconds : " <<
		////		myLocalTime.tm_sec << "\n\n";
		////
		////	std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
		////	nowTime = std::chrono::system_clock::now();
		////	sleepTime = std::chrono::system_clock::to_time_t(nowTime);
		////	std::cout << "Thread " << id << " Awake Time : " << std::ctime(&sleepTime) << std::endl;
		////}
		//
		//int main() {
		//	//std::thread th1(ExecuteThread, 1);
		//	//th1.join();
		//
		//	//std::thread th2(ExecuteThread, 2);
		//	//th2.join();
		//
		//	//std::thread threads[10];
		//	//for (int i = 0; i < 10; i++) {
		//	//	threads[i] = std::thread(getMoney, i, 15);
		//	//}
		//
		//	//for (int i = 0; i < 10; i++) {
		//	//	threads[i].join();
		//	//}
		//
		//	/*std::vector<size_t> primeVect;
		//	int startTime = clock();
		//	findPrimes(1, 100000, primeVect);
		//
		//	for (auto i : primeVect)
		//		std::cout << i << endl;
		//
		//	int endTime = clock();
		//	std::cout << "Execution time: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << endl;*/
		//
		//	int startTime = clock();
		//	findPrimesWithThreads(1, 100000, 3);
		//	int endTime = clock();
		//
		//	for (auto i : primeVect)
		//		cout << i << endl;
		//
		//	cout << "Execution Time: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << endl;
		//
		//	return 0;
		//}

		//#include <thread>
		//class F {
		//public:
		//	F() {
		//		cout << "Default ctor\n";
		//	}
		//	F(const F& other) {
		//		cout << "Copy ctor\n";
		//	}
		//	F(const F&& other) {
		//		cout << "Move ctor\n";
		//	}
		//	void operator()(string& msg) {
		//		/*for (size_t i = 0; i < 100; i++){
		//			cout << i + 1 << " ";
		//		}*/
		//		cout << msg << endl;
		//		msg = "BYE";
		//	}
		//};
		//
		//int main() {
		//	string s = "HI";
		//	//thread t1((F()), std::ref(s));
		//	//t1.join();
		//	cout << s << endl;
		//
		//	cout << std::thread::hardware_concurrency();
		//}



		//using std::bind, passing a funtion object or a lambda
		//to a thread to perform an operation on 
		//another thread and update a local variable's value in main
		//#include <thread>
		//#include <functional>
		//
		//void accumlate(int& num, int id) {
		//	std::this_thread::sleep_for(std::chrono::seconds(1));
		//	cout << "Running thread: " << id << endl;
		//	++num;
		//}
		//
		//int main() {
		//
		//	std::thread t[3];
		//	int num = 0;
		//	/*for (size_t i = 0; i < 3; i++) {
		//		t[i] = thread(bind(accumlate, std::ref(num), i+1));
		//		t[i].join();
		//	}
		//	cout << num;*/
		//
		//	for (size_t i = 0; i < 3; i++) {
		//		t[i] = thread(bind([](int& num, int id) {
		//			std::this_thread::sleep_for(std::chrono::seconds(1));
		//			cout << "Running thread: " << id << endl;
		//			++num;
		//			} , std::ref(num), i + 1));
		//		t[i].join();
		//	}
		//	cout << num; 
		//
		//
		//	//auto lambda = [](int& num, int id) {
		//	//	std::this_thread::sleep_for(std::chrono::seconds(1));
		//	//	cout << "Running thread: " << id << endl;
		//	//	++num;
		//	//};
		//	//for (size_t i = 0; i < 3; i++) {
		//	//	t[i] = thread(bind(lambda , std::ref(num), i + 1));
		//	//	t[i].join();
		//	//}
		//	//cout << num;
		//}


		//#include <future>
		//
		//typedef unsigned long long ull;
		//
		//ull findOdd(ull start, ull end) {
		//	cout << "In findOdd\n";
		//	ull oddSum = 0;
		//	for (ull i = start; i <= end; i++) {
		//		if (i & 1)
		//			oddSum += i;
		//	}
		//	return oddSum;
		//}
		//
		//void main() {
		//	ull start = 0, end = 1900000000;
		//	std::future<ull> oddFuture = std::async(std::launch::deferred, findOdd, start, end);
		//
		//	std::this_thread::sleep_for(std::chrono::seconds(5));
		//	cout << oddFuture.get();
		//}



		//binary file read and write from command line arguments
		//#include <iostream>
		//#include <fstream>
		//#include <string>
		//
		//int main(int argc, char* argv[]) {
		//
		//	char strr[] = "Hello World";
		//
		//	std::fstream f(argv[1], ios::in | ios::out | ios::trunc | ios::binary);
		//	//cout << sizeof strr-1;
		//	f.write(reinterpret_cast<char*>(strr), sizeof strr-1);
		//	//f.write("\0", sizeof(char));
		//	f.write("\nSoham", 6);
		//	//f.write("\0", sizeof(char));
		//	
		//	f.seekg(0, ios::beg); //need to set the streampos to beginning otherwise it will not truncate/overwrite since the current pos is at the end of the file
		//	string data = { "Hello World" };
		//	f.write(data.c_str(), data.size());
		//	f.write("\0", sizeof(char));
		//	data = { "\nSoham" };
		//	f.write(data.c_str(), data.size());
		//
		//	signed long len = f.tellg();
		//	f.seekg(0, ios::beg);
		//
		//	getline(f, data, '\0');
		//	cout << data;
		//
		//	f.close();
		//
		//
		//	//f.seekg(0, ios::end);
		//	//signed long len = f.tellg(); //the current pos for the cursor is already at the end so no need to seekg to the end
		//	//
		//	//f.seekg(0, ios::beg); //set the current pos to beginning so that we can read from the beginning of file
		//	//char* str = new char[len+1];
		//	//while(f.read(reinterpret_cast<char*>(str), len));
		//	//str[len] = '\0';
		//
		//	//std::cout << str << std::endl;
		//	//delete[] str;
		//}


		//#include <fstream>
		//#include <cstring>
		//
		//class Person {
		//	int id;
		//	char name[30];
		//	char addr[50];
		//public:
		//	Person() {}
		//	Person(const char* n, const char* a, int i) {
		//		strcpy(name, n);
		//		strcpy(addr, a);
		//		id = i;
		//	}
		//	friend ostream& operator<<(ostream& os, const Person& p);
		//};
		//
		//ostream& operator<<(ostream& os, const Person& p) {
		//	return os << "ID: " << p.id << "   Name: " << p.name << "   Address: " << p.addr << endl;
		//}
		//
		//void create(Person& person, const char* file) {
		//	ofstream f(file, ios::binary | ios::app);
		//	f.write(reinterpret_cast<char*>(const_cast<Person*>(&person)), sizeof(person));
		//	f.close();
		//}
		//
		//void read(const char* file) {
		//	ifstream f(file, ios::binary);
		//	Person p;
		//	while (f.read(reinterpret_cast<char*>(&p), sizeof(p))) cout << p;
		//	f.close();
		//}
		//
		////update
		////delete
		//
		//int main(int argc, char* argv[]) {
		//	Person soham("Soham Thaker", "118 Timberwolf Cres.", 1);
		//	Person dharit("Dharit Patel", "40 Bedros Lane", 2);
		//
		//	//create(soham, argv[1]);
		//	//create(dharit, argv[1]);
		//
		//	read(argv[1]);
		//
		//	return 0;
		//}

//#include <iterator>
//void main(){
//
//	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }, v2{v.begin(), v.end()};
//
//	copy_backward(v.begin(), v.begin()+5, v2.end()-2);
//
//	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
//}




//specialized tempaltes 
//for a function template specialization, the return type (if auto in base template then auto in specialized template as well or explicitly define the return type for both the templates), the types of the funtion arguments/paramters along with the const status and lvalue reference or an rvalue matters. Also the templated typed arguments, must be exactly the same in number and distinctive, for example specialized add() takes int and unsigned int as templated arguments so the base template must also have exactly 2 distinct typename T and M to match the prototype of the specialised template 
//template <class T, class M>
//unsigned int add(const T& a, const M& b, const M& c) {
//	return static_cast<unsigned int>(a + b + c);
//}
//
//template<>
//unsigned int add<int, unsigned int>(const int& __args0, const unsigned int& __args1, const unsigned int& __args2)
//{
//	return static_cast<unsigned int>(__args0) + __args1 + __args2;
//}
//
//int main() {
//	add(1, 2, 3);
//	return static_cast<int>(add(1, 2u, 3u));
//}



#endif