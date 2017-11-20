#include "stubs.h"

/// Definições de método da classe stub do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o apelido e senha para comparar com os dados do servidor e retorna o valor do resultado.

Resultado StubLNAutenticacao::autenticar(const Apelido &apelido, const Senha &senha) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNAutenticacao::autenticar" << endl ;

    cout << "Apelido = " << apelido.getApelido() << endl ;
    cout << "Senha     = " << senha.getSenha()     << endl ;

    ResultadoAutenticacao resultado;

    // Diferentes comportamentos dependendo do valor da matrícula.

    if (apelido.getApelido() == Apelido::APELIDO_ERRO_SISTEMA){
        throw runtime_error("Erro de sistema");
    }else if(apelido.getApelido() == Apelido::APELIDO_FALHA){
        resultado.setValor(ResultadoAutenticacao::FALHA);
    }else{
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
    }


    return resultado;
}

Resultado StubLNAutenticacao::cadastrar(const Apelido &apelido, const Senha &senha) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNAutenticacao::cadastrar" << endl ;

    cout << "Apelido = " << apelido.getApelido() << endl ;
    cout << "Senha     = " << senha.getSenha()     << endl ;

    ResultadoAutenticacao resultado;

    // Diferentes comportamentos dependendo do valor da matrícula.

    if (apelido.getApelido() == Apelido::APELIDO_ERRO_SISTEMA){
        throw runtime_error("Erro de sistema");
    }else if(apelido.getApelido() == Apelido::APELIDO_FALHA){
        resultado.setValor(ResultadoAutenticacao::FALHA);
    }else{
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
    }


    return resultado;
}

/// Definições de método da classe stub do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe os dados do livro para comparar com os dados do servidor e retorna o valor do resultado.

Resultado StubLNUsuario::incluir(const Codigo &codigo, const Titulo &titulo, const GeneroLiterario &generoLiterario) throw(runtime_error){
    Livro livro;
    // Apresentar dados recebidos.

    cout << endl << "StubLNUsuario::incluir" << endl ;

    Resultado resultado;



    // Diferentes comportamentos dependendo do valor da matrícula.


    if(codigo.getCodigo() == Codigo::CODIGO_ERRO_SISTEMA ||//erro de sistema
        titulo.getTitulo() == Titulo::TITULO_ERRO_SISTEMA ||
       generoLiterario.getGeneroLiterario() == GeneroLiterario::GENERO_ERRO_SISTEMA){
        throw runtime_error("Erro de sistema");
    }else if(codigo.getCodigo() == Codigo::CODIGO_FALHA ||  //falha
        titulo.getTitulo() == Titulo::TITULO_FALHA ||
       generoLiterario.getGeneroLiterario() == GeneroLiterario::GENERO_FALHA){
            resultado.setValor(Resultado::FALHA);
       }else{                                               //sucesso
            resultado.setValor(Resultado::SUCESSO);
       }




    return resultado;
}


/// Definições de método da classe stub do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o codigo para comparar com os dados do servidor e retorna o valor do resultado.

Resultado StubLNUsuario::remover(const Codigo &codigo) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNUsuario::remover" << endl ;

    Resultado resultado;

    resultado.setValor(Resultado::SUCESSO);


    if (codigo.getCodigo() == Codigo::CODIGO_ERRO_SISTEMA){
        throw runtime_error("Erro de sistema");
    }else if(codigo.getCodigo() == Codigo::CODIGO_SUCESSO){
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
    }else{
        resultado.setValor(ResultadoAutenticacao::FALHA);
    }

    return resultado;
}


/// Definições de método da classe stub do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o código do livro para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoLivro StubLNUsuario::consultar(const Codigo &codigo) throw(runtime_error) {

    // Apresentar dados recebidos.
    Livro livro;
    GeneroLiterario genero;
    genero.setGeneroLiterario(GeneroLiterario::GENERO_FALHA);
    Titulo titulo;
    titulo.setTitulo(Titulo::TITULO_FALHA);

    cout << endl << "StubLNUsuario::consultar" << endl ;

    ResultadoLivro resultado;



    // A seguir devem ser implementados os diferentes comportamentos.

    // Sucesso.
    if(codigo.getCodigo() == Codigo::CODIGO_SUCESSO){
        resultado.setValor(Resultado::SUCESSO);
        livro.setCodigo(codigo);
        livro.setTitulo(titulo);
        livro.setGeneroLiterario(genero);
        resultado.setLivro(livro);
    }else if(codigo.getCodigo() == Codigo::CODIGO_ERRO_SISTEMA){// Erro de sistema.
        throw runtime_error("Erro de sistema");
    }else{ // Falha.
        resultado.setValor(Resultado::SUCESSO);
    }




    return resultado;
}


