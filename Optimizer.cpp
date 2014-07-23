/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Optimizer.cpp
 * Last Update: 7/5/14
*/

#include <vector>
#include "Optimizer.h"
#include "Grouper.h"

std::string optimizer::simplify(grouper g) {
	std::string final;
	for(int i = 0; i < g.get_groups().size() -1; i++) {
		std::vector<token> tokens = g.get_groups()[i].get_tokens();
		g.get_groups()[i] = simplify(tokens);
	}
	for(int i = 0; i < g.get_groups().size() -1; i++) {
		std::vector<token> tokens = g.get_groups()[i].get_tokens();
		for(int j = 0; j < tokens.size()-1; j++)
			final += tokens[i].get_token();
	}
	return final;
}

std::vector<token> optimizer::simplify(std::vector<token> tokens) {
	std::string final;
	std::vector<token> newTokens;
	token temp;
	token null, tru, fal;
	null.init('N', 0);
	tru.init('T', 5);
	fal.init('F', 5);
	for(int i = 0; i < tokens.size(); i++) {
		//Double Negation
		//!!p = p
		if(i+1 <= tokens.size() - 1 && (tokens[i] == '!' && tokens[i+1] == '!')) {
			temp.init('N', 0);
			tokens[i] = temp;
			tokens[i+1] = temp;
		}
		//De Morgan's
		//!(p&q) = !p&!q
		/*if(i+5 <= tokens.size() - 1 && (tokens[i] == '!' && tokens[i+1] == '(' && tokens[i+5] == ')')) {
			temp.init('N', 0);
			tokens[i] = temp;
			switch(tokens[i+3].item) {
			case '&':
				temp.init('|', 3);
				tokens[i+3] = temp;
				break;
				case '|':
				temp.init('&', 3);
				tokens[i+3] = temp;
				break;
			}
		}*/
		//Distributivity
		//(p&q)|(p&r) = p&(q|r)
		if(i+12 <= tokens.size() - 1 && (tokens[i+1] == '(' 
			&& tokens[i+2] == tokens[i+8] && tokens[i+3] == tokens[i+9])
			&& tokens[i+3].is_opposite(tokens[i+6]) && tokens[i+4].is_different(tokens[i+10])) {
				temp = tokens[i];
				tokens[i+1] = tokens[i+2];
				tokens[i+2] = tokens[i+3];
				tokens[i+3] = temp;
				tokens[i+5] = tokens[i+9];
				tokens[i+6] = tokens[i+10];
				for(int j = i+6; j < i+12; j++) {
					tokens[j] = null;
				}
				for(i = 0; i < tokens.size(); i++) {
					tokens[i].print();
				}
		}
		//Absorption
		if(i+6 <= tokens.size() - 1 && (tokens[i] == tokens[i+3] && tokens[i+1].is_opposite(tokens[i+4]) && tokens[i+6] == ')')) {
			for(int j = i+1; j <= i+6; j++)
				tokens[j] = null;
		}
		//Universal
		if(i+3 <= tokens.size() - 1 && (tokens[i] == tokens[i+3] && tokens[i+2] == '!')) {
			if(tokens[i+1] == '|')
				tokens[i] = tru;
			else if(tokens[i+1] == '&')
				tokens[i] = fal;
			for(int j = i+1; j <= i+3; j++)
				tokens[j] = null;
		}
		if(i+5 <= tokens.size() - 1 && (tokens[i] == tokens[i+4] && tokens[i+2] == '!' && tokens[i+5] == ')')) {
			if(tokens[i+1] == '|')
				tokens[i] = tru;
			else if(tokens[i+1] == '&')
				tokens[i] = fal;
			for(int j = i+1; j <= i+5; j++)
				tokens[j] = null;
		}
		if(i+2 <= tokens.size() - 1 && (tokens[i] == tru && tokens[i+1] == '|')) {
			for(int j = i+1; j <= i+2; j++)
				tokens[j] = null;
		}
		if(i+2 <= tokens.size() - 1 && (tokens[i] == fal && tokens[i+1] == '|')) {
			tokens[i] = tokens[i+2];
			for(int j = i+1; j <= i+2; j++)
				tokens[j] = null;
		}
		if(i+2 <= tokens.size() - 1 && (tokens[i] == tru && tokens[i+1] == '&')) {
			tokens[i] = tokens[i+2];
			for(int j = i+1; j <= i+2; j++)
				tokens[j] = null;
		}
		if(i+2 <= tokens.size() - 1 && (tokens[i] == fal && tokens[i+1] == '&')) {
			for(int j = i+1; j <= i+2; j++)
				tokens[j] = null;
		}
	}
	for(int i = 0; i < tokens.size(); i++) {
			if(!(tokens[i] == null))
				newTokens.push_back(tokens[i]);
	}
	/*if(tokens.length() == 0) {
		for(int i = 0; i < tokens.size(); i++) {
			if(!(tokens[i] == null))
				tokens += tokens[i].item;
		}
	}*/
	return newTokens;
}