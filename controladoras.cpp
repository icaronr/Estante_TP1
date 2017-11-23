#include "controladoras.h"
#include "comandos.h"
#include "interfaces.h"
#include "global.h"

#include<limits>

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
    getch();
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



void CntrIUUsuario::executar(const Apelido &apelido) throw(runtime_error){

    ComandoIUUsuario *comando;

    int opcao;

    while(true){

        // Ilustra limpeza de tela.

        system("CLS");

        // Apresentar as opções.

        cout << endl << "Gerenciamento de Usuario." << endl << endl;

        cout << "Incluir Livro na estante  - " << INCLUIR << endl;
        cout << "Remover Livro da estante  - " << REMOVER << endl;
        cout << "Consultar dados de Livro  - " << CONSULTAR << endl;
        cout << "Escrever Resenha          - " << ESCREVER << endl;
        cout << "Pesquisar Usuario         - " << PESQUISAR << endl;
        cout << "Trocar Livro              - " << TROCAR << endl;
        cout << "Sair do programa          - " << RETORNAR << endl << endl;
        cout << "Selecione uma opcao :";


            //Sincroniza o buffer para evitar loops
            cin.sync();
            cin >> opcao;
            while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << endl << "Entrada invalida!" << endl << "Informe uma nova opcao: " << endl;
                cin >> opcao;

            }

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
            comandoPesquisarUsuario.executar();
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
                        cout << endl << endl << "Digite uma tecla para continuar.";
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
    // Procura o apelido no banco de dados, se nao encontrar -> cadastra, se encontrar -> diz que ja esta em uso
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

Resultado CntrLNUsuario::incluir(const Livro &livro) throw(runtime_error){

    // Apresentar dados recebidos.
    int cadastrouLivro = 0; /** < Inteiro que sinaliza se o livro foi cadastrado. */
    cout << endl << "CntrLNUsuario::incluir" << endl ;

    Resultado resultado;
     //Primeiro confirmaremos se o usuario ainda não atingiu o limite de livros na biblioteca
    resultado = (CntrLNUsuario::contabilizar());
    if(resultado.getValor() == Resultado::FALHA){
        cout << endl << "Erro ao processar a estante!" << endl;
        getch();
        return resultado;
    }

    int j = usuarioAtual.getUnidades().getUnidades();
    if(j>9){
        resultado.setValor(Resultado::FALHA);
        cout << endl <<"A estante ja atingiu o limite de 10 exemplares!" << endl;
        return resultado;
    }



        //Agora testa se o usuario ja possui um exemplar desse livro na estante

        int i;

        for(i=0; i<j; i++){
            if(usuarioAtual.getEstante(i).getCodigo().getCodigo() == livro.getCodigo().getCodigo()){
                resultado.setValor(Resultado::FALHA);
                cout << "O usuario ja possui esse livro na estante." << endl;
                return resultado;
            }
        }
    Exemplar exemplar;

    try{
        //Confere se o livro ja esta cadastrado

        ComandoPesquisarLivro comandoPesquisarLivro(livro.getCodigo());
        comandoPesquisarLivro.executar();
        Livro livroRecuperado;
        livroRecuperado = comandoPesquisarLivro.getResultado();

        //Se encontrar o livro, cadastra o exemplar vinculado ao usuario

    }
    catch(EErroPersistencia exp){
        //Se não encontrar o livro, cadastra o livro no banco de dados
        cout << endl <<"Livro ainda nao cadastrado no sistema, cadastrando..." << endl;
        ComandoCadastrarLivro comandoCadastrarLivro(livro);
        cout << endl << "Dados recebidos..." << endl;
        comandoCadastrarLivro.executar();
        cout << endl << "Livro cadastrado!" << endl;
        cadastrouLivro = 1;

    }

    //Faz o cadastro do exemplar. A chave de troca é sempre inicializada em '0'.
    cout << endl <<"Cadastrando exemplar..." << endl;
    exemplar.setApelido(usuarioAtual.getApelido());
    cout << endl << "Apelido salvo..." << endl;
    exemplar.setCodigo(livro.getCodigo());
    cout << endl << "Codigo salvo..." << endl;
    Troca troca;
    troca.setTroca("0");
    exemplar.setTroca(troca);
    cout << endl << "Dado de troca salvo..." << endl;
    cout << endl << "Dados recebidos..." << endl;
    try{

    ComandoCadastrarExemplar comandoCadastrarExemplar(exemplar);

    comandoCadastrarExemplar.executar();
    cout << endl << "Exemplar cadastrado!" << endl;
    }
    catch(EErroPersistencia exp){
        cout << endl << "Erro ao cadastrar o exemplar!" << endl;
        if(cadastrouLivro){
            ComandoRemoverLivro comandoRemoverLivro(exemplar.getCodigo());
            comandoRemoverLivro.executar();
        }


        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    resultado.setValor(Resultado::SUCESSO);

    return resultado;
}

Resultado CntrLNUsuario::remover(const Codigo &codigo) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "CntrLNUsuario::remover" << endl ;

    Resultado resultado;
    //Procura o livro no banco de dados
    try{
        ComandoPesquisarLivro comandoPesquisarLivro(codigo);
        comandoPesquisarLivro.executar();
        Livro livroRecuperado;
        livroRecuperado = comandoPesquisarLivro.getResultado();
    }
    catch(EErroPersistencia exp){
        cout << endl <<"Livro nao encontrado no sistema." << endl;
        resultado.setValor(ResultadoAutenticacao::FALHA);
        return resultado;
    }
    //Processa a estante do usuario atual.
    resultado = (CntrLNUsuario::contabilizar());
    if(resultado.getValor() == Resultado::FALHA){
        cout << endl << "Erro ao processar a estante!" << endl;
        getch();
        return resultado;
    }
    //Retorna falha se a estante estiver vazia.
    if(usuarioAtual.getUnidades().getUnidades() == 0){
        cout << endl << "A sua estante nao possui nenhum exemplar!" << endl;
        getch();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }
    //Procura o exemplar na estante do usuario
    int j = usuarioAtual.getUnidades().getUnidades();
    int i;
    resultado.setValor(Resultado::FALHA);
    for(i=0; i<j; i++){
        if(usuarioAtual.getEstante(i).getCodigo().getCodigo() == codigo.getCodigo()){
            resultado.setValor(Resultado::SUCESSO);
            break;
        }
    }
    //Caso nao encontra, retorna falha.
    if(resultado.getValor() == Resultado::FALHA){
        cout << endl << "O exemplar informado nao foi encontrado em sua estante!" << endl;
        return resultado;
    }

    //Remove o exemplar do banco de dados da estante do usuario.
    ComandoRemoverExemplar comandoRemoverExemplar(codigo, usuarioAtual.getApelido());
    comandoRemoverExemplar.executar();

    //Processa novamente a estante para conferir os valores
    resultado = (CntrLNUsuario::contabilizar());
    // j ainda armazena a quantidade antiga de unidades na estante.
    if(usuarioAtual.getUnidades().getUnidades() != (j-1)){
        resultado.setValor(Resultado::FALHA);
        cout << endl << "Houve um erro no processamento da estante apos a remocao do exemplar!" << endl;
        getch();
        return resultado;
    }
    try{
        Exemplar exemplarRecuperado;

        ComandoPesquisarExemplar comandoPesquisarExemplar(codigo);
        comandoPesquisarExemplar.executar();
        //esvazia a lista global
        while(!exemplarTrocaGlobal.empty()){
            exemplarTrocaGlobal.pop_back();
        }
        //Bota os resultados na lista
        while(true){
            //O loop vai quebrar quando nao restarem resultados para serem retornados.
            exemplarTrocaGlobal.push_front(comandoPesquisarExemplar.getResultado());
        }
    }
    catch(EErroPersistencia exp){
        //Se houver pelo menos 1 exemplar na lista, retorna.
        if(!exemplarTrocaGlobal.empty()){
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }else{
            //Se nao houver nenhum exemplar com o codigo, apaga o livro do sistema
            //Apaga as resenhas
            ComandoRemoverResenha comandoRemoverResenha(codigo);
            comandoRemoverResenha.executar();
            //Apaga o livro
            ComandoRemoverLivro comandoRemoverLivro(codigo);
            comandoRemoverLivro.executar();
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
    }
    resultado.setValor(Resultado::SUCESSO);

    return resultado;
}


/// Definições de métodos do controlador da lógica de negócio de usuário.
/// A função stub neste momento preenche o lugar da função definitiva de autenticação para fins de teste de integração.
/// Recebe o código do livro para comparar com os dados do servidor e retorna o valor do resultado.

ResultadoLivro CntrLNUsuario::consultar(const Codigo &codigo) throw(runtime_error) {

    // Apresentar dados recebidos.
    Livro livroRecuperado;


    cout << endl << "CntrLNUsuario::consultar" << endl ;

    ResultadoLivro resultado;
    ComandoPesquisarLivro comandoPesquisarLivro(codigo);
    try{
        comandoPesquisarLivro.executar();
        livroRecuperado = comandoPesquisarLivro.getResultado();
    }
    catch(EErroPersistencia exp){
        cout << endl <<"Livro nao encontrado no sistema." << endl;
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }
        resultado.setLivro(livroRecuperado);
        resultado.setValor(Resultado::SUCESSO);

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
        cout << endl << "Usuario nao encontrado." << endl;
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
        try{
            Exemplar exemplarRecuperado;
/*ComandoPesquisarExemplar comandoPesquisarExemplar(livroRecuperado.getCodigo());
            comandoPesquisarExemplar.executar();
            exemplarRecuperado = comandoPesquisarExemplar.getResultado*/
            for(int i = 0; i<10; i++){
                exemplarRecuperado = usuarioAtual.getEstante(i);
                if(exemplarRecuperado.getCodigo().getCodigo() == livroRecuperado.getCodigo().getCodigo()){
                    ComandoAtualizarExemplar comandoAtualizarExemplar(exemplar);
                    comandoAtualizarExemplar.executar();
                    resultado.setValor(Resultado::SUCESSO);
                    return resultado;

                }


            }
            cout << endl << "O livro nao esta presente na sua estante!" << endl;
            resultado.setValor(Resultado::FALHA);
            return resultado;

        }
        catch(EErroPersistencia exp){
            cout << endl << "O livro nao esta presente na sua estante!" << endl;
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }

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
            //Bota os resultados na lista
            while(true){
                //O loop vai quebrar quando nao restarem resultados para serem retornados.
                exemplarTrocaGlobal.push_front(comandoPesquisarExemplar.getResultado());

            }

        }
        catch(EErroPersistencia exp){
            //Se a lista estiver vazia, retorna falha
            if(exemplarTrocaGlobal.empty()){
                cout << "Nao foram encontrados usuarios com esse livro." << endl;
                resultado.setValor(Resultado::FALHA);
                return resultado;
            }else{
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
            }

        }


    }

    return resultado;
}

Resultado CntrLNUsuario::contabilizar() throw(runtime_error){
    Resultado resultado;
    ComandoPesquisarExemplar comandoPesquisarExemplar(usuarioAtual.getApelido());

    comandoPesquisarExemplar.executar();

    int j = 0;
    Unidades unidades;
    while(true){

        try{

            Exemplar exemplarRecuperado;
            exemplarRecuperado = comandoPesquisarExemplar.getResultado();
            usuarioAtual.setEstante(exemplarRecuperado, j);

            j++;
            if(j>9){
                unidades.setUnidades(10);
                usuarioAtual.setUnidades(unidades);
                resultado.setValor(Resultado::SUCESSO);
                return resultado;
            }

        }
        catch(EErroPersistencia exp){
            unidades.setUnidades(j);
            usuarioAtual.setUnidades(unidades);
            resultado.setValor(Resultado::SUCESSO);
            break;
        }

    }
    return resultado;
}
