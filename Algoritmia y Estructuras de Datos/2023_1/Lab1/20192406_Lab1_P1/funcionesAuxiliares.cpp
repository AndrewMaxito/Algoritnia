#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;
#include "strPaquetes.h"
#include "StrCamiones.h"
#include "funcionesAuxiliares.h"

void solucionCamiones(struct strPaquetes *arrPaquete, struct StrCamiones *arrCamiones,
        int cantCam, int cantPaq) {
    int cantOpciones = pow(cantCam, cantPaq); //combinacion
    int combinaciones[cantPaq]{};
    
    for (int opcion=0; opcion !=cantOpciones; opcion++) {
        cargaBase(opcion, combinaciones, cantPaq, cantCam);
        for (int j = 0; j < cantPaq; j++) cout << combinaciones[j] << " ";
        cout<< endl;
        
        // se convierte a base (Cantidad de camiones =3) para que me indique el camion en que se encuentra
        //entonces si el camion si marca 0 ira al camion 1; si marca 1 ira al camion 2; si marca 2 ira al 3
        //y como esta en base 3 nunca marcara 3 ya que no existe un camion 4 (para este caso en particular)
        
        



    }





}

//void cargaBase(int num, int *arr, int cantPaq, int cantCam) {
//
//    for (int i = 0; num > 0; i++) {
//        arr[i] = num % cantCam;
//        num = num / cantCam;
//    }
//}

void cargaBase(int n, int *arr, int b, int a){
    int re, j=0;
    for(int i=0;i<b; i++)arr[i]=0;

    while(n>0){
        re=n%a;
        n/=a;
        arr[j]=re;
        j++;
    }

}