#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int A[], int n) {
    int i, j, chave;
    for (j = 1; j < n; j++) {
        chave = A[j]; 
        i = j - 1;

        while (i >= 0 && A[i] > chave) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = chave; 
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

void MergeSort(int array[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        MergeSort(array, esq, meio);
        MergeSort(array, meio + 1, dir);

        int n1 = meio - esq + 1;
        int n2 = dir - meio;

        int* arrayEsq = new int[n1];
        int* arrayDir = new int[n2];

        for (int i = 0; i < n1; i++) {
            arrayEsq[i] = array[esq + i];
        }
        for (int j = 0; j < n2; j++) {
            arrayDir[j] = array[meio + 1 + j];
        }

        int i = 0, j = 0, k = esq;
        while (i < n1 && j < n2) {
            if (arrayEsq[i] <= arrayDir[j]) {
                array[k++] = arrayEsq[i++];
            } else {
                array[k++] = arrayDir[j++];
            }
        }

        while (i < n1) {
            array[k++] = arrayEsq[i++];
        }

        while (j < n2) {
            array[k++] = arrayDir[j++];
        }

        delete[] arrayEsq;
        delete[] arrayDir;
    }
}

// QuickSort Versão 1 - Primeiro elemento como pivô
int particionar_v1(int arr[], int baixo, int alto) {
    int pivo = arr[baixo];
    int i = baixo + 1, j = alto;

    while (true) {
        while (i <= alto && arr[i] <= pivo) i++;
        while (arr[j] > pivo) j--;
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[baixo], arr[j]);
    return j;
}

void QuickSort_v1(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo = particionar_v1(arr, baixo, alto);
        QuickSort_v1(arr, baixo, pivo - 1);
        QuickSort_v1(arr, pivo + 1, alto);
    }
}

// QuickSort Versão 2 - Mediana de três como pivô
int particionar_v2(int arr[], int baixo, int alto) {
    int mid = baixo + (alto - baixo) / 2;
    int pivo = arr[mid];
    swap(arr[mid], arr[alto]);

    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivo) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[alto]);
    return i + 1;
}

void QuickSort_v2(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo = particionar_v2(arr, baixo, alto);
        QuickSort_v2(arr, baixo, pivo - 1);
        QuickSort_v2(arr, pivo + 1, alto);
    }
}

// QuickSort Versão 3 - Pivô aleatório
int particionar_v3(int arr[], int baixo, int alto) {
    int randomIndex = baixo + rand() % (alto - baixo + 1);
    swap(arr[randomIndex], arr[alto]);

    int pivo = arr[alto];
    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivo) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[alto]);
    return i + 1;
}

void QuickSort_v3(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo = particionar_v3(arr, baixo, alto);
        QuickSort_v3(arr, baixo, pivo - 1);
        QuickSort_v3(arr, pivo + 1, alto);
    }
}

#endif // ALGORITMO_H
