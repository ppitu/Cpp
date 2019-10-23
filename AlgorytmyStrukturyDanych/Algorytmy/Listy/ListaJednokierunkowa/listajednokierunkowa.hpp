#ifndef LISTAJEDNOKIERUNKOWA_HPP_
#define LISTAJEDNOKIERUNKOWA_HPP_

#include <iostream>

struct ElementList
{
	int data;
	struct ElementList *next;

	ElementList(int element, ElementList *ptr = nullptr)
	{
		data = element;
		next = ptr;
	}
};

class ListaJednokierunkowa
{
	public:
		ListaJednokierunkowa()
		{
			head = tail = nullptr;
		}
		~ListaJednokierunkowa();
		int isEmpty()
		{
			return head == nullptr;
		}
		void addToHead(int );
		void addToTail(int );
		int deleteFromHead(); //usuniecie z poczatku i zwrocenie wartosci 
		int deleteFromTail(); //usunuecie z konca i zwrocenie wartosc
		void deleteNode(int);
		bool isInList(int) const;
		void print() const;
		
	private:
		ElementList *head, *tail;

};

ListaJednokierunkowa::~ListaJednokierunkowa()
{
	for(ElementList *p; !isEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
}

void ListaJednokierunkowa::addToHead(int element)
{
	head = new ElementList(element, head);
	if(tail == nullptr)
		tail = head;
}

void ListaJednokierunkowa::addToTail(int element)
{
	if(tail != nullptr) //jesli lista nie jest pusta
	{
		tail->next = new ElementList(element);
		tail = tail->next;
	}
	else
		head = tail = new ElementList(element);
}

void ListaJednokierunkowa::print() const
{
	for(ElementList *tmp = head; tmp != nullptr; tmp = tmp->next)
		std::cout << tmp->data << " ";
	std::cout << std::endl;
}

int ListaJednokierunkowa::deleteFromHead()
{
	int element = head->data;
	ElementList *tmp = head;
	if(head == tail) //jesli zawiera jeden wezel
		head = tail = nullptr;
	else	
		head = head->next;
	delete tmp;
	return element;
}

int ListaJednokierunkowa::deleteFromTail()
{
	int element = tail->data;
	if(head == tail) //jesli zawiera jeden element
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		ElementList *tmp;
		for(tmp = head; tmp->next != tail; tmp = tmp->next); //znajdz poprzednik elementu ostatniego
		delete tail;
		tail = tmp;
		tail->next = nullptr;
	}
	return element;
}

void ListaJednokierunkowa::deleteNode(int element)
{
	if(head != nullptr) //jesli lista nie jest pusta
	{
		if(head == tail && element == head->data) //jesli zawiera tylko jeden element
		{
			delete head;
			head = tail = nullptr;
		}
		else if(element == head->data) //jesli lista zawiera ponad jeden element
		{
			ElementList *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			ElementList *pred, *tmp;
			for(pred = head, tmp = head->next; tmp != nullptr && !(tmp->data); pred = pred->next, tmp = tmp->next);
			if(tmp != nullptr)
			{
				pred->next = tmp->next;
				if(tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
	}
}

bool ListaJednokierunkowa::isInList(int element) const
{
	ElementList *tmp;
	for(tmp = head; tmp != nullptr && !(tmp->data == element); tmp = tmp->next);
	return tmp != nullptr;
}

#endif //LISTAJEDNOKIERUNKOWA_HPP_
