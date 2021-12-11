#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <iostream>
#include <list>

struct Song {
	std::string m_title{};
	std::string m_artist{};
	std::string m_album{};
	std::string m_year{};
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
	};
	
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}


#endif
