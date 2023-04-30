// Arvores.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "tree.h"

int main()
{
	Tree<int> intTree;
	int value;
	
	cout << "Digite 10 numeros para compor a arvore:\n";
	for (int i = 0; i < 10; i++)
	{//Le o valor e insere na arvore
		cin >> value;
		intTree.insertNode(value);
	}

	cout << "Imprimindo Arvore...\n";
	intTree.printPreOrder();
}
