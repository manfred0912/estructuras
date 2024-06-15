//Fecha: Jueves 13 de Mayo de 2021 
//Autor: José Javier Sánchez de la Campa
//Practica No. 21
//Objetivo: Implementar lista Simple Enlazada Cerrada o Circular 

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

//TDA
struct alumno{
	//Datos 
	char codigo[10];
	char nombre[30];
	char apellidoM[30];
	char apellidoP[30];
	int calificaciones[5];
	float promedio;
	//Direccion del Sig Nodo
	alumno *siguiente;
	alumno *anterior;
};

//Identificador o Apuntador de mi Lista

alumno *INICIO = NULL;

//Operaciones de mi TDA

void AgregarNodo(void);
void menu(void);
void consultarLSEC(void);
void buscarlist(void);
void filtrarlist(void);
void borrarlist(void);

int main (void){
	  int operacion;
	//Declarar Variables
    do {
    	menu();
    	cout<<"Selecciona la operacion a realizar --> ";
    	cin>>operacion;
    	
    	switch(operacion){
    		case 1: AgregarNodo(); break;
    		case 2: consultarLSEC(); break;
    		case 3: borrarlist(); break;
    		case 4: buscarlist(); break;
    		case 5: filtrarlist(); break;
    		case 0: cout<<"Saliendo del Programa..."<<endl; break;
    		default: cout<<"Operacion NO Valida...."<<endl; break;
		}//Switch
		system("PAUSE");
	}while(operacion != 0); 
	
return(0);	

}//main

