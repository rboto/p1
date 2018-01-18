#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstdlib>
using namespace std;

//funções
int listar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Listar" << endl;
	cout << "\n######################" << endl;
	system("PAUSE");
	return 0;
};

int inserir() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Inserir" << endl;
	cout << "\n######################" << endl;
	system("PAUSE");
	return 0;
};

int alterar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Alterar" << endl;
	cout << "\n######################" << endl;
	system("PAUSE");
	return 0;
};

int consultar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Cosultar" << endl;
	cout << "\n######################" << endl;
	system("PAUSE");
	return 0;
};

int eliminar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Eliminar" << endl;
	cout << "\n######################" << endl;
	system("PAUSE");
	return 0;
}





int main() {
	setlocale(LC_ALL, "Portuguese");

	
	bool repetirmenu = true;

	while (repetirmenu = true) {
		int escolhamenu;
		system("cls");
		cout << "######################" << endl;
		cout << "\nBem-vindo ao nosso projeto de programacao Janeiro 2018" << endl;
		cout << "\n######################" << endl;
		cout << "\nSeleccione a sua opção:" << endl;
		cout << "\n\t1. Listar" << endl;
		cout << "\n\t2. Inserir" << endl;
		cout << "\n\t3. Alterar" << endl;
		cout << "\n\t4. Consultar" << endl;
		cout << "\n\t5. Eliminar" << endl;		
		cout << "\n\tOpção: ";
		cin >> escolhamenu;

		//Marcos a testar - validação do input. o objetivo é só conseguir inserir numeros e não outros chars
		if (cin.fail()) {
			system("cls");
			cout << "erro";
			cin.clear();
			system("pause");
		}
		else {

			switch (escolhamenu) {
				case 1:
					listar();

					break;
				case 2:
					inserir();

					break;
				case 3:
					alterar();

					break;
				case 4:
					consultar();

					break;
				case 5:
					eliminar();

					break;
				default:
					cout << "Não escolheu uma opção válida. Tente novamente." << endl;
					system("pause");

			}
			cout << repetirmenu;
			//system("pause");
		}
		cout << repetirmenu;
		//system("pause");
	}
	system("PAUSE");
	return 0;
		
};