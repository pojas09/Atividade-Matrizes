#include "cinema.h"

Cinema meuCinema;

int main() {

    bool retornar;

    for (int i = 0; i < numSalas; i++) {
        for (int j = 0; j < linhas; j++) {
            for (int k = 0; k < colunas; k++) {
                meuCinema.reservar(i, 'A' + j, k + 1);
            }
        }
    } // Para verificar como a matriz se comporta quando cheia

    do {
        retornar = true;
        cout << endl << "----------- Cinema -----------" << endl;  // Listagem das salas
        for (int i = 0; i < numSalas; i++) {
            cout << "(" << (i + 1) << ") Sala " << (i + 1) << endl;
        }
        cout << "(0) Sair" << endl;

        cout << endl << "Escolha uma sala para visualiza-la: " << endl; // Escolha de salas
        int opcaoSala;
        cin >> opcaoSala;
        opcaoSala = opcaoSala - 1;
        if (opcaoSala >= 0 && opcaoSala < numSalas) {
            meuCinema.visualizar(opcaoSala);

            cout << endl << "Deseja reservar uma poltrona? (s/n)" << endl;
            char opcaoReserva;
            cin >> opcaoReserva;

            switch (opcaoReserva) {

            case 's':
                cout << "Digite a linha da poltrona: " << endl;  // Compondo a reserva
                char linha;
                cin >> linha;
                cout << "Digite a coluna da poltrona: " << endl;
                int coluna;
                cin >> coluna;
                if (meuCinema.checarLotacao(opcaoSala) == false)
                    meuCinema.reservar(opcaoSala, linha, coluna);

                else {
                    bool salaLivre = false;

                    for (int i = 0; i < numSalas; i++) {    // Verificando Lotação
                        if (!meuCinema.checarLotacao(i)) {
                            cout << endl << "A sala " << opcaoSala + 1 << " está lotada, recomendamos que verifique a sala " << i + 1 << endl;
                            salaLivre = true;
                            break;
                        }
                    }
                    if (!salaLivre)
                        cout << endl << "Todas as salas estao lotadas!" << endl;
                }
                break;

            case 'n':
                break;

            default:
                cout << endl << "Opção invalida" << endl;
                break;
            }
        }
        else {
            cout << "Saindo..." << endl;
            retornar = false;
        }
    } while (retornar);

    return 0;
}