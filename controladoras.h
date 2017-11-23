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


/// Classe controladora de interacao para o servico de autenticacao.

class CntrIUAutenticacao:public IUAutenticacao {

private:

    /**
    * Ponteiro para a controladora de autenticacao na camada de negocio.
    */
    ILNAutenticacao *cntrLNAutenticacao;

public:
    
    /**
     * Este metodo publico realiza o contato com o usuario para solicitar seus dados para cadastro.
     * Primeiro utiliza os servicos de entrada e saida no console para solicitar apelido, senha, nome e telefone.
     * Em seguida envia para a autenticacao no servico de logica de negocio ("cntrLNAutenticacao->cadastrar()").
     * O metodo determina se a autenticacao falhou (resultado = 1) ou obteve sucesso (resultado = 0).
     * Retorna um objeto do tipo "ResultadoAutenticacao" com o apelido do usuÃ¡rio que tentou o acesso e o resultado da solicitacao.
     */
    ResultadoAutenticacao cadastrar() throw(runtime_error);
    
    /**
     * Este metodo realiza o contato com o usuario para solicitar seus dados para autenticacao.
     * Primeiro utiliza os servicos de entrada e saida no console para solicitar apelido e senha.
     * Em seguida envia para a autenticacao no servico de logica de negocio ("cntrLNAutenticacao->autenticar()").
     * O metodo determina se a autenticacao falhou (resultado = 1) ou obteve sucesso (resultado = 0).
     * Retorna um objeto do tipo "ResultadoAutenticacao" com o apelido do usuario que tentou o acesso e o resultado da solicitacao.
     */
    ResultadoAutenticacao autenticar() throw(runtime_error);

    void setCntrLNAutenticacao(ILNAutenticacao*);
};
evoid inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}


/// Declaracao de controladora de interacao para o servico de gerentes.

class CntrIUUsuario:public IUUsuario {

private:

    const static int INCLUIR   = 1; /**< Valor constante para inclusao. */
    const static int REMOVER   = 2; /**< Valor constante para remocao. */
    const static int CONSULTAR = 3; /**< Valor constante para consulta. */
    const static int ESCREVER  = 4; /**< Valor constante para escrita. */ 
    const static int PESQUISAR  = 5; /**< Valor constante para pesquisa. */ 
    const static int TROCAR    = 6; /**< Valor constante para troca. */
    const static int RETORNAR  = 7; /**< Valor constante para retorno. */

    /**
    * Ponteiro para conectar a interface de usuario com a controladora de negocio.
    */
    ILNUsuario *cntrLNUsuario;

public:

    /**
    * Este metodo recebe como parametro o apelido do usuario que vai selecionar uma opcao a ser executada.
    * Eh apresentada uma tela ao usuario com as diversas opcoes de acao no programa numeradas de 1 a 7.
    * A opcao selecionada eh armazenada no inteiro "opcao", que selecionara o metodo correto a ser chamado.
    * A depender da opcao, o respectivo comando de logica de negocio eh chamado. No caso da opcao "RETORNAR",
    * o programa eh simplesmente encerrado. O metodo nao returna nenhum valor.
    */
    void executar(const Apelido&) throw(runtime_error);

    /**
    * MÃ©todo por meio do qual Ã© estabelecido relacionamento com o servidor.
    */ 
    void setCntrLNUsuario(ILNUsuario *cntrLNUsuario){
        this->cntrLNUsuario = cntrLNUsuario;
    }
};

/// Classe controladora de serviÃ§os da interface de autenticaÃ§Ã£o a nÃ­vel de negÃ³cio.

class CntrLNAutenticacao:public ILNAutenticacao{

public:

    /**
    * Metodo que realiza a etapa de interface com usuario do cadastro. Recebe como parametro
    * um objeto "usuario". Solicita ao usuario a entrada de um apelido e senha. O objeto "usuario"
    * eh preenchido com esses dados e passado como parametro para o comando de pesquisa de usuario.
    * Se o comando de pesquisa encontra usuario com esses dados, o metodo informa que o nome esta em uso.
    * Caso contrario o usuario eh cadastrado. O metodo retorna o resultado do cadastro.
    */
    Resultado cadastrar(const Usuario&) throw(runtime_error);
    
