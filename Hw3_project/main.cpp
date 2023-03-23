#include "Card.h"
#include "Deck.h"
#include "SideDeck.h"
#include "Player.h"

#include <iostream>
#include <string>

int CompareResult(Player& p1, Player& p2)
{
	if (p1.GetCachedSum() > p2.GetCachedSum())return 0;
	if (p1.GetCachedSum() < p2.GetCachedSum())return 1;
	return -1;
}

int main()
{
	Player Human(Player::type::user), Computer(Player::type::ai);
	while (Human.HasCards() && Computer.HasCards())
	{
		Human.DoActions();
		Computer.DoActions();

		// winner is 0 if human wins 1 if computer wins and -1 if tie
		int winner = CompareResult(Human, Computer); 

		switch (winner)
		{
		case 1: // human wins
			Human.GiveCardsFromPlayer(Computer);
			break;
		case 2: // computer wins
			Computer.GiveCardsFromPlayer(Human);
			break;
		default: // tie
			Human.ReturnCachedCards();
			Computer.ReturnCachedCards();
			break;
		}

	}

	std::string winner = Human.HasCards() ? "human" : "computer";
	std::cout << "The " << winner << " has won!\n";
	if (winner == "computer")std::cout << "Maybe next time :/";
	return 0;
}