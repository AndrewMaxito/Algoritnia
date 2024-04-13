#include <iostream>
#include <cmath>
using namespace std;
#include "strPaquetes.h"
#include "StrCamiones.h"
#include "funcionesAuxiliares.h"

int main() {
    int M = 4, N = 5; //M es la cant camiones y N la cantidad de paquetes 
    //Ingreso de datos: 
    
//    cout << "Ingrese el numero de caniones y luego el numero de Paquetes " << endl;
//    cin >> M >> N;
    
     struct strPaquetes arrPaquete[N]{{50},{20},{30},{50},{20}};
     struct StrCamiones arrCamiones[M]{{25},{50},{100},{100}};
    //Ingresar las cargas  y capacidad
     //cout << "Ingrese el peso de cada paquete: "<<endl;
    // for (int i = 0; i < N; i++) cin >> arrPaquete[i].peso;
     // cout << "Ingrese la capacidad de cada camion"<<endl;
     // for (int i = 0; i < N; i++) cin >> arrPaquete[i].peso;
    

    solucionCamiones(arrPaquete,arrCamiones,M,N);


    return 0;
}