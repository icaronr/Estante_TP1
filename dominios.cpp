#include "dominios.h"
#include <string>
#include <iostream>

using namespace std;

//Definições de constantes.
const string Nome::NOME_FALHA = "Dom Pedro";
const string Nome::NOME_ERRO_SISTEMA = "Administrador";

const string Apelido::APELIDO_FALHA = "felix";
const string Apelido::APELIDO_ERRO_SISTEMA = "admin";
const string Apelido::APELIDO_SUCESSO = "jony";

const string Telefone::TELEFONE_FALHA = "61999955555";
const string Telefone::TELEFONE_ERRO_SISTEMA = "99999999999";

const string Senha::SENHA_FALHA = "byer";
const string Senha::SENHA_ERRO_SISTEMA = "admi";

const string Titulo::TITULO_FALHA = "Falhar Titulo";
const string Titulo::TITULO_ERRO_SISTEMA = "Matar Sistema";
const string Titulo::TITULO_SUCESSO = "Monarquia";

const string Data::DATA_FALHA = "310899";
const string Data::DATA_ERRO_SISTEMA = "111213";

const string Codigo::CODIGO_FALHA = "1234";
const string Codigo::CODIGO_ERRO_SISTEMA = "00000";
const string Codigo::CODIGO_SUCESSO = "5786";

const string Texto::TEXTO_FALHA = "Vai falhar o texto";
const string Texto::TEXTO_ERRO_SISTEMA = "Texto que derruba o sistema";

const string GeneroLiterario::GENERO_FALHA = "ROMANCE";
const string GeneroLiterario::GENERO_ERRO_SISTEMA = "EPOPEIA";


// Definições de métodos.

//*********************Nome*********************

///Este método recebe como único parâmetro a string "nome" e avalia seu tamanho
	///e os caracteres que a compôem.

void Nome::validar(string nome) throw (invalid_argument){



    if (nome.length() > TAMANHO_LIMITE)
        throw invalid_argument("Tamanho maior que o permitido.");

    int i=0;

	while(nome[i]!='\0'){
		if((nome[i]==' ')||(nome[i]=='.')||((nome[i]>='A')&&(nome[i]<='Z'))||((nome[i]>='a')&&(nome[i]<='z'))){
			i++;
		}else{
		    throw invalid_argument ("Uso de caractere invalido.");
        }
    }
}

///Este método recebe a string "nome" como único parâmetro.
	///Se o nome é válido, é atribuído a um objeto da classe "Nome".

void Nome::setNome(string nome) throw(invalid_argument){

    validar(nome);
    this->nome = nome;
}

//********************Apelido*******************

	///Este método recebe como único parâmetro a string "apelido" e avalia seu tamanho
	///e os caracteres que a compôem.

void Apelido::validar(string apelido) throw(invalid_argument){

	if (apelido.length() > TAMANHO_LIMITE)
        throw invalid_argument("Tamanho maior que o permitido.");

	int i=0;

	while((apelido[i]!='\0')){
		if(((apelido[i]>='A')&&(apelido[i]<='Z'))||((apelido[i]>='a')&&(apelido[i]<='z'))){
			i++;
		}else{
		    throw invalid_argument ("Uso de caractere inválido.");
		}
	}
}

///Este método recebe a string "apelido" como único parâmetro.
	///Se o apelido é válido, é atribuído a um objeto da classe "Apelido".

void Apelido::setApelido(string apelido) throw(invalid_argument){

	validar(apelido);
    this->apelido = apelido;
}

//********************Telefone******************

///Este método recebe a string "telefone" como único parâmetro.
	///Avalia seu tamanho e se os caracteres são todos numéricos.

void Telefone::validar(string telefone) throw(invalid_argument){

	if (telefone.size() != TAMANHO_LIMITE)
		throw invalid_argument ("O numero deve ter 11 caracteres.");

	//int i=0;

	while(true){
        if (telefone.size() != 11){
            throw invalid_argument ("O numero nao tem 11 caracteres.");
            break;
        }

        int i=0;

        while(telefone[i] != NULL){
            if((telefone[i]>='0')&&(telefone[i]<='9')){
                i++;
            }else{
                throw invalid_argument ("Argumento invalido.");
            }
        }
        break;
    }
}

	///Este método recebe a string "telefone" como único parâmetro.
	///Se o número é válido, é atribuído a um objeto da classe "Telefone".

void Telefone::setTelefone(string telefone) throw(invalid_argument){

	validar(telefone);
    this->telefone = telefone;
}
//********************Senha*********************

///Este método recebe a string "senha" como único parâmetro.
	///Avalia se a senha possui exatamente quatro letras.

