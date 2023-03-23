#include "Card.h"
#include "Deck.h"
#include "SideDeck.h"
#include "Player.h"

#include <iostream>
#include <string>













int main()
{
	Player Human, Computer;
	while (Human.HasCards() && Computer.HasCards())
	{
		Human.DoActions();
		Computer.DoActions();

		// winner is 0 if human wins 1 if computer wins and -1 if tie
		int winner = CompareResult(Human, Computer); 

		// human wins
		if (winner == 0) Human.GiveCardsFromPlayer(Computer);

		// computer wins
		else if (winner == 1) Computer.GiveCardsFromPlayer(Human);

		// tie
		else 
		{
			Human.ReturnCachedCards();
			Computer.ReturnCachedCards();
		}
	}

	std::string winner = Human.HasCards() ? "human" : "computer";
	std::cout << "The " << winner << " has won!\n";
	if (winner == "computer")std::cout << "Maybe next time :/";
	return 0;
}