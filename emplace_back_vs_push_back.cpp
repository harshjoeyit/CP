
/*
push_back & emplace_back
*/	

#include<bits/stdc++.h>
using namespace std;

struct President {
	std::string name;
	std::string country;
	int year;

	President(std::string p_name, std::string p_country, int p_year)
		: name(std::move(p_name)), country(std::move(p_country)), year(p_year) {
		std::cout << "I am being constructed.\n";
	}
	President(President&& other)
	    	: name(std::move(other.name)), country(std::move(other.country)), year(other.year) {
	    	std::cout << "I am being moved.\n";
	}
	President& operator=(const President& other) = default;
};
 
int main() {
	std::vector<President> elections;
	std::cout << "emplace_back:\n";
	elections.emplace_back("Nelson Mandela", "South Africa", 1994);

	std::vector<President> reElections;
	std::cout << "\npush_back:\n";
	reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));

	vector<pair<string, int> > v;
	v.push_back({"kelly", 4});		// pair is created first and then copied 	
	v.emplace_back("sally", 4);		// in place construction
}