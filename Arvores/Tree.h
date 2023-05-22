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
		void printInOrderHelp(Node<T>*)const;
		void printPosOrderHelp(Node<T>*)const;
		void printDefaultHelp(Node<T>*, int, bool)const;
		int countNodeHelp(Node<T>*)const;
	public:
		Tree();
		void insertNode(const T&);//Inserir um noh
		void printPreOrder()const;
		void printInOrder()const;
		void printPosOrder()const;
		void printDefault()const;
		int countNode()const;

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
	//Imprime em pre-ordem
	if (currentNode != nullptr) {
		cout <<"("<< currentNode->getData();
		printPreOrderHelp(currentNode->nodeLeft);
		printPreOrderHelp(currentNode->nodeRight);
		cout << ")";
	}
	else {
		cout << "*";
	}
}


template <typename T>
void Tree<T>::printInOrder()const {
	printInOrderHelp(root);
}

template <typename T>
void Tree<T>::printInOrderHelp(Node<T> *currentNode)const {
	//Imprime em ordem
	if (currentNode != nullptr) {
		cout << "(";
		printInOrderHelp(currentNode->nodeLeft);
		cout << currentNode->getData();
		printInOrderHelp(currentNode->nodeRight);
		cout << ")";
	}
	else {
		cout << "*";
	}
}

template <typename T>
void Tree<T>::printPosOrder()const {
	printPosOrderHelp(root);
}

template <typename T>
void Tree<T>::printPosOrderHelp(Node<T> *currentNode)const {
	//Imprime em pos-ordem
	if (currentNode != nullptr) {
		cout << "(";
		printPosOrderHelp(currentNode->nodeLeft);
		printPosOrderHelp(currentNode->nodeRight);
		cout << currentNode->getData();
		cout << ")";
	}
	else {
		cout << "*";
	}
}

template <typename T>
void Tree<T>::printDefault()const {
	printDefaultHelp(root, 0, false);
}

template <typename T>
void Tree<T>::printDefaultHelp(Node<T> *currentNode, int level, bool left)const {
	//Imprime em arvore na horizontal
	
	if (currentNode == NULL) {
		return;
	}

	printDefaultHelp(currentNode->nodeRight, level+1, false);
	
	for (int i = 0; i < level - 1; i++) {
		cout.width(4);
		cout << "  |";
	}

	if (level > 0) {
		cout.width(4);
		cout.fill('-');
		cout << "+";
		cout.fill(' ');
	}
	cout <<"("<< currentNode->getData()<<")"<< endl;

	printDefaultHelp(currentNode->nodeLeft, level + 1, true);
}

template <typename T>
int Tree<T>::countNode()const {
	return countNodeHelp(root);
}

template <typename T>
int Tree<T>::countNodeHelp(Node<T> *currentNode)const {
	
	if (currentNode == NULL) {
		return 0;
	}
	
	return 1 + countNodeHelp(currentNode->nodeRight) + countNodeHelp(currentNode->nodeLeft);

}

