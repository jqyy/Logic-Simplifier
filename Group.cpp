/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Group.cpp
 * Last Update: 6/21/14
*/

#include <vector>
#include <iostream>
#include "Group.h"

group::group() {

}

group::group(std::vector<token> new_tokens) {
	for(int i = 0; i < new_tokens.size(); i++) {
		tokens.push_back(new_tokens[i]);
	}
}

bool group::compare(group g) {
	int index = 0;
	for(token t : g.tokens) {
		if(index < tokens.size()) {
			if(!(t == tokens[index])) {
				return false;
			}
			index++;
		}
	}
	return true;
}

void group::print() {
	for(token t : tokens)
		t.print();
	std::cout << "\n";
}

std::vector<token> group::get_tokens() {
	return tokens;
}