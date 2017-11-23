//---------------------------------------------------------------------------

#include "unidadePersistencia.h"
#include "stdlib.h"

//Atributo estático container List.

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
//Classe ErroPersistencia.

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia::what() {
        return mensagem;
}

//---------------------------------------------------------------------------
//Classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}


//---------------------------------------------------------------------------
//Classe ComandoSQL.

void ComandoSQL::conectar() throw (EErroPersistencia) {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() throw (EErroPersistencia) {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar() throw (EErroPersistencia) {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                if (mensagem)
                        free(mensagem);
                throw EErroPersistencia("Erro na execucao do comando SQL");
        }
        desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

ComandoLerSenha::ComandoLerSenha(Usuario usuario) {
        comandoSQL = "SELECT senha FROM usuarios WHERE apelido = ";
        comandoSQL += "'"+ usuario.getApelido().getApelido()+ "'";
        comandoSQL += ";";
}

string ComandoLerSenha::getResultado() throw (EErroPersistencia) {
        ElementoResultado resultado;
        string senha;

        //Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha = resultado.getValorColuna();

        return senha;
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarUsuario.

ComandoPesquisarUsuario::ComandoPesquisarUsuario(Apelido apelido) {
        comandoSQL = "SELECT * FROM usuarios WHERE apelido = ";
        comandoSQL += "'" + apelido.getApelido() + "'";
        comandoSQL += ";";
}

Usuario ComandoPesquisarUsuario::getResultado() throw (EErroPersistencia) {
        ElementoResultado resultado;
        Usuario usuario;
        Apelido apelido;
        Senha senha;
        Nome nome;
        Telefone telefone;

        // Remover apelido;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        apelido.setApelido(resultado.getValorColuna());
        usuario.setApelido(apelido);

        // Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha.setSenha(resultado.getValorColuna());
        usuario.setSenha(senha);

        // Remover nome;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        nome.setNome(resultado.getValorColuna());
        usuario.setNome(nome);

        // Remover telefone;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        telefone.setTelefone(resultado.getValorColuna());
        usuario.setTelefone(telefone);



        return usuario;

}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.

ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario) {
        comandoSQL = "INSERT INTO USUARIOS VALUES (";
        comandoSQL += "'" + usuario.getApelido().getApelido() + "', ";
        comandoSQL += "'" + usuario.getSenha().getSenha() + "', ";
        comandoSQL += "'" + usuario.getNome().getNome() + "', ";
        comandoSQL += "'" + usuario.getTelefone().getTelefone() + "'); ";
}

//---------------------------------------------------------------------------
//Classe ComandoRemoverUsuario.

ComandoRemoverUsuario::ComandoRemoverUsuario(Apelido apelido) {
        comandoSQL = "DELETE FROM USUARIOS WHERE APELIDO = ";
        comandoSQL += "'" + apelido.getApelido() + "'";
        comandoSQL += ";";
}

//---------------------------------------------------------------------------
//Classe ComandoEditarUsuario.

ComandoAtualizarUsuario::ComandoAtualizarUsuario(Usuario usuario) {
        comandoSQL = "UPDATE USUARIOS ";
        comandoSQL += "SET apelido = '" + usuario.getApelido().getApelido();
        comandoSQL += "', senha = '" + usuario.getSenha().getSenha();
        comandoSQL += "', nome = '" + usuario.getNome().getNome();
        comandoSQL += "', telefone = '" + usuario.getTelefone().getTelefone();
        comandoSQL += "' WHERE apelido = " + usuario.getApelido().getApelido();
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarLivro.

ComandoPesquisarLivro::ComandoPesquisarLivro(Codigo codigo) {
        comandoSQL = "SELECT * FROM livros WHERE codigo = ";
        comandoSQL += "'" + codigo.getCodigo() + "'";
        comandoSQL += ";";
}

ComandoPesquisarLivro::ComandoPesquisarLivro(Titulo titulo) {
        comandoSQL = "SELECT * FROM livros WHERE titulo = ";
        comandoSQL += "'" + titulo.getTitulo() + "'";
        comandoSQL += ";";
}

Livro ComandoPesquisarLivro::getResultado() throw (EErroPersistencia) {
        ElementoResultado resultado;
        Livro livro;
        Codigo codigo;
        Titulo titulo;
        Autor autor;
        Data data;
        GeneroLiterario generoLiterario;

        // Remover codigo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setCodigo(resultado.getValorColuna());
        livro.setCodigo(codigo);

        // Remover titulo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        titulo.setTitulo(resultado.getValorColuna());
        livro.setTitulo(titulo);

        // Remover autor;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        autor.setAutor(resultado.getValorColuna());
        livro.setAutor(autor);

        // Remover data;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        data.setData(resultado.getValorColuna());
        livro.setData(data);

        // Remover generoLiterario;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        generoLiterario.setGeneroLiterario(resultado.getValorColuna());
        livro.setGeneroLiterario(generoLiterario);


        return livro;

}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarLivro.

ComandoCadastrarLivro::ComandoCadastrarLivro(Livro livro) {
        comandoSQL = "INSERT INTO LIVROS VALUES (";
        comandoSQL += "'" + livro.getCodigo().getCodigo() + "', ";
        comandoSQL += "'" + livro.getTitulo().getTitulo() + "', ";
        comandoSQL += "'" + livro.getAutor().getAutor() + "', ";
        comandoSQL += "'" + livro.getData().getData() + "', ";
        comandoSQL += "'" + livro.getGeneroLiterario().getGeneroLiterario() + "'); ";
}

//---------------------------------------------------------------------------
//Classe ComandoRemoverLivro.

ComandoRemoverLivro::ComandoRemoverLivro(Codigo codigo) {
        comandoSQL = "DELETE FROM LIVROS WHERE CODIGO = ";
        comandoSQL += "'" + codigo.getCodigo() + "'";
        comandoSQL += ";";
}

//---------------------------------------------------------------------------
//Classe ComandoEditarLivro.

ComandoAtualizarLivro::ComandoAtualizarLivro(Livro livro) {
        comandoSQL = "UPDATE LIVROS ";
        comandoSQL += "SET codigo = '" + livro.getCodigo().getCodigo();
        comandoSQL += "', titulo = '" + livro.getTitulo().getTitulo();
        comandoSQL += "', autor = '" + livro.getAutor().getAutor();
        comandoSQL += "', data = '" + livro.getData().getData();
        comandoSQL += "', genero = '" + livro.getGeneroLiterario().getGeneroLiterario();
        comandoSQL += "' WHERE codigo = " + livro.getCodigo().getCodigo();
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarResenha.

ComandoPesquisarResenha::ComandoPesquisarResenha(Codigo codigo) {
        comandoSQL = "SELECT * FROM resenhas WHERE codigo = ";
        comandoSQL += "'" + codigo.getCodigo() + "'";
        comandoSQL += ";";
}

ComandoPesquisarResenha::ComandoPesquisarResenha(Apelido apelido) {
        comandoSQL = "SELECT * FROM resenhas WHERE apelido = ";
        comandoSQL += "'" + apelido.getApelido() + "'";
        comandoSQL += ";";
}


Resenha ComandoPesquisarResenha::getResultado() throw (EErroPersistencia) {
        ElementoResultado resultado;
        Resenha resenha;
        Texto texto;
        Codigo codigo;
        Apelido apelido;
        Data data;

        // Remover texto;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        texto.setTexto(resultado.getValorColuna());
        resenha.setTexto(texto);

        // Remover apelido;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        apelido.setApelido(resultado.getValorColuna());
        resenha.setApelido(apelido);

        // Remover data;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        data.setData(resultado.getValorColuna());
        resenha.setData(data);

        return resenha;

}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarResenha.

ComandoCadastrarResenha::ComandoCadastrarResenha(Resenha resenha) {
        comandoSQL = "INSERT INTO RESENHAS VALUES (";
        comandoSQL += "'" + resenha.getTexto().getTexto() + "', ";
        comandoSQL += "'" + resenha.getCodigo().getCodigo() + "', ";
        comandoSQL += "'" + resenha.getApelido().getApelido() + "', ";
        comandoSQL += "'" + resenha.getData().getData();
        comandoSQL += "'); ";
}

//---------------------------------------------------------------------------
//Classe ComandoRemoverResenha.

ComandoRemoverResenha::ComandoRemoverResenha(Codigo codigo, Apelido apelido) {
        comandoSQL = "DELETE FROM RESENHAS WHERE CODIGO = ";
        comandoSQL += "'" + codigo.getCodigo() + "'";
        comandoSQL += " AND APELIDO = '" + apelido.getApelido();
        comandoSQL += "';";
}

ComandoRemoverResenha::ComandoRemoverResenha(Codigo codigo) {
        comandoSQL = "DELETE FROM RESENHAS WHERE CODIGO = ";
        comandoSQL += "'" + codigo.getCodigo() + "'";
        comandoSQL += ";";
}

ComandoRemoverResenha::ComandoRemoverResenha(Apelido apelido) {
        comandoSQL = "DELETE FROM RESENHAS WHERE APELIDO = ";
        comandoSQL += "'" + apelido.getApelido() + "'";
        comandoSQL += ";";
}

//---------------------------------------------------------------------------
//Classe ComandoEditarResenha.

ComandoAtualizarResenha::ComandoAtualizarResenha(Resenha resenha) {
        comandoSQL = "UPDATE RESENHAS ";
        comandoSQL += "SET texto = '" + resenha.getTexto().getTexto();
        comandoSQL += "', codigo = '" + resenha.getCodigo().getCodigo();
        comandoSQL += "', apelido = '" + resenha.getApelido().getApelido();
        comandoSQL += "', data = '" + resenha.getData().getData();
        comandoSQL += "' WHERE codigo = " + resenha.getCodigo().getCodigo();
        comandoSQL += " AND apelido = '" + resenha.getApelido().getApelido() + "';";
}


//---------------------------------------------------------------------------
//Classe ComandoPesquisarExemplar.

ComandoPesquisarExemplar::ComandoPesquisarExemplar(Codigo codigo) {
        comandoSQL = "SELECT * FROM exemplares WHERE codigo = ";
        comandoSQL += "'" + codigo.getCodigo() + "'";
        comandoSQL += ";";
}

ComandoPesquisarExemplar::ComandoPesquisarExemplar(Apelido apelido) {
        comandoSQL = "SELECT * FROM exemplares WHERE apelido = ";
        comandoSQL += "'" + apelido.getApelido() + "'";
        comandoSQL += ";";
}


Exemplar ComandoPesquisarExemplar::getResultado() throw (EErroPersistencia) {
        ElementoResultado resultado;
        Exemplar exemplar;
        Troca troca;
        Codigo codigo;
        Apelido apelido;


        // Remover apelido;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        apelido.setApelido(resultado.getValorColuna());
        exemplar.setApelido(apelido);

        // Remover codigo;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setCodigo(resultado.getValorColuna());
        exemplar.setCodigo(codigo);

        // Remover troca;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        troca.setTroca(resultado.getValorColuna());
        exemplar.setTroca(troca);

        return exemplar;

}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarExemplar.

ComandoCadastrarExemplar::ComandoCadastrarExemplar(Exemplar exemplar) {
        comandoSQL = "INSERT INTO EXEMPLARES VALUES (";
        comandoSQL += "'" + exemplar.getApelido().getApelido() + "', ";
        comandoSQL += "'" + exemplar.getCodigo().getCodigo() + "', ";
        comandoSQL += exemplar.getTroca().getTroca();
        comandoSQL += "); ";
}

//---------------------------------------------------------------------------
//Classe ComandoRemoverExemplar.

ComandoRemoverExemplar::ComandoRemoverExemplar(Codigo codigo, Apelido apelido) {
        comandoSQL = "DELETE FROM EXEMPLARES WHERE CODIGO = ";
        comandoSQL += "'" + codigo.getCodigo() + "'";
        comandoSQL += " AND APELIDO = ";
        comandoSQL += "'" + apelido.getApelido() + "'";
        comandoSQL += ";";
}
ComandoRemoverExemplar::ComandoRemoverExemplar(Codigo codigo) {
        comandoSQL = "DELETE FROM EXEMPLARES WHERE CODIGO = ";
        comandoSQL += "'" + codigo.getCodigo() + "'";
        comandoSQL += ";";
}
ComandoRemoverExemplar::ComandoRemoverExemplar(Apelido apelido) {
        comandoSQL = "DELETE FROM EXEMPLARES WHERE APELIDO = ";
        comandoSQL += "'" + apelido.getApelido() + "'";
        comandoSQL += ";";
}
//---------------------------------------------------------------------------
//Classe ComandoEditarExemplar.

ComandoAtualizarExemplar::ComandoAtualizarExemplar(Exemplar exemplar) {
        comandoSQL = "UPDATE EXEMPLARES ";
        comandoSQL += "SET apelido = '" + exemplar.getApelido().getApelido();
        comandoSQL += "', codigo = '" + exemplar.getCodigo().getCodigo();
        comandoSQL += "', troca = '" + exemplar.getTroca().getTroca();
        comandoSQL += "' WHERE codigo = " + exemplar.getCodigo().getCodigo();
        comandoSQL += " AND apelido = '" + exemplar.getApelido().getApelido() + "';";
}
