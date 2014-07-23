/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Table.h
 * Last Modified: 6/21/14
 */

#ifndef TABLE_H
#define TABLE_H

#include "Grouper.h"

class table {
public:
	table(std::vector<group> groups, int num_of_vars, char used_vars[]);
	void create_table();
	void propagate_truth_values();
	void compute_table_values();
	void print_table();
private:
	int num_of_vars, num_of_permutations, num_of_groups;
	bool** truth_values;//[num_of_vars][num_of_permutations];
	bool** table_values;//[num_of_groups][num_of_permutations];
	std::vector<group> table_groups;
	char table_vars[10];
};

#endif