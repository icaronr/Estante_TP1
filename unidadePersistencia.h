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

        /**
        * Método que recebe os elementos encontrados no banco de dados conforme a pesquisa realizada.
        * Como parâmetros, recebe um inteiro que conta quantos elementos buscados foram encontrados,
        * e dois ponteiros para string, um apontando para o nome da coluna e outro para os valores daquela coluna.
        */
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        /**
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
        /**
        * Este metódo utiliza um comando SQL para pesquisar um usuário no banco de dados a partir do apelido fornecido.
        */
        ComandoPesquisarUsuario(Apelido);
        /**
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
        /**
        * Recebe apenas um objeto "usuario" como parâmetro. Não retorna valores.
        */
        ComandoCadastrarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarUsuario.
/// Esta classe contém apenas o método "ComandoAtualizarUsuario", que utiliza o comando UPDATE do SQLite
/// para modificar no banco de dados os atributos do usuário recebido como parâmetro.

class ComandoAtualizarUsuario:public ComandoSQL {
public:
        /**
        * Recebe apenas um objeto "usuario" como parâmetro. Não retorna valores.
        */
        ComandoAtualizarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverUsuario.
///Esta classe contém apenas o método "ComandoRemoverUsuario" que utiliza o comando DELETE do SQLite
/// para remover do banco de dados o usuário recebido como parâmetro.

class ComandoRemoverUsuario:public ComandoSQL {
public:
        /**
        * Recebe apenas um objeto "usuario" como parâmetro. Não retorna valores
        */
        ComandoRemoverUsuario(Apelido);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarLivro.
/// Esta classe contém os métodos necessários para realizar a busca de livros no banco de dados
/// utilizando tanto código como título.

class ComandoPesquisarLivro:public ComandoSQL {
public:
        /**
        * Método que utiliza o comando SELECT do SQLite para realizar a busca por código.
        * Recebe como parâmetro um código de livro. Não retorna valores.
        */
        ComandoPesquisarLivro(Codigo);

        /**
        * Método que utiliza o comando SELECT do SQLite para realizar a busca por título.
        * Recebe como parâmetro um título de livro. Não retorna valores.
        */
        ComandoPesquisarLivro(Titulo);

