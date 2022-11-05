#ifndef ARBOL_HPP
#define ARBOL_HPP
#include <iostream>
#include <cstring>
#include "cNodo.hpp"
class cArbol{
	cNodo* pRaiz;
	public:
	cArbol():pRaiz(nullptr){}
	void insertar(std::string);
	void inOrder();
	void preOrder();
	void postOrder();
	void eliminar(std::string);
	bool vacio();
	void juego();
	void cargar();
	private:
	cNodo* buscarMalPadre(std::string);
};
#endif