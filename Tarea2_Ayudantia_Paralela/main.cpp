/* 
 * File:   main.cpp
 * Author: Michel Hernández
 */
#include <iostream>
#include "Cabecera.h"
#define tam 100000

using namespace std;

int main(int argc, char** argv) {
    int A[tam], cantidad_total=0; 
    double suma_total=0, suma_cuadrada=0, prom, desviacion;
    Llenar_Random(A);
    //Mostrar_Arreglo(A);
    Calcular_Sumatorias(A,cantidad_total,suma_total,suma_cuadrada);
    prom=Promedio(cantidad_total,suma_total);
    desviacion=Desviacion(cantidad_total,suma_cuadrada,prom);
    
    cout<<"Promedio de los valores del arreglo: "<<prom<<endl;
    cout<<"Varianza de los valores del arreglo: "<<Varianza(desviacion)<<endl;
    cout<<"Desviacion estandar de los valores del arreglo: "<<desviacion<<endl;
    
    return 0;
}

