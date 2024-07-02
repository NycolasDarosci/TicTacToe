#include <iostream>
#include <time.h>

using namespace std;

// board lines and columns
const int LINES_NORMAL = 3;
const int COLUMNS_NORMAL = 3;
const int LINES_EXPANDED = 6;
const int COLUMNS_EXPANDED = 6;
// board
const char B_NORMAL = 'n';
const char B_EXPANDED = 'a';
// symbols
const char X = 'X';
const char O = '0';

char print_expanded_board(
    char m[LINES_EXPANDED][COLUMNS_EXPANDED],
    int lin,
    int col,
    char player
) {
    system("cls");
    
    for (int c = 0; c < COLUMNS_EXPANDED; c++) {
        cout << '\t' << c ;
    }
    
    if (lin != 6 && col != 6) {
        m[lin][col] = player;
        if (player == X) player = O;
        else player = X;
    }
    
    cout << "\n";
    
    for (int l = 0; l < LINES_EXPANDED; l++) {
        cout << l;
        for(int c = 0; c < COLUMNS_EXPANDED; c++) {
            cout << '\t' << m[l][c];
        }
        cout << "\n";
    }
    
    return player;
}

char print_normal_board(
    char m[LINES_NORMAL][COLUMNS_NORMAL],
    int lin,
    int col,
    char player
) {
    system("cls");
    
    for (int c = 0; c < COLUMNS_NORMAL; c++) {
        cout << '\t' << c ;
    }
    
    if (lin != 3 && col != 3) {
        m[lin][col] = player;
        if (player == X) player = O;
        else player = X;
    }
    
    cout << "\n";
    
    for (int l = 0; l < LINES_NORMAL; l++) {
        cout << l;
        for(int c = 0; c < COLUMNS_NORMAL; c++) {
            cout << '\t' << m[l][c];
        }
        cout << "\n";
    }
    
    return player;
}

