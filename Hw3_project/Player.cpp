#include "Player.h"

/*
do actions takes care of user interface to ensure an end result of editing the cache
to reflect what the user wants to play on this round

requirements:
1) Deals with all user interface for a turn
2) At return of DoActions there must be AT LEAST ONE CARD in the cache

*/
void Player::DoActions()
{
	if (PlayerType == ai) cache[0] = MainDeck.Rem();
}

void Player::GiveCardsFromPlayer(Player &p)
{
	MainDeck.Add(p.cache[0]);
	p.cache[0] = nullptr;
	if (!p.cache[1]) return;
	MainDeck.Add(p.cache[1]);
	p.cache[1] = nullptr;
}

void Player::ReturnCachedCards()
{
	GiveCardsFromPlayer(*this);
}

int Player::GetCachedSum()
{
	int total = 0;
	if (!cache[0])
	{
		total += cache[0]->GetValue();
		if (!cache[1])total += cache[0]->GetValue();
	}
	return total;
}