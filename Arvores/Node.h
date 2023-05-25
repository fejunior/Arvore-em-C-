#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Node
{
	private:
		T data;
		Node<T> *nodeLeft;
		Node<T> *nodeRight;
		int subtreeHeight(Node<T>*);
	public:
		Node(const T&);
		T getData();
		void setLeft(Node<T>*);
		void setRight(Node<T>*);
		Node<T>* getLeft();
		Node<T>* getRight();
		int balanceFactor();
		int nodeHeight();
		
};

template <typename T>
Node<T>::Node(const T &value) {
	data = value;
	nodeLeft = nullptr;
	nodeRight = nullptr;
}

template <typename T>
T Node<T>::getData() {
	return data;
}

template <typename T>
void Node<T>::setLeft(Node<T>* left) {
	nodeLeft= left;
}

template <typename T>
void Node<T>::setRight(Node<T>* right) {
	nodeRight = right;
}

template <typename T>
Node<T>* Node<T>::getLeft() {
	return nodeLeft;
}

template <typename T>
Node<T>* Node<T>::getRight() {
	return nodeRight;
}

template <typename T>
int Node<T>::balanceFactor() {
	
	return subtreeHeight(nodeLeft) - subtreeHeight(nodeRight);
}

template <typename T>
int Node<T>::nodeHeight() {
	
	return subtreeHeight(this) ;
}

template <typename T>
int Node<T>::subtreeHeight(Node<T>* node) {

	if (node == nullptr) {
		return -1;
	}

	int heightLeft  = subtreeHeight(node->getLeft());
	int heigthRight = subtreeHeight(node->getRight());

	return max(heightLeft, heigthRight)+1;
}