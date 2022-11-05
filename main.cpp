#include <iostream>
#include "funciones.hpp"
#include "cNodo.hpp"
#include "cArbol.hpp"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
enum OPCIONES{JUGAR=1,CARGAR,GUARDAR,DESARROLLADOR,SALIR};
int main(){
	bool bRespuesta;
	int opc;
	cArbol arbol;
	do{
		std::system(CLEAR);
		opc = menu();
		switch(opc){
			case JUGAR:
				arbol.juego();
			break;
			case CARGAR:
				arbol.cargar();
			break;
			case GUARDAR:
				arbol.preOrder();
			break;
			case DESARROLLADOR:
				arbol.desarrollador();
			break;
			case SALIR:
			break;
			default:
				std::cout << "Ingrese una opcion válida" << std::endl;
				pausa();
		}
	}while(opc!=SALIR);
}