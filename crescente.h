#ifndef CRESCENTE_H
#define CRESCENTE_H

#include "algoritmo.h" 
#include "classe.h"       
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void crescente(int taminst, FILE* entrada, FILE* saida, Algoritmo alg) {
    double tempexec;
    time_t Comeco, Fim;
    int n = 0, seed = (rand() % 1000000) * 100, *vet;

    std::string algoritmoNome;
    switch (alg) {
        case Algoritmo::Insertion: algoritmoNome = "InsertionSort"; break;
        case Algoritmo::Selection: algoritmoNome = "SelectionSort"; break;
        case Algoritmo::Shell: algoritmoNome = "ShellSort"; break;
        case Algoritmo::Bubble: algoritmoNome = "BubbleSort"; break;
        case Algoritmo::Merge: algoritmoNome = "MergeSort"; break;
    }
    fs::path basePath = fs::current_path() / algoritmoNome;
    fs::path entradaPath = basePath / "ArquivosEntrada" / "Crescente";
    fs::path saidaPath = basePath / "ArquivosSaida" / "Crescente";
    fs::path tempoPath = basePath / "ArquivosTempo" / "Crescente";

    fs::create_directories(entradaPath);
    fs::create_directories(saidaPath);
    fs::create_directories(tempoPath);

    fs::path arq1, arq2, arq3;
    switch (taminst) {
        case 1:
            n = 10;
            arq1 = entradaPath / "10CRES.txt";
            arq2 = saidaPath / "10SAID.txt";
            arq3 = tempoPath / "10TEMPO.txt";
            break;
        case 2:
            n = 100;
            arq1 = entradaPath / "100CRES.txt";
            arq2 = saidaPath / "100SAID.txt";
            arq3 = tempoPath / "100TEMPO.txt";
            break;
        case 3:
            n = 1000;
            arq1 = entradaPath / "1000CRES.txt";
            arq2 = saidaPath / "1000SAID.txt";
            arq3 = tempoPath / "1000TEMPO.txt";
            break;
        case 4:
            n = 10000;
            arq1 = entradaPath / "10000CRES.txt";
            arq2 = saidaPath / "10000SAID.txt";
            arq3 = tempoPath / "10000TEMPO.txt";
            break;
        case 5:
            n = 100000;
            arq1 = entradaPath / "100000CRES.txt";
            arq2 = saidaPath / "100000SAID.txt";
            arq3 = tempoPath / "100000TEMPO.txt";
            break; 
        case 6:
            n = 1000000;
            arq1 = entradaPath / "1000000CRES.txt";
            arq2 = saidaPath / "1000000SAID.txt";
            arq3 = tempoPath / "1000000TEMPO.txt";
            break;       
    }

    cout << "Gerando entrada crescente com " << n << " elementos." << endl;

    vet = new int[n];
    entrada = fopen(arq1.string().c_str(), "w");
    fprintf(entrada, "%d\n", n);
    for (int i = 0; i < n; i++) {
        vet[i] = seed++;
        fprintf(entrada, "%d\n", vet[i]);
    }
    fclose(entrada);

    cout << "Ordenando com o algoritmo " << algoritmoNome << "..." << endl;

    Comeco = clock();
    switch (alg) {
        case Algoritmo::Insertion:
            insertionSort(vet, n);
            break;
        case Algoritmo::Selection:
            SelectionSort(vet, n);
            break;
        case Algoritmo::Shell:
            ShellSort(vet, n);
            break;
        case Algoritmo::Bubble:
            BubbleSort(vet, n);
            break;
        case Algoritmo::Merge:
            MergeSort(vet, 0, n-1);    
        }

    Fim = clock();
    tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC);

    saida = fopen(arq2.string().c_str(), "w");
    fprintf(saida, "%d\n", n);
    for (int m = 0; m < n; m++) {
        fprintf(saida, "%d\n", vet[m]);
    }
    fclose(saida);

    entrada = fopen(arq3.string().c_str(), "w");
    fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec);
    fclose(entrada);

    delete[] vet;
    
    cout << "Processo finalizado." << endl;
}

#endif // CRESCENTE_H