    /**
    * Metodo que realiza a etapa de interface com usuario da autenticacao. Recebe como parametro
    * um objeto "usuario". Solicita ao usuario a entrada de um apelido e senha. O objeto "usuario"
    * eh preenchido com esses dados e passado como parametro para o comando de pesquisa de usuario.
    * Se o comando de pesquisa encontra usuario com esses dados, o usuario eh autenticado.
    * Caso contrario o usuario eh cadastrado. O metodo retorna o resultado da autenticacao.
    */
    Resultado autenticar(const Apelido&, const Senha&) throw(runtime_error);

};

/// Classe controladora dos servicos disponiveis ao usuario apos a autenticacao.

class CntrLNUsuario:public ILNUsuario{  // classe implementa a interface.

public:

    /**
    * Metodo responsavel por incluir um livro na estante do usuario. 
    * Recebe como parametro um objeto "livro". Pesquisa se o usuario, armazenado em
    * "usuarioAtual" atingiu o limite de livros na biblioteca. Se sim, retorna esse resultado
    * sem incluir o livro.
    * Pesquisa se o usuario ja posusi um exemplar daquele livro na estante virtual. Se sim, 
    * retorna esse resultado sem incluir o livro. 
    * Na negativa dos dois casos acima, consulta se o livro ja esta cadastrado.
    * Caso contrario, cadastra o exemplar. Se ha erro ao cadastrar o exemplar, retorna.
    * No sucesso do cadastro, retorna o resultado de sucesso.
    */
    Resultado incluir(const Livro&) throw(runtime_error);
    
    /**
    * Metodo responsavel por remover um livro da estante do usuario. 
    * Recebe como parametro um objeto "codigo". Pesquisa o livro na estante do usuario,
    * armazenando-o em "livroRecuperado. Caso nao encontre, retorna mensagem de erro e o
    * resultado negativo.
    * Executa o comando de remocao do livro e retorna o resultado da remocao.
    */
    Resultado remover(const Codigo&) throw(runtime_error);
    
    /**
    * Metodo responsavel por consultar um livro no banco de dados.
    * Recebe como parametro um objeto "codigo". Pesquisa o livro no banco de dados,
    * armazenando-o em "livroRecuperado. Caso nao encontre, retorna mensagem de erro e o
    * resultado negativo.
    * Retorna o resultado da remocao.
    */
    ResultadoLivro consultar(const Codigo&) throw(runtime_error);
    
    /**
    * Metodo responsavel por consultar um livro no banco de dados.
    * Recebe como parametro um objeto "titulo", um objeto "texto" e um objeto "data".
    * Cria um objeto "resenha" e o preenche com os valores de titulo, texto e data recebidos.
    * Pesquisa o livro cujo titulo foi recebido. Caso encontrado, cadastra a resenha no sistema
    * por meio do comando correspondente.
    * Caso o livro nao tenha sido cadastrado, informa o erro e retorna.
    */
    ResultadoResenha escrever(const Titulo&, const Texto&, const Data&) throw(runtime_error);
    
    /**
    * Metodo responsavel por pesquisar um usuario no banco de dados.
    * Recebe como parametro um objeto "apelido".
    * Cria um objeto de usuario ("usuarioRecuperado"). Pesquisa o usuario na base de dados pelo apelido.
    * Caso encontra, seta o "usuarioRecuperado" para o valor do usuario encontrado.
    * por meio do comando correspondente.
    * Caso o usuario nao tenha sido cadastrado, informa o erro e retorna.
    */
    ResultadoUsuario pesquisar(const Apelido&) throw(runtime_error);
    ResultadoUsuario trocar(const Titulo&, const int) throw(runtime_error);
    
    /**
    *Método responsável por recuperar os dados acerca da estante do usuário atual.
    *Carrega os exemplares encontrados no banco de dados que possuem o apelido do usuario
    */
    Resultado contabilizar() throw(runtime_error);
};


#endif // CONTROLADORAS_H_INCLUDED
