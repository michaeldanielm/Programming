/* 
 * File:   Lista(Apartamento)
 * Author: Michael Daniel Murillo López  
 * Corporación Universitaria Minuto de Dios - UNIMINUTO 
 * NRC:7273
 *
 */
#include <iostream> // liberia 
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;


template <typename T> struct Nodo //Nodos 
{
	T info;
	Nodo<T>* left;
	Nodo<T>* right;
};

struct Registro{
	int legajo;//numero de identificasion del usuaru
	int dni;//numero de identificasion de la Torre
	int nro;//numero de identificasion de los  Apartamento
	string nombre;//Nombre del usuario
};

void Agregar(Nodo<Registro>*& p, Registro x){// Metodo para agregar un Nodo

	Nodo<Registro>* nuevo = new Nodo<Registro>();
	nuevo->info = x;
	nuevo->left = NULL;
	nuevo->right = NULL;

	if (p == NULL){
		p = nuevo;
	}
	else if (x.legajo < p->info.legajo){
		Agregar(p->left, x);
	}
	else if (x.legajo > p->info.legajo){
		Agregar(p->right, x);
	}

	cout << "El archivo se ha agregado correctamente" << endl << endl << endl;
};

void Eliminar(Nodo<Registro>*& p, int l){  // Metodo para eliminar un Nodo

	bool found = false;
	Nodo<Registro>* actual = p;
	Nodo<Registro>* predecesor = NULL;

	if (actual == NULL){
		cout << "No hay archivo" << endl << endl << endl;
		return;
	}

	while (actual != NULL){
		if (actual->info.legajo == l){
			found = true;
			break;
		}
		else{
			predecesor = actual;
			if (l > actual->info.legajo){
				actual = actual->right;
			}
			else{
				actual = actual->left;
			}
		}
	}

	if (!found){
		cout << "El archivo no está en los registros" << endl << endl << endl;
		return;
	}

	// Case 1 : Usuario del apartamento
	if ((actual->left == NULL && actual->right != NULL) || (actual->left != NULL && actual->right == NULL)){
		if (actual->left == NULL && actual->right != NULL){
			if (predecesor->left == actual){
				predecesor->left = actual->right;
				delete actual;
				actual = NULL;
				cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;
			}
			else{
				predecesor->right = actual->right;
				delete actual;
				actual = NULL;
				cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;
			}
		}
		else{
			if (predecesor->left == actual){
				predecesor->left = actual->left;
				delete actual;
				actual = NULL;
				cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;
			}
			else{
				predecesor->right = actual->left;
				delete actual;
				actual = NULL;
				cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;

			}
		}
		return;
	}

	// CASE 2 sin Usuario encontrado (leaf)
	if (actual->left == NULL && actual->right == NULL){
		if (predecesor == NULL){
			delete actual;
			cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;
		}
		else{

			if (predecesor->left == actual){
				predecesor->left = NULL;
			}
			else{
				predecesor->right = NULL;
			}
			delete actual;
			cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;
			return;
		}
	}

	//CASE 3 dos Personas en la misma torre
	if (actual->left != NULL && actual->right != NULL){
		Nodo<Registro>* check = actual->right;

		if ((check->left == NULL) && (check->right == NULL)){
			actual = check;
			delete check;
			actual->right = NULL;
			cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;
		}
		else
		{
			if ((actual->right)->left != NULL){
				Nodo<Registro>* izqActual;
				Nodo<Registro>* izqActualPred;
				izqActualPred = actual->right;
				izqActual = (actual->right)->left;
				while (izqActual->left != NULL){
					izqActualPred = izqActual;
					izqActual = izqActual->left;
				}
				actual->info.legajo = izqActual->info.legajo;
				actual->info.dni = izqActual->info.dni;
				actual->info.nro = izqActual->info.nro;
				actual->info.nombre = izqActual->info.nombre;

				delete izqActual;
				izqActualPred->left = NULL;
				cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;
			}
			else{
				Nodo<Registro>* temp = actual->right;
				actual->info.legajo = temp->info.legajo;
				actual->info.dni = temp->info.dni;
				actual->info.nro = temp->info.nro;
				actual->info.nombre = temp->info.nombre;
				actual->right = temp->right;
				delete temp;
				cout << "El archivo se ha eliminado correctamente" << endl << endl << endl;

			}
		}
		return;
	}

};

void buscarImprimir(Nodo<Registro>* p, int l){//metodo para buscar la lista de los apartamentos
	bool found = false;
	Nodo<Registro>* actual = p;

	if (actual == NULL){
		cout << "El archivo no está en los registros" << endl << endl << endl;
		return;
	}

	while (actual != NULL){
		if (actual->info.legajo == l){
			found = true;
			break;
		}
		else{
			if (l > actual->info.legajo){
				actual = actual->right;
			}
			else{
				actual = actual->left;
			}
		}
	}

	if (!found){
		cout << "El archivo no está en los registros" << endl << endl << endl;
	}
	else{
		cout << "Numero de Identificacion " << actual->info.legajo << endl;
		cout << "Numero de Torre: " << actual->info.nro << endl;
		cout << "Numero de apartemento: " << actual->info.dni << endl;
		cout << "Nombre: " << actual->info.nombre << endl << endl << endl;
	}



}

int main() {//Menu 
	Nodo<Registro>* p = NULL;
	char r;
	Registro a;
	int legajo;
    system("Color 9F");
	do
	{
		
		cout << "-----------------------------------------------------------------" << endl;
		cout << "Nota solo letras en Minuscula " << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "Presiona (  a   )   para agregar un Apartamento" << endl;
		cout << "Presiona (  b   )   para buscar y imprimir la informacion del Apartamento" << endl;
		cout << "Presiona (  e   )   para eliminiar el usuario del Apartamento" << endl;
		cout << "Presiona (  s   )   para Salir" << endl << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cin >> r;
		switch (r){
		case 'a':
			system("Color 2F");
			cout << "Ingrese numero de Identificasion" << endl;
			cin >> a.legajo;
			cout << "Ingrese numero de torre" << endl;
			cin >> a.nro;
			cout << "Ingrese Apartamento" << endl;
			cin >> a.dni;
			cout << "Ingrese Nombre de Usuario" << endl;
			cin >> a.nombre;
			Agregar(p, a);
			break;
		case 'e':
	    	system("Color 4F");   
		    cout << "Ingrese numero de Documento" << endl;
			cin >> legajo;
			Eliminar(p, legajo);
			break;
		case 'b': 
		    system("Color 3F");  
		    cout << "Ingrese numero de Documento" << endl;
			cin >> legajo;
			buscarImprimir(p, legajo);
			system("cls");
			break;
		default:;
		}

	} while (r != 's');
system("cls");
	return 0;

}
