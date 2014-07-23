/*
 * Author: Mike Spallino
 * Project: Logic Simplifer
 * File: Grouper.cpp
 * Last Updated: 6/21/14
 */

#include <iostream>
#include <vector>
#include "Token.h"
#include "Group.h"
#include "Grouper.h"

/*
 * TO DO (6/21/14):
 * If no parenthesis given make the entire token array a group.
 */

std::vector<group> grouper::get_groups() {
	return groups;
}

void grouper::make_groups(std::vector<token> tokens) {
	int index = 0;
	int paren[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	char type[10] = {'N','N','N','N','N','N','N','N','N','N'};

	for(int i = 0; i < tokens.size(); i++) {
		if(tokens[i] == '(') {
			paren[index] = i;
			type[index] = '(';
			index++;
		} else if(tokens[i] == ')') {
			paren[index] = i;
			type[index] = ')';
			index++;
		}
	}

	if(index % 2 != 0) {
		std::cout << "ERROR: mismatched parenthesis!\n";
		return;
	}

	int open = 0;
	int close = 0;
	for(int i = 0; i < 10; i++) {
		if(paren[i] == '(') {
			open++;
		} else if (paren[i] == ')') {
			close++;
		}
	}
	if(open != close) {
		std::cout << "ERROR: mismatched parenthesis!\n";
		return;
	}

	for(int i = 0; i < 10; i++) {
		if(type[i] == ')') {
			for(int j = i; j > -1; j--) {
				if(type[j] == '(') {
					std::vector<token> temp;
					for(int k = paren[j]; k <= paren[i]; k++) {
						temp.push_back(tokens[k]);
					}
					groups.push_back(group(temp));
					type[j] = 'N';
					break;
				}
			}
		}
	}
}

void grouper::print_groups() {
	for(int i = 0; i < groups.size(); i++)
		groups[i].print();
}