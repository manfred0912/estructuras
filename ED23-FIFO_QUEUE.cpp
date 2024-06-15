/*Actividad 7. QUEUE, FIFO, COLA
ED23-FIFO_QUEUE*/

# include <iostream>
using namespace std;
void mostrar();
void ingreso();
void eliminar();

struct datos
{
	int dato;
	datos *direccion_sig;
}*primero,*cola,*ultimo=NULL;
int main()
{
	int opcion;
	while(true){
		cout<<"1 Ingreso de datos a la Cola"<<endl;
		cout<<"2 Mostrar Datos de la cola"<<endl;
		cout<<"3 Eliminar datos de la cola"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:{
				ingreso();
				break;
			}
			case 2:{
				mostrar();
				break;
			}
			case 3:{
				eliminar();
				break;
			}
		}
	}
}
void ingreso(){
	cola=new(datos);
	cout<<"Ingrese dato a la cola"<<endl;
	cin>>cola->dato;
	if(ultimo!=NULL){
		ultimo->direccion_sig=cola;
		cola->direccion_sig=NULL;
		ultimo=cola;
		cout<<"Dato Ingresado "<<endl;
	
	}
	else{
		primero=ultimo=cola;
		cout<<"primer dato ingresado"<<endl;
		cout<<primero<<" "<<ultimo<<" "<<cola<<endl;
	}
		cout<<ultimo->direccion_sig<<" "<<cola->direccion_sig<<endl;
}
void mostrar(){
	if(ultimo==NULL){
		cout<<"La cola esta vacia"<<endl;
		return;
	}
	cola=primero;
	cout<<"Los dato de la cola son; "<<endl;
	while(cola!=NULL){
		cout<<cola->dato<<endl;
		cola=cola->direccion_sig;

	}
}
void eliminar(){
	if(primero!=NULL){
		cola=primero;
		cout<<"Eliminado "<<primero->dato<<endl;
		primero=cola->direccion_sig;
		delete(cola);
		if(primero==NULL){
			cola=NULL;
			ultimo=NULL;
		}
	}
	else{
		cout<<"La cola esta vacia"<<endl;
	}
}
