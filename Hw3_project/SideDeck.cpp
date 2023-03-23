#include "SideDeck.h"
#include <sstream>

void  SideDeck::Add(Card* addCard)
{
	if (count == MAX_SIZE)
	{
		std::stringstream ss;
		ss << "SideDeck: Max amount of cards in stack reached\nFile: " << __FILE__ << "\nLine: " << __LINE__ << "\n";
		throw std::runtime_error(ss.str());
	}
	Stack[count] = addCard;
	count++;
}

Card* SideDeck::Rem()
{
	if (count == 0)
	{
		std::stringstream ss;
		ss << "SideDeck: No cards to remove\nFile: " << __FILE__ << "\nLine: " << __LINE__ << "\n";
		throw std::runtime_error(ss.str());
	}
	Card* res = Stack[count-1];
	Stack[count - 1] = nullptr;
	count--;
	return res;
}

int   SideDeck::Size()
{
	return count;
}