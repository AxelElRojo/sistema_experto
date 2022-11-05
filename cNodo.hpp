#ifndef NODO_HPP
#define NODO_HPP
#include <iostream>
#include <fstream>
#include <sstream>
class cNodo{
	std::string sDato;
	cNodo *pIzq, *pDer;
	friend class cArbol;
	cNodo():pIzq(nullptr),pDer(nullptr),sDato(""){}
	cNodo(std::string sNuevo):pIzq(nullptr),pDer(nullptr),sDato(sNuevo){}
	void insertar(std::string);
	bool toTheLeft(std::string);
	void inOrder();
	void preOrder();
	void postOrder();
	int cantHijos();
	void ponerDato(std::string);
	cNodo* dameUnicoHijo();
	cNodo* buscarExtremo();
	void insertarIzq(std::string);
	void insertarDer(std::string);
	void cargar();
};
#endif