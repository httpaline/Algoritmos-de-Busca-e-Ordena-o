#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

void menu() {
    cout << "\n========== PROJETO DE ALGORITMOS ==========" << endl;
    cout << " Escolha um algoritmo:" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 1 - Insertion Sort" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 2 - Selection Sort" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 3 - Shell Sort" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 4 - Bubble Sort" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 5 - Merge Sort" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 6 - QuickSort (Versão 1 - Primeiro Pivô)" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 7 - QuickSort (Versão 2 - Mediana de Três)" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 8 - QuickSort (Versão 3 - Pivô Aleatório)" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 9 - Sair" << endl;
    cout << "===========================================" << endl;
}

void menu_instancia() {
    cout << "\n========== TAMANHO DA INSTANCIA ==========" << endl;
    cout << " Escolha o tamanho da instancia:" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 1 - 10 numeros" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 2 - 100 numeros" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 3 - 1.000 numeros" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 4 - 10.000 numeros" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 5 - 100.000 numeros" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 6 - 1.000.000 numeros" << endl;
    cout << "===========================================" << endl;
}

void menu_CDR() {
    cout << "\n=========== TIPO DE ENTRADA ==============" << endl;
    cout << " Escolha uma das seguintes entradas:" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 1 - Crescente" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 2 - Decrescente" << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 3 - Randomica" << endl;
    cout << "===========================================" << endl;
}

#endif // MENU_H
