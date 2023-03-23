#include "Player.h"
#include <iostream>

/*
do actions takes care of user interface to ensure an end result of editing the cache
to reflect what the user wants to play on this round

requirements:
1) Deals with all user interface for a turn
2) At return of DoActions there must be AT LEAST ONE CARD in the cache

*/
void Player::DoActions()
{
	std::string input;
	cache[0] = MainDeck.Rem();

	if (PlayerType == ai)return;
	
	
	std::cout << "Your card has been drawn";
	if (!cache[0])
	{
		std::cout << " from your stashed cards.\n";
		cache[0] = Stash.Rem();
	}
	else
	{
		std::cout << ".\n";
	}

	std::cout << "Would you like to peek ? :";
	std::cin >> input;
	std::cout << "\n";

	if (toupper(input[0]) == 'Y')
	{
		std::cout << "Your Card is: " << cache[0]->GetFace() << " of " << cache[0]->GetSuit() << "\n";
	}
	if (MainDeck.Size() > 0 && Stash.Size() < 5)
	{
		std::cout << "Do you want to stash this card? :";
		std::cin >> input;
		std::cout << "\n";
		if (toupper(input[0]) == 'Y')
		{
			Stash.Add(cache[0]);
			cache[0] = MainDeck.Rem();
		}
		else if (Stash.Size() > 0)
		{
			std::cout << "Do you want to take a card from your stash? :";
			std::cin >> input;
			std::cout << "\n";
			if (toupper(input[0]) == 'Y')
			{
				cache[1] = Stash.Rem();
			}
		}
	}


	std::string plural = cache[1] ? "s " : " ";
	std::string pluralp2 = cache[1] ? "are" : "is";
	std::cout << "The card" << plural << "you are playing this round " << pluralp2 << " : \n";
	std::cout << "1) The " << cache[0]->GetFace() << " of " << cache[0]->GetSuit() << "\n";
	if(cache[1])std::cout << "2) The " << cache[1]->GetFace() << " of " << cache[1]->GetSuit() << "\n";
	std::cout << "\n";
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
	if (cache[0])
	{
		total += cache[0]->GetValue();
		if (cache[1])total += cache[0]->GetValue();
	}
	return total;
}