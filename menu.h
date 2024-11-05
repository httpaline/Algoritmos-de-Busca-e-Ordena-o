#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

void menu() {
    cout << "\n========== PROJETO DE ALGORITMOS ==========" << endl;
    cout << " Escolha uma opcao:" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 1 - Insertion Sort" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 2 - Sair" << endl;
    cout << "===========================================" << endl;
}

void menu_instancia() {
    cout << "\n========== TAMANHO DA INSTANCIA ==========" << endl;
    cout << " Escolha o tamanho da instancia:" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 1 - 10 numeros" << endl;
    cout << " 2 - 100 numeros" << endl;
    cout << " 3 - 1.000 numeros" << endl;
    cout << " 4 - 10.000 numeros" << endl;
    cout << " 5 - 100.000 numeros" << endl;
    cout << " 6 - 1.000.000 numeros" << endl;
    cout << "===========================================" << endl;
}

void menu_CDR() {
    cout << "\n=========== TIPO DE ENTRADA ==============" << endl;
    cout << " Escolha uma das seguintes entradas:" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 1 - Crescente" << endl;
    cout << " 2 - Decrescente" << endl;
    cout << " 3 - Randomica" << endl;
    cout << "===========================================" << endl;
}

#endif // MENU_H
