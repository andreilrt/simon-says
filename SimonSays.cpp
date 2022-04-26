#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

int tecla = 0;
int fila = 0;
int columna = 0;
const int Tamano = 3;
int Arreglo[Tamano][Tamano];
int Memoria[100];
int MemoriaJugador[100];
int AumentoMemoria = 0;
int Puntuacion = 0;
int pos = 0;
string Nombre;

void Sonido(){
	if(tecla == 1){
		Beep(500,200);
	}
	if(tecla == 2){
		Beep(550,200);
	}
	if(tecla == 3){
		Beep(600,200);
	}
	if(tecla == 4){
		Beep(650,200);
	}
	if(tecla == 5){
		Beep(700,200);
	}
	if(tecla == 6){
		Beep(750,200);
	}
	if(tecla == 7){
		Beep(800,200);
	}
	if(tecla == 8){
		Beep(850,200);
	}
	if(tecla == 9){
		Beep(900,200);
	}
}

void Portada(){
	cout<<"Bienvenido/a a Simon Says, esperamos que tu memoria sea muy buena!\n\n"
	"Digita tu nombre para comenzar: ";
	getline(cin,Nombre);
}

void InicializarMemoria(){
	for(int posicion = 0; posicion<100; posicion++){
		Memoria[posicion]=0;
		MemoriaJugador[posicion]=0;
	}
}

void MostrarArregloJugador(){
	system("cls");
	for(int f = 0; f<Tamano; f++){
		for(int n = 0; n<Tamano*4+1; n++){
			cout<<"-";
		}
		cout<<endl;
		cout<<"| ";
		for(int c = 0; c<Tamano; c++){
			if(tecla==Arreglo[f][c]){
				Sonido();
				cout<<Arreglo[f][c]<<" | ";
			}
			else{
				cout<<"  | ";
			}
		}
		cout<<endl;
	}
	for(int n = 0; n<Tamano*4+1; n++){
		cout<<"-";
	}
	Sleep(150);
	cout<<endl<<endl;
}

void MostrarArregloJuego(){
	system("cls");
	for(int f = 0; f<Tamano; f++){
		for(int n = 0; n<Tamano*4+1; n++){
			cout<<"-";
		}
		cout<<endl;
		cout<<"| ";
		for(int c = 0; c<Tamano; c++){
			if(Memoria[pos]==Arreglo[f][c]){
				tecla = Arreglo[f][c];
				Sonido();
				cout<<Arreglo[f][c]<<" | ";
			}
			else{
				cout<<"  | ";
			}
		}
		cout<<endl;
	}
	for(int n = 0; n<Tamano*4+1; n++){
		cout<<"-";
	}
	Sleep(150);
	cout<<endl<<endl;
}

void MostrarArregloLleno(){
	for(int f = 0; f<Tamano; f++){
		for(int n = 0; n<Tamano*4+1; n++){
			cout<<"-";
		}
		cout<<endl;
		cout<<"| ";
		for(int c = 0; c<Tamano; c++){
			cout<<Arreglo[f][c]<<" | ";
		}
		cout<<endl;
	}
	for(int n = 0; n<Tamano*4+1; n++){
		cout<<"-";
	}
	cout<<endl<<endl;
}

void LlenarArreglo(){
	int Numero = 1;
	for(int f = 0; f<Tamano; f++){
		for(int c = 0; c<Tamano; c++){
			Arreglo[f][c]=Numero;
			Numero++;
		}
	}
}

int Aleatorio(){
	int Numero = 0;
	Numero = rand()%Tamano;
	return Numero;
}

void IngresarMemoria(){
	fila = Aleatorio();
	columna = Aleatorio();
	Memoria[AumentoMemoria]=Arreglo[fila][columna];
	AumentoMemoria++;
}

bool VerificarMemoria(){
	system("Pause");
	system("cls");
	cout<<"Ahora te toca a ti "<<Nombre<<endl;
	cout<<"Estas en el nivel "<<AumentoMemoria<<endl;
	for(int nivel = 0; nivel<AumentoMemoria; nivel++){
		cout<<"Digita el valor del nivel "<<nivel+1<<": ";
		cin>>tecla;
		MostrarArregloJugador();
		if(tecla!=Memoria[nivel]){
			return false;
		}
		system("cls");
	}
	Puntuacion = Puntuacion + 10;
	system("cls");
	cout<<"Vas muy bien "<<Nombre<<" !!!"<<endl;
	cout<<"Tienes "<<Puntuacion<< "puntos :)"<<endl<<endl;
	system("Pause");
	return true;
}

int main(){
	bool Pierde = true;
	InicializarMemoria();
	srand(time(NULL));
	Portada();
	system("cls");
	LlenarArreglo();
	cout<<"Estas son las teclas que puedes presionar para jugar"
	<<endl<<"Asi que atento/a "<<Nombre<<endl<<endl;
	MostrarArregloLleno();
	system("Pause");
	while(Pierde){
		IngresarMemoria();
		for(int nivel = 0; nivel<AumentoMemoria; nivel++){
			MostrarArregloJuego();
			pos++;
		}
		pos = 0;
		Pierde = VerificarMemoria();
	}
	system("cls");
	cout<<"Has perdido :(";
	
	return 0;
}

