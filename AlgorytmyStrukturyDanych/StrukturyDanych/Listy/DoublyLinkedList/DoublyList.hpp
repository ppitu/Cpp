#ifndef DOUBLYLINKED_HPP_
#define DOUBLYLINKED_HPP_

#include <iostream>
#include <memory>

template <typename T>
class DoublyLinked
{
	public:


	private:
		struct Node
		{
			T data;
			std::shared_ptr<Node> next;
			std::shared_ptr<Node> prev;

			Node(data, 		
		}
};

#endif //DOUBLYLINKED_HPP_
