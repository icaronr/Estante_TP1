#include "dominios.h"
#include <string>
#include <iostream>

using namespace std;

//Defini��es de constantes.
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


// Defini��es de m�todos.

//*********************Nome*********************

///Este m�todo recebe como �nico par�metro a string "nome" e avalia seu tamanho
	///e os caracteres que a comp�em.

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

///Este m�todo recebe a string "nome" como �nico par�metro.
	///Se o nome � v�lido, � atribu�do a um objeto da classe "Nome".

void Nome::setNome(string nome) throw(invalid_argument){

    validar(nome);
    this->nome = nome;
}

//********************Apelido*******************

	///Este m�todo recebe como �nico par�metro a string "apelido" e avalia seu tamanho
	///e os caracteres que a comp�em.

void Apelido::validar(string apelido) throw(invalid_argument){

	if (apelido.length() > TAMANHO_LIMITE)
        throw invalid_argument("Tamanho maior que o permitido.");

	int i=0;

	while((apelido[i]!='\0')){
		if(((apelido[i]>='A')&&(apelido[i]<='Z'))||((apelido[i]>='a')&&(apelido[i]<='z'))){
			i++;
		}else{
		    throw invalid_argument ("Uso de caractere inv�lido.");
		}
	}
}

///Este m�todo recebe a string "apelido" como �nico par�metro.
	///Se o apelido � v�lido, � atribu�do a um objeto da classe "Apelido".

void Apelido::setApelido(string apelido) throw(invalid_argument){

	validar(apelido);
    this->apelido = apelido;
}

//********************Telefone******************

///Este m�todo recebe a string "telefone" como �nico par�metro.
	///Avalia seu tamanho e se os caracteres s�o todos num�ricos.

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

	///Este m�todo recebe a string "telefone" como �nico par�metro.
	///Se o n�mero � v�lido, � atribu�do a um objeto da classe "Telefone".

void Telefone::setTelefone(string telefone) throw(invalid_argument){

	validar(telefone);
    this->telefone = telefone;
}
//********************Senha*********************

///Este m�todo recebe a string "senha" como �nico par�metro.
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

///Este m�todo recebe a string "senha" como �nico par�metro.
	///Se a senha � v�lida, � atribu�do a um objeto da classe "Senha".

void Senha::setSenha(string senha) throw(invalid_argument){

	validar(senha);
    this->senha = senha;
}
//******************Titulo***********************

///Este m�todo recebe a string "titulo" como �nico par�metro.
	///Avalia o tamanho e se o titulo possui espa�os duplicados.

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

///Este m�todo recebe a string "titulo" como �nico par�metro.
	///Se o t�tulo � v�lido, � atribu�do a um objeto da classe "Titulo".

void Titulo::setTitulo(string titulo) throw(invalid_argument){

	validar(titulo);
    this->titulo = titulo;
}

//*********************Autor*********************

///Este m�todo recebe como �nico par�metro a string "autor" e avalia seu tamanho
	///e os caracteres que a comp�em.

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

///Este m�todo recebe a string "autor" como �nico par�metro.
	///Se o autor � v�lido, � atribu�do a um objeto da classe "Autor".

void Autor::setAutor(string autor) throw(invalid_argument){

	validar(autor);
    this->autor = autor;
}


 //*******************Data**********************

 ///Este m�todo recebe a string "data" como �nico par�metro.
	///Converte os dois primeiros caracteres da string para decimal,
	///armazena em uma vari�vel do tipo int e retorna este valor
	///correspondente ao dia de publica��o do livro.


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

///Este m�todo recebe a string "data" como �nico par�metro.
	///Converte o terceiro e quarto caracteres da string para decimal,
	///armazena em uma vari�vel do tipo int e retorna este valor
	///correspondente ao m�s de publica��o do livro.


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

///Este m�todo recebe a string "data" como �nico par�metro.
	///Converte os dois �ltimos caracteres da string para decimal,
	///armazena em uma vari�vel do tipo int e retorna este valor
	///correspondente ao ano de publica��o do livro.

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

///Este m�todo recebe a string "data" como �nico par�metro.
	///Chama as fun��es "converteDia', "converteMes" e "converteAno"
	///para obter os valores de dia, m�s e ano em decimal.
	///Verifica se a data est� em formato correto; por exemplo:
	///dias entre 0 e 31 e m�s entre 1 e 12.


void Data::validar (string data) throw (invalid_argument){

	if (data.size() != TAMANHO_LIMITE)
 		throw invalid_argument ("Formato de data inv�lido.");

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

///Este m�todo recebe a string "data" como �nico par�metro.
	///Se o formato � v�lido, � atribu�do a um objeto da classe "Data".

void Data::setData(string data) throw (invalid_argument){

	validar(data);
	this->data = data;
}

//********************Codigo********************

///Este m�todo recebe a string "codigo" como �nico par�metro.
	///Lan�a exce��o se � maior do que o limite ou se possui
	///caracteres n�o num�ricos.

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

///Este m�todo recebe a string "codigo" como �nico par�metro.
	///Se � v�lido, � atribu�do a um objeto da classe "Codigo".

void Codigo::setCodigo(string codigo) throw(invalid_argument){

	this->codigo = codigo;
}
//*******************Texto**********************

///Este m�todo recebe a string "texto" como �nico par�metro.
	///Lan�a exce��o se o tamanho excede 40 caracteres.


void Texto::validar(string texto) throw (invalid_argument){

	if (texto.length() > TAMANHO_LIMITE)
		throw invalid_argument ("Texto maior que 40 caracteres.");
}

///Este m�todo recebe a string "texto" como �nico par�metro.
	///Se o tamanho � v�lido, � atribu�do a um objeto da classe "Texto".

void Texto::setTexto(string texto) throw(invalid_argument){

	validar(texto);
    this->texto = texto;
}
//******************Genero**********************

///Este m�todo recebe a string "generoLiterario" como �nico par�metro.
	///Lan�a exce��o se a string n�o corresponde aos cinco g�neros permitidos.

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
        throw invalid_argument ("Valor inv�lido.");
    }
}

void Troca::setTroca(string troca) throw (invalid_argument){
    validar(troca);
    this->troca = troca;
}
