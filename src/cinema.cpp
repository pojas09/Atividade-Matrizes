#include "cinema.h"

Cinema::Cinema() {
    for (int i = 0; i < numSalas; i++) {
        for (int j = 0; j < linhas; j++) {
            for (int k = 0; k < colunas; k++) {
                salas[i][j][k] = false;   // Incializa a matriz com valores falsos
            }
        }
    }
}

void Cinema::visualizar(int salaSelecionada) {
    cout << endl << "Sala " << salaSelecionada + 1 << ":" << endl << endl;
    cout << "      =====================================================================" << endl; // Indicador da Tela
    cout << "      |                                                                   |" << endl;
    cout << "      |                           T   E   L   A                           |" << endl;
    cout << "      |                                                                   |" << endl;
    cout << "      =====================================================================" << endl << endl;
    for (int i = 0; i < linhas; i++) {
        char letra = 'A' + i;
        cout << letra;
        cout << "  -  ";
        for (int j = 0; j < colunas; j++) {
            if (!salas[salaSelecionada][i][j])
                cout << " | O | ";
            else {
                cout << " | X | ";
            }
        }
        cout << endl << endl;
    }
    cout << "      ";
    for (int i = 0; i < colunas; i++) {
        cout << " [ " << i << " ] ";
    }
    cout << endl;
    cout << endl << "X = Poltrona Reservada" << endl;  // Especie de "Legenda"
    cout << "O = Poltrona Livre" << endl;
}

void Cinema::reservar(int salaSelecionada, char linhaSelecionada, int poltrona) {
    linhaSelecionada = toupper(linhaSelecionada); // Transformar o char em maiusculo
    int linha = linhaSelecionada - 'A'; /// A = 65 B = 66 ... B - A = 1 -> aponta para o Indice 1 | A - A = 0 -> aponta para o Indice 0
    poltrona = poltrona - 1;   // A poltrona tem que ser decrescida um numero para que o Indice seja adequado

    if (linha >= 0 && linha < linhas && poltrona >= 0 && poltrona < colunas) {
        if (!salas[salaSelecionada][linha][poltrona]) {
            salas[salaSelecionada][linha][poltrona] = true;
            cout << endl << "Reserva realizada com sucesso!" << endl;
        }
        else {
            cout << endl << "Este assento já está reservado." << endl;
        }
    }
    else {
        cout << endl << "Reserva cancelada, informações inválidas." << endl;
    }
}

bool Cinema::checarLotacao(int salaSelecionada) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (!salas[salaSelecionada][i][j])
                return false;  // Verifica se ha algum valor falso na matriz ou seja, livre
        }
    }
    return true;
}

void Cinema::exLotacaoMax() {
        for (int i = 0; i < numSalas; i++) {
        for (int j = 0; j < linhas; j++) {
            for (int k = 0; k < colunas; k++) {
                reservar(i, 'A' + j, k + 1);
            }
        }
    } // Para verificar como a matriz se comporta quando cheia
}

