#include <iostream>
#include "menu.h"
#include "crescente.h"
#include "decrescente.h"
#include "randomico.h"  
#include "classe.h"

using namespace std;

int main() {
    int opcao, entrada_inst, entrada_CDR;
    Algoritmo alg;

    while (true) {
        menu();
        cin >> opcao;

        switch(opcao){
            case 1: 
                alg = Algoritmo::Insertion;
                break;
            case 2:
                alg = Algoritmo::Selection;
                break;
            case 3:
                alg = Algoritmo::Shell;
                break;
            case 4:
                alg = Algoritmo::Bubble;
                break;
            case 5:
                alg = Algoritmo::Merge;
                break;    
            case 6:
                cout << "Saindo do programa..." << endl;
                return 0;
            default:
                cout << "Erro! Digite uma opcao valida." << endl;
                continue;
        }

        menu_instancia();
        cin >> entrada_inst;

        if (entrada_inst < 1 || entrada_inst > 6) {
            cout << "Erro! Digite um tamanho de instancia valido." << endl;
            continue;
        }

        menu_CDR();
        cin >> entrada_CDR;

        if (entrada_CDR < 1 || entrada_CDR > 3) {
            cout << "Erro! Digite uma entrada valida." << endl;
            continue;
        }

        switch (entrada_CDR) {
            case 1:  
                crescente(entrada_inst, nullptr, nullptr, alg);
                break;
            case 2:  
                decrescente(entrada_inst, nullptr, nullptr, alg);
                break;
            case 3:  
                randomico(entrada_inst, nullptr, nullptr, alg);
                break;
            default:
                cout << "Erro! Tente novamente." << endl;
                break;
        }
    }
    return 0;
}
