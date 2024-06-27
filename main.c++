#include <iostream>


using namespace std;


const int LINHAS = 6;

const int COLUNAS = 6;


void imprimir_matriz(int m[LINHAS][COLUNAS],
                     int qtd_linhas,
                     int qtd_colunas) {

    for(int i = 0; i < qtd_colunas; i++) {
        cout << '\t' << i;
    }

    cout << endl;

    for(int l = 0; l < qtd_linhas; l++) {
        cout << l;
        for(int c = 0; c < qtd_colunas; c++) {
            if(m[l][c] == 100) {
                cout << "\t#";
            } else {
                if (m[l][c] == 200) {
                    cout << "\tX";
                } else {
                    cout << '\t' << m[l][c];
                }
            }
        }
        cout << endl;
    }

}


int main() {

    int m[LINHAS][COLUNAS] = {0};

    int qtd_linhas = 3, qtd_colunas = 3;


    srand(time(NULL));


    int contador = 1;

    for(int l = 0; l < qtd_linhas; l++) {

        for(int c = 0; c < qtd_colunas; c++) {

            m[l][c] = contador;

            contador++;

        }

    }


    // Imprimindo a matriz

    cout << "Primeira vez!" << endl;

    imprimir_matriz(m,qtd_linhas,qtd_colunas);

    cout << "Segunda vez!" << endl;

    //imprimir_matriz(m,3,3);


    int escolha_jogador1 = 6 - 1; // Como as células começam com o número 1 (na linha 0 coluna 0), esse menos 1 é necessário em relação ao valor escolhido pelo usuário, nesse caso 6, que deve ser traduzido para a linha 1 coluna 2.

    m[0][2] = 100; // Atribuição em uma casa específica para o jogador 1 (representado pelo número 100). Representa marcar X na posição escolhida.

    m[2][1] = 200; // Atribuição em uma casa específica para o jogador 2 (representado pelo0 número 200). Representa marcar # na posição escolhida.


    imprimir_matriz(m,qtd_linhas,qtd_colunas);


    int linha = escolha_jogador1 / qtd_colunas;

    int coluna = escolha_jogador1 % qtd_colunas;

    cout << endl << linha << " - " << coluna << endl;


    if(m[linha][coluna] < 1 || m[linha][coluna] > 36) {

        cout << "Errado, número fora do tabuleiro!";

    } else {

        if(m[linha][coluna] == 100 || m[linha][coluna] == 200) {

            cout << "Posição ocupada";

        } else {

            cout << "Livre";

        }

    }


/*

    for(int i = 0; i < qtd_linhas * qtd_colunas; i++) {

//        if( i % qtd_colunas == 0 ) {

//            cout << '\n';

//        }

        int linha_calculada = i / qtd_colunas;

        int coluna_calculada = i % qtd_colunas;


        cout << "Linha calculada : " << linha_calculada

             << " - Coluna caculada: " << coluna_calculada

             << " - valor da celula: "

             << m[ linha_calculada ][ coluna_calculada ] << endl;

//        cout <<  << '\t';

    }

*/

    return 0;

}