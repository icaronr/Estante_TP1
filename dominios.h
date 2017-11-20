///As classes definidas em "dominios.h" tratam cada uma
///de um dado necessário para o funcionamento do programa.
///Em geral, elas declaram o tipo de dado que armazenará
///a informação em tela, alguns critérios básicos para
///sua validação e os métodos de acesso a esses dados.
///Todas declaram para cada informação: 1. um método de validação
///("validar") e os métodos básicos de acesso ("setNome" e "getNome",
/// por exemplo).

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

// Declaração de classe.

/// A classe "Nome" comporta o nome do usuario.
/// O nome nao deve exceder 15 caracteres,
/// nem conter quaisquer caracteres diferentes des
/// letras, ponto e espaço em branco.

class Nome {
private:
        string nome;

        const static int TAMANHO_LIMITE = 15;

        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:
        //Declaracao das constantes de erro
        const static string NOME_FALHA;
        const static string NOME_ERRO_SISTEMA;

        // Métodos de acesso.


        void setNome(string) throw (invalid_argument);

        string getNome() const {
            return nome;
        }
};

/// A classe "Apelido" armazena o apelido do usuário.
/// O apelido não deve exceder 5 caracteres, sendo todos letras.

class Apelido {
private:
        string apelido;

        const static int TAMANHO_LIMITE = 5;

        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:

        //contantes de erro
        const static string APELIDO_FALHA;
        const static string APELIDO_ERRO_SISTEMA;
        const static string APELIDO_SUCESSO;
        // Métodos de acesso.
        void setApelido(string) throw (invalid_argument);

        string getApelido() const {
            return apelido;
        }
};

/// A classe "Telefone" comporta o número do usuário,
/// deve ter 11 caracteres incluindo o código de área.

class Telefone {
private:
        string telefone;

        const static int TAMANHO_LIMITE = 11;

        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string TELEFONE_FALHA;
        const static string TELEFONE_ERRO_SISTEMA;

        // Métodos de acesso.

        void setTelefone(string) throw (invalid_argument);

        string getTelefone() const {
            return telefone;
        }
};

/// A classe "Senha" armazena a senha do usuário.
/// Não deve exceder quatro caracteres numericos.

class Senha {
private:
        string senha;

        const static int TAMANHO_LIMITE = 4;

        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string SENHA_FALHA;
        const static string SENHA_ERRO_SISTEMA;

        // Métodos de acesso.

        const static string SENHA_INVALIDA;

        void setSenha(string) throw (invalid_argument);

        string getSenha() const {
            return senha;
        }
};

/// A classe "Titulo" armazena o titulo do livro.
/// O titulo não deve exceder 20 caracteres ou possuir
/// dois espaços em branco seguidos.

class Titulo {
private:
        string titulo;

        const static int TAMANHO_LIMITE = 20;

        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:
        //constatntes de erro
        const static string TITULO_FALHA;
        const static string TITULO_ERRO_SISTEMA;
        const static string TITULO_SUCESSO;

        // Métodos de acesso.

        void setTitulo(string) throw (invalid_argument);

        string getTitulo() const {
            return titulo;
        }
};

/// A classe "Autor" comporta o nome do autor.
/// O nome nao deve exceder 15 caracteres,
/// nem conter quaisquer caracteres diferentes des
/// letras, ponto e espaço em branco.

class Autor {
private:
        string autor;

        const static int TAMANHO_LIMITE = 15;

        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:
        //Declaracao das constantes de erro
        const static string NOME_FALHA;
        const static string NOME_ERRO_SISTEMA;

        // Métodos de acesso.


        void setAutor(string) throw (invalid_argument);

        string getAutor() const {
            return autor;
        }
};

/// A classe "Data" comporta uma string de 6 caracteres
/// que comporta a data de publicação do livro
/// em formato "dia/mes/ano".

class Data {
private:
        string data;

        const static int TAMANHO_LIMITE = 6;

        // Método responsável por validação.
        int converteDia(string data);
        int converteMes(string data);
        int converteAno(string data);
        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string DATA_FALHA;
        const static string DATA_ERRO_SISTEMA;

        // Métodos de acesso.

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

        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string CODIGO_FALHA;
        const static string CODIGO_ERRO_SISTEMA;
        const static string CODIGO_SUCESSO;

        // Métodos de acesso.

        void setCodigo(string) throw (invalid_argument);

        string getCodigo() const {
            return codigo;
        }
};

/// A classe "Texto" armazena o texto da resenha sobre o livro.
/// O texto não pode exceder 40 caracteres quaisquer.

class Texto{
private:
        string texto;

        const static int TAMANHO_LIMITE = 40;

        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string TEXTO_FALHA;
        const static string TEXTO_ERRO_SISTEMA;

        // Métodos de acesso.

        void setTexto(string) throw (invalid_argument);

        string getTexto() const {
            return texto;
        }
};

/// A classe "GeneroLiterario" armazena o gênero do livro.
/// Comporta apenas 5 opções: epopeia, novela, conto,
/// ensaio e romance.

class GeneroLiterario {
private:
        string generoLiterario;


        // Método responsável por validação.

        void validar(string) throw (invalid_argument);

public:
        //constantes de erro
        const static string GENERO_FALHA;
        const static string GENERO_ERRO_SISTEMA;

        // Métodos de acesso.

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
