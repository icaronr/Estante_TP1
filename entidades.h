#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;

/// Declaracao de classes de Entidade.
/// Os objetos da classe sao os tipos basicos definidos no arquivo de dominios,
///ou seja, nome, apelido, telefone e senha do usuario.
/// Os metodos desse bloco servem para atribuir valores aos objetos da Entidade (metodos "set")
///ou para retornar os valores dos objetos da Entidade.
class Usuario {

private:
    Nome nome;
    Apelido apelido;
    Telefone telefone;
    Senha senha;

public:
    void setNome (const Nome &nome){
        this->nome = nome;
    }
    void setApelido (const Apelido &apelido){
        this->apelido = apelido;
    }
    void setTelefone (const Telefone &telefone){
        this->telefone = telefone;
    }
    void setSenha (const Senha &senha){
        this->senha = senha;
    }
    Nome getNome() const{
        return nome;
    }
    Apelido getApelido() const{
        return apelido;
    }
    Telefone getTelefone() const{
        return telefone;
    }
    Senha getSenha() const{
        return senha;
    }
};

/// Os objetos da classe sao os tipos basicos definidos no arquivo de dominios,
/// tais quais o titulo, gênero literario e codigo de cada livro.
/// Os metodos desse bloco servem para atribuir os valores aos objetos da Entidade (metodos
/// "set") ou para retornar os valores desses objetos (metodos "get").
class Livro {
private:
    Titulo titulo;
    GeneroLiterario generoLiterario;
    Codigo codigo;
    Autor autor;
    Data data;

public:
    void setTitulo(const Titulo &titulo){
        this->titulo = titulo;
    }
    void setGeneroLiterario(const GeneroLiterario &generoLiterario){
        this->generoLiterario = generoLiterario;
    }
    void setCodigo(const Codigo &codigo){
        this->codigo = codigo;
    }

    void setAutor(const Autor &autor){
        this->autor = autor;
    }

    void setData(const Data &data){
        this->data = data;
    }

    Titulo getTitulo() const {
        return titulo;
    }
    GeneroLiterario getGeneroLiterario() const{
        return generoLiterario;
    }
    Codigo getCodigo() const {
        return codigo;
    }

    Autor getAutor() const{
        return autor;
    }

    Data getData() const{
        return data;
    }
};

///Esta classe define os tipos basicos para o texto das resenhas que podem ser
///associadas a cada livro. Sao eles: titulo, data e texto.
///Os metodos deste bloco servem para atribuir os valores dos objetos da Entidade (setters)
/// ou para retornar os valores (getters).
class Resenha {
private:

    Titulo titulo;
    Data data;
    Texto texto;
    Apelido apelido;
    Codigo codigo;

public:

    void setTitulo(const Titulo &titulo){
        this->titulo = titulo;
    }
    void setData(const Data &data){
        this->data = data;
    }
    void setTexto(const Texto &texto){
        this->texto = texto;
    }

    void setApelido(const Apelido &apelido){
        this->apelido = apelido;
    }

    void setCodigo(const Codigo &codigo){
        this->codigo = codigo;
    }

    ///*****Getters*****
    /// Os metodos desse bloco servem para retornar os valores dos objetos da Entidade.
    Titulo getTitulo() const {
        return titulo;
    }
    Data getData() const {
        return data;
    }
    Texto getTexto() const{
        return texto;
    }
    Apelido getApelido() const{
        return apelido;
    }
    Codigo getCodigo() const{
        return codigo;
    }
};

///Esta classe define os tipos basicos para os exemplares que podem ser
///associadas a cada livro. Sao eles: troca, codigo e apelido.
///Os metodos deste bloco servem para atribuir os valores dos objetos da Entidade (setters)
/// ou para retornar os valores (getters).
class Exemplar {
private:

    Troca troca;
    Apelido apelido;
    Codigo codigo;

public:

    void setTroca(const Troca &troca){
        this->troca = troca;
    }

    void setApelido(const Apelido &apelido){
        this->apelido = apelido;
    }

    void setCodigo(const Codigo &codigo){
        this->codigo = codigo;
    }

    ///*****Getters*****
    /// Os metodos desse bloco servem para retornar os valores dos objetos da Entidade.
    Troca getTroca() const {
        return troca;
    }
    Apelido getApelido() const{
        return apelido;
    }
    Codigo getCodigo() const{
        return codigo;
    }
};

// Declaracoes de classes que representam resultados.

///Esta classe define os valores padrao utilizados para resultados de testes no programa, determinando
/// os valores "0" como sucesso e "1" como falha.
class Resultado {

protected:
    int valor;

public:

    const static int SUCESSO = 0;
    const static int FALHA   = 1;

    void setValor(int valor){
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }
};

///Esta classe e utilizada na pesquisa dos atributos utilizados para a autenticacao,
///para que o retorno dos metodos nao seja apenas um valor numerico sinalizando sucesso ou falha,
///mas quem tambem retorne o valor de apelido utilizado na autenticacao.
class ResultadoAutenticacao:public Resultado {

private:
    Apelido apelido;

public:
    void setApelido(const Apelido &apelido){      // passagem por referência.
        this->apelido = apelido;
    }

    Apelido getApelido() const {
        return apelido;
    }
};

///Esta classe e utilizada como componente da pesquisa por nome de usuario,
///para que o retorno dos metodos nao seja apenas um valor numerico sinalizando
///sucesso ou falha, mas tambem o objeto Usuario encontrado e todos os demais valores
///que o compoem.
class ResultadoUsuario:public Resultado {

private:
    Usuario usuario;

public:
    void setUsuario(const Usuario &usuario){
        this->usuario = usuario;
    }

    Usuario getUsuario() const {
        return usuario;
    }
};

///Esta classe e utilizada como componente da pesquisa por nome de livro,
///para que o retorno dos metodos nao seja apenas um valor numerico sinalizando
///sucesso ou falha, mas tambem o objeto Livro encontrado e todos os demais valores
///que o compoem.
class ResultadoLivro:public Resultado {

private:
    Livro livro;

public:
    void setLivro(const Livro &livro){
        this->livro = livro;
    }

    Livro getLivro() const {
        return livro;
    }
};

///Esta classe e utilizada como componente da pesquisa por resenha,
///para que o retorno dos metodos nao seja apenas um valor numerico sinalizando
///sucesso ou falha, mas tambem o objeto Resenha encontrado e todos os demais valores
///que o compoem.
class ResultadoResenha:public Resultado {

private:
    Resenha resenha;

public:
    void setResenha(const Resenha &resenha){
        this->resenha = resenha;
    }

    Resenha getResenha() const {
        return resenha;
    }
};


#endif // ENTIDADES_H_INCLUDED
