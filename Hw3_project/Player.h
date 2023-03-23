#pragma once
#include "Card.h"
#include "Deck.h"
#include "SideDeck.h"

class Player
{
public:
	enum type { user, ai };

private:
	type PlayerType;
	Deck MainDeck;
	SideDeck Stash;
	Card* cache[2]{ nullptr };

public:
	
	Player(type pType = ai) : PlayerType(pType) {};
	void DoActions();
	bool HasCards() { return MainDeck.Size() > 0 || Stash.Size() > 0 };
	void GiveCardsFromPlayer(Player &p);
	void ReturnCachedCards();
	int GetCachedSum();
};

