#pragma once

class Card
{
public:
	enum suits { clubs, diamonds, hearts, spades };
private:
	int value;
	suits type;
public:
	Card(int val = 1, suits su = clubs) : value(val), type(su) {};
	char GetFace();
	int GetValue();
	Card* SetValue(int nval);
};