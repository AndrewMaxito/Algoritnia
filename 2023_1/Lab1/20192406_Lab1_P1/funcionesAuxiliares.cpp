#include <iomanip>
#include <iostream>
#include <cmath>


using namespace std;
#include "strPaquetes.h"
#include "StrCamiones.h"
#include "funcionesAuxiliares.h"
#define  SOBREPASO_PESO false

void solucionCamiones(struct strPaquetes *arrPaquete, struct StrCamiones *arrCamiones,
        int cantCam, int cantPaq) {
    //cant opciones da la cantida de comobinaciones posibles 
    int cantOpciones = pow(cantCam, cantPaq); //combinacion
    int combinaciones[cantPaq]{}, combinacionOptima[cantPaq];
    int optimo = 999;

    for (int opcion = 0; opcion != cantOpciones; opcion++) {

        int pesoCam[cantPaq]{}; //se incicializa en cero que ya que puede que  no todos los camiones se llenen y esten en cero 
        cargaBase(opcion, combinaciones, cantPaq, cantCam);
        // se convierte a base (Cantidad de camiones =3) para que me indique el camion en que se encuentra
        //entonces si el camion si marca 0 ira al camion 1; si marca 1 ira al camion 2; si marca 2 ira al 3
        //y como esta en base 3 nunca marcara 3 ya que no existe un camion 4 (para este caso en particular)


        // AGREGO EL PESO A LOS CAMIONES
        for (int i = 0; i < cantPaq; i++) {
            int camionX = combinaciones[i]; //recordar que el camion 0 es el camion 1 y asi sucesivamnete
            pesoCam[camionX] += arrPaquete[i].peso;
        }
        bool pesoAdmitido = true; //en cada iteracion empiezo creyendo que no sobrepasaré el peso maximo hasta comprobarlo

        //Verificar que no excedan los pesos ninguno de los camiones
        //Si encuentra un camion que sobrepaso su peso descarta la alternatva y continua con la siguiente
        for (int i = 0; i < cantCam; i++)
            if (pesoCam[i] > arrCamiones[i].capacidad and pesoCam[i] == 0) { //pesoCam[i] == 0 se descarta la opcion tambien para la pregunta c)
                pesoAdmitido = SOBREPASO_PESO;
                break; //para que seguir probando si un camion ya sobrepaso el peso admitido  
            }
        //Ahora si el peso es admitido en cada camion evaluo si es "OPTIMO" 
        if (pesoAdmitido == true) {
            int max = 0, min = 999;
            for (int i = 0; i < cantCam; i++) {
                int dif = arrCamiones[i].capacidad - pesoCam[i];
                if (dif > max)max = dif;
                if (dif < min) min = dif;
            }
            //se le da el grado de optimicidad a la cominacion que se evaluo
            int optimoAux = max - min;
            if (optimoAux < optimo) {
                optimo = optimoAux; //se le asigna el mejor optimo leido
                //se guarda la mejor combinacion ya que se encontro uno que es mejor optimo
                for (int i = 0; i < cantPaq; i++) {
                    combinacionOptima[i] = combinaciones[i];
                }
            }
        }
    }
    cout << right<<"La opcion mas optima es : "<<endl;
    for (int i=0;i<cantPaq;i++)cout <<"Paquete" << i+1 <<" ";
    cout <<endl;
    for (int i=0;i<cantPaq;i++) cout <<"Camion" << combinacionOptima[i]+1 <<"  ";
    cout<<endl<<"Diferencia Maxima: " << optimo<<endl;
}

//void cargaBase(int num, int *arr, int cantPaq, int cantCam) {
//
//    for (int i = 0; num > 0; i++) {
//        arr[i] = num % cantCam;
//        num = num / cantCam;
//    }
//}

void cargaBase(int n, int *arr, int b, int a) {
    int re, j = 0;
    for (int i = 0; i < b; i++)arr[i] = 0;

    while (n > 0) {
        re = n % a;
        n /= a;
        arr[j] = re;
        j++;
    }

}