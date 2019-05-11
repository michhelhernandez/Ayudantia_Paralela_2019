/* 
 * File:   main.cpp
 * Author: Michel Hernández
 */
#include <iostream>
#include "Cabecera.h"
#define tam 100000
#include <mpi.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    int A[tam], cantidad_total=0; 
    double suma=0, suma_total=0, suma_cuadrada=0, suma_cuadrada_total=0, prom, desviacion;
    
    int rango; //rango del proceso
    int p; //total de procesos
    int origen; //rango del que envia
    int destino=0; //rango del que recibe
    int tag=0; //etiqueta
    int largo_subvec;
    int* sub_vec = NULL;
    Llenar_Random(A); //se llena el arreglo con 100.000 números al azar
    //Mostrar_Arreglo(A);
    
    MPI_Status estado; //devuelve estado al recibir
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rango); //se conoce el rango del proceso 
    MPI_Comm_size(MPI_COMM_WORLD, &p); //se conoce el número total de procesos que se ejecutan 

    largo_subvec=tam/p;
    if (rango!=0) 
    {
        for (int i=1;i<p;i++) 
        {
            if(i==(p-1) && ((i*largo_subvec)+largo_subvec)<tam)
            {
                //crea un subvector con el ultimo segmento del vector original
                sub_vec=Crear_vector(i*largo_subvec,tam,A); 
            }            
            else
            {
                //crea un subvector con lo que está entre el primer (sin inlcluir) y ultimo segmento del vector original
                sub_vec=Crear_vector(i*largo_subvec,(i*largo_subvec)+largo_subvec,A);
            }
            
            cantidad_total=0; suma=0; suma_cuadrada=0;//se inicializa la cantidad y sumas en cero
            Calcular_Sumatorias(sub_vec,cantidad_total,suma,suma_cuadrada);//calcula cantidad y sumatorias en subvector
            MPI_Send(&suma, 1, MPI_DOUBLE, destino, tag, MPI_COMM_WORLD);//envia suma del subvector al rango 0
            MPI_Send(&suma_cuadrada, 1, MPI_DOUBLE, destino, tag, MPI_COMM_WORLD);//envia suma cuadrada del subvector al rango 0
            free(sub_vec);
        }
        
        cantidad_total=0; suma=0; suma_cuadrada=0;//se inicializa la cantidad y sumas en cero
        sub_vec=Crear_vector(0,largo_subvec,A);//crea un subvector con el primer segmento del vector original
        Calcular_Sumatorias(sub_vec,cantidad_total,suma,suma_cuadrada);//calcula cantidad y sumatorias en subvector
        MPI_Send(&suma, 1, MPI_DOUBLE, destino, tag, MPI_COMM_WORLD);//envia suma del subvector al rango 0
        MPI_Send(&suma_cuadrada, 1, MPI_DOUBLE, destino, tag, MPI_COMM_WORLD);//envia suma cuadrada del subvector al rango 0
        free(sub_vec);
    }
    
    else //rango==0
    {
        for (origen=1;origen<p;origen++) 
        {
            MPI_Recv(&suma, 1, MPI_DOUBLE, origen,tag, MPI_COMM_WORLD, &estado);//recibe la suma del rango correspondiente
            MPI_Recv(&suma_cuadrada, 1, MPI_DOUBLE, origen,tag, MPI_COMM_WORLD, &estado);//recibe la suma cuadrada del rango correspondiente
            suma_total=suma_total+suma;
            suma_cuadrada_total=suma_cuadrada_total+suma_cuadrada;
        }
    }
    MPI_Finalize(); //finaliza MPI
    prom=Promedio(tam,suma_total);
    desviacion=Desviacion(tam,suma_cuadrada_total,prom);
    
    cout<<"Promedio de los valores del arreglo: "<<prom<<endl;
    cout<<"Varianza de los valores del arreglo: "<<Varianza(desviacion)<<endl;
    cout<<"Desviacion estandar de los valores del arreglo: "<<desviacion<<endl;
    
    
    return 0;
}
