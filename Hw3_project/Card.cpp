#include "Card.h"
#include <sstream>

char Card::GetFace()
{
	if (value > 0 && value < 11)
	{
		return (char)(48 + value);
	}
	if (value == 11)return 'J';
	if (value == 12)return 'Q';
	if (value == 13)return 'K';

	std::stringstream ss;
	ss << "GetFace: Invalid Face\nFile: " << __FILE__ << "\nLine: " << __LINE__ << "\n";
	throw std::runtime_error(ss.str());
}

int Card::GetValue() { return value; };
Card* Card::SetValue(int nval)
{
	value = nval;
	return this;
}