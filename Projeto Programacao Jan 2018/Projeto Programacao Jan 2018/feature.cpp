#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>
//#include <WinBase.h>
using namespace std;

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

	//system("PAUSE");
	return isbn;
};


int procurar() {

	int salto;
	char encontralivro;
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

	switch(getch()){
		
		case '1': 
			system("cls");
			printf("\n\n\nDigite o numero do registo que pretenda ler: ");
			fflush(stdin);
			scanf("%d", &salto);
			while(fread(&liv, sizeof(liv), 1, fp)==1) {	
				if(liv.num == salto){			
					printf("\nISBN: %ld", liv.num);
					printf("\nNome: %s", liv.nome);
					printf("\nAutor: %s", liv.autor);
					printf("\nValor: %4.2f\n\n\n", liv.valor);
					encontralivro = 'OK'; //verificação se encontra						
				}
		
			}
			if(encontralivro != 'OK'){
				printf("\nISBN não encontrado.");
				printf("\nDeseja procurar novamente? (S/N)");
				if(getch()=='s'){
					return procurar();
				} else {
					return 0;
					//break;
				}	
			}
		case '2':
			
			char nome_proc[30];
			system("cls");
			printf("\n\n\nDigite o nome do livro: ");
			fflush(stdin);
			scanf("%s",nome_proc); 
			
			salto = 0;
			while(fread(&liv, sizeof(liv), 1, fp)==1) {
				printf("\n####\n"); printf("\n%s", liv.nome); printf("%ld", sizeof(liv.nome)); printf("\n%s", nome_proc); printf("%ld", sizeof(nome_proc));
				
				if(strcmp(liv.nome,nome_proc)==0){
					printf("\nISBN: %ld", liv.num);
					printf("\nNome: %s", liv.nome);
					printf("\nAutor: %s", liv.autor);
					printf("\nValor: %4.2f\n\n\n", liv.valor);
					salto++;			
				}
			}
				
			if(salto==0){
				printf("\nNome não encontrado.");
				printf("\nDeseja procurar novamente? (S/N)");
				if(getch()=='s'){
					return procurar();
				} else {
					return 0;
					//break;
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
	//o programa ao correr mostra as linhas acima e fica a espera de um ENTER
	//como saltamos a frente e mostramos logo as perguntas?

	
	//abre ficheiro
	*fp = fopen("dados.dat", "a");
	
	//dormir aqui? Sleep(3000);
	
	if (*fp == NULL)
	{
		cout << "ERRO!\nO Ficheiro não foi aberto.\n" << endl;

		cout << "\n\nDigite uma tecla para terminar Programa\n" << endl;

		cout.flush();		
		ch = getchar();
		exit(0);
	}
		
	if (_getch() != 27)
		do
		{			
			// nota - não estamos a validar a introdução. experimentem ver a opção consultar, visto
			// se inserirem espaços/ENTER ele guarda isso tudo no ficheiro e a consulta/listagem fica "feia"

			
			//liv.num = 60;
			liv.num = ++total;			
			//printf("\n\n\nISBN: %ld", liv.num);

			// HELP - não consigo que a pergunta "titulo do livro" funcione no visual studio
			// :( Simplesmente salta para a pergunta seguinte
			
			printf("\n\nDigite o Titulo do livro:");
			while (getchar() != '\n');
			fgets(liv.nome, 30, stdin);
			// fgets é o gets mas novo e atualizado
			//printf("\nNome: %s", liv.nome);

			printf("\n\nDigite o Autor do livro: ");
			fflush(stdin);
			fgets(liv.autor, 30, stdin);
			//printf("\nAutor: %s", liv.autor);

			printf("\n\nDigite o valor do livro: ");
			fflush(stdin);
			scanf("%f", &liv.valor);
			//printf("\nValor: %4.2f", liv.valor);
			
			fwrite(&liv, sizeof(liv), 1, *fp);

			// o ESC está a gerar loop no menu inicial é preciso perceber porquê
			printf("\n\nClique em ESC para sair\n\n");
			printf("\t ou em outra tecla para novo registo\n\n");

			fflush(stdin);
		} while (_getch() != 27);


		// fecha ficheiro que estava aberto para escrita-append

		fclose(*fp);


	system("PAUSE");
	return 0;
};

int alterar() {
	int salto;
	char encontralivro;
	char cont_procurar;
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Alterar" << endl;
	cout << "\n######################" << endl;
	cout << endl << endl;
	
	cont_procurar ='s';
	
	while(cont_procurar=='s'){

		cout << "Introduza a ID do livro a alterar:" << endl;
		fflush(stdin);
		scanf("%d", &salto);
		fp = fopen("dados.dat", "rw");
		rewind(fp);
		encontralivro = 'KO';
	
		while(fread(&liv, sizeof(liv), 1, fp)==1) {	
			if(liv.num == salto){			
				system("cls");
				printf("\nLivro com o ISBN: %ld encontrado", liv.num);
				printf("\n\t1.Nome: %s", liv.nome);
				printf("\n\t2.Autor: %s", liv.autor);
				printf("\n\t3.Valor: %4.2f\n\n\n", liv.valor);
				printf("Escolha a opção que pretende alterar.");
				
				printf("\n\nDigite o novo Título do livro:"); 
				fflush(stdin);
				scanf("%s", liv.nome);
				
				printf("\n\nDigite o novo Autor do livro: ");
				fflush(stdin);
				scanf("%s", liv.autor);
				
				printf("\n\nDigite o novo valor do livro: ");
				fflush(stdin);
				scanf("%f", &liv.valor);
				
				
				
				/*
				switch(getch()){
					case '1': 
						printf("\n\nDigite o novo Título do livro:");
						fflush(stdin);
						scanf("%s", liv.nome);
						break;
					case '2':
						printf("\n\nDigite o novo Autor do livro: ");
						fflush(stdin);
						scanf("%s", liv.autor);
						break;
					case '3':
						printf("\n\nDigite o novo valor do livro: ");
						fflush(stdin);
						scanf("%f", &liv.valor);
				}
				
				*/
			
				printf("\nRegisto atualizado.");
				fseek(fp,ftell(fp)-sizeof(liv),0);
				fwrite(&liv, sizeof(liv), 1, fp);
				fclose(fp);
				encontralivro = 'OK';
			}
	
			if(encontralivro != 'OK') printf("\nISBN não encontrado.");					
   		}	
		
		printf("\n\nDeseja procurar novamente ou modificar outro registo (S/N)");
	    fflush(stdin);
	   	cont_procurar=getch();
	}
	system("PAUSE");
	return 0;
}

int consultar() {
	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Consultar" << endl;
	cout << "\n######################" << endl;

	// abre agora o ficheiro para leitura

	fp = fopen("dados.dat", "r");

	// enquanto houverem registos imprimir cada um para o ecrã

	while (fread(&liv, sizeof(liv), 1, fp))
	{
		printf("\n\n\nISBN: %ld", liv.num);

		printf("\nNome: %s", liv.nome);

		printf("\nAutor: %s", liv.autor);

		printf("\nValor: %4.2f \n", liv.valor);
	}


	system("PAUSE");
	return 0;
};

int eliminar(FILE **fp) {
	char regapagar[30];
	int regencontrado = 0;
	int salto;
	struct livro registo;
	FILE *fp_tmp;

	*fp = fopen("dados.dat", "a");
	fp_tmp = fopen("tmp.dat", "a");

	system("cls");
	cout << "######################" << endl;
	cout << "\n\t\tOpção Eliminar" << endl;
	cout << "\n######################" << endl;
	
	cout << "Introduza registo a apagar: ";
	while (getchar() != '\n');
	fgets(regapagar,30, stdin);

	

	/*ofstream o;
	o.open("new.dat", ios::out | ios::binary);
	fil.open("binary.dat", ios::in | ios::binary);*/
	if (*fp == NULL)
	{
		cout << "ERRO!\nO Ficheiro não foi aberto.\n" << endl;

		cout << "\n\nDigite uma tecla para terminar Programa\n" << endl;

		cout.flush();
		ch = getchar();
		exit(0);
	}
	else
	{
		//fseek(*fp, (long)(salto - 1) * sizeof(liv), SEEK_SET);
		/*while (fread(&liv, sizeof(liv), 1, fp))
		{
			if (strcmp(regapagar, fileobj.getn()) != 0)
			{
				o.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				cout << "Press Any Key....For Search" << endl;
				getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}*/
		while (fread(regapagar, sizeof(struct livro), 1, *fp) != NULL) {
			if (strcmp(regapagar, registo.nome) == 0) {
				printf("A record with requested name found and deleted.\n\n");
				printf("tou aqui 1");
				regencontrado = 1;
			}
			else {
				
				fwrite(&registo, sizeof(struct livro), 1, fp_tmp);
			}
		}
		if (!regencontrado) {
			printf("No record(s) found with the requested name: %s\n\n", regapagar);
			printf("tou aqui 2"); //adoro estes comentários ahahaha
		}
	}
	/*o.close();
	fil.close();*/
	fclose(*fp);
	fclose(fp_tmp);
	remove("dados.dat");
	rename("new.dat", "dados.dat");



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

		//Marcos a testar - validação do input. o objetivo é só conseguir inserir numeros e não outros chars
		if (cin.fail()) {
			/*system("cls");
			cout << "erro";
			cin.clear();
			system("pause");*/
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
					eliminar(&fp);
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

