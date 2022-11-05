#include "funciones.hpp"
bool leerSN(){
	std::string letra = "";
	std::cout << "(s/n): ";
	while(letra[0] != 'S' && letra[0] != 's' && letra[0] != 'N' && letra[0] != 'n')
		std::cin >> letra;
	std::cin.ignore();
	return (letra[0] == 'S' || letra[0] == 's');
}
int menu(){
	int opc;
	std::cout << "1. Buscar\n2. Cargar\n3. Guardar\n4. Desarrollador\n5. Salir\nEscoja una opción: ";
	std::cin >> opc;
	return opc;
}
void pausa(){
	std::cout << "Presione enter para continuar...";
	std::cin.ignore();
	while(std::cin.get()!='\n');
	std::system(CLEAR);
}