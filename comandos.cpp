#include "comandos.h"
/**
* Método que implementa a exibicao da estante do usuario.
* O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
* O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
* Resgata as unidades do usuario a partir da variavel global "usuarioAtual".
* Utilizando um loop, pesquisa o codigo de cada exemplar da estante do usuario, exibindo na tela
* as informacoes de cada livro. Não retorna valores.
*/
void ComandoIUUsuarioExibir::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error){

    Codigo codigo;
    Livro livro;
    Resultado resultado;
    resultado = cntrLNUsuario->contabilizar();
    int j = usuarioAtual.getUnidades().getUnidades();
    int i=0;
    system("cls");
    cout << endl << "Estante do Usuario" << endl;
    for(i=0; i<j;i++){
        codigo = usuarioAtual.getEstante(i).getCodigo();
        ComandoPesquisarLivro comandoPesquisarLivro(codigo);
        comandoPesquisarLivro.executar();
        livro = comandoPesquisarLivro.getResultado();
        cout << endl << "Exemplar " << i+1 << endl;
        cout << "Codigo             - " << livro.getCodigo().getCodigo() << endl;
        cout << "Titulo             - " << "'" << livro.getTitulo().getTitulo() << "'" << endl;
        cout << "Autor              - " << livro.getAutor().getAutor() << endl;
        string data = livro.getData().getData();
        cout << "Data de publicacao - " << data[0] << data[1] << "/" << data[2] << data[3] << "/" << data[4] << data[5] << endl;
        cout << "Genero Literario   - " << livro.getGeneroLiterario().getGeneroLiterario() << endl;
    }
    if(j == 0)
        cout << "Estante vazia!";
    cout << endl << "Pressione qualquer tecla para continuar..." << endl;
    getch();

}

