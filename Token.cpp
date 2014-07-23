/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Token.cpp
 * Last Update: 7/5/14
*/

#include "Token.h"
#include <iostream>

using namespace std;

void token::init(char i, int c) {
	item = i;
	precedence = c;
}

void token::print() {
	cout << item;
}

char token::get_token() {
	return item;
}

int token::get_precedence() {
	return precedence;
}

bool token::operator==(char c) {
	return(item == c);
}

bool token::operator==(token t) {
	return(item == t.item && precedence == t.precedence);
}

bool token::is_opposite(token t) {
	if(item == '&' && t == '|')
		return true;
	else if(item == '|' && t == '&')
		return true;
	else
		return false;
}

bool token::is_different(token t) {
	return item == t.item;
}