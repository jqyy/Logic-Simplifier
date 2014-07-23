/*
 * Author: Mike Spallino
 * Project: Logic Simplifier
 * File: Token.h
 * Last Update: 7/5/14
*/

#ifndef TOKEN_H
#define TOKEN_H

class token {
public:
	void init(char item, int precedence);
	void print();
	char get_token();
	int get_precedence();
	bool operator ==(char c);
	bool operator ==(token t);
	bool is_opposite(token t);
	bool is_different(token t);
private:
	char item;
	int precedence;
};

#endif