int main() {
    
    char option;
    
    do {
        cout << "Bem-vindo ao jogo da velha!\nMenu:" << endl;
        cout << "Jogar 1 contra 1 (j)" << endl;
        cout << "Desafiar a máquina (m)" << endl;
        cout << "Sobre (s)" << endl;
        cout << "Fim (f)" << endl;
        cout << "Escolha uma opcao: ";
        cin >> option;
        cout << "\n";
        
        system("cls");
        
        if (option == 'j') {
            cout << "modo '1 contra 1' escolhido!\n";
            
            char board;
            
            do {
                cout << "Digite (n) se deseja jogar no tabuleiro normal.\nDigite (a) se deseja jogar no tabuleiro ampliado.\n"; cin >> board;
                
                if (board != B_NORMAL && board != B_EXPANDED) 
                    cout << "Escolha errada!\n";
                
            } while (board != B_NORMAL && board != B_EXPANDED);
            
            
            int lin, col, count;
            bool tied = true;
            char player;
            
            if (board == B_NORMAL) {
                cout << "Tabuleiro normal escolhido!\n";
                
                system("cls");
                
                char m[LINES_NORMAL][COLUMNS_NORMAL] = {
                    {'-', '-', '-'},
                    {'-', '-', '-'},
                    {'-', '-', '-'},
                };
                lin = 3; col = 3; count = 9;
                
                do {
                    cout << "Escolha X ou 0 para começar: "; cin >> player; cout << "\n";
                    if (player != X && player != O) cout << "Incorreto, digite novamente!\n";
                } while (player != X && player != O);
                
                system("cls");
                //srand(time(NULL));
                
                do {
                    player = print_normal_board(
                        m, 
                        lin,
                        col,
                        player
                    );
                    
                    // horizontal and vertical
                    for (int i = 0; i < 3; i++) {
                        if (
                            player == X &&
                            (m[i][0] == X && m[i][1] == X && m[i][2] == X) ||
                            (m[0][i] == X && m[1][i] == X && m[2][i] == X)   
                        ) {
                            cout << "Jogador X venceu!\n";
                            tied = false;
                            break;
                        }
                        else if (
                            (m[i][0] == O && m[i][1] == O && m[i][2] == O) ||
                            (m[0][i] == O && m[1][i] == O && m[2][i] == O)     
                        ) {
                            cout << "Jogador 0 venceu!\n";
                            tied = false;
                            break;
                        }
                    }
                    // diagonal
                    if (
                        (m[0][0] == X && m[1][1] == X && m[2][2] == X) ||
                        (m[0][2] == X && m[1][1] == X && m[2][0] == X)
                    ) {
                        cout << "Jogador X venceu!\n";
                        tied = false;
                        break;
                    }
                    else if (
                        (m[0][0] == O && m[1][1] == O && m[2][2] == O) ||
                        (m[0][2] == O && m[1][1] == O && m[2][0] == O)
                    ) {
                        cout << "Jogador 0 venceu!\n";
                        tied = false;
                        break;
                    }
                    
                    if (!tied) break;
                    
                    cout << "\n";
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
            
                if (tied) cout << "Empate!\n";
                cout << "Fim do jogo!\n";
                system("cls");
            }
            else {
                cout << "Tabuleiro ampliado escolhido!\n";
                
                system("cls");
                
                char m[LINES_EXPANDED][COLUMNS_EXPANDED] = {
                    {'-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-'}
                };
                lin = 6; col = 6; count = 36;
                
                do {
                    cout << "Escolha X ou 0 para começar: "; cin >> player; cout << "\n";
                    if (player != X && player != O) cout << "Incorreto, digite novamente!\n";
                } while (player != X && player != O);
                
                system("cls");
                //srand(time(NULL));
                
                do {
                    player = print_expanded_board(
                        m, 
                        lin,
                        col,
                        player
                    );
                    
                    // horizontal and vertical
                    for (int i = 0; i < 6; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            if (
                                player == X &&
                                (m[i][j] == X && m[i][j+1] == X && m[i][j+2] == X) ||
                                (m[j][i] == X && m[j+1][i] == X && m[j+2][i] == X)
                            ) {
                                cout << "Jogador X venceu!\n";
                                tied = false;
                                break;
                            }
                            else if (
                                (m[i][j] == O && m[i][j+1] == O && m[i][j+2] == O) ||
                                (m[j][i] == O && m[j+1][i] == O && m[j+2][i] == O)
                            ) {
                                cout << "Jogador 0 venceu!\n";
                                tied = false;
                                break;
                            }
                        }
                    }
                    
                    // Diagonal
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            if (
                                player == X &&
                                (m[i][j] == X && m[i+1][j+1] == X && m[i+2][j+2] == X) ||
                                (m[i+2][j] == X && m[i+1][j+1] == X && m[i][j+2] == X)
                            ) {
                                cout << "Jogador X venceu!\n";
                                tied = false;
                                break;
                            }
                            else if (
                                (m[i][j] == O && m[i+1][j+1] == O && m[i+2][j+2] == O) ||
                                (m[i+2][j] == O && m[i+1][j+1] == O && m[i][j+2] == O)
                            ) {
                                cout << "Jogador 0 venceu!\n";
                                tied = false;
                                break;
                            }
                        }
                    }
                    
                    // Anti diagonal
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 2; j < 6; ++j) {
                            if (
                                player == X &&
                                (m[i][j] == X && m[i+1][j-1] == X && m[i+2][j-2] == X) ||
                                (m[i+2][j] == X && m[i+1][j-1] == X && m[i][j-2] == X)
                            ) {
                                cout << "Jogador X venceu!\n";
                                tied = false;
                                break;
                            }
                            else if (
                                (m[i][j] == O && m[i+1][j-1] == O && m[i+2][j-2] == O) ||
                                (m[i+2][j] == O && m[i+1][j-1] == O && m[i][j-2] == O)
                            ) {
                                cout << "Jogador 0 venceu!\n";
                                tied = false;
                                break;
                            }
                        }
                    }
                    
                    if (!tied) break;
                    
                    cout << "\n";
                    if (player == X) cout << "Jogador (" << player << ") sua vez\n";
                    else cout << "Jogador (" << player << ") sua vez\n";
            
                    do {
                        cout << "Digite a linha: "; cin >> lin;
                        cout << "Digite a coluna: "; cin >> col;
                        cout << "\n";
                        
                        if (lin < 0 || lin > 5 || col < 0 || col > 5) {
                            cout << "Errado, número fora do tabuleiro! Digite novamente: " << endl;
                        }
                        if (m[lin][col] == X || m[lin][col] == O) {
                        cout << "Posição ocupada! Digite novamente: " << endl; 
                        }
                    } while (
                        (m[lin][col] == X || m[lin][col] == O) ||
                        (lin < 0 || lin > 5 || col < 0 || col > 5)
                    );
                    
                    count--;
                    
                } while (count != 0);
            
                if (tied) cout << "Empate!\n";
                cout << "Fim do jogo!\n";
                system("cls");
                
            }
        }
        else if (option == 'm') {
            cout << "modo 'Desafiar a máquina' escolhido!\n";
            
            //codigo
            
            cout << "Fim do jogo!\n";
            system("cls");
        }        
        else if (option == 's') {
            cout << "Algoritmo desenvolvido por Nycolas Darosci em 2024, sob a tutoria do professor Eduardo Alves!\n" << endl;
            system("cls");
        }
    }
    while (option != 'f');
    
    cout << "Você saiu do jogo da velha!";

    return 0;
}