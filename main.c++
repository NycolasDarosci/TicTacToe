#include <iostream>
#include <time.h>

using namespace std;

const int LINES = 3;
const int COLUMNS = 3;
const char X = 'X';
const char O = '0';

char print(
    char m[LINES][COLUMNS],
    int lin,
    int col,
    char player
) {
    system("cls");
    
    for (int c = 0; c < COLUMNS; c++) {
        cout << '\t' << c ;
    }
    
    if (lin != 10 && col != 10) {
        m[lin][col] = player;
        if (player == X) player = O;
        else player = X;
    }
    
    cout << "\n";
    
    for (int l = 0; l < LINES; l++) {
        cout << l;
        for(int c = 0; c < COLUMNS; c++) {
            cout << '\t' << m[l][c];
        }
        cout << "\n";
    }
    
    return player;
}


int main() {
    
    char opcao;
    
    do {
        cout << "Bem-vindo ao jogo da velha!\nMenu:" << endl;
        cout << "Jogar 1 contra 1 (j)" << endl;
        cout << "Desafiar a máquina (m)" << endl;
        cout << "Sobre (s)" << endl;
        cout << "Fim (f)" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << "\n";
        
        system("cls");
        
        switch(opcao) {
            case 'j':
                cout << "modo '1 contra 1' escolhido!\n";

                int lin = 10, col = 10, count = 9;
                char player, m[LINES][COLUMNS] = {
                    {'.', '.', '.'},
                    {'.', '.', '.'},
                    {'.', '.', '.'},
                };
                
                do {
                    cout << "Escolha X ou 0 para começar: "; cin >> player; cout << "\n";
                    if (player != X && player != O) cout << "Incorreto, digite novamente!\n";
                } while (player != X && player != O);
                
                system("cls");
                //srand(time(NULL));
                
                do {
                    player = print(
                        m, 
                        lin,
                        col,
                        player
                    );
                    
                    if (
                        player == X &&
                        //horizontal X
                        (m[0][0] == X && m[0][1] == X && m[0][2] == X) ||
                        (m[1][0] == X && m[1][1] == X && m[1][2] == X) ||
                        (m[2][0] == X && m[2][1] == X && m[2][2] == X) ||
                        //vertical X
                        (m[0][0] == X && m[1][0] == X && m[2][0] == X) ||
                        (m[0][1] == X && m[1][1] == X && m[2][1] == X) ||
                        (m[0][2] == X && m[1][2] == X && m[2][2] == X) ||
                        //diagonal X
                        (m[0][0] == X && m[1][1] == X && m[2][2] == X) ||
                        (m[0][2] == X && m[1][1] == X && m[2][0] == X)
                    ) {
                        cout << "Jogador X venceu!\n";
                        break;
                    } else if (
                        //horizontal 0
                        (m[0][0] == O && m[0][1] == O && m[0][2] == O) ||
                        (m[1][0] == O && m[1][1] == O && m[1][2] == O) ||
                        (m[2][0] == O && m[2][1] == O && m[2][2] == O) ||
                        //vertical 0
                        (m[0][0] == O && m[1][0] == O && m[2][0] == O) ||
                        (m[0][1] == O && m[1][1] == O && m[2][1] == O) ||
                        (m[0][2] == O && m[1][2] == O && m[2][2] == O) ||
                        //diagonal 0
                        (m[0][0] == O && m[1][1] == O && m[2][2] == O) ||
                        (m[0][2] == O && m[1][1] == O && m[2][0] == O)
                    ) {
                        cout << "Jogador 0 venceu!\n";
                        break;
                    }
                    
                    if (player == X) cout << "Jogador (" << player << ") sua vez\n";
                    else cout << "Jogador (" << player << ") sua vez\n";

                    do {
                        cout << "Digite a linha: "; cin >> lin;
                        cout << "Digite a coluna: "; cin >> col;
                        cout << "\n";
                        
                        if (lin < 0 || lin > 2 || col < 0 || col > 2) {
                            cout << "Errado, número fora do tabuleiro! Digite novamente: " << endl;
                        }
                        if (m[lin][col] == X || m[lin][col] == O) {
                        cout << "Posição ocupada! Digite novamente: " << endl; 
                        }
                    } while (
                        (m[lin][col] == X || m[lin][col] == O) ||
                        (lin < 0 || lin > 2 || col < 0 || col > 2)
                    );
                    
                    count--;
                    
                } while (count != 0);
            
                cout << "Fim do jogo!" << endl;

                break;
            case 'm':
                cout << "modo 'Desafiar a máquina' escolhido!\n";
                
                break;
            case 's':
                cout << "Algoritmo desenvolvido por Nycolas Darosci em 2024, sob a tutoria do professor Eduardo Alves!\n" << endl;
                system("cls");
                break;
        }
    }
    while (opcao != 'f');
    
    cout << "Você saiu do mastermind.";

    return 0;
}