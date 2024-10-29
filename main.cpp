#include <iostream>
#include "menu.h"
#include "crescente.h"
#include "decrescente.h"
#include "randomico.h"  

using namespace std;

int main() {
    int opcao, entrada_inst, entrada_CDA;

    while (true) {
        menu();
        cin >> opcao;

        if (opcao == 2) {
            cout << "Saindo do programa..." << endl;
            break;
        }

        if (opcao == 1) { // Insertion Sort
            menu_instancia();
            cin >> entrada_inst;

            if (entrada_inst < 1 || entrada_inst > 6) {
                cout << "Erro! Tamanho da instancia invalido." << endl;
                continue;
            }

            menu_CDA();
            cin >> entrada_CDA;

            switch (entrada_CDA) {
                case 1:
                    cout << "Gerando entrada crescente..." << endl;
                    crescente(entrada_inst, nullptr, nullptr);
                    break;
                case 2:
                    cout << "Gerando entrada decrescente..." << endl;
                    decrescente(entrada_inst, nullptr, nullptr);
                    break;
                case 3:
                    cout << "Gerando entrada randomica..." << endl;
                    randomico(entrada_inst, nullptr, nullptr);
                    break;
                default:
                    cout << "Tipo de entrada invalido." << endl;
                    break;
            }
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
