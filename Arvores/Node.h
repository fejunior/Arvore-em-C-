#pragma once
template <typename T> class Tree;//Declaração da classe Arvore

template <typename T>
class Node
{
	friend class Tree<T>;//Permite a classe Tree acessar os atributos privados da classe Node 
	private:
		T data;
		Node<T> *nodeLeft;
		Node<T> *nodeRight;
	public:
		Node(const T&);
		T getData();
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

