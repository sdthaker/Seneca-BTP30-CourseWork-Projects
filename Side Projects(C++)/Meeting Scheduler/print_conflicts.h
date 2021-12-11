#ifdef PRINT_CONFLICTS_H
#define PRINT_CONFLICTS_H

#include "meeting.h"

struct print_conflicts {
	std::ostream& os_;

	print_conflicts(std::ostream& os) : os_(os) {}
	
	const meeting& operator()(const meeting& lhs, const meeting& rhs) {
		if (lhs == rhs) {
			os_ << "CONFLICT:" << std::endl << " " << lhs << std::endl << " " << rhs << std::endl << std::endl;
		} 
		return rhs;
	}
};

#endif