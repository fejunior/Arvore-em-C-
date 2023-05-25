#pragma once
#include "Node.h"


template <typename T> 
class Tree
{
	private:
		Node<T> *root;
		Node<T>* insertNodeHelp(Node<T>*, const T&);//Auxiliar para inserir um noh
		void printPreOrderHelp(Node<T>*)const;
		void printInOrderHelp(Node<T>*)const;
		void printPosOrderHelp(Node<T>*)const;
		void printDefaultHelp(Node<T>*, int, bool)const;
		int countNodeHelp(Node<T>*)const;
		bool treeIsEmpty()const;
		void checkBalanceHelper(Node<T>*)const;
		Node<T>* simpleLeftRotation(Node<T>*)const;
		Node<T>* doubleRightLeftRotation(Node<T>*)const;
		Node<T>* simpleRightRotation(Node<T>*)const;
		Node<T>* doubleLeftRightRotation(Node<T>*)const;
	public:
		Tree();
		void insertNode(const T&);//Inserir um noh
		void printPreOrder()const;
		void printInOrder()const;
		void printPosOrder()const;
		void printDefault()const;
		int countNode()const;
		void checkBalance()const;
		

};

template <typename T>
Tree<T>::Tree() {
	root = nullptr;
}

template <typename T>
void Tree<T>::insertNode(const T& value) {
	root = insertNodeHelp(root, value);
	checkBalanceHelper(root);
}

template <typename T>
Node<T>* Tree<T>::insertNodeHelp(Node<T>* currentNode, const T& value) {
	if (currentNode == nullptr) {
		return new Node<T>(value);
	}

	if (value < currentNode->getData()) {
		currentNode->setLeft(insertNodeHelp(currentNode->getLeft(), value));
	}
	else if (value > currentNode->getData()) {
		currentNode->setRight(insertNodeHelp(currentNode->getRight(), value));
	}
	else {
		cout << "Ops! " << value << " Duplicado!" << endl;
	}

	return currentNode;
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
		printPreOrderHelp(currentNode->getLeft());
		printPreOrderHelp(currentNode->getRight());
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
		printInOrderHelp(currentNode->getLeft());
		cout << currentNode->getData();
		printInOrderHelp(currentNode->getRight());
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
		printPosOrderHelp(currentNode->getLeft());
		printPosOrderHelp(currentNode->getRight());
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
	
	if (currentNode == nullptr) {
		return;
	}

	printDefaultHelp(currentNode->getRight(), level + 1, false);
	
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

	printDefaultHelp(currentNode->getLeft(), level + 1, true);
}

template <typename T>
int Tree<T>::countNode()const {
	return countNodeHelp(root);
}

template <typename T>
int Tree<T>::countNodeHelp(Node<T> *currentNode)const {
	
	if (currentNode == nullptr) {
		return 0;
	}
	
	return 1 + countNodeHelp(currentNode->getRight()) + countNodeHelp(currentNode->getLeft());

}

template <typename T>
bool Tree<T>::treeIsEmpty()const {
	return root == nullptr;
}

template <typename T>
void Tree<T>::checkBalanceHelper(Node<T>* node)const {
	int factorBalance = node->balanceFactor();

	if (factorBalance > 1) {
		//Peso maior para arvore a Direita 
		if (node->getRight()->balanceFactor() >= 0) {
			//Peso maior continua a direita 
		  node = simpleLeftRotation(node);
		}
		else {
			//Peso maior eh na esquerda
			node = doubleRightLeftRotation(node);
		}
	}
	else if (factorBalance < 0) {
		//Peso maior para a subarvore a esquerda
		if (node->getLeft()->balanceFactor() >= 0) {
			//Peso maior continua a esquerda 
			node = simpleRightRotation(node);
		}
		else {
			//Peso maior eh na direita
			node = doubleLeftRightRotation(node);
		}
	}

	if (node->getLeft()) { checkBalanceHelper(node->getLeft()); };
	if (node->getRight()) { checkBalanceHelper(node->getRight()); };

}

template <typename T>
Node<T> * Tree<T>::simpleRightRotation(Node<T>* node)const {
	Node<T>* newRoot = node->getLeft();
	node->setLeft(newRoot->getRight());
	newRoot->setRight(node);
	
	return newRoot;
}

template <typename T>
Node<T> * Tree<T>::simpleLeftRotation(Node<T>* node)const {
	Node<T>* newRoot = node->getRight();
	node->setRight(newRoot->getLeft());
	newRoot->setLeft(node);
	
	return newRoot;
}

template <typename T>
Node<T>* Tree<T>::doubleLeftRightRotation(Node<T>* node)const {
	
		node->setLeft(simpleLeftRotation(node->getLeft()));

		return simpleRightRotation(node);
}

template <typename T>
Node<T>* Tree<T>::doubleRightLeftRotation(Node<T>* node)const {

	node->setRight(simpleRightRotation(node->getRight()));

	return simpleLeftRotation(node);
}