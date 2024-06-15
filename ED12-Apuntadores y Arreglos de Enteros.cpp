// Fecha: Semana 6
// Autor: Rebeca
// Practica No.: 12
// Objetivo: Arpuntadores y Arreglos de Enteros

// Librerias
#include <iostream>
using namespace std;

// Constantes
const int MAX=5;

int main(void) {
	// Declaracion de variables
	int sueldos[MAX], *ap=NULL;
	
	// Leer los sueldos
    cout << "========================================" << endl;
    cout << "1. LEYENDO DATOS DEL ARREGLO" << endl;
    cout << "========================================" << endl;
	for (int i=0;  i<MAX;  i++) {
		cout << "Ingresa el sueldo " << i+1 << " -> ";
		cin >> sueldos[i];
	} // for i
	
	cout << "El arreglo inicia en la direccion " << sueldos 
	     << endl;

	// *******************************************
	// Escribir el contenido
    cout << "========================================" << endl;
    cout << "2. MANIPULANDO EL ARREGLO por s’ mismo"  << endl;
    cout << "========================================" << endl;
	for (int i=0; i<MAX; i++) {
		cout << "Sueldo elemento " << i << " = " << sueldos[i]
		     << " y esta guardado en la direccion "
		     << &sueldos[i] << endl;
	} // for i
    
	// *******************************************
    // Escribir el contenido
    cout << "=================================================" << endl;
    cout << "3. MANIPULANDO EL ARREGLO a traves del APUNTADOR"  << endl;
    cout << "=================================================" << endl;
    ap = sueldos;
	cout << "ANTES ap contiene direccion " << ap << endl;
	for (int i=0; i<MAX; i++) {
		cout << "Sueldo elemento " << i << " = " << *(ap+i)
		     << " y esta guardado en la direccion "
		     << ap+i << endl;
	} // for i
	cout << "DESPUES ap contiene direccion " << ap << endl;
	
	return(0);
} // main
