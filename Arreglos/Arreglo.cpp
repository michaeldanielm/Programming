/**
 *
 * @author Michael Daniel Murillo López
 * Corporación Universitaria Minuto de Dios - UNIMINUTO 
 * NRC:7273
 */
/*
Programa para generar un arreglo y pedir elementos
para rellenarlo
*/

#include <iostream> // biblioteca para manejo de streams
#include <stdlib.h> // funcion rand() y srand()
#include<time.h> // hora del sistema time(NULL)
using namespace std;
int main()
{
    char otra='Y';
    int arraySize=0;
    while(otra=='Y'){
        cout<<"\nIngrese el numero de elementos del arreglo: ";
        cin>>arraySize;
        if(arraySize>0){
            int myArray[arraySize];

            for(int i=0;i<arraySize;i++)
            {
                cout<<"\nInserte el elemento "<<i<<": ";
                cin>>myArray[i];
            } 
            
            cout<<"\nLos elementos del el arreglo: \n\n";
            for(int i=0;i<arraySize;i++)
            {
                cout<<myArray[i]<<"-";
            }
            for(int i=0;i<arraySize;i++)
            {
                cout<<"Inserte el elemento "<<i<<": ";
                cin>>myArray[i];
            }
            cout<<"Los elementos del el arreglo: \n\n";
            for(int i=0;i<arraySize;i++)
            {
                cout<<myArray[i]<<"-";
            }
            

        } else cout<<"Error, debe ser un entero positivo\n";
        
        cout<<"\n\nDesea realizar otra prueba? (Y/N): ";
        cin>>otra;
    }
    cout<<"\n\n";
    return 0;

}
