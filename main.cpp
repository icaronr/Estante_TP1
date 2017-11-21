///TRABALHO 2 - TP1
///ICARO NERY REZENDE (15/0037023)
///JOAO ANTONIO DESIDERIO DE MORAES (16/0126975)

// Exemplos desenvolvidos para ilustrar a sintaxe da linguagem.

#include <iostream>
#include <stdlib.h>
#include <limits>

#include "dominios.h"
#include "entidades.h"
#include "testes.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"
#include "global.h"

using namespace std;



int main()
{ // Declara e instancia as controladoras.

    IUAutenticacao  *cntrIUAutenticacao;
    IUUsuario       *cntrIUUsuario;

    cntrIUAutenticacao = new CntrIUAutenticacao();
    cntrIUUsuario = new CntrIUUsuario();

    // Declara e instancia os stubs.

    ILNAutenticacao *cntrLNAutenticacao;
    ILNUsuario      *cntrLNUsuario;

    cntrLNAutenticacao = new CntrLNAutenticacao();
    cntrLNUsuario = new CntrLNUsuario();

    // Estabelece relacionamentos entre controladoras e stubs.

    cntrIUAutenticacao->setCntrLNAutenticacao(cntrLNAutenticacao);
    cntrIUUsuario->setCntrLNUsuario(cntrLNUsuario);


    ResultadoAutenticacao resultado;

    while(true){
        int opcao = 0;
        // Simula a tela de apresentacao (tela inicial) de sistema.
        system("cls");
        cout << endl << "Tela de apresentacao de sistema." << endl;
        cout << "Seja Bem-Vindo!" << endl;
        cout << endl << "1 - Cadastrar" << endl;
        cout << "2 - Autenticar" << endl;
         //Sincroniza o buffer para evitar loops
            cin.sync();
            cin >> opcao;
            while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << endl << "Entrada invalida!" << endl << "Informe uma nova opcao: " << endl;
                cin >> opcao;

            }

        if (opcao == 1){
             try{
                resultado = cntrIUAutenticacao->cadastrar();
                if(resultado.getValor() == ResultadoAutenticacao::SUCESSO){
                    break;
                }
            }
            catch(const runtime_error &exp){
                cout << "Erro de sistema!" << endl;
            }
        }else if(opcao == 2){
            try{
                // Solicita o serviço de autenticação.
                resultado = cntrIUAutenticacao->autenticar();

                // Critica o resultado da autenticação.
                if(resultado.getValor() == ResultadoAutenticacao::SUCESSO) {
                    break;
                }
            }
            catch(const runtime_error &exp){
                     cout << "Erro de sistema." << endl;
            }
        }else{
            cout << endl << "Entrada invalida!" << endl;
            getch();
        }


    }

    try{
        // Solicita serviço da controladora de interface gerente.
        cntrIUUsuario->executar(resultado.getApelido());
    }
    catch(const runtime_error &exp){
        cout << "Erro de sistema." << endl;
    }

    // Destroi os objetos anteiormente criados.

    delete cntrIUAutenticacao;
    delete cntrIUUsuario;
    delete cntrLNAutenticacao;
    delete cntrLNUsuario;



    /// Encerra o programa.
    cout << "Fim do Programa!" << endl;
    system("PAUSE");
    return 0;
}
