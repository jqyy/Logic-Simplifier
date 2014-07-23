/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Parser.cpp
 * Last Update: 7/5/14
*/

#include <vector>
#include <iostream>
#include "Token.h"
#include "Parser.h"

std::vector<token> parser::parse(std::string input) {
	num_of_vars = 0;
	std::vector<token> tokens;
	token temp;
	temp.init('(', 2);
	tokens.push_back(temp);
	for(char c : input) {
		switch(c) {
		case '!':
			temp.init(c, 1);
			tokens.push_back(temp);
			break;
		case '(':
			temp.init(c, 2);
			tokens.push_back(temp);
			break;
		case ')':
			temp.init(c, 2);
			tokens.push_back(temp);
			break;
		case '&':
			temp.init(c, 3);
			tokens.push_back(temp);
			break;
		case '|':
			temp.init(c, 3);
			tokens.push_back(temp);
			break;
		case '^':
			std::cout << "Use the & symbol for the AND logical connective.\n";
			temp.init('&', 3);
			tokens.push_back(temp);
			break;
		case 'T':
			temp.init(c, 4);
			tokens.push_back(temp);
			break;
		case 'F':
			temp.init(c, 4);
			tokens.push_back(temp);
			break;
		default:
			char alphabet[] = {'a','b','c','d','e','g','h','i','j','k','l','m','n','o','p','q','r','s','u','v','w','x','y','z',
							   'A','B','C','D','E','G','H','I','J','K','L','M','N','O','P','Q','R','S','U','V','W','X','Y','Z'};
			int used_vars_index = 0;
			for(int i = 0; i < 47; i++) {
				if(c == alphabet[i] && !found_var(c)) {
					temp.init(c, 5);
					tokens.push_back(temp);
					num_of_vars++;
					used_vars[used_vars_index] = alphabet[i];
					used_vars_index++;
					break;
				}
			}
			break;
		}
	}

	temp.init(')', 2);
	tokens.push_back(temp);

	return tokens;
}

int parser::get_num_of_vars() {
	return num_of_vars;
}

bool parser::found_var(char target) {
	for(char c: used_vars) {
		if(c == target)
			return true;
	}
	return false;
}

char* parser::get_used_vars() {
	return used_vars;
}