/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 15 de abril de 2024, 15:15
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void cargarBin(int num, int *combin_n) {
    int i = 0;
    while (num > 0) {
        combin_n[i] = num % 2;
        num = num / 2;
        i++;
    }

}

void buscarMejorSeleccion(int matDatos[][2], int cantArt, int pesoMaximo, int articulosMax) {
    //2.- La cantidad de combinaciones es a^n donde a es la cantidad de ¨mochilas¨ y n la cantidad de qarticulos 
    //si bien existe una mochila esta puede llevar o no el articulo asi que el no llevar el articulo es otra mochila
    int cantCombin = pow(2, cantArt);
    int mejorGanancia = 0, mejorPeso = 0, mejorOpcion = -1;
    int combin_n[cantArt]{}, mejorCombi[cantArt]{}; //n es el numero de la combinacion (por eso combinacion_n)
    //3.- Se guardara en el combin_n la combinacion expresada en binarios (1= si lo guardo y 0= si no lo guardó)
    for (int i = 0; i < cantCombin; i++) {
        int flag = 0;
        int pesoParcial = 0, articulosEquipados = 0, ganaParcial = 0; //Esto se declaro en el punto 5)
        cargarBin(i, combin_n);
        //4.- se carga el peso parcial de la combinacion y se verifica las restricciones
        for (int j = 0; j < cantArt; j++) {
            if (pesoParcial > pesoMaximo or articulosEquipados > articulosMax) {
                flag = 1;
                break; //Acab
            } else
                if (combin_n[j] != 0) {
                pesoParcial += matDatos[j][0];
                ganaParcial += matDatos[j][1];
                articulosEquipados++;
            }
        }

        if (flag == 1) break; //se usa la bandera para descartar la combinacion
        //5.- Se buscará la opccion mas optima (Si llega hasta acá cumplio todas las restricciones)
        if (mejorGanancia <= ganaParcial and mejorPeso <= pesoParcial) {
            mejorPeso = pesoParcial;
            mejorGanancia = ganaParcial;
            mejorOpcion = i;
        }
    }

    if (mejorOpcion != -1) {
        cargarBin(mejorOpcion, mejorCombi);
    } else cout << "NO SE ENCONTRO NINGUNA OPCION OPTIMA" << endl;

    for (int i = 0; i < cantArt; i++) {
        if (mejorCombi[i] != 0) cout << i + 1 << " ";
    }
}

int main(int argc, char** argv) {
    //Como es un caso de ingreso de productos en una caja o mochila se usara el metodo de  genes (Así se le dice creo )

    // 1.-Ingreso de datos: (por fines practicos se le asignó los valores para no ingresarlos en cada prueba)
    //Se puede definir como estructuras o como una matriz (se usará el caso de matriz )
    int cantArt = 6, cantCarac, pesoMaximo = 25, articulosMax = 6; //cantCar son los datos por articulo ejm: art1:peso=8, ganancia=15
    int matDatos[6][2]{
        {8, 15}, //por alguna razon no sirve si pongo : matDatos[cantArt][2]
        {2, 20},
        {10, 5},
        {10, 10},
        {5, 8},
        {5, 5}
    };

    //La mejor solucion es cuando se puede llevar la maxima cantidaad de objeto con la mayor ganancia posible
    buscarMejorSeleccion(matDatos, cantArt, pesoMaximo, articulosMax);

    return 0;
}



