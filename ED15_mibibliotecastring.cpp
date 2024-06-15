// practica 15

#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
#include "MiBiblioteca.h"

int main() {
	char cadena1[20], cadena2[20];
	int longitud;
	
	cout<<"Este programa usa mis funciones de biblioteca string propia."<<endl;
	// 1) strlen (funcion que recibe una cadena y regresa su longitud)
	cout<<"Cual es tu animal favorito? ";
	cin>> cadena1;
	
	longitud = tamCadena(cadena1); // invocar la funcion
	cout<< "La longitud de "<<cadena1<<" = "<<longitud<<endl;
	
	// 2) Imprimir la cadena leida al revés
	cout<<cadena1<<" al reves "<<endl;
	cadenaRev(cadena1,longitud);
	
	// 3) copiar una cadena en otra
	copiaCad(cadena2, cadena1);
	cout<<"\ncadena 1 contiene --> "<<cadena1<<endl;
	cout<<"cadena2 contiene --> "<<cadena2<<endl;
	
	// 4) funcion que permite concatenar 2 cadenas
	concatCadenas(cadena1, cadena2);
	cout<<"\nLas cadenas concatenadas se miran de la siguiente manera: "<<cadena2<<endl;
	
	// 5) funcion que compara 2 cadenas
	compararCadenas(cadena1, cadena2);
	if (compararCadenas(cadena1, cadena2) == 0){
		cout<<"Las cadenas son iguales"<<endl;
	}
	else{
		cout<<"Las cadenas son distintas"<<endl;
	}
}//main



