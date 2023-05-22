// Arvores.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "tree.h"

int main()
{
	Tree<int> intTree;
	int value, choice=1;
	
	cout << "#### JUNONN LAB TREE ####\n";
	

	while (choice != 0) {
		intTree.printDefault();
		cout<<"\n-----------------------\n";
		cout << "#0 Sair\n#1 Inserir\n#2 Imprimir Pre-Ordem"
			<< "\n#3 Imprimir em Ordem\n#4 Imprimir Pos-Ordem\n"
			<< "\n#5 Quantidade de noh\n#6 Imprimir Pos-Ordem\n"<<
			"-----------------------\n";

		cout << "\nEscolha uma opcao: ";
		cin >> choice;
		system("cls");
		
		
		switch (choice)
		{
			case 1:
				cout << "#Digite um valor: ";
				cin >> value;
				intTree.insertNode(value);
				break;
			case 2:
				cout << "Imprimindo pre-ordem\n";
				intTree.printPreOrder();
				break;
			case 3:
				cout << "Imprimindo ordem\n";
				intTree.printInOrder();
				break;
			case 4:
				cout << "Imprimindo pos-ordem\n";
				intTree.printInOrder();
				break;
			case 5:
				cout << "Exite(m) "<<intTree.countNode()<<" noh(s)\n\n\n";
				break;

			default:
			break;
		}
	}

	cout << "Digite 10 numeros para compor a arvore:\n";
	for (int i = 0; i < 10; i++)
	{//Le o valor e insere na arvore
	}

	cout << "Imprimindo Arvore...\n";
	intTree.printPreOrder();
}
