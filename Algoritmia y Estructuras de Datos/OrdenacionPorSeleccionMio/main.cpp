/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 2 de abril de 2024, 19:52
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    int arr[7]{89,45, 68, 90, 29, 34, 17};
    int cant=7;
    //pidenn ordenar de forma ascenente (menor a mayor) usando el metodo ordenacion por seleccion 
    // el metodo consiste en agarra el primer valor y comparar ese valor con todos y al final guardar 
    //entre esos el menor valor y colocarlo al principio al final de comprobar en la primera iteracion
    for (int i = 0; i < cant - 1; i++) {
        int min = i;
        for (int j = i + 1; j < cant; j++)
            if (arr[min] > arr[j]) min = j;
        int aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
    }
    //impresion    
    for (int i=0; i < cant ; i++ )cout <<arr[i]<<endl;
    return 0;
}

