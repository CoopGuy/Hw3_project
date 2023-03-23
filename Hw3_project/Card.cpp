#include "Card.h"
#include <sstream>

std::string Card::GetFace()
{
	
	if (value == 1)return "A";
	if (value > 1 && value < 10)
	{
		std::stringstream t;
		t << value;
		return t.str();
	}
	if (value == 10)return "10";
	if (value == 11)return "J";
	if (value == 12)return "J";
	if (value == 13)return "K";

	std::stringstream ss;
	ss << "GetFace: Invalid Face\nFile: " << __FILE__ << "\nLine: " << __LINE__ << "\n";
	throw std::runtime_error(ss.str());
}

std::string Card::GetSuit()
{
	switch (type) 
	{
	case clubs:
		return "Clubs";
	case diamonds:
		return "Diamonds";
	case hearts:
		return "Hearts";
	case spades:
		return "Spades";
	default:
		return "??????";
	}
}

int Card::GetValue() { return value; };
Card* Card::SetValue(int nval)
{
	value = nval;
	return this;
}