#ifndef cinema_h
#define cinema_h

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

    void exLotacaoMax();
};

#endif
