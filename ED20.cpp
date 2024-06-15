/* 
fecha: martes 4 da mayo de 2021
autor: Luis Pablo
practica: # 20
objetivo: implementar lista simplemente enlazada abierta
*/
#include<iostream>
#include<cstdlib>
using namespace std;

// TDA LSEA
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
alumnos *INICIO=NULL;

// operaciones de mi TDA
void AgregarInicioLista(void);
void menu(void);
void ConsultarLista(void);
void EliminarInicioLista(void);
void AgregarFinalLista(void);
void FiltrarListaPromedio(void);
void EliminarFinalLista(void);

int main(){

	// declaracion de variables
	int operacion;
	do {
		menu();
		cout<< "Ingresa la operación a realizar --> ";
		cin>> operacion;
		switch (operacion){
			case 1:
				AgregarInicioLista();
				break;
			case 2:
				ConsultarLista();
				break;
			case 3: 
				EliminarInicioLista();
				break;
			case 4: 
				AgregarFinalLista();
				break;
			case 5: 
				FiltrarListaPromedio();
				break;
			case 6:	
				EliminarFinalLista();
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
	cout<<"1. Agregar las calificaciones de un nuevo estudiante al inicio"<<endl;
	cout<<"2. Consultar las calificaciones registradas"<<endl;
	cout<<"3. Eliminar las calificaciones del primer estudiante en la lista"<<endl;
	cout<<"4. Agregar las calificaciones de un nuevo estudiante al final"<<endl;
	cout<<"5. Filtrar el promedio de los alumnos"<<endl;
	cout<<"6. Eliminar la información del ultimo alumno registrado en la lista"<<endl;
	cout<<"================================================="<<endl;
	cout<<"0. Salir del sistema de calificaciones"<<endl;
	cout<<"================================================="<<endl;
	return;
} // menu

void AgregarInicioLista(void){
	// 1) declarar apuntador
	alumnos *nuevo;
	
	// 2) reservar apuntador
	nuevo = (alumnos *) malloc(sizeof(alumnos)); 
	
	// 3) validar apuntador
	if (nuevo == NULL){
		cout<<"No hay memoria suficiente para los datos de un nuevo alumno"<<endl;
		return;
	} // if
	
	// 4) guardar datos en el nuevo nodo de la lista
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
	
  // AGREGAR O INSERTAR EL NODO CREADO A LA lSEA
	// 5) Actualizar direccion de siguiente en el nuevo nodo
	// caso a) la lista esta vacia
	if (INICIO == NULL){
		nuevo->siguiente = NULL;
		INICIO = nuevo;
	} else
		// caso b) la lista no esta vacia
	{ 
		nuevo->siguiente = INICIO;
		INICIO  = nuevo;
	} // if-else
	
	return;
} // AgregarInicioLista

void ConsultarLista(void) {
	// Declarar variable apuntador para recorrer la lista
	struct alumnos *copia=INICIO;
	
	if (copia == NULL){
		cout<< "Lista de alumnos vacia"<<endl;
		return;
	} // if
	// Lista con al menos un nodo
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
} // ConsultarLista

void EliminarInicioLista(void){
  // Declarar variable apuntador 
	alumnos *borrar=INICIO;
	char respuesta;
	// Caso a) Lista vacia
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
			INICIO = NULL;
			cout<<"Registro eliminado"<<endl;
			return;
		} // if 
		
	// Caso c) Lista con 2 o mas nodos
	INICIO = INICIO->siguiente;
	free(borrar);
	cout<<"Registro eliminado"<<endl;
	return;	
	
} // EliminarInicioLista

void AgregarFinalLista(void){
	// 1) declarar apuntador
	alumnos *nuevo, *recorrer=INICIO;
	
	// 2) reservar apuntador
	nuevo = (alumnos *) malloc(sizeof(alumnos)); 
	
	// 3) validar apuntador
	if (nuevo == NULL){
		cout<<"No hay memoria suficiente para los datos de un nuevo alumno"<<endl;
		return;
	} // if
	
	// 4) guardar datos en el nuevo nodo de la lista
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
	// 5) agregar el nodo al final de la lista
	if(INICIO == NULL){ // a) lista vacia
		nuevo->siguiente = NULL;
		INICIO = nuevo;
		cout<<"Datos del alumno registrados"<<endl;
	} else {  // b) caso lista con uno o mas nodos
		while (recorrer->siguiente != NULL){
			recorrer = recorrer->siguiente;
		} // while -- para posicionarme en el ultimo nodo de la lista
		recorrer->siguiente = nuevo;
	}
return;	
} // AgregarFinalLista

void FiltrarListaPromedio(void){
	// Declarar variable apuntador para recorrer la lista
	struct alumnos *copia=INICIO;
	float prom;
	
	if (copia == NULL){
		cout<< "Lista de alumnos vacia"<<endl;
		return;
	} // if
	cout<<"Ingresa el promedio minimo para filtrare los alumnos --> ";
	cin>>prom;
	// Lista con al menos un nodo
	system("cls");
	cout<< "Calificaciones registradas"<<endl;
	cout<<"==========================="<<endl;
	do {
		// desplegar información
		if(copia->promedio >= prom){
			cout<<"Codigo -->" << copia->codigo <<endl;
			cout<< "Nombre --> " << copia->nombre <<endl;
			cout<<"Apellido paterno --> " << copia->apellidoP <<endl;
			cout<<"Apellido materno --> " << copia->apellidoM <<endl;
			cout<<"Promedio --> " << copia->promedio <<endl;
			for (int i=0; i<5; i++){
				cout<<"Calificacion "<<i+1<<" --> " << copia->calificaciones[i] <<endl;
			} // for
			cout<<"==========================="<<endl;
		} // if
		// ir al siguiente nodo
		copia = copia->siguiente;
	} while (copia != NULL);
	return;	
} // FiltrarListaPromedio

void EliminarFinalLista(void){
// Declarar variable apuntador para recorrer la lista
	struct alumnos *borrar=INICIO, *anterior;
	char respuesta;
	// Caso a) Lista vacia
	if (borrar == NULL){
		cout<< "No hay informacion en esta lista, por lo tanto no hay nada que eliminar"<<endl;
		return;
	} // if
	// Caso b) Lista con un nodo
	if (borrar->siguiente == NULL){
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
				free(borrar);
				INICIO = NULL;
				cout<<"Registro eliminado"<<endl;
				return; 
  } // if un solo nodo 
	
	// Caso c) Lista con 2 o mas nodos
	anterior = INICIO;
	borrar = INICIO->siguiente;
	// Posicionarme en el ultimo y penultimo nodo de la lista
	while (borrar->siguiente != NULL){
		borrar = borrar->siguiente;
		anterior = anterior->siguiente;
	} // while
	
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
				free(borrar);
				anterior->siguiente = NULL;
				cout<<"Registro eliminado"<<endl;
				return; 
	
	
} // EliminarFinalLista

