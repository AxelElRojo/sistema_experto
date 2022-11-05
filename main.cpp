#include <iostream>
#include "funciones.hpp"
#include "cNodo.hpp"
#include "cArbol.hpp"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
enum OPCIONES{JUGAR=1,CARGAR,GUARDAR,SALIR};
int main(){
	bool bRespuesta;
	int opc;
	cArbol pino;
	do{
		std::system(CLEAR);
		opc = menu();
		switch(opc){
			case JUGAR:
				pino.juego();
			break;
			case CARGAR:
				pino.cargar();
			break;
			case GUARDAR:
				pino.preOrder();
			break;
			case SALIR:
			break;
			default:
			std::cout << "Ingrese una opcion válida" << std::endl;
			pausa();

		}
	}while(opc!=SALIR);
}