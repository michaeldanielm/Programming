/* 
 * Author: Michael Daniel Murillo López  
 * Corporación Universitaria Minuto de Dios - UNIMINUTO 
 * NRC:7273
 *
 */
/*
Programa para generar un arreglo lleno con elementos aleatorios

*/

#include <iostream> // biblioteca para manejo de streams
#include <stdlib.h> // funcion rand() y srand()
#include<time.h> // hora del sistema time(NULL)
#define MAX 0xFFFF;
using namespace std;
int main()
{
    srand(time(NULL));
    char otra='Y';
    int arraySize=0;
    int Array[100];
    for(int i=0;i<100;i++)Array[i]=MAX;
    while(otra=='Y'){
        cout<<"Ingrese el numero de elementos del arreglo(1-100): ";
        cin>>arraySize;
        if(arraySize>0){
            for(int i=0;i<arraySize;i++)
            {
                Array[i]=1+rand()%100;
            }
            cout<<"Los elementos el arreglo son: \n\n";
            for(int i=0;i<arraySize;i++)
            {
                cout<<Array[i]<<"-";
            }

        } else cout<<"Error, debe ser un entero positivo\n";

        cout<<"\n\nDesea realizar otra prueba? (Y/N): ";
        cin>>otra;
    }
    cout<<"\n\n";
    return 0;

}
