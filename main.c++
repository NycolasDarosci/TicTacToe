#include <iostream>
#include <time.h>

using namespace std;

const int LINHAS = 6;
const int COLUNAS = 6;


// void imprimir_matriz(int m[LINHAS][COLUNAS],
//                      int qtd_linhas,
//                      int qtd_colunas) {

//     for(int i = 0; i < qtd_colunas; i++) {
//         cout << '\t' << i;
//     }

//     cout << endl;

//     for(int l = 0; l < qtd_linhas; l++) {
//         cout << l;
//         for(int c = 0; c < qtd_colunas; c++) {
//             if(m[l][c] == 100) {
//                 cout << "\t#";
//             } else {
//                 if (m[l][c] == 200) {
//                     cout << "\tX";
//                 } else {
//                     cout << '\t' << m[l][c];
//                 }
//             }
//         }
//         cout << endl;
//     }

// }


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
                cout << "modo 'Jogar 1 contra 1' escolhido!\n";
                
                int qtd_linhas = 3, qtd_colunas = 3, tentativas = 9,
                lin = 10, col = 10;
            
                char m[LINHAS][COLUNAS] = {
                    {'.', '.', '.'},
                    {'.', '.', '.'},
                    {'.', '.', '.'},
                };
                
                srand(time(NULL));
                
                do {
         
                    imprimir_matriz(
                        m, 
                        qtd_linhas, 
                        qtd_colunas,
                        lin,
                        col
                    );

                    do {
                        cin >> lin;
                        cin >> col;

                        if (lin < 0 || lin > 2 || col < 0 || col > 2) {
                            cout << "Errado, número fora do tabuleiro! Digite novamente: " << endl;
                        }
                        if (m[lin][col] != '.') {
                        cout << "Posição ocupada! Digite novamente: " << endl; 
                        }
                    } while (
                        m[lin][col] != '.' ||
                        (lin < 0 || lin > 2 || col < 0 || col > 2)
                    );
                    
                    tentativas--;
                    cout << "tentativas: " << tentativas << endl;

                } while (
                    tentativas != 0
                    //horizontal
                    // (m[0][0] == '.' && m[0][1] == '.' && m[0][2] == '.') ||
                    // (m[1][0] == '.' && m[1][1] == '.' && m[1][2] == '.') ||
                    // (m[2][0] == '.' && m[2][1] == '.' && m[2][2] == '.') ||
                    // //vertical
                    // (m[0][0] == '.' && m[1][0] == '.' && m[2][0] == '.') ||
                    // (m[0][1] == '.' && m[1][1] == '.' && m[2][1] == '.') ||
                    // (m[0][2] == '.' && m[1][2] == '.' && m[2][2] == '.') ||
                    //  //diagonal
                    // (m[0][0] == '.' && m[1][1] == '.' && m[2][2] == '.') ||
                    // (m[0][2] == '.' && m[1][1] == '.' && m[2][0] == '.')
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