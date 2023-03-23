#pragma once

class Card
{
private:
	enum suits{ clubs, diamonds, hearts, spades, };
	int value;
	suits type;
public:
	Card(int val = 1, suits su = clubs) : value(val), type(su) {};
	char GetFace();
	int GetValue();
	Card* SetValue(int nval);
};