#include <iostream>
using namespace std;

int main() {
    int NumeroOculto;
    int palpite;
    int jogador = 1;
    int min = 1, max = 100;
    int acertou = 0; 

    
    cout << "Jogador neutro, escolha um numero entre 1 e 100 (ele nao sera exibido): ";
    cin >> NumeroOculto;

    while (NumeroOculto < 1 || NumeroOculto > 100) {
        cout << "Numero invalido. Digite um numero entre 1 e 100: ";
        cin >> NumeroOculto;
    }

    cout << "\n--- Jogo Iniciado ---\n";

    do {
        cout << "\nJogador " << jogador << ", digite um palpite entre " << min << " e " << max << ": ";
        cin >> palpite;

        if (palpite > min && palpite < max) {
            if (palpite == NumeroOculto) {
                cout << "\nParabens jogador " << jogador << ", voce perdeu o jogo!\n";
                acertou = 1; 
            } else {
                if (palpite < NumeroOculto) {
                    min = palpite;
                } else {
                    max = palpite;
                }

                
                if (jogador == 1) {
                    jogador = 2;
                } else {
                    jogador = 1;
                }
            }
        } else {
            cout << "Numero invalido, digite outro palpite.\n";
        }

    } while (acertou == 0);

    return 0;
}