//***************************************************
void AgregarNodo(void){
	//1 Declarar Apuntador 
	alumno *nuevo, *recorrer = INICIO;
	
	//2 Reservar Memoria 
    nuevo = (alumno *) malloc(sizeof(alumno));
    
    //3 Validar el Apuntador
    if (nuevo == NULL){
    	cout<<"No hay memoria suficiente para los datos de un nuevo alumno"<<endl;
    	return;
	}//if
	
	//4 Guardar Datos en Nuevo Nodo de la Lista 
	system("cls");
	cout<<"Ingresar los Datos del Alumno" <<endl;
	cout<<"Codigo --> ";
	cin>> nuevo->codigo;
	cout<<"Nombre --> ";
	cin>> nuevo->nombre;
	cout<<"Apellido Paterno --> ";
	cin>> nuevo->apellidoP;
	cout<<"Apellido Materno --> ";
	cin>> nuevo->apellidoM;
	cout<<"Promedio --> ";
	cin>> nuevo->promedio;
	for (int i=0; i<5; i++){
		cout<<"Calificacion " << i+1 << " --> ";
		cin >> nuevo->calificaciones[i];
	}//for 
	
	//=====================================================================================
	// 5) AGREGAR O INSERTAR EL NODO CREADO A LA LSEC
	// Caso a) Lista Vacia 
	if (INICIO == NULL){
		INICIO = nuevo;
		nuevo->siguiente = INICIO;
		cout<<"Datos del Alumno Registrado !!!" <<endl;
		return;
	}//if
	
	// Caso b) Lista No Vacia 
    nuevo->siguiente = INICIO->siguiente;
	INICIO->siguiente = nuevo;
	cout<<"Datos del Alumno Registrado !!!" <<endl;
	return;	
	
}//AgregarNodo
//***************************************************
void menu(void){
	system("cls");
	cout<<"      Registro de Calificacion de Estudiantes         " <<endl;
	cout<<"========================================================" <<endl;
	cout<<"1. Agregar Calificaciones de un Nuevo Estudiante "<<endl;
	cout<<"2. Consultar Calificaciones Registradas " <<endl;
    cout<<"3. Eliminar Calificaciones de un Estudiante " <<endl;
	cout<<"4. Buscar los Datos de un Estudiante por Codigo " <<endl;
	cout<<"5. Filtro de Calificaciones por Promedio " <<endl;
	cout<<"=========================================================" <<endl;
	cout<<"0. Salir del Sistema de Calificaciones " <<endl;
	return;	
}
//***************************************************
void consultarLSEC(void){
	//Declarar Variable 
	alumno *copia = INICIO;
	
	if (copia == NULL){
		cout<<"Lista Vacia " <<endl;
		return;
	}//if
	
	//Lista con al menos un nodo
	system("cls");
	cout<<"Calificaciones Registradas " <<endl;
	cout<<"=============================" <<endl;
	do{
		cout<<"Codigo --> " << copia->codigo <<endl;
		cout<<"Nombre --> " << copia->nombre <<endl;
		cout<<"Apellido Paterno --> " << copia->apellidoP <<endl;
		cout<<"Apellido Materno --> " << copia->apellidoM <<endl;
		cout<<"Promedio --> " << copia->promedio <<endl;
		for (int i=0; i<5; i++){
			cout<<"Calificacion " << i+1 << " --> " << copia->calificaciones[i] <<endl;
		}//for 
		//Ir al Sig Nodo
		
		copia = copia->siguiente;	
	cout<<"=============================" <<endl;	
	}while( copia != INICIO );
	
	return;
}
//***************************************************
void buscarlist(void){
  //Declarar Variable 
	alumno *copia = INICIO;
	char codigoBuscar[10];
	
	if (copia == NULL){
		cout<<"Lista Vacia " <<endl;
		return;
	}//if
	
	//Solicitar el Codigo del Alumno a Buscar
	system("cls");
	cout<<"Codigo del Alumno --> ";
	cin>>codigoBuscar;
	//Lista con al menos un nodo
	do{
		if ( strcmp(codigoBuscar,copia->codigo ) == 0) {
			cout<<"Calificaciones Registradas " <<endl;
	    	cout<<"=============================" <<endl;
			cout<<"Codigo --> " << copia->codigo <<endl;
			cout<<"Nombre --> " << copia->nombre <<endl;
			cout<<"Apellido Paterno --> " << copia->apellidoP <<endl;
			cout<<"Apellido Materno --> " << copia->apellidoM <<endl;
			cout<<"Promedio --> " << copia->promedio <<endl;
			for (int i=0; i<5; i++){
				cout<<"Calificacion " << i+1 << " --> " << copia->calificaciones[i] <<endl;
			} 
			//Ir al Sig Nodo
	}
		copia = copia->siguiente;	
	cout<<"=============================" <<endl;	
	}while( copia != INICIO );
	
	cout << codigoBuscar << " Codigo del Alumno NO localizado !!! " <<endl; 
	
	return;	
}
//***************************************************
void filtrarlist(void){
	//Declarar Variable 
	alumno *copia = INICIO;
    float promMin;
    bool encontrar = false;
	
	if (copia == NULL){
		cout<<"Lista Vacia " <<endl;
		return;
	}//if
	
	//Solicitar el Promedio Minimo a Mostrar
	system("cls");
	cout<<"Promedio Minimo a Mostrar --> ";
	cin>>promMin;
	//Lista con al menos un nodo
	do{
		if ( copia->promedio >= promMin ) {
			encontrar = true;
			cout<<"Calificaciones Registradas " <<endl;
	    	cout<<"=============================" <<endl;
			cout<<"Codigo --> " << copia->codigo <<endl;
			cout<<"Nombre --> " << copia->nombre <<endl;
			cout<<"Apellido Paterno --> " << copia->apellidoP <<endl;
			cout<<"Apellido Materno --> " << copia->apellidoM <<endl;
			cout<<"Promedio --> " << copia->promedio <<endl;
			for (int i=0; i<5; i++){
				cout<<"Calificacion " << i+1 << " --> " << copia->calificaciones[i] <<endl;
			}//for 
			//Ir al Sig Nodo
	}
		copia = copia->siguiente;	
	cout<<"=============================" <<endl;	
	}while( copia != INICIO );
	
	if (! encontrar ){
	   	cout << " Promedio no Existente !!! "<< promMin <<endl; 	
	}
	return;	
}
//***************************************************
void borrarlist(void){
	//Declarar Variable 
	alumno *borrar = INICIO;
    char respuesta;
    char SiNo;
	
	//a) Lista Vacia
	if (borrar == NULL){
		cout<<"Lista Vacia " <<endl;
		return;
	}//if
	
			//Caso b) Lista con un unico nodo 
	        if (borrar == borrar->siguiente){
			cout<<"Calificaciones Registradas " <<endl;
	    	cout<<"=============================" <<endl;
			cout<<"Codigo --> " << borrar->codigo <<endl;
			cout<<"Nombre --> " << borrar->nombre <<endl;
			cout<<"Apellido Paterno --> " << borrar->apellidoP <<endl;
			cout<<"Apellido Materno --> " << borrar->apellidoM <<endl;
			cout<<"Promedio --> " << borrar->promedio <<endl;
			for (int i=0; i<5; i++){
				cout<<"Calificacion " << i+1 << " --> " << borrar->calificaciones[i] <<endl;
			}//for 
			cout<<"=============================" <<endl;
			
			//Pregunto 
			cout<<"========================================" <<endl;
			cout<<"Estas seguro de Borrar el Registro del Primer Estudiante (S/s) --> ";
			cin>>respuesta;
	
	   		if(respuesta != 'S' && respuesta != 's'){
			cout<<"Registro No Eliminado" <<endl;
			return;
			}
			
			//Eliminar Nodo
			free(borrar);
			INICIO = NULL;
			cout<<"Registro Eliminado !!!" <<endl;
			return;
		}
		
		// Caso c) Lista con mas de un Nodo
		// 1) Mostrar los datoa a borrar
		do{
		cout<<" es este el registro que desea eliminar? (S/s) " <<endl;
		cout<<"==========================="<<endl;
		cout<<"Codigo --> " << borrar->codigo <<endl;
		cout<<"Nombre --> " << borrar->nombre <<endl;
		cout<<"Apellido Paterno --> " << borrar->apellidoP <<endl;
		cout<<"Apellido Materno --> " << borrar->apellidoM <<endl;
		cout<<"Promedio --> " << borrar->promedio <<endl;
		for (int i=0; i<5; i++){
			cout<<"Calificacion " << i+1 << " --> " << borrar->calificaciones[i] <<endl;
		}//for 
		//Ir al Sig Nodo
		
		    // 2) Preguntar Si lo quiere borrar
			cout<<"========================================" <<endl;
			cout<<"Estas seguro de Borrar el Registro del Primer Estudiante (S/s) --> ";
			cin>>respuesta;
	
	   		if(respuesta != 'S' && respuesta != 's'){
		     //Mover al inicio un nodo antes del que quiero borrar
		     while ( INICIO->siguiente != borrar ){
		     	INICIO = INICIO->siguiente;
			 }
		     //Procedo a eliminar 
		     INICIO->siguiente = borrar->siguiente;
		     free(borrar);
		    cout<<" Registro Borrado " <<endl;
			return;
			}
			
		// 3) Ir al siguiente nodo
	    cout<<"=============================" <<endl;	
	    }while( borrar != INICIO );
	    
		cout<<" Registro No Borrado " <<endl;
	    return;
	
}
