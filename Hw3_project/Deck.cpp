#include "Deck.h"
#include <exception>
#include <random>
#include <time.h>
#include <sstream>

Deck::Deck()
{
	int suit, value;
	for (suit = 0; suit < 4; suit++)
	{
		for (value = 1; value < 14; value++)
		{
			Add(new Card(value, (Card::suits)suit));
		}
	}
	if( count <=0 )
	{
		std::stringstream ss;
		ss << "Deck: Empty deck after init\nFile: " << __FILE__ << "\nLine: " << __LINE__ << "\n";
		throw std::runtime_error(ss.str());
	}
	for (int i = 0; i < 10000; i++)
	{
		swap(rand()%(count-1), rand()%(count - 1));
	}
}

void Deck::swap(int a, int b)
{
	if (a == b)return;
	Node *ptrchange1 = Head, *ptrchange2 = Head;

	for (int i = 0; i < a; i++)
	{
		ptrchange1 = ptrchange1->getNext();
	}
	for (int i = 0; i < b; i++)
	{
		ptrchange2 = ptrchange2->getNext();
	}

	Card* swaptemp = ptrchange1->getValue();
	ptrchange1->setValue(ptrchange2->getValue());
	ptrchange2->setValue(swaptemp);

}

void Deck::Add(Card* addCard)
{
	if (!Head)
	{
		Head = new Node(addCard);
		Tail = Head;
	}
	else
	{
		Tail->setNext(new Node(addCard));
		Tail = Tail->getNext();
	}
	count++;
}

Card* Deck::Rem()
{
	Card* res = Head->getValue();
	Node* temp = Head;
	Head = Head->getNext();
	count--;
	delete temp;
	return res;
}

int Deck::Size()
{
	return count;
}