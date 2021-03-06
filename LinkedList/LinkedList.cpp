#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "Node.cpp"
#include <iostream>

template<class T>
// Acts as a stack, push/pop
class LinkedList {
	Node<T>* head;
public:
	LinkedList(Node<T>* head_) : head(head_) {}

	~LinkedList() {
		// Free memory
		Node<T>* tmp = this->head;

		while (this->head != nullptr) {
			tmp = this->head;
			this->head=this->head->getNext();
			delete(tmp);
			tmp = nullptr;
		}
	}

	inline Node<T>* getHead() {
		return this->head;
	}

	inline void setHead(Node<T>* newHead) {
		this->head = newHead;
	}

	void printList() {
		Node<T>* tmp = this->head;

		while (tmp != nullptr) {
			tmp->printData();
			tmp=tmp->getNext();
		}
		std::cout << std::endl;
	}

	void printList(Node<T>* head) {
		Node<T>* tmp = head;

		while (tmp != nullptr) {
			tmp->printData();
			tmp=tmp->getNext();
		}
		std::cout << std::endl;
	}

	// Performs a 'push'
	void addNode(Node<T>* newNode) {
		Node<T>* tmp = head;
		head = newNode;
		newNode->setNext(tmp);
	}

	// Performs a 'pop'
	void removeNode() {
		Node<T>* tmp = head;
		head = head->getNext();
		delete(tmp); // delete heap allocated objects
		tmp = nullptr;
	}
};
#endif