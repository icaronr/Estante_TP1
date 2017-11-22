#include "global.h"

Usuario usuarioAtual;
list<Exemplar> exemplarTrocaGlobal;

void contabilizar(){
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
                    //resultado.setValor(Resultado::FALHA);
                    //cout << "A estante ja esta cheia." << endl;
                    unidades.setUnidades(10);
                    usuarioAtual.setUnidades(unidades);
                  //  return resultado;
                }

            }
            catch(EErroPersistencia exp){
               // cout << "Estante processada com sucesso!"<< endl;
                unidades.setUnidades(j);
                usuarioAtual.setUnidades(unidades);
                break;
            }

        }
}
