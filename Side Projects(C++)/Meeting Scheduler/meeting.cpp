#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>

#include "meeting.h"

meeting::meeting(char** argv) : title_(argv[0]), day_(meeting::weekday(*argv[1])) {
	std::stringstream a1(argv[2]);
	std::stringstream a2(argv[3]);

	a1 >> start_time_;
	a2 >> finish_time_;
}

meeting::weekday meeting::day_of_week(char c) {
	switch (c) {
		case 'M': return meeting::MO;
		case 'T': return meeting::TU;
		case 'W': return meeting::WE;
		case 'R': return meeting::TH;
		case 'F': return meeting::FR;
		case 'S': return meeting::SA;
		case 'U': return meeting::SU;
		default:
			assert(!"not a week day");
			return meeting::MO;
	}
}

bool meeting::operator==(const meeting& m) const {
	return day_ == m.day_ &&
		((start_time_ <= m.start_time_ && m.start_time_ <= finish_time_) || 
			(m.start_time_ <= start_time_ && start_time_ <= m.finish_time_));
}

bool meeting::operator<(const meeting& m) const {
	return day_ < m.day_ || (day_ == m.day_ && start_time_ < m.start_time_) || (day_ == m.day_ && start_time_ == m.start_time_ && finish_time_ < m.finish_time_);
}

std::ostream&
operator << (std::ostream& os, const meeting& m) {
	std::string d;
	switch (m.day_) {
	case meeting::MO: d = "M "; break;
	case meeting::TU: d = "T "; break;
	case meeting::WE: d = "W "; break;
	case meeting::TH: d = "R "; break;
	case meeting::FR: d = "F "; break;
	case meeting::SA: d = "S "; break;
	case meeting::SU: d = "U "; break;
	}
	return os << m.title_
			<< std::string(" ")
			<< d
			<< m.start_time_
			<< std::string(" ")
			<< m.finish_time_;
}