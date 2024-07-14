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
    cout << endl << "X = Poltrona Reservada" << endl;  // Esp�cie de "Legenda"
    cout << "O = Poltrona Livre" << endl;
}

void Cinema::reservar(int salaSelecionada, char linhaSelecionada, int poltrona) {
    linhaSelecionada = toupper(linhaSelecionada); // Transformar o char em mai�sculo
    int linha = linhaSelecionada - 'A'; /// A = 65 B = 66 ... B - A = 1 -> aponta para o �ndice 1 | A - A = 0 -> aponta para o �ndice 0
    poltrona = poltrona - 1;   // A poltrona tem que ser decrescida um n�mero para que o �ndice seja adequado

    if (linha >= 0 && linha < linhas && poltrona >= 0 && poltrona < colunas) {
        if (!salas[salaSelecionada][linha][poltrona]) {
            salas[salaSelecionada][linha][poltrona] = true;
            cout << endl << "Reserva realizada com sucesso!" << endl;
        }
        else {
            cout << endl << "Este assento ja esta reservado" << endl;
        }
    }
    else {
        cout << endl << "Reserva cancelada, informa��es invalidas" << endl;
    }
}

bool Cinema::checarLotacao(int salaSelecionada) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (!salas[salaSelecionada][i][j])
                return false;  // Verifica se h� algum valor falso na matriz ou seja, livre
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

