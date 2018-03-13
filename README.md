# My final project for Programming 1 class
It is a basic book organizer software. The menu, lists, adds, changes, searches and deletes books. Developed in C.

Trabalho de P1


Elaborar um programa para gestão de livros.

O menu deve ser composto pelas seguintes opções:
1.Listar
2.Inserir
3.Alterar
4.Consultar
5.Eliminar

Considerações:
.Deve ser criada uma class Livros com as seguintes propriedades públicas
    ID;
    Nome;
    Autor;
    Editora;
    Ano publicação;

.Cada objeto deve ser criado com o nome livroID
.A ID de cada livro deve ser sequencial
.Deve ser criado um array prateleira[50][50]
.Cada objeto criado deve ser atribuido uma posição no array prateleira


##########################################################################

1.Listar
  Opções:
      ID
      nome
      Autor
      Editora
      Ano publicação
      Voltar menu inicial

2. Inserir
Buscar o último ID
perguntar o nome, autor, editora, Ano;
cria o objeto (ou struct) livro(nome, autor, editora...)
Atribui valor em prateleira (push//append)
escreve objeto para ficheiro

3.Alterar
Pergunta qual objeto (ID)
Abre ficheiro, lê objeto
Pergunta qual o campo a alterar
Pede para introduzir novo valor para esse campo
Grava no ficheiro
Pergunta se pretende alterar mais alguma coisa (repeat...) ou volta para menu anterior

4.Consultar
Pergunta al é a ID
Devolve array (prateleira/corredor)

5.Eliminar
Pergunta qual é a ID
Lista as propriedades do objeto
Pergunta de confirmação se é aquele objeto para eliminar (S/N)
Elimina objeto, e diz a prateleira de onde ele saiu.

##########################################################################

Funções necessárias:

=Listar menu
=Inserir Livro

=Função abrir ficheiro
=Função fechar ficheiro

=Função criar um array de prateleiras (verificar se já existe um)
=Função adicionar objeto a prateleira
=Função ler prateleira

=Função criar objeto
=Função alterar objetos
=Função apagar objetos
=Função listar objetos
