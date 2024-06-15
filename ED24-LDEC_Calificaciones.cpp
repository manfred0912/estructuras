//Fecha: jueves 27de mayo de 2021
//Autor: Dana Ramírez
//Práctica No. 24
//Objetivo: Implementar una lista doblemente enlazada cerrada o circular

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

// TDA LDEC
struct alumno{
	//Datos
	char codigo[10];
	char nombre[30];
	char apellidoM[30];
	char apellidoP[30];
	int calificaciones[5];
	float promedio;
	//Direccion al siguiente nodo
	alumno *siguiente; //apuntadores autoreferenciales
	alumno *anterior;
};

//Identificador o apuntador a mi lista
alumno *INICIO=NULL;

//Operaciones de mi TDA
void agregarNodo(void);
void eliminarLista(void);
void consultarLista(void);
void consultarListaR(void);
void buscarLista(void);

void menu(void); //muestra las opciones que vamos a tener en el programa

int main(void){
//declaracion de variables
	int operacion;
	
	do{
		menu();
		cout << "Selecciona la operacion a realizar -->" ;
		cin >> operacion;
		switch (operacion){
			case 1:
			   agregarNodo();
			   break;
			case 2:
			   consultarLista();
			   break;
			case 3:
			   // eliminarLista();
			   break; 
			case 4:
			  // buscarLista();
			   break;  
			case 5:
			   consultarListaR();
			   break;           
			case 0:
			    cout << "Saliendo del programa..." << endl;
			    break;
			default:
			    cout << "Operacion No valida para este TDA" << endl;
				break;	
		}//switch
		system("pause");
	}while ( operacion != 0);
	
	
	return(0);
}//main

//********************************************************
void menu(){
	
	 system("cls");
	  cout << "Registro de calificaciones de estudiantes" << endl;
	   cout << "===========================================" << endl;
	    cout << "1. Agregar las calificaciones de estudiantes" << endl;
	    cout << "2. Consultar las calificaciones registradas" << endl;
	    cout << "3. Eliminar las calificaciones de un estudiante" << endl;
	    cout << "4. Buscar los datos de un alumno por codigo" << endl;
	    cout << "5. Consultar las calificaciones registradas hacia atras" << endl;
	    cout << "---------------------------------------------------" << endl;
	    cout << "0. Salir del sistema de calificaciones" << endl;
	    cout << "===========================================" << endl;
	    return;
}//menu

//********************************************************
void agregarNodo(void){
		//1.Declarar apuntador
	alumno *nuevo, *recorrer= INICIO;
	
	//2.Reservar memoria
	nuevo = (alumno *) malloc (sizeof(alumno));
	
	//3.Validar apuntador
	if (nuevo == NULL){
		cout << "No hubo memoria disponible" << endl;
		return;
	}//if
	
	//4.Guardar datos en el nuevo nodo de la lista
	system("cls");
	cout << "Ingresa los datos del alumno" << endl;
	cout << "Codigo -->";
	cin >> nuevo->codigo;
	cout << "Nombre -->";
	cin >> nuevo->nombre;
	cout << "Apellido Paterno -->";
	cin >> nuevo->apellidoP;
	cout << "Apellido Materno -->";
	cin >> nuevo->apellidoM;
	cout << "Promedio -->";
	cin >> nuevo->promedio;
	for (int i=0; i<5; i++){
	   cout << "Calificacion" <<i+1 << "-->";
	    cin >> nuevo->calificaciones[i];
	}//for
	
	//==============================================================
	//5. Agregar o insertar el nodo creado a la LDEC
	//caso a) lista vacia
	if (INICIO == NULL){
		nuevo->siguiente = nuevo;
		nuevo->anterior = nuevo;
		INICIO = nuevo;
		cout << "Datos del alumno registrados"<< endl;
	    return;
	}//if
	
	//caso b) lista con un nodo
/*	if (INICIO->siguiente == INICIO){
	nuevo->siguiente = INICIO->siguiente; //DER
	INICIO->siguiente= nuevo;  //DER
	nuevo->anterior = INICIO;  //IZQ
	INICIO->anterior = nuevo;  //IZQ
	} else{
	*/ 
		nuevo->siguiente = INICIO->siguiente;  //DER
	    INICIO->siguiente->anterior= nuevo; //IZQ 
	    INICIO->siguiente= nuevo; //DER
	    nuevo->anterior = INICIO;  //IZQ
//	}//if-else
	
	cout << "Datos del alumno registrados"<< endl;
	
	return;
}//agregarNodo

//**********************************************************
void consultarLista(void){
	//Declarar variable apuntador para recorrer la lista
	struct alumno *copia=INICIO;
	
	if (copia == NULL){
		cout << "Lista de alumnos vacia" << endl;
		return;
	} //if
	
	//Lista con al menos un nodo
	system("cls");
	cout << "Calificaciones Registradas" << endl;
	cout << "===========================================" << endl;
	
	do{
	cout << "Codigo -->" << copia->codigo << endl;
	cout << "Nombre -->" << copia->nombre << endl;
	cout << "Apellido Paterno -->" << copia->apellidoP << endl;
	cout << "Apellido Materno -->" << copia->apellidoM << endl;
	cout << "Promedio -->" << copia->promedio << endl;
	for (int i=0; i<5; i++){
	   cout << "Calificacion" <<i+1 << "-->" << copia->calificaciones[i] << endl;
	   }//for
    cout << "===========================================" << endl;
	//Ir al siguiente nodo
	copia = copia->siguiente;	
	}while ( copia != INICIO);

 return;	
}//consultarLista

//**********************************************************
void consultarListaR(void){
	//Declarar variable apuntador para recorrer la lista
	struct alumno *copia=INICIO;
	
	if (copia == NULL){
		cout << "Lista de alumnos vacia" << endl;
		return;
	} //if
	
	//Lista con al menos un nodo
	system("cls");
	cout << "Calificaciones Registradas" << endl;
	cout << "===========================================" << endl;
	
	do{
	cout << "Codigo -->" << copia->codigo << endl;
	cout << "Nombre -->" << copia->nombre << endl;
	cout << "Apellido Paterno -->" << copia->apellidoP << endl;
	cout << "Apellido Materno -->" << copia->apellidoM << endl;
	cout << "Promedio -->" << copia->promedio << endl;
	for (int i=0; i<5; i++){
	   cout << "Calificacion" <<i+1 << "-->" << copia->calificaciones[i] << endl;
	   }//for
    cout << "===========================================" << endl;
	//Ir al siguiente nodo
	copia = copia->anterior;	
	}while ( copia != INICIO);

 return;	
}//consultarListaR




