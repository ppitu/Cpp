#include <iostream>

#include "LinkedList.hpp"

int main()
{
	LinkedList<int> x1;

	x1.addToTail(14);

	x1.addToHead(1);
	x1.addToHead(2);
	x1.addToTail(3);	

	x1.addToTail(100);
	
	x1.display();

	x1.deleteFromHead();
	
	x1.display();

	std::cout << "Tworzymy druga liste" << std::endl;

	LinkedList<int> x2(x1);

	x2.addToHead(34);

	x1.display();
	x2.display();

	std::cout << "Dopisanie do konca" << std::endl;
	
	x2 = x1;

	x2.display();

	std::cout << "Konstruktor przenoszacy" << std::endl;
		
	LinkedList<int> x3(std::move(x1));

	x3.display();
	x1.display();

	return 0;
}
