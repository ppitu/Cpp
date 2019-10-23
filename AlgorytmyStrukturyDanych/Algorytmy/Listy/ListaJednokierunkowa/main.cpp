#include <iostream>

#include "listajednokierunkowa.hpp"

int main()
{
	ListaJednokierunkowa<double> x1;
	
	x1.addToHead(1.1);
	x1.addToHead(2);
	x1.addToTail(3);
	x1.addToHead(5);
	x1.addToTail(10);
	x1.addToTail(15);
	x1.print();
	x1.deleteFromHead();
	x1.deleteFromTail();
	x1.print();
	x1.deleteNode(3);
	x1.print();
}
