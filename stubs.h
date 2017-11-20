#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"
#include <stdexcept>
#include <iostream>
#include <cstring>

using namespace std;

/// Declaração de classe stub da interface ILNAutenticacao.

class StubLNAutenticacao:public ILNAutenticacao{

public:

    /// Definições de valores a serem usados como gatilhos para notificações de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    /// Declaração de método previsto na interface.

    Resultado autenticar(const Apelido&, const Senha&) throw(runtime_error);
    Resultado cadastrar(const Apelido&, const Senha&) throw(runtime_error);
};

/// Declaração de classe stub da interface ILNUsuario.

class StubLNUsuario:public ILNUsuario{  // classe implementa a interface.

public:

    /// Definições de valores a serem usados como gatilhos para notificações de erros.


    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    ///declaracoes dos metodos previstos na interface
    Resultado incluir(const Codigo&, const Titulo&, const GeneroLiterario&) throw(runtime_error);
    Resultado remover(const Codigo&) throw(runtime_error);
    ResultadoLivro consultar(const Codigo&) throw(runtime_error);
    ResultadoResenha escrever(const Titulo&, const Texto&, const Data&) throw(runtime_error);
    ResultadoUsuario pesquisar(const Apelido&) throw(runtime_error);
    ResultadoUsuario trocar(const Titulo&) throw(runtime_error);
};

#endif // STUBS_H_INCLUDED
