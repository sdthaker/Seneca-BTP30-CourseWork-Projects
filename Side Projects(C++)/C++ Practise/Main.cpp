// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


//#include <cstring>
//#include <iostream>
//
//using namespace std;


/*External and Internal Linking 

//extern int var;
int var;

extern void Function();

int main() {
	//cout << var << endl;
	Function();
}
*/


//move semantics, move operations
//class String {
//private: 
//	char* m_data = nullptr;
//	int m_size = 0;
//public:
//	String() {
//		cout << "Created(def constructor): " << this << endl;
//	}
//
//	String(const char* string) {
//		cout << "Created(1-arg constructor): ";
//		m_size = strlen(string);
//		m_data = new char[m_size + 1];
//		strcpy(m_data, string);
//		cout << this << endl;
//	}
//
//	String(String&& other) noexcept{
//		cout << "Moved" << endl;
//		m_size = other.m_size;
//		m_data = other.m_data;
//
//		other.m_size = 0;
//		other.m_data = nullptr;
//	}
//
//	String& operator=(String&& other) noexcept{
//		if (this != &other) {
//			cout << "Moved" << endl;
//			delete[] m_data;
//
//			m_size = other.m_size;
//			m_data = other.m_data;
//
//			other.m_size = 0;
//			other.m_data = nullptr;
//		}
//		return *this;
//	}
//
//	~String() {
//		cout << "Deleted: " << this << endl;
//		delete[] m_data;
//	}
//
//	String(const String& other): String(other.m_data) {
//		cout << "Copied" << endl;
//		//m_size = other.m_size;
//		//m_data = new char[m_size + 1];
//		//strcpy(m_data, other.m_data);
//	}
//
//	void printName() {
//		for (int i = 0; i < m_size; i++)	cout << m_data[i];
//		cout << endl;
//	}
//};
//
//
//class Entity {
//private:
//	String m_name;
//public:
//	Entity(const String& name) : m_name(name) {}
//	Entity(String&& name) : m_name(move(name)) {}
//	void printName() {
//		m_name.printName();
//	}
//};
//
//int main() {
//	/*Entity entity(String("Cherno"));
//	entity.printName();*/
//
//	String apple("Apple"), dest;
//
//	cout << "apple: ";
//	apple.printName();
//	cout << "dest: ";
//	dest.printName();
//	
//	dest = move(apple);
//
//	cout << "apple: ";
//	apple.printName();
//	cout << "dest: ";
//	dest.printName();
//}


//template <typename T>
//T findMin(T arr[], int size) {
//	T val = arr[0];
//
//	for (int i = 0; i < size; i++) {
//		if (val > arr[i]) {
//			val = arr[i];
//		}
//	}
//	return val;
//}
//template <>
//char findMin<char>(char arr[], int size) {
//	char* ch = &arr[0];
//
//	for (int i = 0; i < size; i++) {
//		if (*ch > arr[i]) {
//			*ch = arr[i];
//		}
//	}
//	return *ch;
//}
//int main() {
//
//	int a[] = { 1,2,3,4,5 };
//
//	char b[] = { 'A', '=', 'X', 'Y', 'Z', '\0' };
//	char* c = b;
//
//	cout << findMin(a, 5) << endl;
//	cout << findMin(c, 5) << endl;
//}



//template specialization
//put as less restrictions as possible for custom types. Here in the below functions, we only need to define '>' operator and nothing else for classes. Since val is a pointer, it points an address of an existing memory and thus we dont need copy operations for line 153 and 157 and dont need to return a local object

//template <typename T>
//const T* findMin(const T* arr, int size) {
//	const T* val = &arr[0];
//
//	for (int i = 0; i < size; i++) {
//		if (*val > arr[i]) {
//		    val = &arr[i];
//		}
//	}
//	return val;
//}
//
//template <>
//const char* findMin<char>(const char* arr, int size) {
//	const char* val = &arr[0];
//
//	for (int i = 0; i < size; i++) {
//		if (*val > arr[i]) {
//			val = &arr[i];
//		}
//	}
//	return val;
//}
//
//int main() {
//
//	int a[] = { 2,1,3,4,5 };
//
//	char b[] = { 'A', '=', 'X', 'Y', 'Z', '\0' };
//	const char* c = b;
//
//	cout << *(findMin(a, 5)) << endl;
//	cout << *(findMin(c, 5)) << endl;
//}
//


