#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"

using namespace std;

/// Declara��o de classes de teste.
///** Teste Unitario - Nome **
class TUNome{
private:
    /// Defini��es de constantes para evitar numeros m�gicos
    static string VALOR_VALIDO;
    static string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado
    Nome *nome;

    /// Estado do teste
    int estado;

    ///Declara��es de m�todos
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    /// Metodo que roda os testes.
    int run();
};
///** Teste Unitario - Apelido **
class TUApelido{
private:
     /// Defini��es de constantes para evitar numeros m�gicos
    string VALOR_VALIDO;
    string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado
    Apelido *apelido;

    /// Estado do teste
    int estado;

    ///Declara��es de m�todos
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    /// Metodo que roda os testes.
    int run();
};

///** Teste Unitario - Telefone **
class TUTelefone{
private:
    /// Defini��es de constantes para evitar numeros m�gicos
    string VALOR_VALIDO;
    string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado
    Telefone *telefone;

    /// Estado do teste
    int estado;

    /// Declara��es de m�todos
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    /// Metodo que roda os testes.
    int run();
};
///** Teste Unitario - Senha **
class TUSenha{
private:
    /// Defini��es de constantes para evitar numeros m�gicos
    string VALOR_VALIDO;
    string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado
    Senha *senha;

    /// Estado do teste
    int estado;

    /// Declara��es de m�todos
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    /// Metodo que roda os testes.
    int run();
};
///** Teste Unitario - Titulo **
class TUTitulo{
private:
    /// Defini��es de constantes para evitar numeros m�gicos
    string VALOR_VALIDO;
    string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado
    Titulo *titulo;

    /// Estado do teste
    int estado;

    /// Declara��es de m�todos
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    /// Metodo que roda os testes.
    int run();
};
///** Teste Unitario - Data **
class TUData{
private:
    /// Defini��es de constantes para evitar numeros m�gicos
    string VALOR_VALIDO;
    string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado
    Data *data;

    /// Estado do teste
    int estado;

    /// Declara��es de m�todos
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    /// Metodo que roda os testes.
    int run();
};

///** Teste Unitario - Codigo **
class TUCodigo {
private:
    /// Defini��es de constantes para evitar numeros m�gicos.
    string VALOR_VALIDO;
    string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado.
    Codigo *codigo;

    /// Estado do teste.
    int estado;

    /// Declara��es de m�todos.
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    /// Metodo que roda os testes.
    int run();
};

///** Teste Unitario - Texto **
class TUTexto{
private:
    /// Defini��es de constantes para evitar numeros m�gicos
    string VALOR_VALIDO;
    string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado
    Texto *texto;

    /// Estado do teste
    int estado;

    /// Declara��es de m�todos
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    /// Metodo que roda os testes.
    int run();
};

///** Teste Unitario - Genero Literario **
class TUGeneroLiterario{
private:
    /// Defini��es de constantes para evitar numeros m�gicos
    string VALOR_VALIDO;
    string VALOR_INVALIDO;

    /// Refer�ncia para o objeto a ser testado
    GeneroLiterario *generoLiterario;

    /// Estado do teste
    int estado;

    ///Declara��es de m�todos.
    /// Metodo que inicializa a classe.
    void setUp();
    /// Metodo responsavel por usar o 'delete' para liberar a memoria.
    void tearDown();
    /// Metodo que testa o cenario de sucesso.
    void testarCenarioSucesso();
    ///Metodo que testa o cenario de falha
    void testarCenarioFalha();

public:
    /// Defini��es de constantes para reportar resultado do teste.
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    /// Metodo que roda os testes.
    int run();
};

#endif // TESTES_H_INCLUDED
