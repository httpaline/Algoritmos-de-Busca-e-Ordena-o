#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void insertionSort(int A[], int n){
    int i,j,chave;
    for(j=1;j<n;j++){
        chave=A[j]; 
        i=j-1;

        while(i>=0 && A[i]>chave){
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=chave; 
    }
}

//outros algoritmos...



#endif //ALGORITMO_H