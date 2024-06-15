/* 
fecha: 11 de junio de 2021
autor: Luis Pablo Gutiérrez Padilla
			 Ayax Alexis Covarrubias Fermín
Proyecto final: LSEC Cultivos  
objetivo: Sistema de control de cultivos.
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<locale.h>
#include<windows.h> 
#include<stdio.h>
#include<time.h>
#include<vector>
#include<conio.h>
using namespace std;



// TDA LSEC
struct cultivos {  // 136 bytes
	// Datos
	char ID_cultivo[5];
	char tipoDeCultivo[10];
	char tipoDeFumigacion[30];
	char fechaFumigacion[10];
	char tipoDeAbono[30];
	char fechaAbono[10];
	char fechaSiembra[10];
	char fechaCosecha[10];
	char propietario[20];
	float totalCosecha;
	char lugar[20];
	// dirección del siguiente nodo
	cultivos *siguiente;
};

// identificador o apuntador de mi lista
cultivos *INICIO=NULL;
 
// funciones
void menu(void);
void logo(void);
void AgregarRegistroCultivos(void);
void EliminarRegistroCultivos(void);
void ConsultarLista(void);
void FiltrarPorCosecha(void);
void BuscarPorID(void);
void fecha(void);


int main (void){
	  setlocale(LC_ALL, "spanish"); // función para que los acentos se vean en la terminal
	  system ("color 0F");
		
		//Declarar Variables
		int operacion;
		
		
		
		// presentacion del programa y logo del programa
    do {
    	menu();
    	cout<<"Selecciona la operación a realizar --> ";
    	cin>>operacion;
    	
    	switch(operacion){
    		case 1: AgregarRegistroCultivos(); break;
    		case 2: EliminarRegistroCultivos(); break;
    		case 3: ConsultarLista(); break;
    		case 4: FiltrarPorCosecha(); break;
    		case 5: BuscarPorID(); break;
    		case 0: cout<<"Presione cualquier tecla para confirmar la salida del programa"<<endl;
				getch();
				cout<<"Saliendo del Programa..."<<endl;
				break;
    		default: cout<<"Operación no Valida...."<<endl; break;
		}//Switch para entrar a las funciones del programa
		system("PAUSE");
	}while(operacion != 0); 
 return(0);
}//main

void menu(void){ // menu que muestra las opciones del programa
	system ("color 0F");
	system("cls");
	cout<<"Administracion de cultivos, fumigaciones y abonos"<<endl;
	cout<<"                   TIERRA NEGRA"<<endl<<endl;
	logo();
	fecha();
	cout<<"      Registro de sistema de Cultivos         " <<endl;
	cout<<"========================================================" <<endl;
	cout<<"1. Agregar registro de cultivo "<<endl;
	cout<<"2. Eliminar registro de cultivo " <<endl;
  cout<<"3. Consultar los registros ingresados " <<endl;
	cout<<"4. Filtrar los registros por cantidad cosechada " <<endl;
	cout<<"5. Buscar un registro por ID " <<endl;
	cout<<"=========================================================" <<endl;
	cout<<"0. Salir del Sistema de Cultivos " <<endl;
	return;	
}

void logo(void){
  HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
  SetConsoleTextAttribute(hConsole, 4);
	cout<<"                8  88     8"<<endl;
	cout<<"               88 8  8     8"<<endl;
	cout<<"              888     88   88888"<<endl;
	cout<<"             8888      88 8    88"<<endl;
	cout<<"            8888       88      8 8"<<endl;
	cout<<"            8888       88      8 8"<<endl;
	cout<<"            8888       8       8"<<endl;
	cout<<"            8888     8       8"<<endl;
	cout<<"             88888    8      8"<<endl;
	cout<<"              8888888      8"<<endl;
	cout<<"                 88888 8"<<endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout<<"     888           88"<<endl;
	cout<<"   8888888        88"<<endl;
	cout<<"    8888888       8"<<endl;
	cout<<"     888888       88"<<endl;
	cout<<"      88     8     8"<<endl;
	cout<<"       8      8    8     8 88"<<endl;
	cout<<"          8888 8  88 8 88888"<<endl;
	cout<<"        888888 8 88  8888888"<<endl;
	cout<<"       8888888  88      88888"<<endl;
	cout<<"       88888     8         888"<<endl;
	cout<<"       88         8          8"<<endl;
	cout<<"        8         8"<<endl;
	cout<<"                  8"<<endl;
	cout<<"               8 8"<<endl;
	cout<<"                88 8"<<endl;
	cout<<"                 88"<<endl;
	cout<<"                 8"<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void AgregarRegistroCultivos(void){ // agregar la informacion de los cultivos a un nodo e incluir el nodo en la lista
system ("color 5F");
	//1 Declarar Apuntador 
	cultivos *nuevo, *recorrer = INICIO;
	char var1[20], var2[20], var3[20];
	int cosecha = 500, validador = 0;
	
	//2 Reservar Memoria 
    nuevo = (cultivos *) malloc(sizeof(cultivos));
    
    //3 Validar el Apuntador
    if (nuevo == NULL){
    	cout<<"No hay memoria suficiente para los datos de un nuevo cultivo"<<endl;
    	return;
	} else {
	//4 Guardar Datos en Nuevo Nodo de la Lista 
		system("cls");
		cout<<"Ingresar los Datos del Cultivo, todo en minusculas por favor" <<endl;
		cout<<"ID --> ";
		cin>> nuevo->ID_cultivo;
		cout<<"Tipo de cultivo (frutas o verduras) --> ";
		cin>> nuevo->tipoDeCultivo;
	 	strcpy(var1, "frutas"), strcpy(var2, "verduras");
		if ((strcmp (nuevo->tipoDeCultivo, var1) == 0) || (strcmp (nuevo->tipoDeCultivo, var2) == 0)) {
			cout<<"Tipo de fumigación (gas o polvo) --> ";
			cin>> nuevo->tipoDeFumigacion;
			strcpy(var1, "gas"), strcpy(var2, "polvo");
			if ((strcmp (nuevo->tipoDeFumigacion, var1) == 0) || (strcmp (nuevo->tipoDeFumigacion, var2) == 0)){
				cout<<"Fecha de fumigación --> ";
				cin>> nuevo->fechaFumigacion;
				cout<<"Tipo de abono (organico o sintetico) --> ";
				cin>> nuevo->tipoDeAbono;
				strcpy(var1, "organico"), strcpy(var2, "sintetico");
				if ((strcmp (nuevo->tipoDeAbono, var1) == 0) || (strcmp (nuevo->tipoDeAbono, var2) == 0)){
					cout<<"Fecha de aplicacion del abono --> ";
					cin>> nuevo->fechaAbono;
					cout<<"Fecha de sembrado --> ";
					cin>> nuevo->fechaSiembra;
					cout<<"Fecha de cosechado --> ";
					cin>> nuevo->fechaCosecha;
					cout<<"Propietario (gutierrez, fermin o rivera) --> ";
					cin>> nuevo->propietario;
					strcpy(var1, "gutierrez"), strcpy(var2, "fermin"), strcpy(var3, "rivera");
					if ((strcmp (nuevo->propietario, var1) == 0) || (strcmp (nuevo->propietario, var2) == 0) || (strcmp (nuevo->propietario, var3) == 0)){
						cout<<"Total de la cosecha --> ";
						cin>> nuevo->totalCosecha;
						if (nuevo->totalCosecha <= cosecha){
							cout<<"Ciudad (guadalajara, zapopan o tlajomulco) --> ";
							cin>> nuevo->lugar;	
							strcpy(var1, "guadalajara"), strcpy(var2, "zapopan"), strcpy(var3, "tlajomulco");
							if ((strcmp (nuevo->lugar, var1) == 0) || (strcmp (nuevo->lugar, var2) == 0) || (strcmp (nuevo->lugar, var3) == 0)){
								validador = 1;
							} else{
								cout<<"Porfavor ingrese una ciudad valida (guadalajara, zapopan o tlajomulco)";
								free(nuevo);
							}
					 } else{
					 		cout<<"Porfavor ingrese un numero valido (500 o menor)";
							free(nuevo);
					 } 
				 } else{
				 	cout<<"Porfavor ingrese un elemento valido (gutierrez, fermin o rivera)";
						free(nuevo);
					}
				} else{
					cout<<"Porfavor ingrese un elemento valido (organico o sintetico)";
					free(nuevo);
				}
			}else {
				cout<<"Porfavor ingrese un elemento valido (gas o polvo)";
				free(nuevo);
			 }	
		} else{
				cout<<"Porfavor ingrese un elemento valido (frutas o verduras)"<<endl;
				free(nuevo);
		}	
	}
	//=====================================================================================
	// 5) AGREGAR O INSERTAR EL NODO CREADO A LA LSEC
	if(validador == 1){
		// Caso a) Lista Vacia 
		if (INICIO == NULL){
			INICIO = nuevo;
			nuevo->siguiente = INICIO;
			cout<<"\nDatos del cultivo registrados exitosamente" <<endl;
			return;
		} else {
		// Caso b) Lista No Vacia 
		while(recorrer->siguiente != INICIO){
			recorrer = recorrer->siguiente;
		} // while para posicionarnos en el ultimo nodo de la lista
		recorrer->siguiente = nuevo;
		nuevo->siguiente = INICIO;
		cout<<"\nDatos del cultivo Registrados exitosamente" <<endl;
	  }
	} 
	return;
}

void EliminarRegistroCultivos(void){
	system ("cls");
	system ("color 5F");
	//Declarar Variable 
	cultivos *borrar = INICIO;
	cultivos *anterior = INICIO;
    int SiNo, respuesta;
	
	//a) Lista Vacia
	if (borrar == NULL){
		cout<<"Lista Vacia" <<endl;
		return;
	}//if
	
			//Caso b) Lista con un unico nodo 
	  if (borrar == borrar->siguiente){
		cout<<" Registro a Eliminar " <<endl;
		cout<<"==========================="<<endl;
		cout<<"Id de cultivo--> " << borrar->ID_cultivo <<endl;
		cout<<"Tipo de fumigación --> " << borrar->tipoDeFumigacion <<endl;
		cout<<"Fecha de fumigación --> " << borrar->fechaFumigacion <<endl;
		cout<<"Tipo de abono --> " << borrar->tipoDeAbono <<endl;
		cout<<"Fecha de cuando se uso el abono --> " << borrar->fechaAbono <<endl;
		cout<<"Fecha de sembrado --> " << borrar->fechaSiembra <<endl;
		cout<<"Fecha de cosechado --> " << borrar->fechaCosecha <<endl;
		cout<<"Propietario --> " << borrar->propietario <<endl;
		cout<<"Cantidad total cosechada --> " << borrar->totalCosecha <<endl;
		cout<<"Ciudad --> " << borrar->lugar <<endl;
		cout<<"==========================="<<endl;
			
			//Pregunto 
			cout<<"========================================" <<endl;
			cout<<"Estas seguro de Borrar el Registro del cultivo? presione 1 para si y 2 para no ";
			cin>>respuesta;
	
	   		if(respuesta == 2){
			cout<<"Registro No Eliminado" <<endl;
			return;
			} if(respuesta == 1){
		  //Eliminar Nodo
			free(borrar);
			INICIO = NULL;
			cout<<"Registro Eliminado" <<endl;
			return;
			} else{
				cout<<"Porfavor introduzca una respuesta valida"<<endl;
			}
		}
		
		// Caso c) Lista con mas de un Nodo
		// 1) Mostrar los datos a borrar
		while(SiNo != 1){
			cout<<"Es este el registro que deseas eliminar? presione 1 para si y 2 para no"<<endl;
			cout<<"==========================="<<endl;
		cout<<"Id de cultivo--> " << borrar->ID_cultivo <<endl;
		cout<<"Tipo de fumigación --> " << borrar->tipoDeFumigacion <<endl;
		cout<<"Fecha de fumigación --> " << borrar->fechaFumigacion <<endl;
		cout<<"Tipo de abono --> " << borrar->tipoDeAbono <<endl;
		cout<<"Fecha de cuando se uso el abono --> " << borrar->fechaAbono <<endl;
		cout<<"Fecha de sembrado --> " << borrar->fechaSiembra <<endl;
		cout<<"Fecha de cosechado --> " << borrar->fechaCosecha <<endl;
		cout<<"Propietario --> " << borrar->propietario <<endl;
		cout<<"Cantidad total cosechada --> " << borrar->totalCosecha <<endl;
		cout<<"Ciudad --> " << borrar->lugar <<endl;
		cout<<"==========================="<<endl;
		cin>>SiNo;
			
		if(SiNo == 2){ // este if se posiciona en el siguiente nodo en caso de que el mostrado no sea el que el usuario quiere borrar
			anterior = borrar;
			borrar = borrar->siguiente;
		} else {
			cout<<"Ingrese una opcion valida"<<endl;
		}
	  } // este while se termina hasta que el usuario marca 1, con esto se selecciona el nodo que se quiere borrar 
		
			// 2) Preguntar Si lo quiere borrar
			cout<<"========================================" <<endl;
			cout<<"Estas seguro de Borrar el Registro de este cultivo? presione 1 para si y 2 para no ";
			cin>>respuesta;
			if( respuesta == 1 ){
		    // Procedo a borrar
				anterior->siguiente = borrar->siguiente;
		    free(borrar);
		    cout<<" Registro Borrado " <<endl;
			return;
			} if(respuesta == 2){ // en este caso el usuario decide no borrar
			cout<<"Registro No Borrado " <<endl;
			} else{ // 
				cout<<"Porfavor introduzca una respuesta valida"<<endl;
			}
	    return;
}

void ConsultarLista(void){
	system ("color 5F");
	//Declarar Variable 
	cultivos *copia = INICIO;
	
	if (copia == NULL){
		cout<<"Lista Vacia " <<endl;
		return;
	}//if
	
	//Lista con al menos un nodo
	system("cls");
	cout<<"Datos de cultivos registrados" <<endl;
	do{ 
		cout<<"==========================="<<endl;
		fflush(stdin);
			cout<<"Id de cultivo--> " << copia->ID_cultivo <<endl;
			fflush(stdin);
			cout<<"Tipo de fumigación --> " << copia->tipoDeFumigacion <<endl;
			fflush(stdin);
			cout<<"Fecha de fumigación --> " << copia->fechaFumigacion <<endl;
			fflush(stdin);
			cout<<"Tipo de abono --> " << copia->tipoDeAbono <<endl;
			fflush(stdin);
			cout<<"Fecha de cuando se uso el abono --> " << copia->fechaAbono <<endl;
			fflush(stdin);
			cout<<"Fecha de sembrado --> " << copia->fechaSiembra <<endl;
			fflush(stdin);
			cout<<"Fecha de cosechado --> " << copia->fechaCosecha <<endl;
			fflush(stdin);
			cout<<"Propietario --> " << copia->propietario <<endl;
			fflush(stdin);
			cout<<"Cantidad total cosechada --> " << copia->totalCosecha <<endl;
			fflush(stdin);
			cout<<"Ciudad --> " << copia->lugar <<endl;
			fflush(stdin);
		//Ir al Siguiente Nodo
		
		copia = copia->siguiente;	
	cout<<"=============================" <<endl;	
	}while( copia != INICIO ); // este do while hace que se muestre lo registrado en la lista hasta que copia sea diferente de INICIO
	
	return;
}

void FiltrarPorCosecha(void){
	system ("color 5F");
	//Declarar Variable 
	cultivos *copia = INICIO;
    float cosechaMin;
    bool encontrar = false;
	
	if (copia == NULL){
		cout<<"Lista Vacia " <<endl;
		return;
	}//if
	
	//Solicitar la cantidad cosechada Minima a Mostrar
	system("cls");
	cout<<"Cantidad de cosecha minima a mostrar --> ";
	cin>>cosechaMin;
	//Lista con al menos un nodo
	do{
		if (copia->totalCosecha >= cosechaMin) {
			encontrar = true;
			cout<<"Datos de cultivos registrados " <<endl;
	    cout<<"==========================="<<endl;
			cout<<"Id de cultivo--> " << copia->ID_cultivo <<endl;
			cout<<"Tipo de fumigación --> " << copia->tipoDeFumigacion <<endl;
			cout<<"Fecha de fumigación --> " << copia->fechaFumigacion <<endl;
			cout<<"Tipo de abono --> " << copia->tipoDeAbono <<endl;
			cout<<"Fecha de cuando se uso el abono --> " << copia->fechaAbono <<endl;
			cout<<"Fecha de sembrado --> " << copia->fechaSiembra <<endl;
			cout<<"Fecha de cosechado --> " << copia->fechaCosecha <<endl;
			cout<<"Propietario --> " << copia->propietario <<endl;
			cout<<"Cantidad total cosechada --> " << copia->totalCosecha <<endl;
			cout<<"Ciudad --> " << copia->lugar <<endl;
			//Ir al Sig Nodo
	}
		copia = copia->siguiente;	
	cout<<"=============================" <<endl;	
	}while( copia != INICIO ); // este do while hace que se muestre lo registrado en la lista hasta que copia sea diferente de INICIO
	
	if (! encontrar ){ // si encontrar no es true, se marca que no hay cosechas mayores al numero ingresado
	   	cout << "No hay cosechas mayores al numero ingresado "<< cosechaMin <<endl; 	
	}
	return;	
}

void BuscarPorID(void){
	system ("color 5F");
	//Declarar Variable 
	cultivos *copia = INICIO;
	char IDBuscar[10], verificador = 0;
	
	if (copia == NULL){
		cout<<"Lista Vacia " <<endl;
		return;
	}//if
	
	//Solicitar el ID del cultivo a Buscar
	system("cls");
	cout<<"ID del cultivo --> ";
	cin>>IDBuscar;
	//Lista con al menos un nodo
	do{
		if(strcmp(IDBuscar, copia->ID_cultivo) == 0) {
	    cout<<"==========================="<<endl;
			cout<<"Id de cultivo--> " << copia->ID_cultivo <<endl;
			cout<<"Tipo de fumigación --> " << copia->tipoDeFumigacion <<endl;
			cout<<"Fecha de fumigación --> " << copia->fechaFumigacion <<endl;
			cout<<"Tipo de abono --> " << copia->tipoDeAbono <<endl;
			cout<<"Fecha de cuando se uso el abono --> " << copia->fechaAbono <<endl;
			cout<<"Fecha de sembrado --> " << copia->fechaSiembra <<endl;
			cout<<"Fecha de cosechado --> " << copia->fechaCosecha <<endl;
			cout<<"Propietario --> " << copia->propietario <<endl;
			cout<<"Cantidad total cosechada --> " << copia->totalCosecha <<endl;
			cout<<"Lugar --> " << copia->lugar <<endl;
			cout<<"==========================="<<endl;
			verificador = 1;
			} 
		copia = copia->siguiente;	
	} while(copia != INICIO);
	
	if(verificador == 0){ // Si el verificador no es igual a 1, significa que el ID no existe, y este if es para que no se inicie si no se cumple
	cout <<"ID "<<IDBuscar<<" de cultivo no localizado" <<endl; }
	return;		
}

void fecha(void){
// fecha/hora actual basado en el sistema actual 
time_t now = time(0);

// Objeto de una estructura tm con fecha/hora local 
tm * time = localtime(&now);

vector<string> dia_semana; // string para imprimir el dia
dia_semana.push_back("Domingo");
dia_semana.push_back("Lunes");
dia_semana.push_back("Martes");
dia_semana.push_back("Miercoles");
dia_semana.push_back("Jueves");
dia_semana.push_back("Viernes");
dia_semana.push_back("Sabado");

vector<string> mes; // string para imprimir el mes
mes.push_back("Enero");
mes.push_back("Febrero");
mes.push_back("Marzo");
mes.push_back("Abril");
mes.push_back("Mayo");
mes.push_back("Junio");
mes.push_back("Julio");
mes.push_back("Agosto");
mes.push_back("Septiembre");
mes.push_back("Octubre");
mes.push_back("Noviembre");
mes.push_back("Diciembre");

int year = 1900 + time->tm_year;

// imprimir la fecha y hora
cout << "Hoy es dia " << dia_semana[time->tm_wday] << ", ";
cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
cout <<"Hora: "<< time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl<<endl;

 return;
}




