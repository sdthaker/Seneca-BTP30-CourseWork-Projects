#include <utility>
#include "Shared_Ptr.h"

using namespace sdds;

int main() {
	/*Shared_ptr<int> s1(new int(1));
	Shared_ptr<int> s2 = s1;
	Shared_ptr<int> s3 = std::move(s1);*/

	Shared_ptr<int> s1(new int(1));
	Shared_ptr<int> ss = s1;

	Shared_ptr<int> s2(new int(1));
	Shared_ptr<int> s22 = s2;
	s2 = s1; //error

	Shared_ptr<int> s3 = std::move(s2);

	s3 = std::move(s22);
}