/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 2 de abril de 2024, 19:52
 */

#include <iostream>
#include <iomanip>

using namespace std;




void ordenarFormaRecursiva(int *arrA,int pos,int cantA){
    
    if (pos >= cantA) return;
    int min=pos;
    for (int i=pos;i<cantA;i++)
        if (arrA[min] > arrA[i] ) min=i;
    int aux = arrA[pos];
    arrA[pos]=arrA[min];
    arrA[min]=aux;
    pos++;
    ordenarFormaRecursiva( arrA,  pos, cantA);
}



int main(int argc, char** argv) {
    int arr[7]{89,45, 68, 90, 29, 34, 17};
    int cant=7;
    //Piden ordenar de forma ascenente (menor a mayor) usando el metodo ordenacion por seleccion
    
    /*El algoritmo se basa en fijar la pocision en que se quiere poner el numero luego se busca el 
      menor numero de la serie y cuando se encuentre al haber evaludado todos se colocara en la
     poscision que se estaba evaluando y se pasara a la siguinte poscion y se repetira el proceso */
    
    //Forma iterativa
    for (int i = 0; i < cant - 1; i++) {
        int min = i;
        for (int j = i + 1; j < cant; j++)
            if (arr[min] > arr[j]) min = j;
        int aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
    }
    
    //Forma recursiva (echo por mi para practicar)
    int arrA[7]{89,45, 68, 90, 29, 34, 17};
    int cantA=7,pos=0;
    ordenarFormaRecursiva(arrA,pos,cantA);
    
    //impresion
    cout<<"Metodo Recursivo Resultado: "<<endl;
    for (int i=0; i < cant ; i++ )cout <<arrA[i]<< " ";
    cout<<endl<<endl;
    cout << "Metodo iterativo " << endl;
    for (int i=0; i < cant ; i++ )cout <<arr[i]<< " ";
    return 0;
}

