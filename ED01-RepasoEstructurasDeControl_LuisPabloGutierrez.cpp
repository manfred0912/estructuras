#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int op, num1, num2, num3=1, resul, i;
	do{
	cout<<"En este programa se revisaran las estructuras secuenciales, selectivas y repetitivas con ejemplos basicos"<<endl;
	cout<<"Porfavor ingrese el numero de la opcion que desea ejecutar"<<endl;
	cout<<"Opción 1: determinar el mayor de 2 numeros"<<endl;
	cout<<"Opcion 2: suma de varios numeros"<<endl;
	cout<<"Opcion 3: muestra una lista de numeros del 1 al 10"<<endl;
	cout<<"Opcion 4: salir del programa"<<endl;
	cin>>op;
	
	switch(op){
		case 1: cout<<"Porfavor ingrese el primer numero ";cin>>num1;
						cout<<"\nPorfavor ingrese el segundo numero ";cin>>num2; 
						if(num1>num2){
							cout<<"el numero "<<num1<<" es mayor que "<<num2;
			        }
			        else{
			        	cout<<"el numero "<<num2<<" es mayor que "<<num1<<endl;
							}
		break;
		case 2: cout<<"En esta opcion es necesario que el usuario digite los numeros que se van a sumar, la condición para salir es que se digite el numero 0"<<endl;
						while(num3!=0){
							cout<<"Porfavor digite un numero ";cin>>num3;
							resul += num3;
						}
						cout<<"El resultado de los numeros es "<<resul<<endl;
						break;
		case 3: for(i=1; i<=10; i++)
						cout<<i<<endl;
						break;
		case 4: cout<<"Presione enter para continuar"; break;
		default: cout<<"La opcion ingresada no esta disponible";
	}
	
	
	
getch();}while(op!=4);
}
