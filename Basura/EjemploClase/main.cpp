/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 13 de abril de 2024, 21:19
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    char arr[8]{'a','b','m','a','x','e','r'};
    int pa[3]{'m','a','x'};
    int pruebasPosibles=7-3+1,pos=-1;
    
    
    for (int i=0;i<pruebasPosibles;i++){
        int j;
        for ( j=0;pa[j]==arr[i+j] and j<3 ;j++);
        if (j==3) pos=i;
    }
    if (pos != -1){
        cout<< "Se encontro lo buscado en la pos " << pos+1 <<" de la cadena "<<endl;
    }else cout<<"No se encontro el nombre en la cadena"<<endl;
    cout << arr <<endl;


    return 0;
}

