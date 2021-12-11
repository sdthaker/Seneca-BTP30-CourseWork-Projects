// Workshop 9 - Multi-Threading
// SecureData.cpp

// Workshop 9
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/11/19
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		vector<thread> vTh(4);
		int dividedBytes = nbytes / 4;

		auto f = std::bind(converter, placeholders::_1, key, 
							placeholders::_2, Cryptor());

		for (size_t i = 0; i < vTh.size(); i++) {

			if (i != (vTh.size() - 1)) {
				//below code creates a functor for every iteration
				/*vTh[i] = thread
				(std::bind(converter, text + i * dividedBytes,
					key, dividedBytes, Cryptor()));*/

				//below code uses the same functor for every iteration
				vTh[i] = thread(f, text + i * dividedBytes, dividedBytes);
			}
			else {
				//below code uses the same functor for every iteration
				dividedBytes = nbytes - i * dividedBytes;
				vTh[i] = thread(f, text + nbytes - dividedBytes, dividedBytes);

				//below code creates a functor for every iteration
				//dividedBytes = nbytes - i * dividedBytes;
				/*vTh[i] = thread
				(std::bind(converter, text + nbytes - dividedBytes,
					key, dividedBytes, Cryptor()));*/
			}
		}

		for (auto itr = vTh.begin(); itr != vTh.end(); itr++) {
			itr->join();
		}

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			fstream fs(file, ios::out | ios::binary);

			if (fs.good()) {
				fs.write(text, nbytes);
			}
			else {
				throw std::string("File opening failed!");
			}
			fs.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		fstream fs(file, ios::in | ios::binary);

		if (fs.good()) {
			delete[] text;

			fs.seekg(0, std::ios::end);
			nbytes = (int)fs.tellg();

			text = new char[nbytes];

			fs.seekg(ios::beg);
			int i = 0;
			fs >> noskipws;
			while (fs.good())
				fs >> text[i++];

			*ofs << "\n" << nbytes << " bytes copied from binary file "
				<< file << " into memory.\n";

			encoded = true;

			// decode using key
			code(key);

			*ofs << "Data decrypted in memory\n\n";
		}
		else {
			throw string("File opening failed!");
		}
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
