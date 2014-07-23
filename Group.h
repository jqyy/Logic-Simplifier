/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Group.h
 * Last Update: 5/25/14
*/

#ifndef GROUP_H
#define GROUP_H

#include "Token.h"
#include <vector>

class group {
	public:
		group();
		group(std::vector<token> tokens);
		std::vector<token> get_tokens();
		bool compare(group g);
		bool simplified;
		void print();
	private:
		std::vector<token> tokens;
};

#endif