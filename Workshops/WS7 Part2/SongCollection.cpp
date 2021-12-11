// Workshop 7
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/11/05
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <exception>

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

					try {
						song.m_year = stoi(buffer.substr(pos, 5));
					}
					catch (const exception& e) {
						//
					}
					pos += 5;

					song.m_length = stoi(buffer.substr(pos, 5));
					pos += 5;

					song.m_price = stod(buffer.substr(pos, 5));

					m_songColl.push_back(std::move(song));
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

	void SongCollection::display(ostream& out) const {
		
		for_each(m_songColl.begin(), m_songColl.end(), 
			[&out](const Song& s) {
				out << s << endl;
			});

		size_t accum = accumulate(m_songColl.begin(), m_songColl.end(), 0, 
			[](const size_t& val, const Song& s) {
				return val + s.m_length;
			});

		size_t hour = accum / 3600;
		size_t min = (accum % 3600)/60;
		size_t sec = (accum % 3600)%60;

		out << std::setw(89) << std::setfill('-') << '\n' 
			<< std::setfill(' ') << "| " << std::setw(77) 
			<< "Total Listening Time: " << hour 
			<< ":" << min << ":" << sec << " |\n";
	}

	void SongCollection::sort(const string& field){

		if (field == "title") {
			auto comp = [field](const Song& lhs, const Song& rhs) {
				return lhs.m_title < rhs.m_title;
			};
			m_songColl.sort(comp);
		}
		else if (field == "album") {
			auto comp = [field](const Song& lhs, const Song& rhs) {
				return lhs.m_album < rhs.m_album;
			};
			m_songColl.sort(comp);
		}
		else if (field == "length") {
			auto comp = [field](const Song& lhs, const Song& rhs) {
				return lhs.m_length < rhs.m_length;
			};
			m_songColl.sort(comp);
		}
	}

	void SongCollection::cleanAlbum() {

		transform(m_songColl.begin(), m_songColl.end(), m_songColl.begin(),
			[](Song& song) {
				if (song.m_album == "[None]") {
					song.m_album = "";
				}
				return song;
			});
	}

	bool SongCollection::inCollection(const std::string& artist) const {
		return any_of(m_songColl.begin(), m_songColl.end(), 
			[artist](const Song& song){
				return song.m_artist == artist;
			});
	}

	list<Song> SongCollection::getSongsForArtist
		(const string& artist) const {
		
		size_t cnt = count_if(m_songColl.begin(), m_songColl.end(), 
			[artist](const Song& song) {
				return song.m_artist == artist;
			});
		
		list<Song> local(cnt);

		copy_if(m_songColl.begin(), m_songColl.end(), local.begin(), 
			[artist](const Song& song) {
				return song.m_artist == artist;
			});

		return local;
	}
}

std::ostream& operator<<(ostream& out, const Song& theSong) {

	size_t min = theSong.m_length / 60;
	size_t sec = theSong.m_length % 60;

	out << "| " << setw(20) << left << theSong.m_title
		<< " | " << setw(15) << left << theSong.m_artist
		<< " | " << setw(20) << left << theSong.m_album;

	if (theSong.m_year) {
		out << " | " << right << setw(6) << setfill(' ') 
			<< theSong.m_year << " | " << min << ":" << setw(2) 
			<< setfill('0') << sec << " | " << setfill(' ') 
			<< theSong.m_price << " |";
	}
	else {
		out << " | " << right << setw(6) << setfill(' ')
			<< "" << " | " << min << ":" << setw(2)
			<< setfill('0') << sec << " | " << setfill(' ')
			<< theSong.m_price << " |";
	}
	return out;
}