/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Main.cpp
 * Last Update: 7/5/14
*/

#include <iostream>
#include <string>
#include <vector>

#include "Token.h"
#include "Group.h"
#include "Grouper.h"
#include "Parser.h"
#include "Optimizer.h"
#include "Table.h"

using namespace std;

int main() {
	string expression, choice;
	parser p;
	optimizer o;

	cout << "-------------------------\n| LOGICAL CONNECTIVES:  |\n-------------------------\n|\t!\tNOT\t|\n|\t&\tAND\t|\n|\t|\tOR\t|\n-------------------------\n\n";

	cout << "Enter a logical expression: ";
	cin >> expression;

	cout << "\nWould you like to simplify or print a truth table? ";
	cin >> choice;

	vector<token> tokens = p.parse(expression);
	grouper groups;
	groups.make_groups(tokens);

	while(choice !="truth table" || choice != "truth" || choice != "table" || choice != "tt" || choice != "t" || choice != "simplify" || choice != "s" || choice != "quit" || choice!= "q") {
		if(choice == "truth table" || choice == "truth" || choice == "table" || choice == "tt" || choice == "t") {
			table truth_table(groups.get_groups(), p.get_num_of_vars(), p.get_used_vars());
			truth_table.propagate_truth_values();
			truth_table.print_table();
			choice = "q";
		} else if(choice == "simplify" || choice == "s") {
			string final = o.simplify(groups);
			cout << "\n------------------------------\nSIMPLIFIED LOGICAL EXPRESSION:\n------------------------------\n" << final << "\n";
			choice = "q";
		} else if(choice == "quit" || choice == "q") {
			return 0;
		} else {
				cout << "\nThat was not an option.\n";
				cout << "\nWould you like to simplify or print a truth table? ";
				cin >> choice;
		}
	}

	return 0;
}