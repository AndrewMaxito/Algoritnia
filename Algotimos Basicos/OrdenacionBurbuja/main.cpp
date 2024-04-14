/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 2 de abril de 2024, 20:41
 */

#include <iostream>
#include <iomanip>

using namespace std;

void metodoBurbujaRecursividad(int *arrA, int cant) {

    if (cant <= 1) return; // se realizara el proceso hasta que solo quede un dato por evaluar

    for (int i = 0; i < cant - 1; i++) {
        if (arrA[i] > arrA[i + 1]) {
            int aux = arrA[i];
            arrA[i] = arrA[i + 1];
            arrA[i + 1] = aux;
        }
    }
    metodoBurbujaRecursividad(arrA, --cant);
}

int main(int argc, char** argv) {
    int arr[7]{89, 45, 68, 90, 29, 34, 17};
    int cant = 7, numeroItera = 0;
//------------------------------------------------------------------------------
    /*Metodo por iteraciones*/

    /*Si evaluamos los casos nos daremos cuenta que repetiremos el metodo (asumiendo que tenemos 
     n datos) n-1 veces ya que para la ultima evaluacion sí o sí ya estara ordenado ademas  
     debemos tomar en cuenta que cuando se aplica por primea vez la burbuja el ultimo dato 
     quedara ordenado asi que en la siguiente vez deberemos evaluar ya no n-1 veces sino 
     n-1-cantidad de veces que se itero*/


    for (numeroItera = 0; numeroItera < cant - 1; numeroItera++) {
        for (int i = 0; i < cant - numeroItera - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
        }
    }
    /*Otra forma usando iteraciones pero con While (yo concidero mas efectivo el for en este caso
     ya que existe un contador de iteraciones y se adapta mejor al for () ) */

    //    while (numeroItera != cant - 1) {
    //        for (int i = 0; i < cant - numeroItera- 1; i++) {
    //            if (arr[i] > arr[i + 1]) {
    //                int aux = arr[i];
    //                arr[i] = arr[i + 1];
    //                arr[i + 1] = aux;
    //            }
    //        }
    //        for (int i = 0; i < cant ; i++ ) cout <<arr[i]<< " ";
    //        cout<<endl;
    //        numeroItera++;
    //    }
    //---------------------------------------------------------------------------
    /*Usando metodo de recursividad: */
    int arrA[7]{89, 45, 68, 90, 29, 34, 17};
    int canA = 7;
    metodoBurbujaRecursividad(arrA, canA);


    cout << "Metodo iteracion: " << endl;
    for (int i = 0; i < cant; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Metodo Recursividad: " << endl;
    for (int i = 0; i < cant; i++) cout << arrA[i] << " ";
    return 0;
}

