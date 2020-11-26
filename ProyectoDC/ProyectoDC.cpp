#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
#include<windows.h>
using namespace System;
using namespace std;
//GLOBALES
string jugador1;
string jugador2;
int contador1 = 0;
int contador2 = 0;
int contador_cancela1 = 0;
int contador_cancela2 = 0;
int total_contador = 0;
//FIN GLOABLES

void posicion(int x1, int y1) 
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x1;
	dwPos.Y = y1;
	SetConsoleCursorPosition(hcon, dwPos);
}
/*
class JUGADOR1
{
	private : //Atributos
		char ficha;
	public: //Metodos
		//JUGADOR1();
		void mostrar();
		void setFicha(char);
		char getFicha();
};
//JUGADOR1::JUGADOR1(char ficha) {
//	this->ficha = ficha;
//}
void JUGADOR1::mostrar() {
	cout << ficha;
}
void JUGADOR1::setFicha(char ficha) {
	this->ficha = ficha;
}
char JUGADOR1::getFicha() {

	return '1';
}
*/
void mostrarGuia() {
	
	posicion(45, 8);
	cout << "DATOS :";
	posicion(45, 9);
	cout << "X -> 10";
	posicion(45, 10);
	cout << "Pasando X cuenta como 11,12,13... 19" ;
	posicion(45, 11);
	cout << "V -> 20";
	posicion(45, 12);
	cout << "Pasando V cuenta como 21,22,23,24";
	posicion(0, 2);
	cout << "0 2 4 6 89X123456 8 V 2 4";
	for (int i = 0; i < 17; i++) {
		if (i == 0) {
			cout << " " << endl;
		}
		cout << "                           " << i << endl;
	}
	posicion(0, 2);
}
char tablerobase[17][25] = { 
																			  //*
			/*  0   1   2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24*/
	/*0*/	   {9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	'R',9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9},
	/*1*/	   {9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	'R',9,	'R',9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9},
	/*2*/	   {9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	'R',9,	'R',9,	'R',9,	9,	9,	9,	9,	9,	9,	9,	9,	9},
	/*3*/	   {9,	9,	9,	9,	9,	9,	9,	9,	9,	'R',9,	'R',9,	'R',9,	'R',9,	9,	9,	9,	9,	9,	9,	9,	9},//jugador1
	/*4*/	   {'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O'},
	/*5*/	   {9,  'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9},
	/*6*/	   {9,	9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	9},
	/*7*/	   {9,	9,	9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	9,	9},
	/*8*/	   {9,	9,	9,	9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	9,	9,	9},
	/*9*/	   {9,	9,	9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	9,	9},
	/*10*/	   {9,	9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	9},
	/*11*/	   {9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9},
	/*12*/	   {'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O',9,	'O'},
	/*13*/	   {9,	9,	9,	9,	9,	9,	9,	9,	9,	'A',9,	'A',9,	'A',9,	'A',9,	9,	9,	9,	9,	9,	9,	9,	9},//jugador2
	/*14*/	   {9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	'A',9,	'A',9,	'A',9,	9,	9,	9,	9,	9,	9,	9,	9,	9},
	/*15*/	   {9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	'A',9,	'A',9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9},
	/*16*/	   {9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	'A',9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9},
};
void BienvenidaJuego() {
	posicion(15, 5);	cout << "BIENVENIDO "<<jugador1<<" Y "<<jugador2;
	_sleep(1000);
	posicion(15, 8); cout << "EL JUEGO...";
	cout << endl;
	_sleep(1000);
	posicion(15, 11); cout << "EMPIEZA... ";
	cout << endl;
	_sleep(1000);
	posicion(15, 14); cout << "¡¡¡AHORA!!!";
	_sleep(1000);
}
void AniadirJugador() {
	
	/*
	Console::ForegroundColor = ConsoleColor::Red;
	vector[0] = new JUGADOR1('1');
	vector[0]->getFicha();
	cout << endl;
	vector[0] = new JUGADOR1('2');
	vector[0]->mostrar();
	*/
	Console::ForegroundColor = ConsoleColor::Red;
	cout << " Ingrese nombre del jugador1: "; 
	Console::ForegroundColor = ConsoleColor::Green;
	cin >> jugador1;
	system("cls");
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << " Ingrese nombre del jugador2: "; 
	Console::ForegroundColor = ConsoleColor::Green; 
	cin >> jugador2;
	Console::ForegroundColor = ConsoleColor::Yellow;
	BienvenidaJuego();
	system("cls");
	Console::ForegroundColor = ConsoleColor::Red;
	cout << " Jugador1 equipo rojo: ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout<<jugador1;
	Console::ForegroundColor = ConsoleColor::White;
	cout << " | ";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << " Jugador2 equipo azul: ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << jugador2 << endl;
	Console::ForegroundColor = ConsoleColor::White;
	cout << endl;
}
void mostrarJugadas() {   
	posicion(64, 3);     
	cout << "*";      
	posicion(64, 4);
	cout << "*";
	posicion(67, 3);
	cout << " TOTAL DE JUGADAS: ";
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << contador1 + contador2;
	Console::ForegroundColor = ConsoleColor::White;
	posicion(45, 3);
	cout << "JUGADA DE ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << jugador1;
	Console::ForegroundColor = ConsoleColor::White;
	cout << " :";
	Console::ForegroundColor = ConsoleColor::Magenta;
	cout << contador1;
	Console::ForegroundColor = ConsoleColor::White;
	posicion(45, 4);
	cout << "JUGADA DE ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << jugador2;
	Console::ForegroundColor = ConsoleColor::White;
	cout << " :";
	Console::ForegroundColor = ConsoleColor::Magenta;
	cout << contador2;
	Console::ForegroundColor = ConsoleColor::White;
	posicion(45, 5);
	cout << "****************************************";
	Console::ForegroundColor = ConsoleColor::White;
	posicion(45, 6);//+1
	cout << "JUGADA CANCELADA DE ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << jugador1;
	Console::ForegroundColor = ConsoleColor::White;
	cout << " :";
	Console::ForegroundColor = ConsoleColor::Red;
	cout<< contador_cancela1;
	posicion(45, 7);//+1
	Console::ForegroundColor = ConsoleColor::White;
	cout << "JUGADA CANCELADA DE ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << jugador2;
	Console::ForegroundColor = ConsoleColor::White;
	cout << " :";
	Console::ForegroundColor = ConsoleColor::Red;
	cout << contador_cancela2;
	Console::ForegroundColor = ConsoleColor::White;
}
bool mostrarGanador() {
	cout << endl;
	if (tablerobase[0][12] == 'A' && tablerobase[1][11] == 'A' && tablerobase[1][13] == 'A' && tablerobase[2][10] == 'A' && tablerobase[2][12] == 'A'
		&& tablerobase[2][14] == 'A' && tablerobase[3][9] == 'A' && tablerobase[3][11] == 'A' && tablerobase[3][13] == 'A' && tablerobase[3][15] == 'A') {
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << jugador2 << "DEL EQUIPO AZUL";
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout<<"GANASTE!";
		Console::ForegroundColor = ConsoleColor::White;
		return true;
	}
	if (tablerobase[16][12] == 'R' && tablerobase[15][11] == 'R' && tablerobase[15][13] == 'R' && tablerobase[14][10] == 'R' && tablerobase[14][12] == 'R'
		&& tablerobase[14][14] == 'R' && tablerobase[13][9] == 'R' && tablerobase[13][11] == 'R' && tablerobase[13][13] == 'R' && tablerobase[13][15] == 'R') {
		Console::ForegroundColor = ConsoleColor::Red;
		cout << jugador1 << "DEL EQUIPO ROJO";
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "GANASTE!";
		Console::ForegroundColor = ConsoleColor::White;
		return true;
	}
}
void pintar() {
	system("cls");
	Console::ForegroundColor = ConsoleColor::Red;
	cout << " Jugador1 equipo rojo: ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << jugador1;
	Console::ForegroundColor = ConsoleColor::White;
	cout << " | ";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << " Jugador2 equipo azul: ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << jugador2 << endl;
	Console::ForegroundColor = ConsoleColor::White;
	cout << endl;
	
	mostrarGuia();
	mostrarJugadas();
	posicion(0, 2);
	cout << endl;
									
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 25; j++) {

			if (tablerobase[i][j] == 9) {
				cout << " ";
			}
			else {
				if (tablerobase[i][j] == 'R') {
					Console::ForegroundColor = ConsoleColor::Red;
					cout << tablerobase[i][j];
					Console::ForegroundColor = ConsoleColor::White;
				}
				if (tablerobase[i][j] == 'O') {
					Console::ForegroundColor = ConsoleColor::White;
					cout << tablerobase[i][j];
				}
				if (tablerobase[i][j] == 'A') {
					Console::ForegroundColor = ConsoleColor::Blue;
					cout << tablerobase[i][j];
					Console::ForegroundColor = ConsoleColor::White;
				}
			}
		}
		cout << endl;
	}
	mostrarGanador();
}
/*
void SeleccionaYPinta(int cordX, int cordY,int x, int y, char posicion) {
	system("cls");
	tablerobase[cordX][cordY] = 'S';
	pintar();
	cout << endl;
	cout << "Ingrese fila [X]: "; cin >> x;
	cout << "Ingrese columna [Y]: "; cin >> y;

	tablerobase[x][y] = posicion;
	cout << tablerobase[x][y];
	tablerobase[cordX][cordY] = 'O';
	system("cls");
	pintar();
}
*/
int BuscayPinta(int xa, int ya,int xf,int yf, string txtEquipo) {
	if (mostrarGanador() == true) {
		getch();
	}
	bool ok;
	if (txtEquipo == "ROJO") {
		cout << endl;
		cout << "TURNO (" << txtEquipo << ") - Busque la ficha que se movera : " << endl;
		cout << "Ingrese fila [X]: "; cin >> xa;
		cout << "Ingrese columna [Y]: "; cin >> ya;
		//pintar();
		cout << "TURNO (" << txtEquipo << ") - A donde deseas mover la ficha : " << endl;
		cout << "Ingrese fila [X]: "; cin >> xf;
		cout << "Ingrese columna [Y]: "; cin >> yf;
		char op1;
		cout << "Ingrese (T) ó (t) si tu jugada terminó, para cancelar jugada ingrese cualquier otra letra [A-Z] ó [a-z]: ";
		cin >> op1;
		if (op1 == 'T' || op1 == 't') { //prueba
			ok = true;
			_sleep(500);
			cout << "Jugada terminada de: " << jugador1;
			_sleep(1500);

			if (tablerobase[xa][ya] == 'O' && tablerobase[xf][yf] == 'R' || tablerobase[xf][yf] == 'A') {
				ok = false;
				cout << endl;
				cout << "Error no puede seleccionar o buscar primero un la ficha 'O' y luego colocar la ficha a una ficha R ó A";
				getch();
				pintar();
			}
			else {
				if (tablerobase[xf][yf] == 9 || tablerobase[xa][ya] == 9) {
					ok = false;
					cout << endl;
					cout << "Error en una coordenada ingresada inicial[" << xf << "][" << yf << "] ó final[" << xa << "][" << ya << "] obtuviste un 9";
					getch();
					pintar();
				}
				else {
					ok = true;
					tablerobase[xf][yf] = tablerobase[xa][ya];
					tablerobase[xa][ya] = 'O';
					//cout << tablerobase[xf][yf];
					contador1++;
					system("cls");
					pintar();
				}
				
			}
		}
		else {
			ok = false;
			contador_cancela1++;
			cout << endl;
			_sleep(500);
			cout << jugador1 << " Canceló la jugada...";
			_sleep(1000);
			pintar();
		}
	}
	else {
		cout << endl;
		cout << "TURNO (" << txtEquipo << ") - Busque la ficha que se movera : " << endl;
		cout << "Ingrese fila [X]: "; cin >> xa;
		cout << "Ingrese columna [Y]: "; cin >> ya;
		//pintar();
		cout << "TURNO (" << txtEquipo << ") - A donde deseas mover la ficha : " << endl;
		cout << "Ingrese fila [X]: "; cin >> xf;
		cout << "Ingrese columna [Y]: "; cin >> yf;
		char op1;
		cout << "Ingrese (T) ó (t) si tu jugada terminó, para cancelar jugada ingrese cualquier otra letra [A-Z] ó [a-z]: ";
		cin >> op1;
		if (op1 == 'T' || op1 == 't') { //prueba
			ok = true;
			_sleep(500);
			cout << "Jugada terminada de: " << jugador2;
			_sleep(1500);
			if (tablerobase[xa][ya] == 'O' && tablerobase[xf][yf] == 'R' || tablerobase[xf][yf] == 'A') {
				ok = false;
				cout << endl;
				cout << "Error no puede seleccionar o buscar primero un la ficha 'O' y luego colocar la ficha a una ficha R ó A";
				getch();
				pintar();
			}
			else {
				if (tablerobase[xf][yf] == 9 || tablerobase[xa][ya] == 9) {
					ok = false;
					cout << endl;
					cout << "Error en una coordenada ingresada inicial[" << xf << "][" << yf << "] ó final[" << xa << "][" << ya << "] obtuviste un 9";
					getch();
					pintar();
				}
				else {
					ok = true;
					tablerobase[xf][yf] = tablerobase[xa][ya];
					tablerobase[xa][ya] = 'O';
					//cout << tablerobase[xf][yf];
					contador2++;
					system("cls");
					pintar();
				}

			}
		}
		else {
			ok = false;
			contador_cancela2++;
			cout << endl;
			_sleep(500);
			cout << jugador2 << " Canceló la jugada";
			_sleep(1000);
			pintar();
		}
	}
	return ok;
}
void moverFicha() {

	int x, y;
	int ficha;
	int xa, ya,xf,yf;
	bool turn = true;
	int estado = 0;
	while(true){
		
		switch (estado){
			case 0:
				//si ingresa T es true = 1 almacenado con la variable ok
				(estado == BuscayPinta(xa, ya, xf, yf, "ROJO") ? estado = 0 : estado = 1);
				/*
				switch (ficha) {
					case 0:
						SeleccionaYPinta(3,15,x,y, '0'); //4 //14
						break;
					case 1:
						SeleccionaYPinta(0, 12, x, y, '1'); 
						break;
					case 2:
						SeleccionaYPinta(1, 11, x, y, '2');
						break;
					case 3:
						SeleccionaYPinta(1, 13, x, y, '3');
						break;
					case 4:
						SeleccionaYPinta(2, 14, x, y, '4');
						break;
					case 5:
						SeleccionaYPinta(2, 12, x, y, '5');
						break;
					case 6:
						SeleccionaYPinta(2, 10, x, y, '6');
						break;
					case 7:
						SeleccionaYPinta(3, 9, x, y, '7');
						break;
					case 8:
						SeleccionaYPinta(3, 11, x, y, '8');
						break;
					case 9:
						SeleccionaYPinta(3, 13, x, y, '9');
						break;
				}
				*/
				//turn = false;
				break;
			case 1:
				(estado == BuscayPinta(xa, ya, xf, yf, "AZUL") ? estado = 0 : estado = 1);
				/*
				cout << endl;
				cout << "TURNO (AZUL) - Ingrese la ficha a mover: ";
				cin >> ficha;
				switch (ficha) {
					case 0:
						SeleccionaYPinta(13, 15, x, y, '0'); //12 /14
						break;
					case 1:
						SeleccionaYPinta(16, 12, x, y, '1');
						break;
					case 2:
						SeleccionaYPinta(15, 11, x, y, '2');
						break;
					case 3:
						SeleccionaYPinta(15, 13, x, y, '3');
						break;
					case 4:
						SeleccionaYPinta(14, 14, x, y, '4');
						break;
					case 5:
						SeleccionaYPinta(14, 12, x, y, '5');
						break;
					case 6:
						SeleccionaYPinta(14, 10, x, y, '6');
						break;
					case 7:
						SeleccionaYPinta(13, 9, x, y, '7');
						break;
					case 8:
						SeleccionaYPinta(13, 11, x, y, '8');
						break;
					case 9:
						SeleccionaYPinta(13, 13, x, y, '9');
						break;
				}
				*/
				//turn = true;
				break;
		}
	} 
	
}

