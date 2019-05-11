#ifndef CABECERA_H
#define CABECERA_H

void Llenar_Random(int[]); //Ingresa 100000 valores random a un arreglo de enteros.

void Mostrar_Arreglo(int[]); //Muestra el arreglo.

void Calcular_Sumatorias(int[], int&, double&, double&); //Calcula la sumatoria, cantidad total y sumatoria al cuadrado de los numeros en el arreglo.

double Promedio(int, double); //Calcula y retorna el promedio.

double Desviacion(int, double, double); //Calcula y retorna la desviacion estandar poblacional.

double Varianza(double); //Calcula y retorna la varianza.

//int* Crear_vector(int desde, int hasta, int* original); //Crea a partir de un vector original un subvector.
int* Crear_vector(int, int, int*); //Crea a partir de un vector original un subvector.



#endif /* CABECERA_H */

