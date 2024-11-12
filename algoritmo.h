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

void SelectionSort(int vet[], int n) {
	int i, j, min, aux;

	for (i = 0; i < (n - 1); i++) {
		min = i;

		for (j = (i + 1); j < n; j++) {
			if (vet[j] < vet[min])
				min = j;
		}

		if (vet[i] != vet[min]) {
			aux = vet[i];
			vet[i] = vet[min];
			vet[min] = aux;
		}
	}
}

void ShellSort(int vet[], int n) {
	int i, j, aux, h = 1;

	while (h < n)
		h = 3 * h + 1;

	while (h > 1) {
		h /= 3;

		for (i = h; i < n; i++) {
			aux = vet[i];
			j = i - h;

			while (j >= 0 && aux < vet[j]) {
				vet[j + h] = vet[j];
				j -= h;
			}

			vet[j + h] = aux;
		}
	}
}

void BubbleSort(int vet[], int n) {
	int i, j, aux;

	for (i = 0; i < n; i++) {
		for (j = 0; j < (n - 1); j++) {
			if (vet[j] > vet[j + 1]) {
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}
	}
}



#endif //ALGORITMO_H