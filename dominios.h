///As classes definidas em "dominios.h" tratam cada uma
///de um dado necess�rio para o funcionamento do programa.
///Em geral, elas declaram o tipo de dado que armazenar�
///a informa��o em tela, alguns crit�rios b�sicos para
///sua valida��o e os m�todos de acesso a esses dados.
///Todas declaram para cada informa��o: 1. um m�todo de valida��o
///("validar") e os m�todos b�sicos de acesso ("setNome" e "getNome",
/// por exemplo).

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

// Declara��o de classe.

/// A classe "Nome" comporta o nome do usuario.
/// O nome nao deve exceder 15 caracteres,
/// nem conter quaisquer caracteres diferentes des
/// letras, ponto e espa�o em branco.

class Nome {
private:
        string nome;

        const static int TAMANHO_LIMITE = 15;

        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:
        //Declaracao das constantes de erro
        const static string NOME_FALHA;
        const static string NOME_ERRO_SISTEMA;

        // M�todos de acesso.


        void setNome(string) throw (invalid_argument);

        string getNome() const {
            return nome;
        }
};

/// A classe "Apelido" armazena o apelido do usu�rio.
/// O apelido n�o deve exceder 5 caracteres, sendo todos letras.

class Apelido {
private:
        string apelido;

        const static int TAMANHO_LIMITE = 5;

        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:

        //contantes de erro
        const static string APELIDO_FALHA;
        const static string APELIDO_ERRO_SISTEMA;
        const static string APELIDO_SUCESSO;
        // M�todos de acesso.
        void setApelido(string) throw (invalid_argument);

        string getApelido() const {
            return apelido;
        }
};

/// A classe "Telefone" comporta o n�mero do usu�rio,
/// deve ter 11 caracteres incluindo o c�digo de �rea.

class Telefone {
private:
        string telefone;

        const static int TAMANHO_LIMITE = 11;

        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string TELEFONE_FALHA;
        const static string TELEFONE_ERRO_SISTEMA;

        // M�todos de acesso.

        void setTelefone(string) throw (invalid_argument);

        string getTelefone() const {
            return telefone;
        }
};

/// A classe "Senha" armazena a senha do usu�rio.
/// N�o deve exceder quatro caracteres numericos.

class Senha {
private:
        string senha;

        const static int TAMANHO_LIMITE = 4;

        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string SENHA_FALHA;
        const static string SENHA_ERRO_SISTEMA;

        // M�todos de acesso.

        const static string SENHA_INVALIDA;

        void setSenha(string) throw (invalid_argument);

        string getSenha() const {
            return senha;
        }
};

/// A classe "Titulo" armazena o titulo do livro.
/// O titulo n�o deve exceder 20 caracteres ou possuir
/// dois espa�os em branco seguidos.

class Titulo {
private:
        string titulo;

        const static int TAMANHO_LIMITE = 20;

        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:
        //constatntes de erro
        const static string TITULO_FALHA;
        const static string TITULO_ERRO_SISTEMA;
        const static string TITULO_SUCESSO;

        // M�todos de acesso.

        void setTitulo(string) throw (invalid_argument);

        string getTitulo() const {
            return titulo;
        }
};

/// A classe "Autor" comporta o nome do autor.
/// O nome nao deve exceder 15 caracteres,
/// nem conter quaisquer caracteres diferentes des
/// letras, ponto e espa�o em branco.

class Autor {
private:
        string autor;

        const static int TAMANHO_LIMITE = 15;

        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:
        //Declaracao das constantes de erro
        const static string NOME_FALHA;
        const static string NOME_ERRO_SISTEMA;

        // M�todos de acesso.


        void setAutor(string) throw (invalid_argument);

        string getAutor() const {
            return autor;
        }
};

/// A classe "Data" comporta uma string de 6 caracteres
/// que comporta a data de publica��o do livro
/// em formato "dia/mes/ano".

class Data {
private:
        string data;

        const static int TAMANHO_LIMITE = 6;

        // M�todo respons�vel por valida��o.
        int converteDia(string data);
        int converteMes(string data);
        int converteAno(string data);
        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string DATA_FALHA;
        const static string DATA_ERRO_SISTEMA;

        // M�todos de acesso.

        void setData(string) throw (invalid_argument);

        string getData() const {
            return data;
        }
};

/// A classe "Codigo" armazena o codigo do livro
/// em questao, composto de 5 algarismos numericos.

class Codigo {
private:
        string codigo;

        const static int TAMANHO_LIMITE = 5;

        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string CODIGO_FALHA;
        const static string CODIGO_ERRO_SISTEMA;
        const static string CODIGO_SUCESSO;

        // M�todos de acesso.

        void setCodigo(string) throw (invalid_argument);

        string getCodigo() const {
            return codigo;
        }
};

/// A classe "Texto" armazena o texto da resenha sobre o livro.
/// O texto n�o pode exceder 40 caracteres quaisquer.

class Texto{
private:
        string texto;

        const static int TAMANHO_LIMITE = 40;

        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string TEXTO_FALHA;
        const static string TEXTO_ERRO_SISTEMA;

        // M�todos de acesso.

        void setTexto(string) throw (invalid_argument);

        string getTexto() const {
            return texto;
        }
};

/// A classe "GeneroLiterario" armazena o g�nero do livro.
/// Comporta apenas 5 op��es: epopeia, novela, conto,
/// ensaio e romance.

class GeneroLiterario {
private:
        string generoLiterario;


        // M�todo respons�vel por valida��o.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string GENERO_FALHA;
        const static string GENERO_ERRO_SISTEMA;

        // M�todos de acesso.

        void setGeneroLiterario(string) throw (invalid_argument);

        string getGeneroLiterario() const {
            return generoLiterario;
        }
};

class Troca{
private:
    string troca;

    void validar(string) throw (invalid_argument);

public:

    void setTroca(string) throw(invalid_argument);

    string getTroca() const{
        return troca;
    }
};


#endif // DOMINIOS_H_INCLUDED
