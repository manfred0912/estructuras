#include <iostream>
#include<conio.h>
#include <stdio.h>

using namespace std;

struct detallesMaterias{
	char CVE[100];
	char SEC[100];
	char nombre[600];
};

struct materias{
	int NRC;
	struct detallesMaterias detalles;
	int aula;
}materia[7];

int main(){
	for(int i=0;i<7;i++){
		fflush(stdin);
		cout<<"Digite el nombre de la materia: ";
		cin.getline(materia[i].detalles.nombre,60,'\n');
		fflush(stdin);
		cout<<"Digite el CVE de la materia: ";
		cin.getline(materia[i].detalles.CVE,5,'\n');
		fflush(stdin);
		cout<<"Digite el NRC de la materia: ";
		cin>>materia[i].NRC;
		fflush(stdin);
		cout<<"Digite el SEC de la materia: ";
		cin.getline(materia[i].detalles.SEC,3,'\n');
		fflush(stdin);
		cout<<"Digite el aula: ";
		cin>>materia[i].aula;
		cout<<"\n";
	}
	
	for(int i=0;i<7;i++){
		cout<<"Nombre de la materia: "<<materia[i].detalles.nombre<<endl;
		cout<<"CVE de la materia: "<<materia[i].detalles.CVE<<endl;
		cout<<"NRC de la materia: "<<materia[i].NRC<<endl;
		cout<<"SEC de la materia: "<<materia[i].detalles.SEC<<endl;
		cout<<"aula de la materia: "<<materia[i].aula<<endl;
	}
	
	return 0;
}
