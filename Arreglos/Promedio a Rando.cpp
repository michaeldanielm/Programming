/* 
 * Author: Michael Daniel Murillo López  
 * Corporación Universitaria Minuto de Dios - UNIMINUTO 
 * NRC:7273
 *
 */

/*
Programa para generar calificaciones aleatorias e
imprimir el promedio de los mismos, ademas de indicar
cuantas calificaciones estan por encima del proyecto
*/

#include <iostream> // biblioteca para manejo de streams
#include <stdlib.h> // funcion rand() y srand()
#include<time.h> // hora del sistema time(NULL)
using namespace std;

int main()
{
    srand(time(NULL));
    char otra='Y';
    int arraySize=0,sum=0,best=0;
    float prom;
    while(otra=='Y'){
        cout<<"Ingrese el numero de alumnos: ";
        cin>>arraySize;
        if(arraySize>0){
            int myArray[arraySize];

            for(int i=0;i<arraySize;i++)
            {
                myArray[i]=1+rand()%100;
                sum+=myArray[i];
            }

            cout<<"Las calificaciones son: \n\n";
            prom=float(sum)/float(arraySize);
            for(int i=0;i<arraySize;i++)
            {
                cout<<myArray[i]<<"-";
                if(myArray[i]>prom)best++;
            }
            cout<<"\n\n El promedio del arreglo es: "<<prom<<"\n";
            cout<<best<<" alumnos estan arriba del promedio";


        } else cout<<"\nError, debe ser un entero positivo\n";

        cout<<"\n\nDesea realizar otra prueba? (Y/N): ";
        cin>>otra;
        best=0;
        sum=0;
    }
    cout<<"\n\n";
    return 0;

}
