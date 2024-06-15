// 20-05-21. 

// Autora: Isabel Franco García.

// Tipos de datos abstractos.

//IDA LSEC

#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;


struct alumno {  //136 bytes
	//Datos
	char codigo[10];
	char nombre[30];
	char apellidoM[30];
	char apellidoP[30];
	int calificaciones[5];
	float promedio;
	//Dirección del siguiente nodo
	alumno *siguiente;
	alomno *anterior;
};

//Identificador o Apuntador de mi lista

alumno *INICIO=NULL;
alumno *FIN=NULL;
//funciones

void agregarInicioLista(void);


//Operaciones de mi TDA




int main(){
	int operacion, i;
	
	do {
		menu();
		
		cout << "Selecciona la operacion a realizar --> ";
		cin >> operacion;
		switch (operacion){
			case 1:
				agregarInicioLista();
			break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
			
				break;
			case 5:
				
				break;
			case 0: 
			cout << "Saliendo del programa..."<<endl;
				break;
			default:
				cout << "Operacion no valida para este TDA unu" << endl;
		}
		
	}while ( operacion !=0 );
	
return (0);
	
}

void agregarInicioLista(void){
	
	void agregarNodo(void){
	
	//1) Declarar Apuntador
	alumno *nuevo, *recorrer;
	
	//2) Reservar apuntador
	nuevo = (alumno *)malloc (sizeof (alumno));
	
	//3) Validar apuntador
	
	
	if (nuevo == NULL){
		
		cout << "No hay memoria suficiente para los datos de un nuevo alumno" << endl;
		return;
	}
	
	//4) Guardar datos en el nuevo nodo de la lista
	system("cls");

	cout << "Ingresa los datos del nuevo alumno" << endl;
	cout << "Código -->";
	cin >> nuevo->codigo;
	cout << "Nombre" << endl;
	cin >> nuevo->nombre;
	cout << "Apellido Paterno" << endl;
	cin >> nuevo->apellidoP;
	cout << "Apellido Materno" << endl;
	cin >> nuevo->apellidoM;
	cout << "Promedio" << endl;
	cin >> nuevo->promedio;
	
	for (int i=0; i<5; i++){
		cout << "Calificacion " << i+1 << "--> ";
		cin >> nuevo -> calificaciones [i];
	} //for
	
//5) agregar o insertar nodo
//caso a) Lista vacia
		if (INICIO ==NULL){
	nuevo->siguiente = NULL;
	nuevo->anterior =NULL;
	INICIO = nuevo;
	FIN =  nuevo;

cout<<"Datos del alumno registrados"<<endl;
return;
}//if

//caso b) lista no vacía

	nuevo->siguiente=INICIO->siguiente;
	INICIO->siguiente=nuevo;
	
	
}//agregar nodo
	
}//iniciolista

void menu(){
	system("cls");
	cout << "Registro de calificaciones de estudiantes" <<endl;
	cout <<"==============================================================="<<endl;
	cout <<"1. Agregar las calificaciones de un nuevo estudiante al inicio" <<endl;
	cout <<"2. Consultar las calificaciones registradas" <<endl;
	cout <<"3. Eliminar las calificaciones de un estudiante" <<endl;
	cout <<"4. Buscar los datos de un alumno por codigo"<<endl;
	cout <<"5. Filtrar los alumnos por promedio."<<endl;
	cout <<"==============================================================="<<endl;
	cout <<"0. Salir del sistema de calificaciones"<<endl;
	return;
}//menu




