#pragma once
#include "ListInterface.h"

// queue must be implemented using linked list
class Deck : ListInterface
{
private:
	class Node {
	private:
		Card* value;
		Node* next;
	public:
		Node(Card* v = nullptr, Node* n = nullptr) : value(v), next(n) {};

		void setValue(Card* val) { value = val; };
		void setNext(Node* val) { next = val; };
		Card* getValue() { return value; };
		Node* getNext() { return next; };
		Node** getNextAddr() { return &next; };
	};

private:
	Node* Head;
	Node* Tail;
	int count;
	void swap(int a, int b);
public:
	Deck();
	void Add(Card*) override;
	Card* Rem() override;
	int Size() override;
};

