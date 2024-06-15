/* 
fecha: 5 de junio de 2021
autor: Luis Pablo Gutiérrez
practica: # 25
objetivo: implementar una pila con 4 operaciones
*/
#include<iostream>
#include<cstdlib>
using namespace std;

// TDA LIFO
struct alumnos {  // 136 bytes
	// Datos
	char codigo[10];
	char nombre[30];
	char apellidoM[30];
	char apellidoP[30];
	int calificaciones[5];
	float promedio;
	// dirección del siguiente nodo
	alumnos *siguiente;
};

// identificador o apuntador de mi lista
alumnos *CIMA=NULL;

// operaciones de mi TDA
void menu(void);
void AgregarCimaPila(void);
void EliminarCimaPila(void);
void ConsultarPila(void);
void ConsultarCimaPila(void);

int main(){

	// declaracion de variables
	int operacion;
	do {
		menu();
		cout<< "Ingresa la operación a realizar --> ";
		cin>> operacion;
		switch (operacion){
			case 1:
				AgregarCimaPila();
				break;
			case 2:
				EliminarCimaPila();
				break;
			case 3: 
				ConsultarPila();
				break;
			case 4: 
				ConsultarCimaPila();
				break;
			case 0: 
				cout<< "Saliendo del programa..."<<endl;
				break;
			default:
				cout<< "Operacion no valida para este TDA!!!"<<endl;
				break;
			} // switch
		system("pause");
	} while (operacion != 0);
	
	return(0);
}

void menu(){
	system("cls");
	cout << "Registro de calificaciones de estudiantes" <<endl;
	cout<<"================================================="<<endl;
	cout<<"1. Agregar las calificaciones de un nuevo estudiante"<<endl;
	cout<<"2. Eliminar las calificaciones del ultimo estudiante registrado"<<endl;
	cout<<"3. Consultar la información de los estudiantes registrados"<<endl;
	cout<<"4. Consultar la información del ultimo estudiante registrado"<<endl;
	cout<<"================================================="<<endl;
	cout<<"0. Salir del sistema de calificaciones"<<endl;
	cout<<"================================================="<<endl;
	return;
} // menu

void AgregarCimaPila(void){ // "PUSH"
	// 1) declarar apuntador
	alumnos *nuevo;
	
	// 2) reservar apuntador
	nuevo = (alumnos *) malloc(sizeof(alumnos)); 
	
	// 3) validar apuntador
	if (nuevo == NULL){
		cout<<"No hay memoria suficiente para los datos de un nuevo alumno"<<endl;
		return;
	} // if
	
	// 4) guardar datos en el nuevo nodo de la pila
	cout<<"Ingresa los datos del alumno"<<endl;
	cout<<"Codigo -->";
	cin>> nuevo->codigo;
	cout<< "Nombre --> ";
	cin>> nuevo->nombre;
	cout<<"Apellido paterno --> ";
	cin>> nuevo->apellidoP;
	cout<<"Apellido materno --> ";
	cin>> nuevo->apellidoM;
	cout<<"Promedio --> ";
	cin>> nuevo->promedio;
	for (int i=0; i<5; i++){
		cout<<"Calificacion "<<i+1<<" --> ";
		cin>> nuevo->calificaciones[i];
	} // for
	
  // AGREGAR O INSERTAR EL NODO CREADO A LA LIFO
	// 5) Actualizar direccion de siguiente en el nuevo nodo
	// caso a) la Pila esta vacia
	if (CIMA == NULL){
		nuevo->siguiente = NULL;
		CIMA = nuevo;
	} else
		// caso b) la Pila no esta vacia
	{ 
		nuevo->siguiente = CIMA;
		CIMA  = nuevo;
	} // if-else
	
	return;	
} // AgregarCimaPila ("PUSH")

void EliminarCimaPila(void){ // "PULL"
	// Declarar variable apuntador 
	alumnos *borrar=CIMA;
	char respuesta;
	// Caso a) Pila vacia
	if (borrar == NULL){
		cout<< "No hay informacion en esta lista, por lo tanto no hay nada que eliminar"<<endl;
		return;
	} // if
	// Lista con al menos un nodo
	// Mostrar la información del primer nodo que se va a borrar
	system("cls");
	cout<< "Informacion que se va a borrar"<<endl;
	cout<<"==========================="<<endl;
		cout<<"Codigo -->" << borrar->codigo <<endl;
		cout<< "Nombre --> " << borrar->nombre <<endl;
		cout<<"Apellido paterno --> " << borrar->apellidoP <<endl;
		cout<<"Apellido materno --> " << borrar->apellidoM <<endl;
		cout<<"Promedio --> " << borrar->promedio <<endl;
		for (int i=0; i<5; i++){
			cout<<"Calificacion "<<i+1<<" --> " << borrar->calificaciones[i] <<endl;
		} // for
		cout<<"============================="<<endl;
		cout<<"Estas seguro de borrar esta informacion? (S/s) -->";
		cin>>respuesta;
		if(respuesta != 's' && respuesta != 'S'){
			cout<<"Registro NO eliminado";
			return;
		} // if
		
		// Procedemos a borrarlo
		// Caso b) Lista con un solo nodo
		if(borrar->siguiente == NULL){
			free(borrar);
			CIMA = NULL;
			cout<<"Registro eliminado"<<endl;
			return;
		} // if 
		
	// Caso c) Lista con 2 o mas nodos
	CIMA = CIMA->siguiente;
	free(borrar);
	cout<<"Registro eliminado"<<endl;
	return;	
} // EliminarCimaPila ("PULL")

void ConsultarPila(void){ // "SHOW"
	// Declarar variable apuntador para recorrer la Pila
	struct alumnos *copia=CIMA;
	
	if (copia == NULL){
		cout<< "Pila de alumnos vacia"<<endl;
		return;
	} // if
	// Pila con al menos un nodo
	system("cls");
	cout<< "Calificaciones registradas"<<endl;
	cout<<"==========================="<<endl;
	do {
		cout<<"Codigo -->" << copia->codigo <<endl;
		cout<< "Nombre --> " << copia->nombre <<endl;
		cout<<"Apellido paterno --> " << copia->apellidoP <<endl;
		cout<<"Apellido materno --> " << copia->apellidoM <<endl;
		cout<<"Promedio --> " << copia->promedio <<endl;
		for (int i=0; i<5; i++){
			cout<<"Calificacion "<<i+1<<" --> " << copia->calificaciones[i] <<endl;
		} // for
		cout<<"==========================="<<endl;
		// ir al siguiente nodo
		copia = copia->siguiente;
	} while (copia != NULL);
	return;	
} // ConsultarPila ("SHOW")

void ConsultarCimaPila(void){ // "TOP"
	if(CIMA == NULL){
		cout<< "Pila de alumnos vacia"<<endl;
		return;
	}
		// Pila con al menos un nodo
	system("cls");
	cout<< "Calificacion del ultimo estudiante registrado"<<endl;
	cout<<"==========================="<<endl;
		cout<<"Codigo -->" << CIMA->codigo <<endl;
		cout<< "Nombre --> " << CIMA->nombre <<endl;
		cout<<"Apellido paterno --> " << CIMA->apellidoP <<endl;
		cout<<"Apellido materno --> " << CIMA->apellidoM <<endl;
		cout<<"Promedio --> " << CIMA->promedio <<endl;
		for (int i=0; i<5; i++){
			cout<<"Calificacion "<<i+1<<" --> " << CIMA->calificaciones[i] <<endl;
		} // for
		cout<<"==========================="<<endl;
	return;
} // ConsultarCimaPila ("TOP")
