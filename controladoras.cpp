#include "controladoras.h"
#include "comandos.h"
#include "interfaces.h"
#include "global.h"

// Definições de métodos da classe CntrIUAutenticacao.
///Este metodo realiza o contato com o usuario para solicitar seus dados para autenticacao.
///Primeiro utiliza os servicos de entrada e saida no console para solicitar apelido e senha.
///Em seguida envia para a autenticacao no servico de logica de negocio ("cntrLNAutenticacao->autenticar()").
///O metodo determina se a autenticacao falhou (resultado = 1) ou obteve sucesso (resultado = 0).
///Retorna um objeto do tipo ResultadoAutenticacao com o apelido do usuario que tentou o acesso e o resultado da solicitacao.
ResultadoAutenticacao CntrIUAutenticacao::autenticar() throw(runtime_error) {

    ResultadoAutenticacao resultadoAutenticacao;
    Resultado resultado;
    Apelido apelido;
    Senha senha;
    string entrada;

    // Solicitar apelido e senha.
    while(true){
        while(true) {

            try {
                cout << "Digite o apelido : ";
                cin >> entrada;
                apelido.setApelido(entrada);
                cout << "Digite a senha     : ";
                cin >> entrada;
                senha.setSenha(entrada);
                break;
            }
            catch (const invalid_argument &exp) {
                cout << endl << "Dado em formato incorreto." << endl;
            }
        }

        // Solicitar autenticação.

        resultado = cntrLNAutenticacao->autenticar(apelido, senha);

        // Informar resultado da autenticação.

        if(resultado.getValor() == ResultadoAutenticacao::FALHA){
            cout << endl << "Falha na autenticacao." << endl;
            system("PAUSE");
        }else{
            resultadoAutenticacao.setValor(resultado.getValor());
            resultadoAutenticacao.setApelido(apelido);

            break;
        }


    }
    return resultadoAutenticacao;
}

ResultadoAutenticacao CntrIUAutenticacao::cadastrar() throw(runtime_error) {

    ResultadoAutenticacao resultadoAutenticacao;
    Usuario usuario;
    Resultado resultado;
    Apelido apelido;
    Senha senha;
    Nome nome;
    Telefone telefone;
    string entrada;

    // Solicitar apelido e senha.
    while(true){
        while(true) {

            try {
                cout << "Digite o apelido (5 letras): ";
                cin >> entrada;
                apelido.setApelido(entrada);
                cout << "Digite a senha (4 letras sem repeticao): ";
                cin >> entrada;
                senha.setSenha(entrada);
                cout << "Digite o nome (até 15 caracteres)";
                cin >> entrada;
                nome.setNome(entrada);
                cout << "Digite o telefone (11 caracteres)";
                cin >> entrada;
                telefone.setTelefone(entrada);
                break;
            }
            catch (const invalid_argument &exp) {
                cout << endl << "Dado em formato incorreto." << endl;
            }
        }

        // Solicitar autenticação.
        resultado = cntrLNAutenticacao->cadastrar(usuario);

        // Informar resultado da autenticação.

        if(resultado.getValor() == ResultadoAutenticacao::FALHA){
            cout << endl << "Falha na autenticacao." << endl;
        }else{
            resultadoAutenticacao.setValor(resultado.getValor());
            resultadoAutenticacao.setApelido(apelido);
            break;
        }
        system("PAUSE");

    }
    return resultadoAutenticacao;
}


// Definições de métodos da classe CntrIUUsuario.
///Este metodo recebe como parâmetro o apelido do usuario que vai selecionar uma opcao a ser executada.
///e apresentada uma tela ao usuario com as diversas opcoes de acao no programa numeradas de 1 a 7.
///A opcao selecionada e armazenada no inteiro "opcao", que selecionara o metodo correto a ser chamado.
///A depender da opcao, o respectivo comando de logica de negocio e chamado. No caso da opcao "RETORNAR",
///o programa e simplesmente encerrado.
void CntrIUUsuario::executar(const Apelido &apelido) throw(runtime_error){

    ComandoIUUsuario *comando;

    int opcao;

    while(true){

        // Ilustra limpeza de tela.

        system("CLS");

        // Apresentar as opções.

        cout << endl << "Gerenciamento de Usuario." << endl << endl;

        cout << "Incluir Livro       - " << INCLUIR << endl;
        cout << "Remover Livro       - " << REMOVER << endl;
        cout << "Consultar Livro     - " << CONSULTAR << endl;
        cout << "Escrever Resenha    - " << ESCREVER << endl;
        cout << "Pesquisar Usuario   - " << PESQUISAR << endl;
        cout << "Trocar Livro        - " << TROCAR << endl;
        cout << "Retornar            - " << RETORNAR << endl << endl;
        cout << "Selecione uma opcao :";

        cin >> opcao;

        switch(opcao){
            case INCLUIR:   comando = new ComandoIUUsuarioIncluir();
                            comando->executar(cntrLNUsuario);
                            delete comando;
                            break;
            case REMOVER:   comando = new ComandoIUUsuarioRemover();
                            comando->executar(cntrLNUsuario);
                            delete comando;
                            break;
            case CONSULTAR: comando = new ComandoIUUsuarioConsultar();
                            comando->executar(cntrLNUsuario);
                            delete comando;
                            break;
            case ESCREVER:  comando = new ComandoIUUsuarioEscrever();
                            comando ->executar(cntrLNUsuario);
                            delete comando;
                            break;
            case PESQUISAR: comando = new ComandoIUUsuarioPesquisar();
                            comando->executar(cntrLNUsuario);
                            delete comando;
                            break;
            case TROCAR:    comando = new ComandoIUUsuarioTrocar();
                            comando->executar(cntrLNUsuario);
                            delete comando;
                            break;
        }

        if(opcao == RETORNAR){
            break;
        }

    }

    return;
}


