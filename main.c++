#include <iostream>
#include <time.h>

using namespace std;

const int LINHAS = 6;
const int COLUNAS = 6;

const char X = 'X';
const char O = '0';


char print(
    char m[LINES][COLUMNS],
    int qtd_lines,
    int qtd_columns,
    int lin,
    int col,
    char player
) {
    system("cls");
    
    for (int c = 0; c < qtd_columns; c++) {
        cout << '\t' << c ;
    }
    
    if (lin != 10 && col != 10) {
        m[lin][col] = player;
        if (player == X) player = O;
        else player = X;
    }
    
    cout << "\n";
    
    for (int l = 0; l < qtd_columns; l++) {
        cout << l;
        for(int c = 0; c < qtd_columns; c++) {
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
                int qtd_lines = 3, qtd_columns = 3,
                    lin = 10, col = 10,
                    count = 9;
    
                char player;
                
                do {
                    cout << "Escolha X ou 0 para começar: "; cin >> player; cout << "\n";
                    if (player != X && player != O) cout << "Incorreto, digite novamente!\n";
                } while (player != X && player != O);
                
                
                char m[LINES][COLUMNS] = {
                    {'.', '.', '.'},
                    {'.', '.', '.'},
                    {'.', '.', '.'},
                };
                
                srand(time(NULL));
                
                do {
                    player = print(
                        m, 
                        qtd_lines, 
                        qtd_columns,
                        lin,
                        col,
                        player
                    );
                    
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
                } while (
                    count != 0 ||
                    //horizontal
                    // testando essas condicoes
                    (m[0][0] != '.' && m[0][1] != '.' && m[0][2] != '.') &&
                    (m[1][0] != '.' && m[1][1] != '.' && m[1][2] != '.') &&
                    (m[2][0] != '.' && m[2][1] != '.' && m[2][2] != '.') &&
                    //vertical
                    (m[0][0] != '.' && m[1][0] != '.' && m[2][0] != '.') &&
                    (m[0][1] != '.' && m[1][1] != '.' && m[2][1] != '.') &&
                    (m[0][2] != '.' && m[1][2] != '.' && m[2][2] != '.') &&
                    //diagonal
                    (m[0][0] != '.' && m[1][1] != '.' && m[2][2] != '.') &&
                    (m[0][2] != '.' && m[1][1] != '.' && m[2][0] != '.')
                );
            
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