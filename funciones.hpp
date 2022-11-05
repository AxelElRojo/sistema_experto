#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
bool leerSN();
int menu();
void pausa();
#endif