void Senha::validar (string senha) throw (invalid_argument){

	if(senha.size() != TAMANHO_LIMITE)
		throw invalid_argument ("A senha deve possuir 4 caracteres.");

	int i=0;
	int j=1;

	while(senha[i]!='\0'){
		if(((senha[i]>='A')&&(senha[i]<='Z'))||((senha[i]>='a')&&(senha[i]<='z'))){
			j=i+1;
			while(j<4){
				if(senha[i]!=senha[j]) {
					j++;
				}else{
				    throw invalid_argument ("Caractere repetido.");
				}
			}
		}else{
		    throw invalid_argument ("Uso de caractere invalido.");
		}
		i++;
	}
}

///Este método recebe a string "senha" como único parâmetro.
	///Se a senha é válida, é atribuído a um objeto da classe "Senha".

void Senha::setSenha(string senha) throw(invalid_argument){

	validar(senha);
    this->senha = senha;
}
//******************Titulo***********************

///Este método recebe a string "titulo" como único parâmetro.
	///Avalia o tamanho e se o titulo possui espaços duplicados.

void Titulo::validar (string titulo) throw (invalid_argument){

	if (titulo.size() > TAMANHO_LIMITE)
		throw invalid_argument ("Titulo maior que 20 caracteres.");

	int i=0;

	while(titulo[i]!='\0'){
		if(titulo[i]==' '){
			if(titulo[i+1]==' '){
                cout << "Titulo\n";
				throw invalid_argument("Espaco duplicado.");
			}
		}
		i++;
	}
}

///Este método recebe a string "titulo" como único parâmetro.
	///Se o título é válido, é atribuído a um objeto da classe "Titulo".

void Titulo::setTitulo(string titulo) throw(invalid_argument){

	validar(titulo);
    this->titulo = titulo;
}

//*********************Autor*********************

///Este método recebe como único parâmetro a string "autor" e avalia seu tamanho
	///e os caracteres que a compôem.

void Autor::validar(string autor) throw (invalid_argument){



    if (autor.length() > TAMANHO_LIMITE)
        throw invalid_argument("Tamanho maior que o permitido.");

    int i=0;

	while(autor[i]!='\0'){
		if((autor[i]==' ')||(autor[i]=='.')||((autor[i]>='A')&&(autor[i]<='Z'))||((autor[i]>='a')&&(autor[i]<='z'))){
			i++;
		}else{
		    throw invalid_argument ("Uso de caractere invalido.");
        }
    }
}

///Este método recebe a string "autor" como único parâmetro.
	///Se o autor é válido, é atribuído a um objeto da classe "Autor".

void Autor::setAutor(string autor) throw(invalid_argument){

	validar(autor);
    this->autor = autor;
}


 //*******************Data**********************

 ///Este método recebe a string "data" como único parâmetro.
	///Converte os dois primeiros caracteres da string para decimal,
	///armazena em uma variável do tipo int e retorna este valor
	///correspondente ao dia de publicação do livro.


int Data::converteDia(string data){

	char digitoDezena = data[0];
	char digitoUnidade = data[1];
	int dia = 0;

	switch(digitoDezena){
		case '1': dia = 10; break;
		case '2': dia = 20; break;
		case '3': dia = 30; break;
            default: dia = 0;
	}
	switch(digitoUnidade){
        case '1': dia += 1; break;
        case '2': dia += 2; break;
        case '3': dia += 3; break;
        case '4': dia += 4; break;
        case '5': dia += 5; break;
        case '6': dia += 6; break;
        case '7': dia += 7; break;
        case '8': dia += 8; break;
        case '9': dia += 9; break;
            default: break;
	}

	return dia;
}

///Este método recebe a string "data" como único parâmetro.
	///Converte o terceiro e quarto caracteres da string para decimal,
	///armazena em uma variável do tipo int e retorna este valor
	///correspondente ao mês de publicação do livro.


int Data::converteMes(string data){

	char digitoDezena = data[2];
	char digitoUnidade = data[3];
	int mes = 0;

	switch(digitoDezena){
		case '1': mes = 10; break;
		case '0': mes = 0; break;
	}
	switch(digitoUnidade){
        case '1': mes += 1; break;
        case '2': mes += 2; break;
        case '3': mes += 3; break;
        case '4': mes += 4; break;
        case '5': mes += 5; break;
        case '6': mes += 6; break;
        case '7': mes += 7; break;
        case '8': mes += 8; break;
        case '9': mes += 9; break;
            default: break;
	}

	return mes;
}