void juegonuevo()
{
	
	AniadirJugador();
	mostrarJugadas();
	mostrarGuia();
	
	cout << endl;
	
		for (int i = 0; i < 17; i++) {
			
			for (int j = 0; j < 25; j++) {
				
				if (tablerobase[i][j] == 9) {
					cout << " ";
				}
				else {
					if (tablerobase[i][j] == 'R') {
						Console::ForegroundColor = ConsoleColor::Red;
						cout << tablerobase[i][j];
					}
					if (tablerobase[i][j] == 'O') {
						Console::ForegroundColor = ConsoleColor::White;
						cout << tablerobase[i][j];						
					}
					if (tablerobase[i][j] == 'A') {
						Console::ForegroundColor = ConsoleColor::Blue;
						cout << tablerobase[i][j];
						Console::ForegroundColor = ConsoleColor::White;
					}
				}
			}
			cout << endl;
		}

		moverFicha();
		getch();
}

int main()
{
	setlocale(LC_ALL, "");
	int op;
	bool estado = true;
	do {
			_sleep(500);
			cout << "***************** Menu Principal - DAMAS CHINAS *****************" << endl;
			_sleep(1000);
			cout << endl;
			cout << "               (1) Iniciar juego." << endl;
			cout << "               (2) Mostrar reglas." << endl;
			cout << "               (3) Mostrar creditos." << endl;
			cout << "               (4) Salir del juego." << endl;
			_sleep(1000);
			cout << endl;
			cout << "*****************************************************************"<<endl;
			cout << "Por favor ingresar una opcion mostrada :"; cin >> op;
			

			//se ejecuta el código de arriba mientras el op
			//cumpla o ingrese una opcion mostrada
			switch (op) {
			
			case 1:
				system("cls");
				juegonuevo();
				break;
			case 2:
				system("cls");
	
				cout << endl;
				for (int i; i < 120; i++) {
					Console::ForegroundColor = ConsoleColor::DarkMagenta;
					cout << "*";
					Console::ForegroundColor = ConsoleColor::White;
				}
				cout << endl; cout << endl;
				cout << "\t\t\tREGLAS" << endl;
				cout << "\t\to Se juega en un tablero con 121 casillas en forma de estrella de David, (de seis puntas)." << endl;
				cout << "\t\to Cada equipo consta de diez fichas o piezas. Al empezar el juego, estas diez fichas de un mismo " <<
					"jugador"; 
				cout<<"\t\t\t  estan juntas, en uno de los triángulos que forman las puntas de la estrella." << endl;
				cout << "\t\to Cada uno de los equipos tiene un color diferente o una característica que las distinga de las "
					<< "de otro ";
				cout<< "\t\t\t  jugador." << endl;
				cout << "\t\to Generalmente, las 121 posiciones del tablero tienen forma de " <<
					"agujeros en los que se encajan las piezas.";
					cout << "\t\t  Este diseño ayuda a dejar clara la regla de sólo puede haber una pieza por casilla." << endl;
					cout << "\t\to El objetivo del juego es llevar las 10 fichas o piezas de un equipo "
						<< "desde una punta hasta la opuesta.";
					cout << "\t\t\t  Por ejemplo, el dibujo ASCII " <<
						" siguiente muestra una disposición inicial del juego para seis ";
					cout<< "\t\t\t\t\t  participantes, A, B, R, C, N y V" << endl;
				cout << "\t\to R mueve sus fichas desde la zona con la letra R hasta la zona " <<
					"Opuesta con la letra V" << endl;
				cout << "\t\to R mueve sus fichas desde la zona con la letra R hasta la zona "<<
					"Opuesta con la letra V;" << endl;
				cout << "\t\to Y lo mismo para las siguientes." << endl;
				cout << endl; cout << endl;
				for (int i; i < 120; i++) {
					Console::ForegroundColor = ConsoleColor::DarkMagenta;
					cout << "*";
					Console::ForegroundColor = ConsoleColor::White;
				}
				cout << endl << endl;
				cout << "Regresar al menu principal (1):"; cin >> op;
				break;

			case 3:
				system("cls");
				
				cout << endl;
				for (int i; i < 70;i++) {
					Console::ForegroundColor = ConsoleColor::Red;
					cout << "*";
					Console::ForegroundColor = ConsoleColor::White;
				}
				cout << endl; cout << endl;
				cout << "\t\t\tCREDITOS DEL JUEGO" << endl;

				cout << "\t\to Davis Perez Guzman - U202021265" << endl,
				cout << "\t\to Daniel - Vasquez Ventura - U202018456" << endl;
				cout << "\t\to Joseph Degaldo Aguirre - U202017568" << endl;
				cout << endl; cout << endl;
				for (int i; i < 70; i++) {
					Console::ForegroundColor = ConsoleColor::Red;
					cout << "*";
					Console::ForegroundColor = ConsoleColor::White;
				}
				cout << endl << endl;
				cout << "Regresar al menu principal (1):"; cin >> op;
				//getch();
				break;                         
			case 4: //saliendo del juego
				exit(0);
				break;
			}
			system("cls");
		

	} while (op != 4);

}
