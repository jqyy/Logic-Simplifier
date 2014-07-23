/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Parser.h
 * Last Update: 7/5/14
*/

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "Token.h"

class parser {
public:
	std::vector<token> parse(std::string input);
	char* get_used_vars();
	int get_num_of_vars();
	bool found_var(char target);
private:
	char used_vars[10];
	int num_of_vars;
};

#endif