/// Definições de método da classe stub do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe os dados da resenha para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoResenha StubLNUsuario::escrever(const Titulo &titulo, const Texto &texto, const Data &data) throw(runtime_error) {
    Resenha resenha;
    // Apresentar dados recebidos.

    cout << endl << "StubLNUsuario::escrever" << endl ;

    ResultadoResenha resultado;



    // A seguir devem ser implementados os diferentes comportamentos.
    if(data.getData() == Data::DATA_ERRO_SISTEMA || // Erro de sistema.
        titulo.getTitulo() == Titulo::TITULO_ERRO_SISTEMA ||
       texto.getTexto() == Texto::TEXTO_ERRO_SISTEMA)
    {
        throw runtime_error("Erro de sistema");
    }else if(data.getData() == Data::DATA_FALHA || // Falha.
        titulo.getTitulo() == Titulo::TITULO_FALHA ||
       texto.getTexto() == Texto::TEXTO_FALHA)
       {
       resultado.setValor(Resultado::FALHA);
       }else{
            resultado.setValor(Resultado::SUCESSO); // Sucesso.
            resenha.setData(data);
            resenha.setTexto(texto);
            resenha.setTitulo(titulo);
            resultado.setResenha(resenha);
       }


    return resultado;
}


/// Definições de método da classe stub do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o apelido do usuário para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoUsuario StubLNUsuario::pesquisar(const Apelido &apelido) throw(runtime_error) {
    //Inicializacao do usuario valido

    Usuario usuario;
    Nome nome;
    nome.setNome("Johnny Test");

    Apelido APELIDO_VALIDO;
    APELIDO_VALIDO.setApelido(Apelido::APELIDO_SUCESSO);

    Telefone telefone;
    string numeros = "61888287546";
    telefone.setTelefone(numeros);

    usuario.setApelido(APELIDO_VALIDO);

    usuario.setNome(nome);

    usuario.setTelefone(telefone);

    //Trigger de erro de sistema

    // Apresentar dados recebidos.

    cout << endl << "StubLNUsuario::pesquisar" << endl ;

    ResultadoUsuario resultado;
    // Sucesso.
    if(apelido.getApelido() == APELIDO_VALIDO.getApelido()){
        resultado.setValor(Resultado::SUCESSO);
        resultado.setUsuario(usuario);
    }else if(apelido.getApelido() == Apelido::APELIDO_ERRO_SISTEMA){// Erro de sistema.
        throw runtime_error("Erro de sistema");
    }else{// Falha.
        resultado.setValor(Resultado::FALHA);
    }

    return resultado;
}


/// Definições de método da classe stub do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o título do livro para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoUsuario StubLNUsuario::trocar(const Titulo &titulo) throw(runtime_error) {
    Usuario usuario;
    Apelido apelido;
    Nome nome;
    Telefone telefone;

    // Apresentar dados recebidos.

    cout << endl << "StubLNUsuario::trocar" << endl ;

    ResultadoUsuario resultado;



    // A seguir devem ser implementados os diferentes comportamentos.

    if(titulo.getTitulo() == Titulo::TITULO_ERRO_SISTEMA){// Erro de sistema.
         throw runtime_error("Erro de sistema");

    }else if(titulo.getTitulo() == Titulo::TITULO_SUCESSO){// Sucesso.
        resultado.setValor(Resultado::SUCESSO);
        nome.setNome(Nome::NOME_FALHA);
        apelido.setApelido(Apelido::APELIDO_FALHA);
        telefone.setTelefone(Telefone::TELEFONE_FALHA);
        usuario.setApelido(apelido);
        usuario.setNome(nome);
        usuario.setTelefone(telefone);
        resultado.setUsuario(usuario);

    }else{
        resultado.setValor(Resultado::FALHA);// Falha.
    }


    return resultado;
}
