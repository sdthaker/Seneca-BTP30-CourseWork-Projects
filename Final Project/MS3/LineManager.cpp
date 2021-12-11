// Name: Soham Thaker
// Seneca Student ID: 011-748-159
// Seneca email: sdthaker1@myseneca.ca
// Date of completion: 29/10/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	LineManager::LineManager(const std::string& file, 
		const std::vector<Workstation*>& stations) {

		Utilities util;
		bool more = true;
		size_t pos = 0u;
		string token{}, current{}, next{};

		ifstream fin(file);
		if (!fin)
			throw string("Unable to open [") + file + "] file.";

		while (!fin.eof()) {
			getline(fin, token);

			current = util.extractToken(token, pos, more);
			if (more) {
				next = util.extractToken(token, pos, more);
			}

			auto found =
				find_if(stations.begin(), stations.end(), 
					[&current](const auto& station) {
					return station->getItemName() == current;
				});

			if (found != stations.end()) {
				activeLine.push_back(*found);
			}
			else {
				throw string("No station exists named: " + current);
			}

			//auto lastAdded = activeLine.end() - 1;
			Workstation* lastAdded = activeLine.back();
			
			if (!next.empty()) {
				auto found =
					find_if(stations.begin(), stations.end(), 
						[&next](const auto& station) {
						return station->getItemName() == next;
					});

				if (found != stations.end()) {
					//(*lastAdded)->setNextStation(*found);
					lastAdded->setNextStation(*found);
				}
				else {
					throw string("No station exists named: " + current);
				}
			}

			current.clear();
			next.clear();
			more = true;
		}

		m_firstStation = *activeLine.begin();
		m_cntCustomerOrder = pending.size();
		fin.close();

		//to find which station is the first one out of all; 
		//below code is bad in terms of time complexity
		
		//for_each(activeLine.begin(), activeLine.end(), 
		//	[&activeLine = activeLine, &m_firstStation = m_firstStation]
		//	(Workstation* outerWs) {

		//		bool found = any_of(activeLine.begin(), activeLine.end(), 
		//			[&outerWs](const Workstation* ws) {
		//				if (ws->getNextStation()) {
		//					return outerWs->getItemName() == 
		//						   ws->getNextStation()->getItemName();
		//				}
		//			});

		//		if (!found) {
		//			m_firstStation = outerWs;
		//		}
		//	});		
	}

	void LineManager::linkStations() {
		
		vector<Workstation*> local{};
		//Workstation* next = activeLine.front();
		Workstation* next = m_firstStation;

		while (next) {
			local.push_back(next);
			next = next->getNextStation();
		}

		activeLine.clear();
		activeLine.insert(activeLine.begin(), local.begin(), local.end());

		/*static size_t cnt = 0;
		static Workstation* cur = m_firstStation;

		std::transform(activeLine.begin(), activeLine.end(), 
			activeLine.begin(),	[](Workstation* ws) {
				Workstation* prev = nullptr;

				if (!cnt) {
					prev = cur;
					if (cur->getNextStation()) {
						cur = cur->getNextStation();
					}
					++cnt;
					return prev;
				}
				
				prev = cur;
				if (cur->getNextStation()) {
					cur = cur->getNextStation();
				}
				return prev;
		});*/
	}

	bool LineManager::run(std::ostream& os) {
		static size_t cnt{};
		 
		os << "Line Manager Iteration: " << ++cnt << endl;

		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}

		for_each(activeLine.begin(), activeLine.end(), 
			[&os](Workstation* ws) {
			ws->fill(os);
		});

		for_each(activeLine.begin(), activeLine.end(), 
			[](Workstation* ws) {
			ws->attemptToMoveOrder();
		});
			
		return m_cntCustomerOrder == completed.size() + incomplete.size();
	}

	void LineManager::display(std::ostream& os) const {
		//1
		for_each(activeLine.begin(), activeLine.end(), 
			[&os](const Workstation* ws) {
			ws->display(os);
		});

		//2
		/*auto show = [](const Workstation* ws, ostream& os) {
			ws->display(os);
		};

		std::for_each(activeLine.begin(), activeLine.end(), 
			std::bind(show, placeholders::_1, std::ref(os)));*/
		
		//3
		/*ostream_iterator<Workstation> os_itr (os);

		std::for_each(activeLine.begin(), activeLine.end(), 
		 [&os_itr](const Workstation* ws) {
			const Workstation& ws_ref = *ws;
			os_itr = ws_ref;
		});*/
	}
}