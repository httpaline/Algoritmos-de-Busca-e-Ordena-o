#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

void menu(){
    cout<<"       PROJETO DE ALGORITMOS       "<<endl;
    cout<<"Escolha uma opcao:"<<endl<<endl;
    cout<<"1 - Insertion Sort"<<endl;
    //outros algoritmos ...
    cout<<"2 - Sair."<<endl;
}

void menu_instancia(){
    cout<<"Escolha o tamanho da instancia:"<<endl;
    cout<<"1 - 10 numeros"<<endl;
    cout<<"2 - 100 numeros"<<endl;
    cout<<"3 - 1.000 numeros"<<endl;
    cout<<"4 - 10.000 numeros"<<endl;
    cout<<"5 - 100.000 numeros"<<endl;
    cout<<"6 - 1.000.000 numeros"<<endl;
}

void menu_CDA(){
    cout<<"Escolha uma das seguintes entradas:"<<endl;
    cout<<"1 - Crescente"<<endl;
    cout<<"2 - Decrescente"<<endl;
    cout<<"3 - Randomico"<<endl;
}

#endif //MENU_H