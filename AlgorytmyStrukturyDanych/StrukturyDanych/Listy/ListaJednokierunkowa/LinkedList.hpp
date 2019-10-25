#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>

template <typename T>
struct Element
{
	T data;
	struct Element* next;

	Element(T data, Element<T> *ptr = nullptr)
	{
		this->data = data;
		next = ptr;
	}
};

template <typename T>
class LinkedList
{
	public:
		LinkedList()
		{
			head = nullptr;
		}

		LinkedList(const LinkedList &);
		LinkedList(LinkedList &&);		

		LinkedList & operator= (LinkedList & list)
		{
			std::swap(list.head, head);
			return *this;
		}
		

		void addToHead(T );
		void addToTail(T );
		void display();	
		void deleteFromHead();
		void deleteFormTail();

	private:
		Element<T> *head, *tail;
};

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & list)
{
	head = tail = nullptr;

	for(Element<T> *tmp = list.head; tmp != nullptr; tmp = tmp->next)
	{
		addToHead(tmp->data);
	}
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> && list)
{
	head = list.head;
	list.head = nullptr;
	tail = list.tail;
	list.tail = nullptr;
}

template <typename T>
void LinkedList<T>::addToHead(T data)
{
	head = new Element<T>(data, head);
	if(tail == nullptr)
		tail = head;
}

template <typename T>
void LinkedList<T>::addToTail(T data)
{
	if(head == nullptr)
	{
		head = tail = new Element<T>(data);
		return;
	}

	tail->next = new Element<T>(data);
	tail = tail->next;
}

template <typename T>
void LinkedList<T>::display()
{
	if(head == nullptr)
	{
		std::cout << "Brak elementow" << std::endl;
		return;
	}

	for(Element<T> *tmp = head; tmp != nullptr; tmp = tmp->next)
		std::cout << tmp->data << " ";
	std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::deleteFromHead()
{
	if(head == nullptr)
		return;

	Element<T> *tmp = head;

	head = head->next;

	delete tmp;
}

#endif //LINKEDLIST_HPP_
