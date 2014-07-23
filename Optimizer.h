/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Optimizer.h
 * Last Update: 6/3/14
*/

#include <vector>
#include "Token.h"
#include "Grouper.h"

#ifndef OPTIMIZER_H
#define OPTIMIZER_H

class optimizer {
public:
	std::string simplify(grouper g);
	std::vector<token> simplify(std::vector<token> tokens);
};
#endif