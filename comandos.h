#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"
#include "controladoras.h"
#include "global.h"
#include "unidadePersistencia.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>
//Declara��es adiantadas

//class ILNUsuario;
///Declaracao do metodo que solicita a execucao dos comandos solicitados pelo usuario.
class ComandoIUUsuario {

public:

    // M�todo por meio do qual � solicitada a execu��o do comando.

    virtual void executar(ILNUsuario*) throw(runtime_error) = 0;

    // M�todo destrutor virtual.

    virtual ~ComandoIUUsuario(){}
};

///Declaracao do metodo de exibicao de estante.
class ComandoIUUsuarioExibir:public ComandoIUUsuario {

public:

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de inclusao de livro.
class ComandoIUUsuarioIncluir:public ComandoIUUsuario {

public:

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de remocao de livro.
class ComandoIUUsuarioRemover:public ComandoIUUsuario {

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de consulta de livro.
class ComandoIUUsuarioConsultar:public ComandoIUUsuario {

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de escrita de resenha de livro.
class ComandoIUUsuarioEscrever:public ComandoIUUsuario {

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de pesquisa de usuario.
class ComandoIUUsuarioPesquisar:public ComandoIUUsuario {

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de informacao de troca.
class ComandoIUUsuarioTrocar:public ComandoIUUsuario {

    // M�todo por meio do qual � solicitada a execu��o do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};


#endif // COMANDOS_H_INCLUDED

