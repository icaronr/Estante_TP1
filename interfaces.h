#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "global.h"

#include <stdexcept>
#include <list>

using namespace std;

// Declarações adiantadas.

class ILNAutenticacao;
class ILNUsuario;
class ILNGerente;
class ILNDesenvolvedor;

// Declarações de serviços na camada de apresentação
// -----------------------------------------------------------------

/// Declaração de interface para serviço de autenticação na camada de apresentação.

class IUAutenticacao {
public:
    /// Método por meio do qual é feito o cadastro.

    virtual ResultadoAutenticacao cadastrar() throw(runtime_error) = 0;

    /// Método por meio do qual é solicitada autenticacao.

    virtual ResultadoAutenticacao autenticar() throw(runtime_error) = 0;

    /// Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;
};

/// Declaração de interface para serviço de projeto na camada de apresentação.

class IUUsuario {
public:

    /// Método por meio do qual é solicitada autenticacao.

    virtual void executar(const Apelido&) throw(runtime_error) = 0;

    /// Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setCntrLNUsuario(ILNUsuario *) = 0;
};

// Declaração de interface para serviço de gerente na camada de apresentação.
/*
class IUGerente {
public:

    // Método por meio do qual é solicitada autenticacao.

    virtual void executar(const Matricula&) throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setCntrLNGerente(ILNGerente *) = 0;
};

// Declaração de interface para serviço de desenvolvedor na camada de apresentação.

class IUDesenvolvedor {
public:

    // Método por meio do qual é solicitada autenticacao.

    virtual void executar(const Matricula&) throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setCntrLNDesenvolvedor(ILNDesenvolvedor*) = 0;
};*/

// Declarações de serviços na camada de negócio
// ------------------------------------------------------------------

/// Declarações de interfaces para serviços na camada de negócio.

/// Declaração de interface para o serviço de autenticação na camada de negócio.

class ILNAutenticacao {
public:
    virtual Resultado cadastrar(const Usuario&) throw(runtime_error)= 0;
    virtual Resultado autenticar(const Apelido&, const Senha&) throw(runtime_error)= 0;
};

/// Declaração de interface para o serviço de projeto na camada de negócio.

class ILNUsuario {
public:
    virtual Resultado incluir(const Codigo&, const Titulo&, const GeneroLiterario&) throw(runtime_error) = 0;
    virtual Resultado remover(const Codigo&) throw(runtime_error) = 0;
    virtual ResultadoLivro consultar(const Codigo&) throw(runtime_error) = 0;
    virtual ResultadoResenha escrever(const Titulo&, const Texto&, const Data&) throw(runtime_error) = 0;
    virtual ResultadoUsuario pesquisar(const Apelido&) throw(runtime_error) = 0;
    virtual ResultadoUsuario trocar(const Titulo&, const int) throw(runtime_error) = 0;
};

// Declaração de interface para o serviço de gerente na camada de negócio.
/*
class ILNGerente {
public:
    virtual ResultadoGerente incluir(const Gerente&) throw(runtime_error) = 0;
    virtual ResultadoGerente remover(const Matricula&) throw(runtime_error) = 0;
    virtual ResultadoGerente pesquisar(const Matricula&) throw(runtime_error) = 0;
    virtual ResultadoGerente editar(const Gerente&) throw(runtime_error) = 0;
};

// Declaração de interface para o serviço de desenvolvedor na camada de negócio.

class ILNDesenvolvedor {
public:
    virtual ResultadoGerente incluir(const Desenvolvedor&) throw(runtime_error) = 0;
    virtual ResultadoGerente remover(const Matricula&) throw(runtime_error) = 0;
    virtual ResultadoGerente pesquisar(const Matricula&) throw(runtime_error) = 0;
    virtual ResultadoGerente editar(const Desenvolvedor&) throw(runtime_error) = 0;
};

// Declrações de serviços na camada de persistência.
// ------------------------------------------------------------------

class IPersistencia {

public:
    // Método por meio do qual é solicitada execução de comando.

    // Observe que o parâmetro é um ponteiro para a classe no topo da hierarquia de comandos.

    virtual void executar(const ComandoBancoDados*) throw(runtime_error) = 0;

};
*/

#endif // INTERFACES_H_INCLUDED
