// ****************************************
// Fecha: Semana 6
// Autor: Rebeca
// Practica No.: 11
// Objetivo: Introduccion a Apuntadores
// ****************************************

// Librerias
// ****************************************
#include <iostream>
#include <iomanip>
using namespace std;

// Funci—n principal
// ****************************************
int main(void) {
    // Declaracion del apuntador
    // *************************
    int num=7;
    int *apEntero=NULL;
    
    float pi = 3.14151692;
    float *apReal=&pi;
    
    char letra='a', *apLetra=&letra;
    
    double dato=2.3049350339, *apDoble = &dato;
    
    // Apuntadores a Enteros
    // ******************************************************************
    cout << "----------------------------------- ENTEROS" << endl;
    cout << "tamanio en bytes de (int) = " << sizeof(int) << endl;
    cout << "tamanio en bytes de num (int) = " << sizeof(num) << endl;
    cout << endl;
    cout << "num = " << num << endl;
    cout << "direccion en memoria de num = " << &num << endl;
    cout << endl;
    apEntero = &num;
    cout << "num (a traves del apuntador) = " << *apEntero << endl;
    cout << "direccion en memoria de num (a traves del apuntador) = "
    << apEntero << endl;
    
    // Apuntadores a Reales (float)
    // ******************************************************************
    cout << "----------------------------------- REALES float" << endl;
    cout << "tamanio en bytes de (float) = " << sizeof(float) << endl;
    cout << "tamanio en bytes de pi (float) = " << sizeof(pi) << endl;
    cout << endl;
    cout << "Valor de pi = " << pi << endl;
    cout << "Direccion variable pi = " << &pi << endl;
    cout << endl;
    cout << "Valor de pi (a traves del apuntador) = " << *apReal << endl;
    cout << "Direccion variable pi (a traves del apuntador) = "
    << apReal << endl;
    cout << endl;
    cout << "Direccion de la variable apuntador apReal --> "
    << &apReal << endl;
    
    // Apuntadores a Reales (double)
    // ******************************************************************
    cout << "----------------------------------- REALES double" << endl;
    cout << "tamanio en bytes de double = " << sizeof(double) << endl;
    cout << "tamanio en bytes de dato (double) = " << sizeof(dato) << endl;
    cout << endl;
    cout << "Valor de dato = " << fixed << setprecision(10) << dato << endl;
    cout << "Direccion variable dato = " << &dato << endl;
    cout << endl;
    cout << "Valor de dato (a traves del apuntador) = "
    << fixed << setprecision(10) << *apDoble << endl;
    cout << "Direccion variable dato (a traves del apuntador) = "
    << apDoble << endl;
    cout << endl;
    
    // Apuntadores a Char
    // ******************************************************************
    cout << "----------------------------------- CHAR" << endl;
    cout << "tamanio en bytes de char = " << sizeof(char) << endl;
    cout << "tamanio en bytes de letra (char) = " << sizeof(letra) << endl;
    cout << endl;
    cout << "Letra = " << letra << endl;
    cout << "direccion en memoria de letra = " << (unsigned long int *) &letra << endl;
    cout << endl;
    cout << "letra (a traves del apuntador) = " << *apLetra << endl;
    cout << "direccion en memoria de letra (a traves del apuntador) = "
    << (unsigned long int *) apLetra << endl;
    cout << "-----------------------------------" << endl;
    
    return(0);
} // main()
