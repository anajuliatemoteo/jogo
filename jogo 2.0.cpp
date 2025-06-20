#include <iostream>
using namespace std;

int main() {
    int MAX_TENTATIVAS = 50;
    int NumeroOculto;
    int palpites[MAX_TENTATIVAS];
    int jogador = 1;
    int min = 1, max = 100;
    int acertou = 0;


    for (int i = 0; i < MAX_TENTATIVAS; i++) {
        palpites[i] = 0;
    }

    cout << "Jogador neutro, escolha um numero entre 1 e 100 (ele nao sera exibido): ";
    cin >> NumeroOculto;

    while (NumeroOculto < 1 || NumeroOculto > 100) {
        cout << "Numero invalido. Digite um numero entre 1 e 100: ";
        cin >> NumeroOculto;
    }
    cout << "\n--- Jogo Iniciado ---\n";

    int i;
    for (i = 0; i < MAX_TENTATIVAS && acertou == 0; i++) {
        int palpite;
        cout << "\nJogador " << jogador << ", digite um palpite entre " << min << " e " << max << ": ";
        cin >> palpite;

        if (palpite <= min || palpite >= max) {
            cout << "Numero invalido, digite outro palpite.\n";
            i--;
        } else {
            palpites[i] = palpite;

            if (palpite == NumeroOculto) {
                cout << "\nParabens jogador " << jogador << ", voce perdeu o jogo!\n";
                acertou = 1;
            } else {
                if (palpite < NumeroOculto) {
                    min = palpite;
                } else {
                    max = palpite;
                }

                jogador = (jogador == 1) ? 2 : 1;
            }
        }
    }

    cout << "\n--- Palpites realizados ---\n";
    for (int j = 0; j < i; j++) {
        cout << "Tentativa " << j + 1 << ": " << palpites[j] << endl;
    }

    return 0;
}