///Este método recebe a string "data" como único parâmetro.
	///Converte os dois últimos caracteres da string para decimal,
	///armazena em uma variável do tipo int e retorna este valor
	///correspondente ao ano de publicação do livro.

int Data::converteAno(string data){

	char digitoDezena = data[4];
	char digitoUnidade = data[5];
	int ano = 0;

	switch(digitoDezena){
        case '1': ano += 10; break;
        case '2': ano += 20; break;
        case '3': ano += 30; break;
        case '4': ano += 40; break;
        case '5': ano += 50; break;
        case '6': ano += 60; break;
        case '7': ano += 70; break;
        case '8': ano += 80; break;
        case '9': ano += 90; break;
            default: break;
	}
	switch(digitoUnidade){
        case '1': ano += 1; break;
        case '2': ano += 2; break;
        case '3': ano += 3; break;
        case '4': ano += 4; break;
        case '5': ano += 5; break;
        case '6': ano += 6; break;
        case '7': ano += 7; break;
        case '8': ano += 8; break;
        case '9': ano += 9; break;
            default: break;
	}

	return ano;
}

///Este método recebe a string "data" como único parâmetro.
	///Chama as funções "converteDia', "converteMes" e "converteAno"
	///para obter os valores de dia, mês e ano em decimal.
	///Verifica se a data está em formato correto; por exemplo:
	///dias entre 0 e 31 e mês entre 1 e 12.


void Data::validar (string data) throw (invalid_argument){

	if (data.size() != TAMANHO_LIMITE)
 		throw invalid_argument ("Formato de data inválido.");

 	int dia_int, mes_int, ano_int;
 	dia_int = Data::converteDia(data);
 	mes_int = Data::converteMes(data);
 	ano_int = Data::converteAno(data);


	if((dia_int<0)||(dia_int>31))
		throw invalid_argument ("Argumento invalido.");

	if((mes_int<1)||(mes_int>12))
		throw invalid_argument ("Argumento invalido.");

	if((ano_int<0)||(ano_int>99))
		throw invalid_argument ("Argumento invalido.");
}

///Este método recebe a string "data" como único parâmetro.
	///Se o formato é válido, é atribuído a um objeto da classe "Data".

void Data::setData(string data) throw (invalid_argument){

	validar(data);
	this->data = data;
}

//********************Codigo********************

///Este método recebe a string "codigo" como único parâmetro.
	///Lança exceção se é maior do que o limite ou se possui
	///caracteres não numéricos.

void Codigo::validar(string codigo) throw (invalid_argument){

    if (codigo.size() > TAMANHO_LIMITE)
        throw invalid_argument("Argumento invalido.");

	int i=0;

	while(codigo[i]!='\0'){
		if((codigo[i]>='0')&&(codigo[i]<='9')){
			i++;
		}else{
			throw invalid_argument ("Argumento invalido.");
		}
		i++;
	}
}

///Este método recebe a string "codigo" como único parâmetro.
	///Se é válido, é atribuído a um objeto da classe "Codigo".

void Codigo::setCodigo(string codigo) throw(invalid_argument){

	this->codigo = codigo;
}
//*******************Texto**********************

///Este método recebe a string "texto" como único parâmetro.
	///Lança exceção se o tamanho excede 40 caracteres.


void Texto::validar(string texto) throw (invalid_argument){

	if (texto.length() > TAMANHO_LIMITE)
		throw invalid_argument ("Texto maior que 40 caracteres.");
}

///Este método recebe a string "texto" como único parâmetro.
	///Se o tamanho é válido, é atribuído a um objeto da classe "Texto".

void Texto::setTexto(string texto) throw(invalid_argument){

	validar(texto);
    this->texto = texto;
}
//******************Genero**********************

///Este método recebe a string "generoLiterario" como único parâmetro.
	///Lança exceção se a string não corresponde aos cinco gêneros permitidos.

void GeneroLiterario::validar (string generoLiterario) throw (invalid_argument){

	if(generoLiterario!="EPOPEIA" && generoLiterario!="NOVELA" && generoLiterario!="CONTO" && generoLiterario!="ENSAIO" && generoLiterario!="ROMANCE")
		throw invalid_argument ("Genero invalido.");
}

void GeneroLiterario::setGeneroLiterario(string generoLiterario) throw(invalid_argument){
    validar(generoLiterario);
    this->generoLiterario = generoLiterario;
}

//******************Troca**********************

void Troca::validar(string troca) throw(invalid_argument){
    if((troca != "0") && (troca != "1") ){
        throw invalid_argument ("Valor inválido.");
    }
}

void Troca::setTroca(string troca) throw (invalid_argument){
    validar(troca);
    this->troca = troca;
}
