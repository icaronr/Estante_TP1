//---------------------------------------------------------------------------

#ifndef unidadePersistenciaH
#define unidadePersistenciaH
//---------------------------------------------------------------------------

#include "dominios.h"
#include "entidades.h"
#include <list>

// Posteriomente remover.

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "sqlite3.h"

using namespace std;

//---------------------------------------------------------------------------
//Classe EErroPersistencia.
///Esta classe define as variáveis e métodos utilizados em caso de erro na conexão 
///com o banco de dados. Como variável privada, possui a string "mensagem", que é 
///utilizada para armazenar a mensagem de erro produzida pelo programa.
///O método público "EErroPersistencia" recebe a string que será armazenada em mensagem. 
///A string pública "what" é utilizada para retornar a mensagem para outros métodos.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//---------------------------------------------------------------------------
//Classe ElementoResultado.
///A classe "ElementoResultado" recebe o retorno dos comandos que buscam valores no banco de dados.
///Os métodos "setNomeColuna" e "setValorColuna" servem apenas para atribuir às strings "nomeColuna"
///e "valorColuna" os valores recebidos do banco de dados.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;

        void setValorColuna(const string&);
        string getValorColuna() const;
};

//---------------------------------------------------------------------------
//Classe ComandoSQL.
///A classe "ComandoSQL" define os métodos de conexão do programa com o banco de dados gerado
///com a utilização do SQLite.
///O método público "ComandoSQL" informa o nome do banco de dados.
///O método público "executar" realiza a execução dos diversos comandos SQL possíveis. O método

class ComandoSQL {
private:
        /**
        * String que armazena o nome do banco de dados.
        */
        const char *nomeBancoDados;
        /**
        * Um ponteiro para banco de dados do SQLite3.
        */
        sqlite3 *bd;
        /**
        * String que armazena mensagem de erro, se existente.
        */
        char *mensagem;
        int rc;
        /**
         * Método que realiza a tentativa de abertura do banco de dados,
         * retornando mensagem de erro em caso de falha.
         */
        void conectar() throw (EErroPersistencia);
        /**
        * Método que realiza a tentativa de fechamento do banco de dados, retornando
        * mensagem de erro em caso de falha.
        */
        void desconectar() throw (EErroPersistencia);
        
        /*
        * Método que recebe os elementos encontrados no banco de dados conforme a pesquisa realizada.
        * Como parâmetros, recebe um inteiro que conta quantos elementos buscados foram encontrados,
        * e dois ponteiros para string, um apontando para o nome da coluna e outro para os valores daquela coluna.
        */
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        /*
        * Informa o nome do banco de dados.
        */
        ComandoSQL() {
             nomeBancoDados = "bancoEstante.db";
        }
        void executar() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoLerSenha.
///A classe "ComandoLerSenha" é essencial ao processo de autenticação. O método "ComandoLerSenha" 
///recebe o nome de usuário fornecido e por meio de comandos SQL, acessa a senha daquele usuário.
///O comando "getResultado" quando não encontra erros retorna a senha do usuario. Quando não
///consegue encontrar a senha para o nome de usuário fornecido, retorna uma mensagem de erro.

class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(Usuario);
        string getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarUsuario.
///Esta classe pesquisa um usuário no banco de dados por meio do apelido fornecido.

class ComandoPesquisarUsuario:public ComandoSQL {
public:
        /*
        * Este metódo utiliza um comando SQL para pesquisar um usuário no banco de dados a partir do apelido fornecido.
        */
        ComandoPesquisarUsuario(Apelido);
        /*
        * Este metódo parte do resultado encontrado no método acima para preencher um objeto "usuario" com os dados
        * encontrados no banco de dados, retornando o usuário pesquisado com todos os seus campos completos.
        */
        Usuario getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.
/// Esta classe contém apenas o método "ComandoCadastrarUsuario(Usuario)", ou seja, recebe como parâmetro
/// um objeto do tipo "usuario". Utiliza os métodos de acesso aos dados deste objeto (getApelido, 
/// getSenha, getNome, getTelefone) e passa o resultado desses gets para o banco de dados por meio de comando
/// INSERT do SQL, criando um novo usuário.  

class ComandoCadastrarUsuario:public ComandoSQL {
public:
        ComandoCadastrarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarUsuario.

class ComandoAtualizarUsuario:public ComandoSQL {
public:
        ComandoAtualizarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverUsuario.

class ComandoRemoverUsuario:public ComandoSQL {
public:
        ComandoRemoverUsuario(Apelido);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarLivro.

class ComandoPesquisarLivro:public ComandoSQL {
public:
        ComandoPesquisarLivro(Codigo);
        ComandoPesquisarLivro(Titulo);
        Livro getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarLivro.

class ComandoCadastrarLivro:public ComandoSQL {
public:
        ComandoCadastrarLivro(Livro);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarLivro.

class ComandoAtualizarLivro:public ComandoSQL {
public:
        ComandoAtualizarLivro(Livro);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverLivro.

class ComandoRemoverLivro:public ComandoSQL {
public:
        ComandoRemoverLivro(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarExemplar.

class ComandoPesquisarExemplar:public ComandoSQL {
public:
        ComandoPesquisarExemplar(Codigo);
        ComandoPesquisarExemplar(Apelido);
        Exemplar getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarExemplar.

class ComandoCadastrarExemplar:public ComandoSQL {
public:
        ComandoCadastrarExemplar(Exemplar);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarExemplar.

class ComandoAtualizarExemplar:public ComandoSQL {
public:
        ComandoAtualizarExemplar(Exemplar);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverExemplar.

class ComandoRemoverExemplar:public ComandoSQL {
public:
        ComandoRemoverExemplar(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarResenha.

class ComandoPesquisarResenha:public ComandoSQL {
public:
        ComandoPesquisarResenha(Codigo);
        ComandoPesquisarResenha(Apelido);
        Resenha getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarResenha.

class ComandoCadastrarResenha:public ComandoSQL {
public:
        ComandoCadastrarResenha(Resenha);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarResenha.

class ComandoAtualizarResenha:public ComandoSQL {
public:
        ComandoAtualizarResenha(Resenha);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverResenha.

class ComandoRemoverResenha:public ComandoSQL {
public:
        ComandoRemoverResenha(Codigo);
};

//---------------------------------------------------------------------------
//Classe ElementoResultado.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}


#endif
