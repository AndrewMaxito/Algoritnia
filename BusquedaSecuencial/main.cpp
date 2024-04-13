/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 2 de abril de 2024, 21:41
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    int arr[7]{25,8,96,48,75,36,27};
    int i=0,cant=7,pos,numeroBuscad=27;
    
//    while (i<cant and arr[i] != numeroBuscad){
//        i++;
//    }
//    
//    if (i < cant){
//        pos = i;
//    }else pos = -1;
    
    int j=0;
    for ( j=0;j<cant;j++)
        if (arr[j]==numeroBuscad) break;
    
    if (j < cant){
        pos = j;
    }else pos = -1;
    return 0;
}

