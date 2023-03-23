#pragma once
#include "Card.h"

class ListInterface
{
public:
	virtual void  Add(Card*) = 0;
	virtual Card* Rem() = 0;
	virtual int   Size() = 0;
};