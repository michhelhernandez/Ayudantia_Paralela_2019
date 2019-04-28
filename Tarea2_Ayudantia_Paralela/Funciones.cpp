#include <iostream>
#include <math.h>
#define tam 100000

void Llenar_Random(int A[]) //Ingresa 100000 valores random a un arreglo de enteros.
{
    srand(time(NULL));
    for (int i=0;i<tam;i++)
        A[i]=1+rand() % (1000);  // Se almacena un numero aleatorio entre 1 y 1000.
}

void Mostrar_Arreglo(int A[]) //Muestra el arreglo.
{
    for(int i=0;i<tam;i++)
        std::cout<<"Elemento "<<i<<": "<<A[i]<<std::endl;
    
}

void Calcular_Sumatorias(int A[],int& cantidad_total,double& suma,double& suma_cuadrada) //Calcula la sumatoria, cantidad total y sumatoria al cuadrado de los numeros en el arreglo.
{
    for (int i=0;i<tam;i++)
    {
        cantidad_total++;
        suma=suma+A[i];
        suma_cuadrada=suma_cuadrada+(A[i]*A[i]);
    }
}

double Promedio(int cantidad,double sumatoria) //Calcula y retorna el promedio.
{
    double media=0;
    if (cantidad!=0)
        media=(sumatoria/cantidad);
    
    return media;
}

double Desviacion(int cant,double suma_cuadrada,double promedio) //Calcula y retorna la desviacion estandar poblacional.
{
    double desv=0;
    if(cant!=0)
        desv=sqrt( (suma_cuadrada/cant) - (promedio*promedio) ); //Se calcula la desviacion de forma "simplificada".
    
    return desv;
}

double Varianza(double desviacion) //Calcula y retorna la varianza.
{
    return (desviacion*desviacion);
}
