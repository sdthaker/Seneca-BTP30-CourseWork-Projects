#ifndef MEETING_H
#define MEETING_H

#include <string>

struct meeting {
	
	enum weekday{ MO, TU, WE, TH, FR, SA, SU };

	static weekday day_of_week(char c);

	explicit meeting(char** argv);

	bool operator<(const meeting& m) const;
	bool operator==(const meeting& m) const;

	std::string title_;
	weekday day_;
	size_t start_time_{};
	size_t finish_time_{};
};

std::ostream& operator<<(std::ostream& os, const meeting& m);

#endif