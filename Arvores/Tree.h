#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template <typename T> 
class Tree
{
	private:
		Node<T>* root;
		void insertNodeHelp(Node<T>**, const T&);//Auxiliar para inserir um noh
		void printPreOrderHelp(Node<T>*)const;
	public:
		Tree();
		void insertNode(const T&);//Inserir um noh
		void printPreOrder()const;

};

template <typename T>
Tree<T>::Tree() {
	root = nullptr;
}

template <typename T>
void Tree<T>::insertNode(const T &value) {
	insertNodeHelp(&root, value);
}

template <typename T>
void Tree<T>::insertNodeHelp(Node<T> **currentNode, const T &value) {
	if (*currentNode == nullptr) {
		*currentNode = new Node<T>(value);
	}
	else {
		if (value < (*currentNode)->data) {
			insertNodeHelp(&((*currentNode)->nodeLeft), value);
		}
		else if (value > (*currentNode)->data) {
			insertNodeHelp(&((*currentNode)->nodeRight), value);
		}
		else {
			cout << "Ops! "<<value << " Duplicado!" << endl;
		}
	}
}

template <typename T>
void Tree<T>::printPreOrder()const {
	printPreOrderHelp(root);
}

template <typename T>
void Tree<T>::printPreOrderHelp(Node<T> *currentNode)const {
	if (currentNode != nullptr) {
		cout <<"("<< currentNode->getData();
		printPreOrderHelp(currentNode->nodeLeft);
		printPreOrderHelp(currentNode->nodeRight);
		cout << ")";
	}
	else {
		cout << "()";
	}

}

