#include <iostream>
#include "menu.h"
#include "crescente.h"
#include "decrescente.h"
#include "randomico.h"  

using namespace std;

int main() {
    int opcao, entrada_inst, entrada_CDR;

    while (true) {
        menu();
        cin >> opcao;

        if (opcao == 1) { // Insertion Sort
            menu_instancia();
            cin >> entrada_inst;

            if (entrada_inst < 1 || entrada_inst > 6) {
                cout << "Erro! Tamanho da instancia invalido." << endl;
                continue;
            }

            menu_CDR();
            cin >> entrada_CDR;

            switch (entrada_CDR) {
                case 1:
                    crescente(entrada_inst, nullptr, nullptr);
                    break;
                case 2:
                    decrescente(entrada_inst, nullptr, nullptr);
                    break;
                case 3:
                    randomico(entrada_inst, nullptr, nullptr);
                    break;
                default:
                    cout << "Erro! Tipo de entrada invalido." << endl;
                    break;
            }
        }else if(opcao==2){
            cout << "Saindo do programa..." << endl;
            break;
        }else{
            cout<< "Erro! Digite uma opcao valida." << endl;
        }
        
    }

    return 0;
}