        /**
        * Método que utiliza o resultado da busca realizada pelos métodos acima para
        * preencher um objeto "livro" com os dados encontrados no banco. Retorna o objeto
        * "livro" com todos os campos preenchidos em caso de sucesso. Em caso de falha retorna
        * mensagem de erro.
        */
        Livro getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarLivro.
/// Esta classe contém apenas o método "ComandoCadastrarLivro", que utiliza o comando INSERT do SQLite
/// para inserir valores de um novo livro no banco de dados.

class ComandoCadastrarLivro:public ComandoSQL {
public:
       /**
        * Recebe como parâmetro um objeto "livro". Não retorna valores.
        */
        ComandoCadastrarLivro(Livro);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarLivro.
/// Esta classe contém apenas o método "ComandoAtualizarLivro", que utiliza o comando UPDATE do SQLite
/// para modificar valores de novo livro no banco de dados.

class ComandoAtualizarLivro:public ComandoSQL {
public:
        /**
        * Recebe como parâmetro um objeto "livro". Não retorna valores.
        */
        ComandoAtualizarLivro(Livro);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverLivro.
/// Esta classe contém apenas o método "ComandoRemoverLivro" que utiliza o comando DELETE do SQLite
/// para remover do banco de dados os valores do livro em questão.

class ComandoRemoverLivro:public ComandoSQL {
public:
        /**
        * Recebe como parâmetro um objeto "livro".
        */
        ComandoRemoverLivro(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarExemplar.
/// Esta classe contém apenas o método "ComandoPesquisarExemplar" que utiliza o comando SELECT do SQLite
/// para pesquisar no banco de dados exemplares do livro desejado.

class ComandoPesquisarExemplar:public ComandoSQL {
public:
        /**
        * Recebe como parâmetro o código do livro buscado. Não retorna valores.
        */
        ComandoPesquisarExemplar(Codigo);
        /**
        * Recebe como parâmetro o apelido do usuario que posssui o exemplar. Não retorna valores.
        */
        ComandoPesquisarExemplar(Apelido);
        /**
        * Não recebe parâmetro. Utiliza o resultado da busca realizada pelos métodos acima (constante
        * da variável "listaResultado") para preencher os campos de um objeto "exemplar". Retorna este objeto.
        */
        Exemplar getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarExemplar.
/// Esta classe contém apenas o método "ComandoCadastrarExemplar", que utiliza o comando INSERT do SQLite
/// para inserir valores de um novo exemplar no banco de dados.

class ComandoCadastrarExemplar:public ComandoSQL {
public:
        /**
        * Recebe como parâmetro um objeto "exemplar". Não retorna valores.
        */
        ComandoCadastrarExemplar(Exemplar);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarExemplar.
/// Esta classe contém apenas o método "ComandoAtualizarExemplar", que utiliza o comando UPDATE do SQLite
/// para modificar valores de um exemplar no banco de dados.

class ComandoAtualizarExemplar:public ComandoSQL {
public:
        /**
        * Recebe como parâmetro um objeto "exemplar". Não retorna valores.
        */
        ComandoAtualizarExemplar(Exemplar);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverExemplar.
/// Esta classe contém apenas o método "ComandoRemoverExemplar", que utiliza o comando DELETE do SQLite
/// para remover um exemplar do banco de dados.

class ComandoRemoverExemplar:public ComandoSQL {
public:
        /**
        * Recebe como parâmetro um objeto "codigo" e um objeto "apelido". Não retorna valores.
        */
        ComandoRemoverExemplar(Codigo, Apelido);
        ComandoRemoverExemplar(Codigo);
        ComandoRemoverExemplar(Apelido);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarResenha.
/// Esta classe contém os métodos necessários para realizar a busca de livros no banco de dados
/// utilizando tanto código como título.

class ComandoPesquisarResenha:public ComandoSQL {
public:
        /**
        * Método que utiliza o comando SELECT do SQLite para realizar a busca de resenha por código.
        * Recebe como parâmetro um código de livro. Não retorna valores.
        */
        ComandoPesquisarResenha(Codigo);
        /**
        * Método que utiliza o comando SELECT do SQLite para realizar a busca de resenha por apelido.
        * Recebe como parâmetro um código de livro. Não retorna valores.
        */
        ComandoPesquisarResenha(Apelido);
        /**
        * Método que utiliza o resultado da busca realizada pelos métodos acima para
        * preencher um objeto "resenha" com os dados encontrados no banco. Retorna o objeto
        * "resenha" com todos os campos preenchidos em caso de sucesso. Em caso de falha retorna
        * mensagem de erro.
        */
        Resenha getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarResenha.
/// Esta classe contém apenas o método "ComandoCadastrarResenha", que utiliza o comando INSERT do SQLite
/// para inserir valores de uma nova resenha no banco de dados.

class ComandoCadastrarResenha:public ComandoSQL {
public:
       /**
        * Recebe como parâmetro um objeto "resenha". Não retorna valores.
        */
        ComandoCadastrarResenha(Resenha);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarResenha.
/// Esta classe contém apenas o método "ComandoAtualizarResenha", que utiliza o comando UPDATE do SQLite
/// para modificar valores de uma resenha no banco de dados.

class ComandoAtualizarResenha:public ComandoSQL {
public:
       /**
        * Recebe como parâmetro um objeto "resenha". Não retorna valores.
        */
        ComandoAtualizarResenha(Resenha);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverResenha.
/// Esta classe contém apenas o método "ComandoRemoverResenha", que utiliza o comando DELETE do SQLite
/// para remover uma resenha do banco de dados.

class ComandoRemoverResenha:public ComandoSQL {
public:
        /**
        * Recebe como parâmetro um objeto "codigo" e um objeto "apelido". Não retorna valores.
        */
        ComandoRemoverResenha(Codigo, Apelido);
        ComandoRemoverResenha(Codigo);
        ComandoRemoverResenha(Apelido);
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
