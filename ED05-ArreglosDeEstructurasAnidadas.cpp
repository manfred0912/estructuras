// Fecha: Semana 4
// Autor: Rebeca
// Práctica No.: 5
// Objetivo: Arreglos de Estructuras Anidadas

// Librerías
#include <iostream>
using namespace std;

// Definir Constantes
const int MAXP = 2;

// Definir los TDA - Tipo de Dato Abstracto
struct tPaquete {
	char nombre[20];
	float precio;
	int articulos;
	bool soda;
};

struct tFecha {		// TDA tFecha
	int dia;
	int mes;
	int axo;	
};

struct tPedido {
	struct tPaquete combo;
	struct tFecha fecha;
	float total;
	int cantidad;	
}; 

// Programa principal
int main(void) {
	struct tPedido pedidos[MAXP];
	
	// Leer datos de primer pedido
	cout << "Ingresa los datos de los pedidos." << endl;
	cout << "====================================" << endl;
	for (int i=0; i<MAXP; i++ ) {	
		cout << "Datos del pedido " << i+1 << endl;
		cout << "Nombre --> ";
		fflush(stdin);
		cin.getline(pedidos[i].combo.nombre,20,'\n');
		cout << "Precio --> ";
		
		fflush(stdin);	
		cin >> pedidos[i].combo.precio;
		cout << "Numero de articulos --> ";
		cin >> pedidos[i].combo.articulos;
		cout << "Soda (1-Si  0-No) --> ";
		
		//fflush(stdin);	
		cin >> pedidos[i].combo.soda;
		cout << "Fecha del pedido (dia) --> ";
		cin >> pedidos[i].fecha.dia;
		cout << "Fecha del pedido (mes) --> ";
		cin >> pedidos[i].fecha.mes;
		cout << "Fecha del pedido (axo) --> ";
		cin >> pedidos[i].fecha.axo;
	
		cout << "Total a pagar --> ";
		cin >> pedidos[i].total;
		cout << "Cantidad de combos --> ";
		cin >> pedidos[i].cantidad;
		cout << "====================================" << endl;
    } // for i
	
	// Mandar llamar la función imprime
	for (int i=0; i<MAXP; i++) {
		cout << "Imprimiendo el Pedido " << i+1 << endl;
		cout << "====================================" << endl;
		cout << "Datos del paquete." << endl;
		cout << "Nombre --> " << pedidos[i].combo.nombre << endl;
		cout << "Precio --> " << pedidos[i].combo.precio << endl;
		cout << "Numero de articulos --> " 
		     << pedidos[i].combo.articulos << endl;
		cout << "Soda (1-Si  0-No) --> " << pedidos[i].combo.soda << endl;
		cout << "Fecha del pedido (dia) --> " << pedidos[i].fecha.dia << endl;
		cout << "Fecha del pedido (mes) --> " << pedidos[i].fecha.mes << endl;
		cout << "Fecha del pedido (axo) --> " << pedidos[i].fecha.axo << endl;
		cout << "Total a pagar --> " << pedidos[i].total << endl;
		cout << "Cantidad de combos --> " << pedidos[i].cantidad << endl;
		cout << "====================================" << endl;
	} // for i
	
	return(0);
} // main

