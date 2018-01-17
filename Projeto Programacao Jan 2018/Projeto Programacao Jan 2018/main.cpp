#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;

//funções
int listar() {
	cout << "######################" << endl;
	cout << "\n\t\tOpção Listar" << endl;
	cout << "\n######################" << endl;
	return 0;
};

int inserir() {
	cout << "######################" << endl;
	cout << "\n\t\tOpção Inserir" << endl;
	cout << "\n######################" << endl;
	return 0;
};

int alterar() {
	cout << "######################" << endl;
	cout << "\n\t\tOpção Alterar" << endl;
	cout << "\n######################" << endl;
	return 0;
};

int consultar() {
	cout << "######################" << endl;
	cout << "\n\t\tOpção Cosultar" << endl;
	cout << "\n######################" << endl;
	return 0;
};

int eliminar() {
	cout << "######################" << endl;
	cout << "\n\t\tOpção Eliminar" << endl;
	cout << "\n######################" << endl;
	return 0;
}



//menu
bool menu() {

	cout << "######################" << endl;
	cout << "\nBem-vindo ao nosso projeto de programacao Janeiro 2018" << endl;
	cout << "\n######################" << endl;
	cout << "\nSeleccione a sua opção:" << endl;
	cout << "\n\t1. Listar" << endl;
	cout << "\n\t2. Inserir" << endl;
	cout << "\n\t3. Alterar" << endl;
	cout << "\n\t4. Consultar" << endl;
	cout << "\n\t5. Eliminar" << endl;

	//apanhar a escolha
	char escolhamenu;
	cin >> escolhamenu;

	switch (escolhamenu)
	{
	case 1:
		cout << "1. Listar";

		break;
	case 2:
		cout << "2. Inserir";

		break;
	case 3:
		cout << "3. Alterar";

		break;
	case 4:
		cout << "4. Consultar";

		break;
	case 5:
		cout << "5. Eliminar";

		break;
	default:
		cout << "Não escolheu uma opção válida. Tente novamente \n";
		cin >> escolhamenu;
		break;
	}
	return true;
};


int main() {
	setlocale(LC_ALL, "Portuguese");

	//loop para voltar sempre ao inicio	depois de escolher qualquer coisa
	while (!menu()) {		
		cout << "\nNão escolheu uma opção válida. Tente novamente" << endl;
		system("PAUSE");
	}
	cout << endl << "##########  Salta fora ##########" << endl;
	system("PAUSE");
	return 0;
};
