// Workshop 7
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/11/05
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <iostream>
#include <list>

struct Song {
	std::string m_title{};
	std::string m_artist{};
	std::string m_album{};
	size_t m_year{};
	size_t m_length{};
	double m_price{};
};

namespace sdds {
	class SongCollection {
		std::list<Song> m_songColl{};
		void beginTrim(std::string& str) const;
		void endTrim(std::string& str) const;
	public:
		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void sort(const std::string& field);
		void cleanAlbum();
		bool inCollection(const std::string& artist) const;
		std::list<Song> getSongsForArtist(const std::string& artist) const;
	};
}
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
#endif
