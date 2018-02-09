#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>
//#include <errno.h> //livraria para deteção de erros
//#include <time.h>
//#include <WinBase.h>
using namespace std;


/*
Trabalho de grupo elaborado por (ordem alfabética)
Cátia Sousa nº
Edgar Basto nº
Marcos Campos nº 2222
Rui Boto nº

*/

struct livro
{
	long num;
	char nome[30];
	char autor[30];
	float valor;
};

struct livro liv;
FILE *fp;
char ch;

//funções

long atrisbn(FILE **fp, struct livro liv) {

	long isbn = 0;

	*fp = fopen("dados.dat", "r");

	while (fread(&liv, sizeof(liv), 1, *fp))
	{
		isbn++;
	}

	fclose(*fp);


	return isbn;
};


int procurar() {

	int salto;
	int encontralivro = 0;
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Procurar" << endl;
	cout << "\n######################" << endl;
	cout << endl << endl;
	cout << "1. Procurar por ISBN" << endl;
	cout << "2.Procurar por nome" << endl;
	cout << "Escolha a opção:" << endl;

	fp = fopen("dados.dat", "r");
	rewind(fp);

	switch (_getch()) {

	case '1':
		system("cls");
		printf("\n\n\nDigite o numero do registo que pretenda ler: ");
		fflush(stdin);
		scanf("%d", &salto);
		while (fread(&liv, sizeof(liv), 1, fp) == 1) {
			if (liv.num == salto) {
				printf("\nISBN: %ld", liv.num);
				printf("\nNome: %s", liv.nome);
				printf("\nAutor: %s", liv.autor);
				printf("\nValor: %4.2f\n\n\n", liv.valor);
				encontralivro = 1; //verificação se encontra	
			}

		}
		if (encontralivro != 1) {
			printf("\nISBN não encontrado.");
			printf("\nDeseja procurar novamente? (S/N)");
			if (_getch() == 's') {
				return procurar(); 
			}
			else {
				return 0;
		
			}
		}
		break;

	case '2':

		char nome_proc[30];
		system("cls");
		printf("\n\n\nDigite o nome do livro: ");
		fflush(stdin);
		fgets(nome_proc, 30, stdin);

		salto = 0;
		while (fread(&liv, sizeof(liv), 1, fp) == 1) {

			if (strcmp(liv.nome, nome_proc) == 0) {
				printf("\nISBN: %ld", liv.num);
				printf("\nNome: %s", liv.nome);
				printf("\nAutor: %s", liv.autor);
				printf("\nValor: %4.2f\n\n\n", liv.valor);
				salto++;
			}
		}
		if (salto == 0) {
			printf("\nNome não encontrado.");
			printf("\nDeseja procurar novamente? (S/N)");
			if (_getch() == 's') {
				return procurar();
			}
			else {
				return 0;
			
			}

		}


	}

	fclose(fp);

	system("PAUSE");
	return 0;
};

int inserir(long total, FILE **fp) {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Inserir" << endl;
	cout << "\n######################" << endl;	


	

	*fp = fopen("dados.dat", "a");
	

	
	if (*fp == NULL)
	{
		cout << "ERRO!\nO Ficheiro não foi aberto.\n" << endl;

		cout << "\n\nDigite uma tecla para terminar Programa\n" << endl;

		cout.flush();		
		ch = getchar();
		exit(0);
	}
		

		liv.num = ++total;			

			
		printf("\n\nDigite o Titulo do livro:");
		while (getchar() != '\n');
		fgets(liv.nome, 30, stdin);


		printf("\n\nDigite o Autor do livro: ");
		fflush(stdin);
		fgets(liv.autor, 30, stdin);


		printf("\n\nDigite o valor do livro: ");
		fflush(stdin);
		scanf("%f", &liv.valor);

			
		fwrite(&liv, sizeof(liv), 1, *fp);


		printf("\n\nLivro introduzido\n\n");

		fflush(stdin);

		fclose(*fp);


	system("PAUSE");
	return 0;
};

