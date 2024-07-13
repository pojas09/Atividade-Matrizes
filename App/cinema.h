#ifndef CINEMA_H
#define CINEMA_H

#include <iostream>

using namespace std;
const int numSalas = 2;
const int linhas = 15;
const int colunas = 10;

class Cinema {

private:

    bool salas[numSalas][linhas][colunas];

public:

    Cinema();
    void visualizar(int salaSelecionada);
    void reservar(int salaSelecionada, char linhaSelecionada, int poltrona);
    bool checarLotacao(int salaSelecionada);
};

#endif
