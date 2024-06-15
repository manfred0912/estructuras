// practica 15

#include<iostream>
using namespace std;

//prototipo de funciones
int tamCadena(char *)

int main() {
	char cadena1[20], cadena2[20];
	int longitud;
	
	cout<<"Este programa usa mis funciones de biblioteca string propia."<<endl;
	// 1) strlen (funcion que recibe una cadena y reggresa su longitud)
	cout<<"Cual es tu animal favorito? ";
	cin>> cadena1;
	
	longitud = tamCadena(cadena1); // invocar la funcion
	cout<< "La longitud de "<<cadena1<<"="<<longitud<<endl;
	
	return(0);
}//main

//implementacion de las funciones
int tamCadena(char *apCad){
	int  contador=0;
	
	while ( *apCad != '\0' ){
		contador++;
		apCad++;
	}
	
}// tamCadena
