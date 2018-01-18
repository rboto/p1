#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstdlib>
//#include <WinBase.h>
using namespace std;

//a inventar cenas dos refs 073 e afins
//declarações
struct livro
{
	long num;
	char nome[30];
	char autor[30];
	float valor;
};

struct livro liv;

//ref 073

FILE *fp;

char ch;


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
	
	
	// abertura do ficheiro para escrita-append 

	fp = fopen("dados.dat", "a");
	//dormir aqui? Sleep(3000);
	if (fp == NULL)
	{
		cout << "ERRO!\nO Ficheiro não foi aberto.\n" << endl;

		cout << "\n\nDigite uma tecla para terminar Programa\n" << endl;

		cout.flush();
		//fflush(stdin);
		ch = getchar();

		exit(0);
	}

	// se cheguei a esta parte do programa é que está tudo bem

	/*cout << "\n\nClique em ESC para sair\n\n" << endl;
	cout << "\t ou em outra tecla para novo registo\n\n" << endl;
	cout.flush();*/

	//fflush(stdin);
	if (_getch() != 27)
		do
		{
			// ler os dados de cada registo e a seguir carregá-lo no 
			// ficheiro binário
			// repetir até que se digite a tecla ESC

			system("cls");

			printf("\n\nDigite o ISBN do livro: ");
			fflush(stdin);
			scanf("%ld", &liv.num);

			printf("\n\nDigite o Titulo do livro: ");
			fflush(stdin);
			gets_s(liv.nome);

			printf("\n\nDigite o Autor do livro: ");
			fflush(stdin);
			gets_s(liv.autor);

			printf("\n\nDigite o valor do livro: ");
			fflush(stdin);
			scanf("%f", &liv.valor);

			// os args do comando fwrite são:
			//
			// o endereço da variável da estrutura, o tamanho da 
			// estrutura em bytes, o numero de registos a gravar
			// e o ponteiro associado ao ficheiro

			fwrite(&liv, sizeof(liv), 1, fp);

			printf("\n\nClique em ESC para sair\n\n");
			printf("\t ou em outra tecla para novo registo\n\n");

			fflush(stdin);
		} while (_getch() != 27);


		// fecha ficheiro que estava aberto para escrita-append

		fclose(fp);

		



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

	// abre agora o ficheiro para leitura

	fp = fopen("dados.dat", "r");

	// enquanto houverem registos imprimir cada um para o ecrã

	while (fread(&liv, sizeof(liv), 1, fp))
	{
		printf("\n\n\nISBN: %ld", liv.num);

		printf("\nNome: %s", liv.nome);

		printf("\nAutor: %s", liv.autor);

		printf("\nValor: %4.2f", liv.valor);
	}


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
	//aceitar chars portugueses
	setlocale(LC_ALL, "Portuguese");

	//validar se precisamos de repetir o menu
	bool repetirmenu = true;
	
	//repete o menu em loop
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
		}		
	}

	







	system("PAUSE");
	return 0;
		
};