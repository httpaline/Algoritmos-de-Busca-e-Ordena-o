#ifndef CRESCENTE_H
#define CRESCENTE_H

#include "algoritmo.h"        
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void crescente(int taminst, FILE* entrada, FILE* saida) {
    double tempexec;
    time_t Comeco, Fim;
    int n = 0, seed = (rand() % 1000000) * 100, *vet;

    fs::path basePath = fs::current_path() / "InsertionSort";
    fs::path entradaPath = basePath / "ArquivosEntrada" / "Crescente";
    fs::path saidaPath = basePath / "ArquivosSaida" / "Crescente";
    fs::path tempoPath = basePath / "ArquivosTempo" / "Crescente";

    fs::remove_all(entradaPath);
    fs::remove_all(saidaPath);
    fs::remove_all(tempoPath);

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

    vet = new int[n];
    entrada = fopen(arq1.string().c_str(), "w");
    fprintf(entrada, "%d\n", n);
    for (int i = 0; i < n; i++) {
        vet[i] = seed++;
        fprintf(entrada, "%d\n", vet[i]);
    }
    fclose(entrada);

    Comeco = clock();
    insertionSort(vet, n);
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
}

#endif // CRESCENTE_H
