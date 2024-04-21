/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 19 de abril de 2024, 16:44
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
#define MAXCOL 5
#define MAXFIL 5 

void insertarMovimientos(int movimientos[8][2]) {
    movimientos[0][0] = -1;
    movimientos[0][1] = -1;
    movimientos[1][0] = 0;
    movimientos[1][1] = -1;
    movimientos[2][0] = 1;
    movimientos[2][1] = -1;

    movimientos[3][0] = -1;
    movimientos[3][1] = 0;
    movimientos[4][0] = 1;
    movimientos[4][1] = 0;

    movimientos[5][0] = -1;
    movimientos[5][1] = 1;
    movimientos[6][0] = 0;
    movimientos[6][1] = 1;
    movimientos[7][0] = 1;
    movimientos[7][1] = 1;

}

int buscar(char tabla[5][5], char *word, int fila, int columna, int tamano, int movimientos[8][2]) {

    int i, j, nrow, ncol;
    if (tabla[fila][columna] != word[0])
        return 0;

    for (i = 0; i < 8; i++) {
        nrow = fila + movimientos[i][0];
        ncol = columna + movimientos[i][1];

        for (j = 1; j < tamano; j++) {
            if (nrow >= MAXFIL or nrow < 0 or ncol >= MAXCOL or ncol < 0)
                break;
            if (tabla[nrow][ncol] != word[j])
                break;
            nrow = nrow + movimientos[i][0];
            ncol = ncol + movimientos[i][1];
            /*MOSTRAR LA MATRIZ CON RESULTADOS*/
        }
        if (j == tamano)
            return 1;
    }
    return 0;
}

void SearchWord(char *word, int t, char tablero[5][5], char *res) {
    /*Se recorrera el tablero buscando la primera letra y si se encunetra se analizara sus 8 
     posibilidades */
    int movimientos[8][2];
    insertarMovimientos(movimientos);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (buscar(tablero, word, i, j, t, movimientos)){
                cout<<"bingoooo"<<endl;
                cout<<i+1<<","<<j+1<<endl;
            }

        }
    }
}

void ShowGameBoard(int t, char tablero [5][5]) {
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

void PopulateGameBoard(int t, char tablero[5][5]) {
    // Inicializamos la semilla para generar números aleatorios
    srand(time(NULL));

    // Llenamos el tablero con letras aleatorias
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            // Generamos un número aleatorio entre 65 ('A') y 90 ('Z')
            tablero[i][j] = rand() % 26 + 65;
        }
    }
}

int main(int argc, char** argv) {
    const int tamano = 5; // Tamaño del tablero
    char tablero[tamano][tamano]{
        {'H', 'G', 'A', 'F', 'Y'},
        {'D', 'Q', 'V', 'Z', 'R'},
        {'A', 'M', 'E', 'N', 'H'},
        {'O', 'G', 'O', 'R', 'F'},
        {'T', 'R', 'W', 'I', 'P'}
    };
    //   a. PopulateGameBoard(tamano, tablero); //Esyduarilo por diversion
    // b. Mostramos el tablero lleno
    ShowGameBoard(tamano, tablero);
    //c.
    char word[4]{'T', 'O', 'A', 'D'};
    char res[3];
    SearchWord(word, tamano, tablero, res);
    return 0;
}

