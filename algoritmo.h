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

void MergeSort(int array[], int dir, int esq) {
    if (dir < esq) {

        int meio = dir + (esq - dir) / 2;

        MergeSort(array, dir, meio);
        MergeSort(array, meio + 1, esq);

        int n1 = meio - dir + 1;
        int n2 = esq - meio;

        int* arrayDir = new int[n1];
        int* arrayEsq = new int[n2];

        for (int i = 0; i < n1; i++) {
            arrayDir[i] = array[dir + i];
        }
        for (int j = 0; j < n2; j++) {
            arrayEsq[j] = array[meio + 1 + j];
        }

        int i = 0, j = 0, k = dir;
        while (i < n1 && j < n2) {
            if (arrayDir[i] <= arrayEsq[j]) {
                array[k++] = arrayDir[i++];
            } else {
                array[k++] = arrayEsq[j++];
            }
        }

        while (i < n1) {
            array[k++] = arrayDir[i++];
        }

        while (j < n2) {
            array[k++] = arrayEsq[j++];
        }
		
        delete[] arrayDir;
        delete[] arrayEsq;
    }
}





#endif //ALGORITMO_H