/**
* Método por meio do qual é solicitada a execução do comando.
* Metodo que implementa a execucao da inclusao de um livro na estante do usuario.
* O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
* O metodo solicita ao usuario o codigo, titulo e gênero do livro em questao. As entradas do usuario ja sao validadas pelos metodos "set" de cada dominio.
* As informacoes sao passadas como parâmetro ao metodo de inclusao no servidor.
* O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
* O metodo nao retorna nenhum valor, apenas informa se as mudancas realizadas efetivamente pela logica de negocio tiveram ou nao sucesso.
*/
void ComandoIUUsuarioIncluir::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error){

    Resultado resultado;
    Livro livro;
    Exemplar exemplar;
    Codigo codigo;
    Titulo titulo;
    GeneroLiterario generoLiterario;
    Data data;
    Autor autor;


    // Código de interação com o usuário.

    while(true){
            system("CLS");

        try{
            string codigoDoLivro;
            string tituloDoLivro;
            string generoDoLivro;
            string dataDoLivro;
            string autorDoLivro;
            cout << "Digite o codigo do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> codigoDoLivro;
            codigo.setCodigo(codigoDoLivro);

            cout << "Digite o titulo do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> tituloDoLivro;
            titulo.setTitulo(tituloDoLivro);

            cout << "Digite o nome do autor do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> autorDoLivro;
            autor.setAutor(autorDoLivro);

            cout << "Digite a data de publicacao do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> dataDoLivro;
            data.setData(dataDoLivro);

            cout << "Digite o genero do livro: "<< endl;
            cout << "CONTO, ENSAIO, EPOPEIA, NOVELA ou ROMANCE." << endl;
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> generoDoLivro;
            generoLiterario.setGeneroLiterario(generoDoLivro);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Codigo com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.
    livro.setCodigo(codigo);
    livro.setTitulo(titulo);
    livro.setAutor(autor);
    livro.setData(data);
    livro.setGeneroLiterario(generoLiterario);

    resultado = cntrLNUsuario->incluir(livro);

    if(resultado.getValor() == Resultado::SUCESSO){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else if(resultado.getValor() == Resultado::FALHA) {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}

/**
* Método por meio do qual é solicitada a execução do comando.
* Metodo que implementa a execucao da remocao de um livro na estante do usuario.
* O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
* e solicitado ao usuario o codigo do livro em questao e este e enviado como parâmetro ao metodo de remocao efetiva no servidor.
* O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
* O metodo nao retorna nenhum valor, apenas informa se a exclusao teve ou nao sucesso.
*/
void ComandoIUUsuarioRemover::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error){

    Resultado resultado;

    Codigo codigo;


    // Código de interação com o usuário.

    while(true){
            system("CLS");

        try{
            string codigoDoLivro;
            cout << "Digite o codigo do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> codigoDoLivro;
            codigo.setCodigo(codigoDoLivro);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Codigo com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.

    resultado = cntrLNUsuario->remover(codigo);

    if(resultado.getValor() == Resultado::SUCESSO){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}

/**
* Método por meio do qual é solicitada a execução do comando.
* Metodo que implementa a consulta de um livro.
* O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
* e solicitado ao usuario o codigo do livro em questao e este e enviado como parâmetro ao metodo de consulta efetiva no servidor.
* O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
* O metodo nao retorna nenhum valor, apenas informa se a exclusao teve ou nao sucesso. Se teve, as informacoes do livro sao impressas na tela.
*/
void ComandoIUUsuarioConsultar::executar(ILNUsuario* cntrLNUsuario)throw(runtime_error){

    ResultadoLivro resultado;
    Codigo codigo;

     // Código de interação com o usuário.

    while(true){
            system("CLS");

        try{
            string codigoDoLivro;
            cout << "Digite o codigo do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> codigoDoLivro;
            codigo.setCodigo(codigoDoLivro);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Codigo com formato incorreto" << endl;
        }
    }


    // Solicitar serviço.


    resultado = cntrLNUsuario->consultar(codigo);

    if(resultado.getValor() == Resultado::SUCESSO){
        Livro livro;
        livro = resultado.getLivro();
         cout << "Sucesso na execucao da operacao" << endl;
         cout << "Codigo             - " << livro.getCodigo().getCodigo() << endl;
         cout << "Titulo             - " << livro.getTitulo().getTitulo() << endl;
         cout << "Autor              - " << livro.getAutor().getAutor() << endl;
         string data = livro.getData().getData();
         cout << "Data de publicacao - " << data[0] << data[1] << "/" << data[2] << data[3] << "/" << data[4] << data[5] << endl;
         cout << "Genero Literario   - " << livro.getGeneroLiterario().getGeneroLiterario() << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
        return;
    }

    ComandoPesquisarResenha comandoPesquisarResenha(codigo);
    comandoPesquisarResenha.executar();
    Resenha resenhaRecuperada;
    int recuperouResenha = 0;
    try{
        while(true){

          resenhaRecuperada = comandoPesquisarResenha.getResultado();
          if(!recuperouResenha){
            cout << endl << "Resenhas sobre este livro: " << endl;
          }
          cout << endl << "Resenha " << recuperouResenha+1;
          cout << endl << "Apelido do autor   - " << resenhaRecuperada.getApelido().getApelido();
          cout << endl << "Data da resenha    - " << resenhaRecuperada.getData().getData();
          cout << endl << "Texto              - " << resenhaRecuperada.getTexto().getTexto() << endl;
        }
        recuperouResenha++;
    }
    catch(EErroPersistencia exp){

        //Se nao encontrar nenhuma resenha
        if(!recuperouResenha){
            cout << endl << "Ainda nao existem resenhas sobre este livro!" << endl;
        }
    }

    system("PAUSE");
}

/** 
* Metodo que implementa a pesquisa de usuario na base de dados.
* O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
* e solicitado ao usuario o apelido do usuario em questao e este e enviado como parâmetro ao metodo de pesquisa no servidor.
* O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
* O metodo nao retorna nenhum valor, apenas informa se a pesquisa teve ou nao sucesso. Se teve, os dados do usuario sao impressos em tela.
*/
void ComandoIUUsuarioPesquisar::executar(ILNUsuario* cntrLNUsuario)throw(runtime_error){

    ResultadoUsuario resultado;
    Usuario usuario;
    Apelido apelido;

    // Código de interação com o usuário.

    while(true){
            system("CLS");

        try{
            string apelidoUsuario;
            cout << "Digite o apelido do usuario: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> apelidoUsuario;
            apelido.setApelido(apelidoUsuario);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Apelido com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.


    resultado = cntrLNUsuario->pesquisar(apelido);

    if(resultado.getValor() == Resultado::SUCESSO){
        usuario = resultado.getUsuario();
        cout << "Sucesso na execucao da operacao" << endl;
        cout << "Nome     - " << usuario.getNome().getNome() << endl;
        cout << "Apelido  - " << usuario.getApelido().getApelido() << endl;
        cout << "Telefone - " << usuario.getTelefone().getTelefone() << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}

/**
* Metodo que permite o contato da controladora de interface de usuario com a controladora de logica de negocio para escrita de resenha.
* e solicitado ao usuario o titulo do livro, o texto da resenha e a data da submissao. Estes sao enviados como parâmetro ao metodo de inclusao efetiva no servidor.
* O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
* O metodo nao retorna nenhum valor, apenas informa se a operacao teve ou nao sucesso.
*/
void ComandoIUUsuarioEscrever::executar(ILNUsuario* cntrLNUsuario)throw(runtime_error){

    ResultadoResenha resultado;
    Titulo titulo;
    Texto texto;
    Data data;
    // Código de interação com o usuário.
    while(true){
            system("CLS");

        try{
            string tituloResenha;
            cout << "Digite o titulo: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> noskipws >> tituloResenha;

            titulo.setTitulo(tituloResenha);

            string textoResenha;
            cout << "Digite o texto da resenha: (max. 40 carac.)";
            cin.sync(); //sincronizar buffer para evitar loop
            getline(cin, textoResenha);
            texto.setTexto(textoResenha);

            string dataResenha;
            cout << "Entre com a data no formato (ddmmaa): ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> dataResenha;
            data.setData(dataResenha);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Titulo com formato incorreto" << endl;
        }
    }


    // Solicitar serviço.


    resultado = cntrLNUsuario->escrever(titulo, texto, data);

    if(resultado.getValor() == Resultado::SUCESSO){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}

/**
* Metodo que implementa a execucao do comando de troca de livro.
* O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
* Oferece ao usuario as opcoes de troca, cuja selecao é feita utilizando a variavel "int opcao".
* No caso da opcao 1, solicita o titulo do livro.
* No caso da opcao 2, solicita o titulo do livro, busca usuarios com aquele livro na base de dados e realiza a troca.
* Nao retorna valores.
*/
void ComandoIUUsuarioTrocar::executar(ILNUsuario* cntrLNUsuario)throw(runtime_error){

    ResultadoUsuario resultado;
    int opcao;
    Titulo titulo;
Codigo codigo;

    // Código de interação com o usuário.
    while(true){
            system("CLS");
            cout << "1 - Indicar troca" << endl;
            cout << "2 - Procurar livros para troca" << endl;
            cout << "3 - Voltar ao menu principal" << endl;
            //Sincroniza o buffer para evitar loops
            cin.sync();
            cin >> opcao;
        if(opcao == 1){
            string tituloTroca;
            cout << "Digite o titulo para informar troca: ";
            cin.sync(); //sincronizar buffer para evitar loop
            getline(cin, tituloTroca);
            titulo.setTitulo(tituloTroca);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }else if(opcao == 2){
            try{
                string tituloTroca;
                cout << "Digite o titulo: ";
                cin.sync(); //sincronizar buffer para evitar loop
                getline(cin, tituloTroca);

                titulo.setTitulo(tituloTroca);
                cin.sync(); //sincronizar buffer para evitar loop
                break;
            }
            catch(invalid_argument &exp){
                cout << "Titulo com formato incorreto" << endl;
            }
        }else if(opcao == 3){
            return;
        }else{
            cout << "Opcao invalida!" << endl;
        }

    }


    // Solicitar serviço.

    if(opcao == 1){
        resultado = cntrLNUsuario->trocar(titulo, 1);
    }else{
        resultado = cntrLNUsuario->trocar(titulo, 2);
    }


    if((resultado.getValor() == Resultado::SUCESSO)&&(opcao == 2)){
        Usuario usuario;
        Exemplar exemplar;
        cout << "Sucesso na execucao da operacao" << endl;
        cout << "Foram encontrados usuarios que possuem o livro para troca" << endl;
        while(!exemplarTrocaGlobal.empty()){
            exemplar = exemplarTrocaGlobal.back();
            exemplarTrocaGlobal.pop_back();
            ComandoPesquisarUsuario comandoPesquisarUsuario(exemplar.getApelido());
            comandoPesquisarUsuario.executar();
            usuario = comandoPesquisarUsuario.getResultado();

            cout << "Livro    - " << titulo.getTitulo() << endl;
            cout << "Nome     - " << usuario.getNome().getNome() << endl;
            cout << "Apelido  - " << usuario.getApelido().getApelido() << endl;
            cout << "Telefone - " << usuario.getTelefone().getTelefone() << endl;
        }

    }
    else if(resultado.getValor() == Resultado::FALHA){
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}
