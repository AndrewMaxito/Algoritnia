/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 2 de abril de 2024, 20:41
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    int arr[7]{89, 45, 68, 90, 29, 34, 17};
    int cant=7,aux,numeroItera=0;
    
    for (numeroItera=0;numeroItera<cant - 1;numeroItera++){
        for (int i = 0; i < cant - numeroItera- 1; i++) {
            if (arr[i] > arr[i + 1]) {
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
        }
        for (int i = 0; i < cant ; i++ ) cout <<arr[i]<< " ";
        cout<<endl;  
    }
    
//    while (numeroItera != cant - 1) {
//        for (int i = 0; i < cant - numeroItera- 1; i++) {
//            if (arr[i] > arr[i + 1]) {
//                aux = arr[i];
//                arr[i] = arr[i + 1];
//                arr[i + 1] = aux;
//            }
//        }
//        for (int i = 0; i < cant ; i++ ) cout <<arr[i]<< " ";
//        cout<<endl;
//        numeroItera++;
//    }
    
    for (int i = 0; i < cant ; i++ ) cout <<arr[i]<<endl;



    return 0;
}