int alterar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Alterar" << endl;
	cout << "\n######################" << endl;
	cout << endl << endl;
	
	int salto;
	FILE *fp_tmp2;

	fp = fopen("dados.dat", "r");
	fp_tmp2 = fopen("tmp2.dat", "w");

	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Eliminar" << endl;
	cout << "\n######################" << endl;

	cout << "Introduza a ID do livro a alterar:" << endl;
	fflush(stdin);
	scanf("%d", &salto);


	if (fp == NULL)
	{
		cout << "ERRO!\nO Ficheiro não foi aberto.\n" << endl;

		cout << "\n\nDigite uma tecla para terminar Programa\n" << endl;

		cout.flush();
		ch = _getch();
		exit(0);
	} 

	while (fread(&liv, sizeof(liv), 1, fp) == 1){
		
		if(liv.num != salto){
			
			fwrite(&liv, sizeof(liv), 1, fp_tmp2);
			
		} else {
					
	
			printf("\n\nDigite o Titulo do livro:");
			while (getchar() != '\n');
			fgets(liv.nome, 30, stdin);

			printf("\n\nDigite o Autor do livro: ");
			fflush(stdin);
			fgets(liv.autor, 30, stdin);

			printf("\n\nDigite o valor do livro: ");
			fflush(stdin);
			scanf("%f", &liv.valor);
			
			fwrite(&liv, sizeof(liv), 1, fp_tmp2);

			printf("\n\nRegisto alterado.\n\n");

			fflush(stdin);
					
		}	
		
	}	

	fclose(fp);
	fclose(fp_tmp2);
	
	
	fp = fopen("dados.dat", "w");
	fp_tmp2 = fopen("tmp2.dat", "r");
	
	while (fread(&liv, sizeof(liv), 1, fp_tmp2) == 1){
		
		fwrite(&liv, sizeof(liv), 1, fp);		
		
	}
		
	fclose(fp);
	fclose(fp_tmp2);
	
	system("PAUSE");
	return 0;

	
}

int consultar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Consultar" << endl;
	cout << "\n######################" << endl;


	fp = fopen("dados.dat", "r");


	while (fread(&liv, sizeof(liv), 1, fp))
	{
		printf("\n\n\nISBN: %ld", liv.num);

		printf("\nNome: %s", liv.nome);

		printf("\nAutor: %s", liv.autor);

		printf("\nValor: %4.2f \n", liv.valor);
	}


	system("PAUSE");
	return 0;
}


int eliminar() {
	int regencontrado = 0;
	int salto;

	FILE *fp_tmp;

	fp = fopen("dados.dat", "r");
	fp_tmp = fopen("tmp.dat", "w");

	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Eliminar" << endl;
	cout << "\n######################" << endl;

	cout << "Introduza a ID do livro a apagar:" << endl;
	fflush(stdin);
	scanf("%d", &salto);


	if (fp == NULL)
	{
		cout << "ERRO!\nO Ficheiro não foi aberto.\n" << endl;

		cout << "\n\nDigite uma tecla para terminar Programa\n" << endl;

		cout.flush();
		ch = _getch();
		exit(0);
	} 

	while (fread(&liv, sizeof(liv), 1, fp) == 1){
		
		if(liv.num != salto){
			
			fwrite(&liv, sizeof(liv), 1, fp_tmp);
			
		} 	
		
	}	

	fclose(fp);
	fclose(fp_tmp);
	
	

	fp = fopen("dados.dat", "w");
	fp_tmp = fopen("tmp.dat", "r");
	
	while (fread(&liv, sizeof(liv), 1, fp_tmp) == 1){
		
		fwrite(&liv, sizeof(liv), 1, fp);		
		
	}
		
	fclose(fp);
	fclose(fp_tmp);
	
	system("PAUSE");
	return 0;

}




int main() {
	//aceitar chars portugueses
	setlocale(LC_ALL, "Portuguese");

	//validar se precisamos de repetir o menu
	bool repetirmenu = true;
	int total = 0;

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
		cout << "\n\t4. Procurar(consultar)" << endl;
		cout << "\n\t5. Eliminar" << endl;
		cout << "\n\tOpção: ";
		cin >> escolhamenu;

		//validação do input. o objetivo é só conseguir inserir numeros e não outros chars
		if (cin.fail()) {

		}
		else {

			switch (escolhamenu) {
			case 1:
				consultar();
				break;
			case 2:
				total = atrisbn(&fp, liv);
				inserir(total, &fp);
				break;
			case 3:
				alterar();
				break;
			case 4:
				procurar();
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

