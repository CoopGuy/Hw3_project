#pragma once
#include "ListInterface.h"

// stack must be implemented using array
class SideDeck : ListInterface
{
private:
	Card** Stack;
	int count;
	const int MAX_SIZE;
public:
	SideDeck(int maxsize = 5) : MAX_SIZE(maxsize)
	{
		Stack = new Card * [maxsize];
		count = 0;
	}
	void  Add(Card* addCard);
	Card* Rem();
	int   Size();
};

