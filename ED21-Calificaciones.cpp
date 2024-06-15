//Fecha: jueves 13 de mayo de 2021
//Autor: Luis Pablo Gutiérrez Padilla
//Práctica No. 21
//Objetivo: Implementar una lista simplemente enlazada cerrada o circular

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

// TDA LSEA
struct alumno{
	//Datos
	char codigo[10];
	char nombre[30];
	char apellidoM[30];
	char apellidoP[30];
	int calificaciones[5];
	float promedio;
	//Direccion al siguiente nodo
	alumno *siguiente;
	alumno *anterior;
};

//Identificador o apuntador a mi lista
alumno *INICIO=NULL;

//Operaciones de mi TDA
void agregarNodo(void);
void menu(void); //muestra las opciones que vamos a tener en el programa
void consultarLista(void);
void buscarLista(void);
void filtrarLista(void);
void eliminarLista(void);

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
			    eliminarLista();
			   break; 
			case 4:
			   buscarLista();
			   break;
			case 5:
			   filtrarLista();
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
	    cout << "5. Filtrar los alumnos por promedio" << endl;
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
	//5. Agregar o insertar el nodo creado a la LSEC
	//caso a) lista vacia
	if (INICIO == NULL){
		INICIO = nuevo;
		nuevo->siguiente = INICIO;
	}//if
	
	//caso b) lista no vacía
	nuevo->siguiente = INICIO->siguiente;
	INICIO->siguiente = nuevo;
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
void buscarLista(void){
	//Declarar variable apuntador para recorrer la lista
	struct alumno *copia=INICIO;
	char codigoBuscar[10];
	
	if (copia == NULL){
		cout << "Lista de alumnos vacia" << endl;
		return;
	} //if
	
	//Solicitar el codigo de busqueda
	system("cls");
	cout << "Ingrese el codigo a consultar-->";
	cin >> codigoBuscar;
	
	//Lista con al menos un nodo
	do{
		if( strcmp(codigoBuscar, copia->codigo) == 0){  //Esa función compara 2 cadenas y regresa 0 si son iguales
	cout << "Calificaciones Registradas" << endl;
	cout << "===========================================" << endl;
	cout << "Codigo -->" << copia->codigo << endl;
	cout << "Nombre -->" << copia->nombre << endl;
	cout << "Apellido Paterno -->" << copia->apellidoP << endl;
	cout << "Apellido Materno -->" << copia->apellidoM << endl;
	cout << "Promedio -->" << copia->promedio << endl;
	for (int i=0; i<5; i++){
	   cout << "Calificacion" <<i+1 << "-->" << copia->calificaciones[i] << endl;
	   }//for
    cout << "===========================================" << endl;
    return;
	}//if
	
	//Ir al siguiente nodo
	copia = copia->siguiente;	
	}while (copia != INICIO);
	
	cout << codigoBuscar <<", codigo del alumno no localizado" << endl;

 return;	
}//buscarLista

//**********************************************************
void filtrarLista(void){
	//Declarar variable apuntador para recorrer la lista
	struct alumno *copia=INICIO;
	float promMin; 
	bool encontrar=false;  //bandera (permite comunicar una parte el codigo con otro)
	
	if (copia == NULL){
		cout << "Lista de alumnos vacia" << endl;
		return;
	} //if
	
	//Solicitar el p´romedio mínimo a mostrar
	system("cls");
	cout << "Ingrese el promedio minimo a buscar-->";
	cin >> promMin;
	
	//Lista con al menos un nodo
	do{
		if( copia->promedio >= promMin){  //Esa función compara 2 cadenas y regresa 0 si son iguales
	encontrar = true;
	cout << "Calificaciones Registradas" << endl;
	cout << "===========================================" << endl;
	cout << "Codigo -->" << copia->codigo << endl;
	cout << "Nombre -->" << copia->nombre << endl;
	cout << "Apellido Paterno -->" << copia->apellidoP << endl;
	cout << "Apellido Materno -->" << copia->apellidoM << endl;
	cout << "Promedio -->" << copia->promedio << endl;
	for (int i=0; i<5; i++){
	   cout << "Calificacion" <<i+1 << "-->" << copia->calificaciones[i] << endl;
	   }//for
    cout << "===========================================" << endl;
	}//if
	
	//Ir al siguiente nodo
	copia = copia->siguiente;	
	}while (copia != INICIO);
	
	if( ! encontrar){ //que si no hay encontrado entonces hace el if
		cout <<"No se tienen alumnos que cumplan con el promedio minimo de " << promMin << endl;
	}//if

 return;	
}//buscarLista

//**********************************************************
void eliminarLista(void){
	//Declarar variable apuntador para recorrer la lista
	struct alumno *borrar=INICIO;
	bool eliminado=false;  //bandera (permite comunicar una parte el codigo con otro)
	
	if (borrar == NULL){
		cout << "Lista de alumnos vacia" << endl;
		return;
	} //if
	
	//caso a) lista con un único nodo
	if (borrar == borrar->siguiente){
	cout << "Calificaciones Registradas" << endl;
	cout << "===========================================" << endl;
	cout << "Codigo -->" << borrar->codigo << endl;
	cout << "Nombre -->" << borrar->nombre << endl;
	cout << "Apellido Paterno -->" << borrar->apellidoP << endl;
	cout << "Apellido Materno -->" << borrar->apellidoM << endl;
	cout << "Promedio -->" << borrar->promedio << endl;
	for (int i=0; i<5; i++){
	   cout << "Calificacion" <<i+1 << "-->" << borrar->calificaciones[i] << endl;
	   }//for
	cout << "===========================================" << endl;
	
	//Preguntar si etá seguro
	
	//eliminar nodo
	free(borrar);
	INICIO = NULL;
	cout << "Registro eliminado" << endl;
	return;
	
	}//if
	
	//Caso b) lista con 2 o más nodos
	
	return;
}//eliminarLista





