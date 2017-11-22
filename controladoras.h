#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"
#include "unidadePersistencia.h"
#include "global.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;


/// Classe controladora de interação para o serviço de autenticação.

class CntrIUAutenticacao:public IUAutenticacao {

private:

    /**
    * Ponteiro para a controladora de autenticação na camada de negócio.
    */
    ILNAutenticacao *cntrLNAutenticacao;

public:
    
    /**
     * Este método público realiza o contato com o usuário para solicitar seus dados para cadastro.
     * Primeiro utiliza os serviços de entrada e saída no console para solicitar apelido, senha, nome e telefone.
     * Em seguida envia para a autenticação no serviço de lógica de negócio ("cntrLNAutenticacao->cadastrar()").
     * O método determina se a autenticação falhou (resultado = 1) ou obteve sucesso (resultado = 0).
     * Retorna um objeto do tipo "ResultadoAutenticacao" com o apelido do usuário que tentou o acesso e o resultado da solicitação.
     */
    ResultadoAutenticacao cadastrar() throw(runtime_error);
    
    /**
     * Este método realiza o contato com o usuário para solicitar seus dados para autenticação.
     * Primeiro utiliza os serviços de entrada e saída no console para solicitar apelido e senha.
     * Em seguida envia para a autenticação no serviço de lógica de negócio ("cntrLNAutenticacao->autenticar()").
     * O método determina se a autenticação falhou (resultado = 1) ou obteve sucesso (resultado = 0).
     * Retorna um objeto do tipo "ResultadoAutenticacao" com o apelido do usuário que tentou o acesso e o resultado da solicitação.
     */
    ResultadoAutenticacao autenticar() throw(runtime_error);

    void setCntrLNAutenticacao(ILNAutenticacao*);
};


void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}


/// Declaração de controladora de interação para o serviço de gerentes.

class CntrIUUsuario:public IUUsuario {

private:

    const static int INCLUIR   = 1; /**< Valor constante para inclusão. */
    const static int REMOVER   = 2; /**< Valor constante para remoção. */
    const static int CONSULTAR = 3; /**< Valor constante para consulta. */
    const static int ESCREVER  = 4; /**< Valor constante para escrita. */ 
    const static int PESQUISAR  = 5; /**< Valor constante para pesquisa. */ 
    const static int TROCAR    = 6; /**< Valor constante para troca. */
    const static int RETORNAR  = 7; /**< Valor constante para retorno. */

    /**
    * Ponteiro para conectar a interface de usuário com a controladora de negócio.
    */
    ILNUsuario *cntrLNUsuario;

public:

    /**
    * Este método recebe como parâmetro o apelido do usuário que vai selecionar uma opcao a ser executada.
    * É apresentada uma tela ao usuário com as diversas opções de ação no programa numeradas de 1 a 7.
    * A opção selecionada é armazenada no inteiro "opcao", que selecionará o método correto a ser chamado.
    * A depender da opção, o respectivo comando de lógica de negocio é chamado. No caso da opção "RETORNAR",
    * o programa é simplesmente encerrado. O método não returna nenhum valor.
    */
    void executar(const Apelido&) throw(runtime_error);

    /**
    * Método por meio do qual é estabelecido relacionamento com o servidor.
    */ 
    void setCntrLNUsuario(ILNUsuario *cntrLNUsuario){
        this->cntrLNUsuario = cntrLNUsuario;
    }
};

/// Classe controladora de serviços da interface de autenticação a nível de negócio.

class CntrLNAutenticacao:public ILNAutenticacao{

public:

    /**
    * Método que realiza a etapa de interface com usuário do cadastro. Recebe como parâmetro
    * um objeto "usuario". Solicita ao usuário a entrada de um apelido e senha. O objeto "usuario"
    * é preenchido com esses dados e passado como parâmetro para o comando de pesquisa de usuário.
    * Se o comando de pesquisa encontra usuário com esses dados, o método informa que o nome está em uso.
    * Caso contrário o usuário é cadastrado. O método retorna o resultado do cadastro.
    */
    Resultado cadastrar(const Usuario&) throw(runtime_error);
    
    /**
    * Método que realiza a etapa de interface com usuário da autenticação. Recebe como parâmetro
    * um objeto "usuario". Solicita ao usuário a entrada de um apelido e senha. O objeto "usuario"
    * é preenchido com esses dados e passado como parâmetro para o comando de pesquisa de usuário.
    * Se o comando de pesquisa encontra usuário com esses dados, o usuário é autenticado.
    * Caso contrário o usuário é cadastrado. O método retorna o resultado da autenticação.
    */
    Resultado autenticar(const Apelido&, const Senha&) throw(runtime_error);

};

/// Classe controladora dos serviços disponíveis ao usuário após a autenticação.

class CntrLNUsuario:public ILNUsuario{  // classe implementa a interface.

public:

    /**
    * Método responsável por incluir um livro na estante do usuário. 
    * Recebe como parâmetro um objeto "livro". Pesquisa se o usuario, armazenado em
    * "usuarioAtual" atingiu o limite de livros na biblioteca. Se sim, retorna esse resultado
    * sem incluir o livro.
    * Pesquisa se o usuario já posusi um exemplar daquele livro na estante virtual. Se sim, 
    * retorna esse resultado sem incluir o livro. 
    * Na negativa dos dois casos acima, consulta se o livro já está cadastrado.
    * Caso contrário, cadastra o exemplar. Se há erro ao cadastrar o exemplar, retorna.
    * No sucesso do cadastro, retorna o resultado de sucesso.
    */
    Resultado incluir(const Livro&) throw(runtime_error);
    
    /**
    * Método responsável por remover um livro da estante do usuário. 
    * Recebe como parâmetro um objeto "codigo". Pesquisa o livro na estante do usuário,
    * armazenando-o em "livroRecuperado. Caso não encontre, retorna mensagem de erro e o
    * resultado negativo.
    * Executa o comando de remoção do livro e retorna o resultado da remoção.
    */
    Resultado remover(const Codigo&) throw(runtime_error);
    ResultadoLivro consultar(const Codigo&) throw(runtime_error);
    ResultadoResenha escrever(const Titulo&, const Texto&, const Data&) throw(runtime_error);
    ResultadoUsuario pesquisar(const Apelido&) throw(runtime_error);
    ResultadoUsuario trocar(const Titulo&, const int) throw(runtime_error);
};


#endif // CONTROLADORAS_H_INCLUDED
