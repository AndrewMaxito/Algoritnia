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

void SearchWord(char *word, int t, char tablero[5][5], char *res){
    
    
    
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
    char word[4]{'T','O','A','D'};
    char res[3];
    
    SearchWord( word,  tamano, tablero, res);
    


    

    return 0;
}

