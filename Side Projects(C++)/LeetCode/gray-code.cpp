#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		//if (n < 1 || n > 16) {
		//	return vector<int>{0};
		//}
		//else {
		//	vector<int> binaryNum {};
		//	binaryNum.push_back(0);
		//	binaryNum.push_back(1);
		//	int max = pow(2, n) - 1, num = 2;

		//	while (num <= max) {
		//		binaryNum.push_back(num);
		//		num++;
		//	}
		//	adjacentNums(binaryNum);
		//	//firstAndLastNums(binaryNum);
		//	return binaryNum;
		//}
		vector<int> ans(1);
		for (int i = 1; i < (1 << n); ++i)
			ans.push_back(ans.back() ^ (i & -i));
		return ans;
	}
private:
	
	/*bool differAtOneBitPos(int a, int b) {
		return b == (a ^ 1) || (b == (a ^ ((a & -a) << 1)));
	}*/
	//bool differAtOneBitPos(unsigned int a, unsigned int b) {
	//	return isPowerOfTwo(a ^ b);
	//}
	//bool isPowerOfTwo(unsigned int x) {
	//	return x && (!(x & (x - 1)));
	//}

	//vector<int>& adjacentNums(vector<int>& binaryNum) {
	//	for (size_t i = 0; i < binaryNum.size(); i++) {
	//		if (i + 1 <= binaryNum.size() - 1 && this->differAtOneBitPos(binaryNum[i], binaryNum[i+1])) {
	//			continue;
	//		}
	//		else {
	//			int posToSwitch = i+1;
	//			for (size_t j = i+1; j < binaryNum.size(); j++) {
	//				if(j + 1 <= binaryNum.size()-1 && this->differAtOneBitPos(binaryNum.at(i), binaryNum.at(j+1))) {
	//					int temp = binaryNum[posToSwitch];
 //						binaryNum[posToSwitch] = binaryNum[j + 1];
	//					binaryNum[j + 1] = temp;
	//					//i++;
	//					break;
	//				}
	//				else {
	//					//posToSwitch = j + 1;
	//					//continue to check if the next number(j+1) differs with i... if true then swap the pos of number at j+1 to position at next index to i 
	//					// 
	//					//make a condition to exit the outer loop coz inner loop takes care of rest of the numbers
	//				}
	//			}
	//		}
	//	}
	//	return binaryNum;
	//}
	/*vector<int>& firstAndLastNums(vector<int>& binaryNum) {
		int i = binaryNum.size() - 1;

		while (i >= 0) {
			if (this->differAtOneBitPos(binaryNum[0], binaryNum[i])) {
				int temp = binaryNum[i];
				binaryNum[i] = binaryNum[binaryNum.size()-1];
				binaryNum[binaryNum.size() - 1] = temp;
				return binaryNum;
			}
			else i--;
		}
		return binaryNum;
	}*/
};

int main() {
	Solution s;
	vector<int> v = std::move(s.grayCode(16));

	cout << "[";
	for (int n : v) {
		cout << n << ",";
	}
	cout << "]";
}



