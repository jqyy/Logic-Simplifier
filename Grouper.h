/*
 * Author: Mike Spallino
 * Project: Logic Simplifer
 * File: Grouper.h
 * Last updated: 5/25/14
 */

#include <vector>
#include "Token.h"
#include "Group.h"

#ifndef GROUPER_H
#define GROUPER_H

class grouper {
	public:
		std::vector<group> get_groups();
		void make_groups(std::vector<token> tokens);
		void print_groups();
	private:
		std::vector<group> groups;
};

#endif