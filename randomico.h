#ifndef RANDOMICO_H
#define RANDOMICO_H

#include "algoritmo.h"
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
namespace fs = std::filesystem;

void randomico(int taminst, FILE* entrada, FILE* saida) {
    double tempexec;
    time_t Comeco, Fim;
    int n = 0, *vet;

    fs::path basePath = fs::current_path() / "InsertionSort";
    fs::path entradaPath = basePath / "ArquivosEntrada" / "Randomico";
    fs::path saidaPath = basePath / "ArquivosSaida" / "Randomico";
    fs::path tempoPath = basePath / "ArquivosTempo" / "Randomico";

    fs::create_directories(entradaPath);
    fs::create_directories(saidaPath);
    fs::create_directories(tempoPath);

    fs::path arq1, arq2, arq3;
    switch (taminst) {
        case 1:
            n = 10;
            arq1 = entradaPath / "10RAND.txt";
            arq2 = saidaPath / "10SAID.txt";
            arq3 = tempoPath / "10TEMPO.txt";
            break;
        case 2:
            n = 100;
            arq1 = entradaPath / "100RAND.txt";
            arq2 = saidaPath / "100SAID.txt";
            arq3 = tempoPath / "100TEMPO.txt";
            break;
        case 3:
            n = 1000;
            arq1 = entradaPath / "1000RAND.txt";
            arq2 = saidaPath / "1000SAID.txt";
            arq3 = tempoPath / "1000TEMPO.txt";
            break;
        case 4:
            n = 10000;
            arq1 = entradaPath / "10000RAND.txt";
            arq2 = saidaPath / "10000SAID.txt";
            arq3 = tempoPath / "10000TEMPO.txt";
            break;
        case 5:
            n = 100000;
            arq1 = entradaPath / "100000RAND.txt";
            arq2 = saidaPath / "100000SAID.txt";
            arq3 = tempoPath / "100000TEMPO.txt";
            break; 
        case 6:
            n = 1000000;
            arq1 = entradaPath / "1000000RAND.txt";
            arq2 = saidaPath / "1000000SAID.txt";
            arq3 = tempoPath / "1000000TEMPO.txt";
            break;       
    }

    cout << "Gerando entrada randomica com " << n << " elementos." << endl;

    vet = new int[n];
    srand((unsigned)time(0));
    entrada = fopen(arq1.string().c_str(), "w");
    fprintf(entrada, "%d\n", n);
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 1000000;
        fprintf(entrada, "%d\n", vet[i]);
    }
    fclose(entrada);

    //cout << "Entrada randomica gerada em: " << arq1 << endl;

    cout << "Ordenando com o algoritmo Insertion Sort..." << endl;

    Comeco = clock();
    insertionSort(vet, n);
    Fim = clock();
    tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC);

    cout << "Ordenação concluída em " << tempexec << " segundos." << endl;

    saida = fopen(arq2.string().c_str(), "w");
    fprintf(saida, "%d\n", n);
    for (int m = 0; m < n; m++) {
        fprintf(saida, "%d\n", vet[m]);
    }
    fclose(saida);

    //cout << "Arquivo de saída gerado em: " << arq2 << endl;

    entrada = fopen(arq3.string().c_str(), "w");
    fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec);
    fclose(entrada);

    //cout << "Arquivo de tempo de execução gerado em: " << arq3 << endl;

    delete[] vet;

    cout << "Processo finalizado." << endl;
}

#endif // RANDOMICO_H