//Definições dos métodos da classe CntrLNAutenticacao

/// Lógica de Negócio do método responsável pela autenticação.
/// Recebe o apelido e senha para comparar com os dados do servidor e retorna o valor do resultado.

Resultado CntrLNAutenticacao::autenticar(const Apelido &apelido, const Senha &senha) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "CntrLNAutenticacao::autenticar" << endl ;

    cout << "Apelido = " << apelido.getApelido() << endl ;
    cout << "Senha     = " << senha.getSenha()     << endl ;

    ResultadoAutenticacao resultado;

    // Diferentes comportamentos dependendo do valor da matrícula.

    //Ler do banco de dados, se usuario e senha bater -> autentica, senao -> erro.
    Usuario usuario;
    usuario.setApelido(apelido);
    usuario.setSenha(senha);
    ComandoLerSenha comandoLerSenha(usuario);

    try{
        comandoLerSenha.executar();
        string senhaRecuperada;
        senhaRecuperada = comandoLerSenha.getResultado();

        //Compara a senha do banco com a senha informada
        if(senhaRecuperada == senha.getSenha()){
            resultado.setValor(ResultadoAutenticacao::SUCESSO);
            ComandoPesquisarUsuario comandoPesquisarUsuario(apelido);
            usuarioAtual = comandoPesquisarUsuario.getResultado();
        }else{
            resultado.setValor(ResultadoAutenticacao::FALHA);
            cout << endl << "Senha digitada diferente da cadastrada.";
            cout << endl << endl << "Digite algo para continuar.";
        getch();
        }


    }
    catch(EErroPersistencia exp) {
                        cout << endl << exp.what();
                        cout << endl << endl << "Digite algo para continuar.";
                        getch();
    }

    return resultado;
}

Resultado CntrLNAutenticacao::cadastrar(const Usuario &usuario) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "CntrLNAutenticacao::cadastrar" << endl ;

    cout << "Apelido = " << usuario.getApelido().getApelido() << endl;
    cout << "Senha   = " << usuario.getSenha().getSenha() << endl;

    ResultadoAutenticacao resultado;

    // Diferentes comportamentos dependendo do valor da matrícula.
    //Procura o apelido no banco de dados, se nao encontrar -> cadastra, se encontrar -> diz que ja esta em uso
    try{
        ComandoPesquisarUsuario comandoPesquisarUsuario(usuario.getApelido());
        comandoPesquisarUsuario.executar();
        Usuario usuarioRecuperado;
        usuarioRecuperado = comandoPesquisarUsuario.getResultado();
    }
    catch(EErroPersistencia exp){
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
        ComandoCadastrarUsuario comandoCadastrarUsuario(usuario);
        comandoCadastrarUsuario.executar();
        return resultado;
    }
    resultado.setValor(ResultadoAutenticacao::FALHA);
 /*   if (apelido.getApelido() == Apelido::APELIDO_ERRO_SISTEMA){
        throw runtime_error("Erro de sistema");
    }else if(apelido.getApelido() == Apelido::APELIDO_FALHA){

    }else{

    }
*/

    return resultado;
}


/// Definições de métodos do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe os dados do livro para comparar com os dados do servidor e retorna o valor do resultado.

