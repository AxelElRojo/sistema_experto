#pragma once
#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
bool leerSN(){
	char letra = 0;
	std::cout << "(s/n): ";
	while(letra != 'S' && letra != 's' && letra != 'N' && letra!='n')
		std::cin >> letra;
	return (letra == 'S' || letra == 's');
}
int menu(){
	int opc;
	std::cout << "1. Buscar\n2. Cargar\n3. Guardar\n4. Salir\nEscoja una opción: ";
	std::cin >> opc;
	return opc;
}
void pausa(){
	std::cout << "Presione enter para continuar...";
	std::cin.ignore();
	while(std::cin.get()!='\n');
	std::system(CLEAR);
}