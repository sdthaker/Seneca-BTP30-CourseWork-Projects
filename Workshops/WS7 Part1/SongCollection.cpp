#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include <iomanip>

#include "SongCollection.h"

using namespace std;

namespace sdds {

	void SongCollection::beginTrim(string& str) const {
		str.erase(0, str.find_first_not_of(' '));
	}

	void SongCollection::endTrim(string& str) const {
		str.erase(str.find_last_not_of(' ') + 1);
	}

	SongCollection::SongCollection(const char* filename) {

		try {
			if (filename && filename[0] != '\0') {
				fstream inf(filename, ios_base::in);

				if (inf.is_open()) {
					string buffer{};
					size_t pos{};
					Song song{};

					while (getline(inf, buffer)) {
						song.m_title = buffer.substr(pos, 25);
						beginTrim(song.m_title);
						endTrim(song.m_title);
						pos += 25;

						song.m_artist = buffer.substr(pos, 25);
						beginTrim(song.m_artist);
						endTrim(song.m_artist);
						pos += 25;

						song.m_album = buffer.substr(pos, 25);
						beginTrim(song.m_album);
						endTrim(song.m_album);
						pos += 25;

						song.m_year = buffer.substr(pos, 5);
						beginTrim(song.m_year);
						endTrim(song.m_year);
						pos += 5;
						//song.m_year = stoi(buffer.substr(pos, 5));

						song.m_length = stoi(buffer.substr(pos, 5));
						pos += 5;

						song.m_price = stod(buffer.substr(pos, 5));
						pos += 5;

						m_songColl.push_back(song);
						pos = 0;
						song = {};
					}
				}
				else {
					throw string("No such file named ") + filename + " exists";
				}
			}
			else {
				throw "Filename was not provided";
			}
		}
		catch (const char* what) {
			cout << what << endl;
		}
		catch (const string& what) {
			cout << what << endl;
		}
		catch (...) {
			cout << "An unknown error occured" << endl;
		}
	}

	void SongCollection::display(std::ostream& out) const {
		for_each(m_songColl.begin(), m_songColl.end(), [&out](const Song& s) {
			out << s;
		});
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		
		size_t min = theSong.m_length / 60;
		size_t sec = theSong.m_length % 60;

		return out << "| " << setw(20) << left << theSong.m_title
			<< " | " << setw(15) << left << theSong.m_artist
			<< " | " << setw(20) << left << theSong.m_album
			<< " | " << right << setw(6) << setfill(' ') << theSong.m_year
			<< " | " << min << ":" << setw(2) << setfill('0') << sec
			<< " | " << setfill(' ') << theSong.m_price << " |\n";
	}
}