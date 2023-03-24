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

	for (int i = 0; i < 100000; i++)
	{
		swap(rand()%(count - 1), rand()%(count - 1));
	}
}

void Deck::swap(int a, int b)
{
	if (a == b)return;
	if (a > b)
	{
		int t = a;
		a = b;
		b = t;
	}
	Node** ptrchange1 = &Head, ** ptrchange2 = &Head;

	for (int i = 0; i < a; i++) ptrchange1 = (*ptrchange1)->getNextAddr();
	for (int i = 0; i < b; i++) ptrchange2 = (*ptrchange2)->getNextAddr();

	Node* nextof1 = (*ptrchange1)->getNext();
	Node* nextof2 = (*ptrchange2)->getNext();
	Node* refto2 = *ptrchange2;

	(*ptrchange2)->setNext(nextof1);
	(*ptrchange1)->setNext(nextof2);

	if (refto2 == refto2->getNext())refto2->setNext(*ptrchange1);
	else *ptrchange2 = *ptrchange1;

	*ptrchange1 = refto2;
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