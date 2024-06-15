// Fecha: Semana 5
// Autor: Rebeca Andalon
// Practica No.: 7
// Objetivo: Arreglos de Estructuras

#include <iostream>
using namespace std;

// TDA
typedef struct tLigaMB {
	char equipo[20];
	float precio;
	int jugadores;
	char estado[20];
	int derrotas;
	int victorias;
	char coach[30];
};

// Constantes
const int MAX = 10;
const int MIN = 1;

// Prototipos de funciones
void imprime(struct tLigaMB, int);
struct tLigaMB lee(int);

// programa principal
int main(void) {
	// Arreglos de estructuras
	tLigaMB  afiliados[MAX];
	int tot;
	
	do {
		cout << "Cuantos equipos de Baseball deseas ingresar? ";
		cin >> tot;
    } while (tot<MIN || tot>MAX);
	
	// Leer los datos de los equipos
	for ( int i=0; i<tot; i++) {
		afiliados[i]=lee(i+1);
	}  // for i
	
	// Escribir los datos leídos
	cout << "DATOS DE LOS EQUIPOS " << endl;
	cout << "=================================" << endl;
	for ( int i=0; i<tot; i++) {
		imprime(afiliados[i], i+1);
	}  // for i

	return(0);	
} // main

// IMPLEMENTACION DE FUNCIONES
//====================================
struct tLigaMB lee(int n){
	// variable local tipo estructura
	struct tLigaMB afi;
	
	cout << "DATOS DEL EQUIPO " << n << endl;
	cout << "=================================" << endl;
	cin.ignore();
	cout << "Nombre --> ";
	cin.getline(afi.equipo,20,'\n');
	cout << "Precio --> ";
	cin >> afi.precio ;
	cout << "Numero de jugadores --> ";
	cin >> afi.jugadores;
    cin.ignore();
	cout << "Estado de origen --> ";
	cin.getline(afi.estado,20,'\n');	
	cout << "Total de derrotas --> ";
	cin >> afi.derrotas ;
	cout << "Total de victorias --> ";
	cin >> afi.victorias;
	cin.ignore();
	cout << "Nombre del coach --> ";
	cin.getline(afi.coach,30,'\n');
	cout << "============================" << endl;
	// Regreso la variable tipo estructura con los datos
	return(afi);
} // lee()

//====================================
void imprime (struct tLigaMB afi, int n) {
	cout << "EQUIPO # " << n << endl;
	cout << "Nombre: " << afi.equipo << endl;
	cout << "Precio: " << afi.precio  << endl;
	cout << "Numero de jugadores: " << afi.jugadores << endl;
	cout << "Estado de origen: " << afi.estado  << endl;	
	cout << "Total de derrotas: " << afi.derrotas  << endl;
	cout << "Total de victorias: " << afi.victorias << endl;
	cout << "Nombre del coach: " << afi.coach << endl;
	cout << "============================" << endl;	
	return;
} // imprime()


