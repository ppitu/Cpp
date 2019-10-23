#ifndef LISTAJEDNOKIERUNKOWA_HPP_
#define LISTAJEDNOKIERUNKOWA_HPP_

#include <iostream>

template <typename T>
struct ElementList
{
	T data;
	struct ElementList *next;

	ElementList(T element, ElementList *ptr = nullptr)
	{
		data = element;
		next = ptr;
	}
};

template <typename T>
class ListaJednokierunkowa
{
	public:
		ListaJednokierunkowa()
		{
			head = tail = nullptr;
		}
		~ListaJednokierunkowa();
		T isEmpty()
		{
			return head == nullptr;
		}
		void addToHead(T );
		void addToTail(T );
		T deleteFromHead(); //usuniecie z poczatku i zwrocenie wartosci 
		T deleteFromTail(); //usunuecie z konca i zwrocenie wartosc
		void deleteNode(T );
		bool isInList(T ) const;
		void print() const;
		
	private:
		ElementList<T> *head, *tail;

};

template <typename T>
ListaJednokierunkowa<T>::~ListaJednokierunkowa()
{
	for(ElementList<T> *p; !isEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
}

template <typename T>
void ListaJednokierunkowa<T>::addToHead(T element)
{
	head = new ElementList<T>(element, head);
	if(tail == nullptr)
		tail = head;
}

template <typename T>
void ListaJednokierunkowa<T>::addToTail(T element)
{
	if(tail != nullptr) //jesli lista nie jest pusta
	{
		tail->next = new ElementList<T>(element);
		tail = tail->next;
	}
	else
		head = tail = new ElementList<T>(element);
}

template <typename T>
void ListaJednokierunkowa<T>::print() const
{
	for(ElementList<T> *tmp = head; tmp != nullptr; tmp = tmp->next)
		std::cout << tmp->data << " ";
	std::cout << std::endl;
}

template <typename T>
T ListaJednokierunkowa<T>::deleteFromHead()
{
	T element = head->data;
	ElementList<T> *tmp = head;
	if(head == tail) //jesli zawiera jeden wezel
		head = tail = nullptr;
	else	
		head = head->next;
	delete tmp;
	return element;
}

template <typename T>
T ListaJednokierunkowa<T>::deleteFromTail()
{
	T element = tail->data;
	if(head == tail) //jesli zawiera jeden element
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		ElementList<T> *tmp;
		for(tmp = head; tmp->next != tail; tmp = tmp->next); //znajdz poprzednik elementu ostatniego
		delete tail;
		tail = tmp;
		tail->next = nullptr;
	}
	return element;
}

template <typename T>
void ListaJednokierunkowa<T>::deleteNode(T element)
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
			ElementList<T> *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			ElementList<T> *pred, *tmp;
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

template <typename T>
bool ListaJednokierunkowa<T>::isInList(T element) const
{
	ElementList<T> *tmp;
	for(tmp = head; tmp != nullptr && !(tmp->data == element); tmp = tmp->next);
	return tmp != nullptr;
}

#endif //LISTAJEDNOKIERUNKOWA_HPP_
