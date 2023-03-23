#pragma once
#include <string>

class Card
{
public:
	enum suits { clubs, diamonds, hearts, spades };
private:
	int value;
	suits type;
public:
	Card(int val = 1, suits su = clubs) : value(val), type(su) {};
	std::string GetFace();
	std::string GetSuit();
	int GetValue();
	Card* SetValue(int nval);
};