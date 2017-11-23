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
//Declarações adiantadas

//class ILNUsuario;
///Declaracao do metodo que solicita a execucao dos comandos solicitados pelo usuario.
class ComandoIUUsuario {

public:

    // Método por meio do qual é solicitada a execução do comando.

    virtual void executar(ILNUsuario*) throw(runtime_error) = 0;

    // Método destrutor virtual.

    virtual ~ComandoIUUsuario(){}
};

///Declaracao do metodo de exibicao de estante.
class ComandoIUUsuarioExibir:public ComandoIUUsuario {

public:

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de inclusao de livro.
class ComandoIUUsuarioIncluir:public ComandoIUUsuario {

public:

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de remocao de livro.
class ComandoIUUsuarioRemover:public ComandoIUUsuario {

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de consulta de livro.
class ComandoIUUsuarioConsultar:public ComandoIUUsuario {

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de escrita de resenha de livro.
class ComandoIUUsuarioEscrever:public ComandoIUUsuario {

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de pesquisa de usuario.
class ComandoIUUsuarioPesquisar:public ComandoIUUsuario {

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};

///Declaracao do metodo de informacao de troca.
class ComandoIUUsuarioTrocar:public ComandoIUUsuario {

    // Método por meio do qual é solicitada a execução do comando.

    void executar(ILNUsuario*) throw(runtime_error);
};


#endif // COMANDOS_H_INCLUDED