//templates in a heirarchy
//template <typename T = int, int size = 50>
//class Array {
//    T a[size];
//    unsigned n;
//    T dummy;
//    static unsigned count;
//public:
//    Array() {
//        n = 0u;
//        dummy = 0;
//        ++count;
//    }
//    T& operator[](unsigned i) {
//        return i < 50u ? a[i] : dummy;
//    }
//    static unsigned cnt() {
//        return count;
//    }
//    ~Array() {
//        --count;
//    }
//};
//
// 
// class variable declaration:
//template <typename T, int size>
//unsigned Array<T, size>::count = 0u;
//
//
//int main() {
//    Array<> a, b;
//
//    for (int i = 0; i < 5; i++)
//        a[i] = i * i;
//    b = a;
//    for (int i = 0; i < 5; i++)
//        std::cout << b[i] << ' ';
//    std::cout << endl;
//}


//templates in a heirarchy + virtuals
//template <typename T>
//class Base {
//    T m_value;
//public:
//    Base(const T& val) : m_value {val} {
//        cout << m_value << " Base(const T& val)\n";
//    }
//    virtual void display() const {
//        cout << m_value << "Base::display()\n";
//    }
//    virtual ~Base() {
//        cout << "~Base()\n";
//    }
//};
//
//template <typename U, typename T>
//class Derived : public Base<T> {
//    U m_value;
//public:
//    Derived(const U& value, const T& val) : Base<T>(val){
//        m_value = value;
//        cout << value << " Derived(const U& value, const T& val)\n";
//    }
//    void display() const {
//        cout << m_value << " Derived::display()\n";
//    }
//    ~Derived() {
//        cout << "~Derived()\n";
//    }
//};
//
//int main() {
//    Base<double>*b = new Derived<int, double>(5, 15.5);
//    b->display();
//    delete b;
//
//    b = new Base<double>(16.5);
//    b->display();
//    delete b;
//}


//
//#include <iostream>
//
//template <typename T>
//void print(const T& t) {
//    std::cout << t << std::endl;
//}
//
//template <typename T, typename... etc>
//void print(const T& t, const etc&... pp) {
//    std::cout << t << " | ";
//    print(pp...);
//}
//
//int main() {
//    print(100);
//    print("abcd", 100, 34.56);
//}


//variable template
//template <typename T>
//T pi = T(3.141473485923539572396547L);
//
//template <>
//char pi<char> = 'a';
//
//int main() {
//	cout.precision(std::numeric_limits<long double>::max_digits10);
//
//	cout << pi<int> << endl;
//	cout << pi<float> << endl;
//	cout << pi<double> << endl;
//	cout << pi<long double> << endl;
//	cout << pi<char> << endl;
//}


//class template specialization
//template <typename T>
//class Test {
//	static int val;
//public:
//	Test() {
//		cout << ++val << endl;
//	}
//};
//
//template <>
//class Test<int> {
//	static int val;
//public:
//	Test() {
//		cout << ++val << endl;
//	}
//};
//
//template <typename T>
//int Test<T>::val = 10;
//
//int Test<int>::val = 0;
//
//
//int main(){
//	Test<int> a;
//	Test<int> b;
//
//	Test<char>c;
//	Test<char>d;
//
//}

//class template specialization
//template <typename T>
//class A {
//public:
//	A() {
//		cout << "A()\n";
//	}
//	T add(T x, T y);
//};
//
//template <typename T>
//T A<T>::add(T x, T y) {
//	return x + y;
//}
//
//template <>
//class A <char> {
//public:
//	A() {
//		cout << "Specialized A()\n";
//	}
//	char add(char x, char y);
//};
//
//char A<char>::add(char x, char y) {
//	int i = x - '0';
//	int j = y - '0';
//	return i + j;
//}
//
//int main() {
//	A<int> intA;
//	A<double> doubleA;
//	A<char> charA;
//
//	int a = 1, b = 2;
//	cout << intA.add(1, 2) << endl;
//
//	double c = 3.0, d = 5.5;
//	cout << doubleA.add(c, d) << endl;
//
//	char e = 'e', f = 'f';
//	cout << charA.add(e, f) << endl;
//}


//variadic templates
//#include <typeinfo>
//void print() {
//	cout << "I am an empty function\n";
//}
//
//template <typename T>
//void print(const T& v) {
//	cout << typeid(T).name() << endl << v << endl;
//	cout << "I print something\n";
//}
//
//template <typename T, typename... Ts>
//void print(T a, Ts... b) {
//	cout << a << endl;
//	print(b...);
//}
//
//int main() {
//	print(1, 2, 3.14, "Pass me any number of arguments I will print\n");
//}
