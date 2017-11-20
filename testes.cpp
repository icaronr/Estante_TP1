#include "testes.h"
#include <iostream>

string TUNome::VALOR_VALIDO;
string TUNome::VALOR_INVALIDO;

/// Definições de métodos.
//** Teste Unitario - Nome **
/// Metodo que inicializa a classe.
void TUNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUNome::tearDown(){
    delete nome;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUNome::testarCenarioSucesso(){
    TUNome::VALOR_VALIDO = "Ana Clara";
    try{
        nome->setNome(VALOR_VALIDO);
        if (nome->getNome() != VALOR_VALIDO)
            estado = FALHA;

    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}
///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUNome::testarCenarioFalha(){
    TUNome::VALOR_INVALIDO = "Marcos.123";
    try{
        nome->setNome(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUNome::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

///** Teste Unitario - Apelido **
/// Metodo que inicializa a classe.
void TUApelido::setUp(){
    apelido = new Apelido();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUApelido::tearDown(){
    delete apelido;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUApelido::testarCenarioSucesso(){
    TUApelido::VALOR_VALIDO = "clara";
    try{
        apelido->setApelido(VALOR_VALIDO);
        if (apelido->getApelido() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}
///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUApelido::testarCenarioFalha(){
    TUApelido::VALOR_INVALIDO = "Ana888";
    try{
        apelido->setApelido(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUApelido::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

///** Teste Unitario - Telefone **
/// Metodo que inicializa a classe.
void TUTelefone::setUp(){
    telefone = new Telefone();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUTelefone::tearDown(){
    delete telefone;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUTelefone::testarCenarioSucesso(){
    TUTelefone::VALOR_VALIDO = "61984596895";
    try{
        telefone->setTelefone(VALOR_VALIDO);
        if (telefone->getTelefone() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}
///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUTelefone::testarCenarioFalha(){
    TUTelefone::VALOR_INVALIDO = "84596";
    try{
        telefone->setTelefone(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUTelefone::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

///** Teste Unitario - Senha **
/// Metodo que inicializa a classe.
void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUSenha::tearDown(){
    delete senha;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUSenha::testarCenarioSucesso(){
    TUSenha::VALOR_VALIDO = "pulo";
    try{
        senha->setSenha(VALOR_VALIDO);
        if (senha->getSenha() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}
///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUSenha::testarCenarioFalha(){
    TUSenha::VALOR_INVALIDO = "lala";
    try{
        senha->setSenha(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUSenha::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

///** Teste Unitario - Titulo **
/// Metodo que inicializa a classe.
void TUTitulo::setUp(){
    titulo = new Titulo();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUTitulo::tearDown(){
    delete titulo;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUTitulo::testarCenarioSucesso(){
    TUTitulo::VALOR_VALIDO = "Harry Potter";
    try{
        titulo->setTitulo(VALOR_VALIDO);
        if (titulo->getTitulo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}
///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUTitulo::testarCenarioFalha(){
    TUTitulo::VALOR_INVALIDO = "Percy  Jackson";
    try{
        titulo->setTitulo(VALOR_INVALIDO);
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUTitulo::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

///** Teste Unitario - Data **
/// Metodo que inicializa a classe.
void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUData::tearDown(){
    delete data;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUData::testarCenarioSucesso(){
    TUData::VALOR_VALIDO = "240594";

    try{
        data->setData(VALOR_VALIDO);
        if (data->getData() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUData::testarCenarioFalha(){
    TUData::VALOR_INVALIDO = "231394";
    try{
        data->setData(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUData::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

///** Teste Unitario - Codigo **
/// Metodo que inicializa a classe.
void TUCodigo::setUp(){
    codigo = new Codigo();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUCodigo::tearDown(){
    delete codigo;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUCodigo::testarCenarioSucesso(){
    TUCodigo::VALOR_VALIDO = "89642";
    try{
        codigo->setCodigo(VALOR_VALIDO);
        if (codigo->getCodigo() != VALOR_VALIDO)
            estado = FALHA;
    }catch(invalid_argument excecao){
        estado = FALHA;
    }
}
///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUCodigo::testarCenarioFalha(){
    TUCodigo::VALOR_INVALIDO = "946852";
    try{
        codigo->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUCodigo::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

///** Teste Unitario - Texto **
/// Metodo que inicializa a classe.
void TUTexto::setUp(){
    texto = new Texto();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUTexto::tearDown(){
    delete texto;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUTexto::testarCenarioSucesso(){
    TUTexto::VALOR_VALIDO = "Esse eh um teste de valor valido.";
    try{
        texto->setTexto(VALOR_VALIDO);
        if (texto->getTexto() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}
///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUTexto::testarCenarioFalha(){
    TUTexto::VALOR_INVALIDO = "Este texto eh um teste de valor invalido.";
    try{
        texto->setTexto(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUTexto::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

///** Teste Unitario - Genero Literario **
/// Metodo que inicializa a classe.
void TUGeneroLiterario::setUp(){
    generoLiterario = new GeneroLiterario();
    estado = SUCESSO;
}
/// Metodo responsavel por usar o 'delete' para liberar a memoria.
void TUGeneroLiterario::tearDown(){
    delete generoLiterario;
}
/// Metodo que testa o cenario de sucesso.
/// Atribui um valor valido para a variavel de teste, e roda o teste.
void TUGeneroLiterario::testarCenarioSucesso(){
   TUGeneroLiterario::VALOR_VALIDO = "EPOPEIA";
    try{
        generoLiterario->setGeneroLiterario(VALOR_VALIDO);
        if (generoLiterario->getGeneroLiterario() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}
///Metodo que testa o cenario de falha.
/// Atribui um valor invalido para a variavel de teste, e roda o teste.
void TUGeneroLiterario::testarCenarioFalha(){
    TUGeneroLiterario::VALOR_INVALIDO = "QUADRINHO";
    try{
        generoLiterario->setGeneroLiterario(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}
/// Metodo que roda os testes.
int TUGeneroLiterario::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
