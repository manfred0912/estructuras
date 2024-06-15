// mi archivo de biblioteca propio
//implementacion de las funciones
//1) longitud de la cadena
using namespace std;
int tamCadena(char *apCad){
	
	int contador = 0;
	
	while ( *apCad != '\0' ){
		contador++;
		apCad++;
	}
	
        return(contador);
}// tamCadena

//2) imprime al reves la cadena

void cadenaRev(char *apCad, int longi){
	apCad = apCad + longi -1;
	while (longi >= 1){
		cout << *apCad; 
		longi--;
		apCad--;
	}
  return;
}// cadenaRev

// 3) copiar una cadena en otra
void copiaCad(char *apDest, char *apFuente){
	while ( *apFuente != '\0' ){
		*apDest = *apFuente;
		apFuente++;
		apDest++;
	}
	*apDest = '\0';
	return;
}// copiaCad

// 4) concatenar 2 cadenas
void concatCadenas(char *cadena1, char *cadena2){
	strcat(cadena2, cadena1);
}

// 5) comparar 2 cadenas
float compararCadenas(char *cadena1, char *cadena2){
	bool indicador;
if(strcmp(cadena1, cadena2)==0){
	indicador = 0;
}
else{
	indicador = 1;
}
return(indicador);
}