Resultado CntrLNUsuario::incluir(const Codigo &codigo, const Titulo &titulo, const GeneroLiterario &generoLiterario) throw(runtime_error){
    Livro livro;
    // Apresentar dados recebidos.

    cout << endl << "CntrLNUsuario::incluir" << endl ;

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


/// Definições de métodos do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o codigo para comparar com os dados do servidor e retorna o valor do resultado.

Resultado CntrLNUsuario::remover(const Codigo &codigo) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "CntrLNUsuario::remover" << endl ;

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


/// Definições de métodos do controlador da lógica de negócio de usuário.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o código do livro para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoLivro CntrLNUsuario::consultar(const Codigo &codigo) throw(runtime_error) {

    // Apresentar dados recebidos.
    Livro livro;
    GeneroLiterario genero;
    genero.setGeneroLiterario(GeneroLiterario::GENERO_FALHA);
    Titulo titulo;
    titulo.setTitulo(Titulo::TITULO_FALHA);

    cout << endl << "CntrLNUsuario::consultar" << endl ;

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


/// Definições de métodos do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe os dados da resenha para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoResenha CntrLNUsuario::escrever(const Titulo &titulo, const Texto &texto, const Data &data) throw(runtime_error) {
    Resenha resenha;
    Livro livroRecuperado;
    // Apresentar dados recebidos.

    cout << endl << "CntrLNUsuario::escrever" << endl ;

    ResultadoResenha resultado;
    resenha.setTitulo(titulo);
    resenha.setTexto(texto);
    resenha.setData(data);
    resenha.setApelido(usuarioAtual.getApelido());
    try{
        ComandoPesquisarLivro comandoPesquisarLivro(titulo);
        comandoPesquisarLivro.executar();
        livroRecuperado = comandoPesquisarLivro.getResultado();
        resenha.setCodigo(livroRecuperado.getCodigo());
    }
    catch(EErroPersistencia exp){
        cout << "O livro informado ainda nao foi cadastrado." << endl;
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    ComandoCadastrarResenha comandoCadastrarResenha(resenha);
    resultado.setValor(Resultado::SUCESSO);

    return resultado;

}


/// Definições de métodos do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o apelido do usuário para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoUsuario CntrLNUsuario::pesquisar(const Apelido &apelido) throw(runtime_error) {
    //Inicializacao do usuario valido

    Usuario usuarioRecuperado;



    // Apresentar dados recebidos.

    cout << endl << "CntrLNUsuario::pesquisar" << endl ;

    ResultadoUsuario resultado;
    try{
        ComandoPesquisarUsuario comandoPesquisarUsuario(apelido);
        comandoPesquisarUsuario.executar();
        usuarioRecuperado = comandoPesquisarUsuario.getResultado();
        resultado.setValor(Resultado::SUCESSO);
        resultado.setUsuario(usuarioRecuperado);
    }
    catch(EErroPersistencia exp){
        resultado.setValor(Resultado::FALHA);
    }

    return resultado;
}


/// Definições de métodos do controlador da lógica de negócio de autenticação.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o título do livro para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoUsuario CntrLNUsuario::trocar(const Titulo &titulo, const int operacao) throw(runtime_error) {
    Usuario usuario;
    Livro livroRecuperado;
    Troca troca;
    Exemplar exemplar;
    Apelido apelido;
    Nome nome;
    Telefone telefone;

    // Apresentar dados recebidos.

    cout << endl << "CntrLNUsuario::trocar" << endl ;

    ResultadoUsuario resultado;
    try{
        ComandoPesquisarLivro comandoPesquisarLivro(titulo);
        comandoPesquisarLivro.executar();
        livroRecuperado = comandoPesquisarLivro.getResultado();
    }
    catch(EErroPersistencia exp){
        cout << "O livro informado nao esta cadastrado!" << endl;
        resultado.setValor(Resultado::FALHA);
        return resultado;

    }
    exemplar.setApelido(usuarioAtual.getApelido());
    exemplar.setCodigo(livroRecuperado.getCodigo());
    troca.setTroca("1");
    exemplar.setTroca(troca);

    if(operacao == 1){
        ComandoAtualizarExemplar comandoAtualizarExemplar(exemplar);
        comandoAtualizarExemplar.executar();
        resultado.setValor(Resultado::SUCESSO);

    }else{
        ComandoPesquisarExemplar comandoPesquisarExemplar(livroRecuperado.getCodigo());
        try{

            comandoPesquisarExemplar.executar();
            //esvazia a lista global
            while(!exemplarTrocaGlobal.empty()){
                exemplarTrocaGlobal.pop_back();
            }
        }
        catch(EErroPersistencia exp){
            cout << "Nao foram encontrados usuarios com esse livro." << endl;
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
        try{
            while(true){
                exemplarTrocaGlobal.push_front(comandoPesquisarExemplar.getResultado());

            }
        }
        catch(EErroPersistencia exp){
            resultado.setValor(Resultado::SUCESSO);
        }

    }

    return resultado;
}

