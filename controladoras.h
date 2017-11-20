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


/// Declara��o de classe controladora de intera��o para o servi�o de autentica��o.

class CntrIUAutenticacao:public IUAutenticacao {

private:

    // Refer�ncia para servidor.

    ILNAutenticacao *cntrLNAutenticacao;

public:
    ResultadoAutenticacao cadastrar() throw(runtime_error);
    ResultadoAutenticacao autenticar() throw(runtime_error);

    void setCntrLNAutenticacao(ILNAutenticacao*);
};


void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}


/// Declara��o de controladora de intera��o para o servi�o de gerentes.

class CntrIUUsuario:public IUUsuario {

private:

    const static int INCLUIR   = 1;
    const static int REMOVER   = 2;
    const static int CONSULTAR = 3;
    const static int ESCREVER  = 4;
    const static int PESQUISAR  = 5;
    const static int TROCAR    = 6;
    const static int RETORNAR  = 7;

    // Refer�ncia para servidor.

    ILNUsuario *cntrLNUsuario;

public:

    // M�todo previsto na interface por meio do qual � solicitada execu��o da controladora.

    void executar(const Apelido&) throw(runtime_error);

    // M�todo por meio do qual � estabelecido relacionamento com o servidor.

    void setCntrLNUsuario(ILNUsuario *cntrLNUsuario){
        this->cntrLNUsuario = cntrLNUsuario;
    }
};

/// Declara��o de classe controladora de servi�os da interface ILNAutenticacao.

class CntrLNAutenticacao:public ILNAutenticacao{

public:

    /// Declara��o de m�todo previsto na interface.
    Resultado cadastrar(const Usuario&) throw(runtime_error);
    Resultado autenticar(const Apelido&, const Senha&) throw(runtime_error);

};

/// Declara��o de classe controladora de servi�os da interface ILNUsuario.

class CntrLNUsuario:public ILNUsuario{  // classe implementa a interface.

public:

    ///declaracoes dos metodos previstos na interface
    Resultado incluir(const Livro&) throw(runtime_error);
    Resultado remover(const Codigo&) throw(runtime_error);
    ResultadoLivro consultar(const Codigo&) throw(runtime_error);
    ResultadoResenha escrever(const Titulo&, const Texto&, const Data&) throw(runtime_error);
    ResultadoUsuario pesquisar(const Apelido&) throw(runtime_error);
    ResultadoUsuario trocar(const Titulo&, const int) throw(runtime_error);
};


#endif // CONTROLADORAS_H_INCLUDED
