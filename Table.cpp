/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Table.cpp
 * Last Modified: 6/21/14
 */

#include <iostream>

#include "Grouper.h"
#include "Table.h"

table::table(std::vector<group> groups, int num_of_vars, char used_vars[]) {
	num_of_groups = groups.size();
	table::num_of_vars = num_of_vars;
	num_of_permutations = pow(2, table::num_of_vars);
	truth_values = new bool*[table::num_of_vars];
	for(int i = 0; i < table::num_of_vars; i++) 
		truth_values[i] = new bool[num_of_permutations];
	table_values = new bool*[num_of_groups];
	for(int i = 0; i < table::num_of_vars; i++)
		table_values[i] = new bool[num_of_permutations];
	for(int i = 0; i < groups.size(); i++)
		table_groups.push_back(groups[i]);
	for(int i = 0; i < 10; i++) 
		table_vars[i] = used_vars[i];
}

void table::create_table() {
}

void table::propagate_truth_values() {
	int k = 0;
	bool val = true;
	for(int i = 0; i < num_of_vars; i++) {
		k = 0;
		for(int j = 0; j < num_of_permutations; j++) {
			truth_values[i][j] = val;
			k++;
			if(k == pow(2, num_of_vars - i - 1)) {
				k = 0;
				val = !val;
			}
		}
	}
}

void table::compute_table_values() {
	//int var_index = 0;
	//for(int i = 0; i < num_of_groups; i++) {
	//	for(int j = 0; j < num_of_permutations; j++) {
	//		for(token t : table_groups[i].get_tokens()) {
	//			if(t.get_token() == '&') {
	//				table_values[var_index]
	//			} else if(t.get_token() == '|') {
	//			}
	//	}
	//}
}

void table::print_table() {
	for(int i = 0; i < num_of_permutations; i++) {
		for(int j = 0; j < num_of_vars; j++) {
			std::cout << truth_values[j][i];
		}
		std::cout << "\n";
	}
}