#include <iostream>
#include <conio.h>

using namespace std;
void semana(int sab[], int tamano);
int main(){

	
	int lun[5] = {1,2,3,4,5};
	int mar[5] = {6,7,8,9,10};
	
	semana(lun, 5);
	semana(mar, 5);

return 0;

}

void semana(int sab[], int tamano) {
	for(int i=0; i<tamano; i++){
    cout<<sab[i]<<endl;	
	}
	cout<<endl; 
	
	getch();

 }
 
