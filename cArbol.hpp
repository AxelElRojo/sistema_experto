#pragma once
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
void cArbol::insertar(std::string sDato){
	if(pRaiz==nullptr)
		pRaiz = new cNodo(sDato);
	else
		pRaiz->insertar(sDato);
}
void cArbol::inOrder(){
	if(pRaiz!=nullptr)
		pRaiz->inOrder();
}
void cArbol::preOrder(){
	if(pRaiz!=nullptr)
		pRaiz->preOrder();
}
void cArbol::postOrder(){
	if(pRaiz!=nullptr)
		pRaiz->postOrder();
}
cNodo* cArbol::buscarMalPadre(std::string sDato){
	cNodo* pActual = pRaiz;
	if(pRaiz->sDato == sDato)
			return pRaiz;
	while(pActual!=nullptr){
		if(pActual->toTheLeft(sDato)){
			if(pActual->pIzq->sDato == sDato)
				return pActual;
			else
				pActual = pActual->pIzq;
		}else
			if(pActual->pDer->sDato == sDato)
				return pActual;
			else
				pActual = pActual->pDer;
	}
	return nullptr;
}
void cArbol::eliminar(std::string sDato){
	cNodo* malPadre = buscarMalPadre(sDato);
	int cantHijos;
	if(pRaiz != nullptr && pRaiz->sDato == sDato){
		cantHijos = pRaiz->cantHijos();
		switch(cantHijos){
			case 0:
				delete pRaiz;
				pRaiz = nullptr;
			break;
			case 1:{
				cNodo* aux = pRaiz->dameUnicoHijo();
				delete pRaiz;
				pRaiz = aux;
			}break;
			case 2:{
				cNodo* nietoIzq, *nietoDer, *extremo;
				nietoIzq = pRaiz->pIzq;
				nietoDer = pRaiz->pDer;
				extremo = nietoIzq->buscarExtremo();
				delete pRaiz;
				pRaiz = nietoIzq;
				extremo->pDer = nietoDer;
			}break;
			default:
			break;
		}
	}else if(malPadre->toTheLeft(sDato)){
		cantHijos = malPadre->pIzq->cantHijos();
		switch(cantHijos){
			case 0:
				delete malPadre->pIzq;
				malPadre->pIzq = nullptr;
			break;
			case 1:{
				cNodo* nodoAux = malPadre->pIzq->dameUnicoHijo();
				delete malPadre->pIzq;
				malPadre->pIzq = nodoAux;
			}break;
			case 2:{
				cNodo* nodoNietoIzq = malPadre->pIzq->pIzq, *nodoNietoDer = malPadre->pIzq->pDer, *aux;
				aux = nodoNietoIzq->buscarExtremo();
				delete malPadre->pIzq;
				malPadre->pIzq = nodoNietoIzq;
				aux->pDer = nodoNietoDer;
			}break;
			default:
			break;
		}
	}else{
		cantHijos = malPadre->pDer->cantHijos();
		switch(cantHijos){
			case 0:
				delete malPadre->pDer;
				malPadre->pDer = nullptr;
			break;
			case 1:{
				cNodo* nodoAux = malPadre->pDer->dameUnicoHijo();
				delete malPadre->pDer;
				malPadre->pDer = nodoAux;
			}break;
			case 2:{
				cNodo* nodoNietoIzq = malPadre->pDer->pIzq, *nodoNietoDer = malPadre->pDer->pDer, *aux;
				aux = nodoNietoIzq->buscarExtremo();
				delete malPadre->pDer;
				malPadre->pDer = nodoNietoIzq;
				aux->pDer = nodoNietoDer;
			}break;
			default:
			break;
		}
	}
}
bool cArbol::vacio(){
	return pRaiz == nullptr;
}
void cArbol::juego(){
	bool jugando = true, victoria = false;
	std::string nuevo;
	cNodo* pActual = pRaiz, *pAnterior = pRaiz;
	if(vacio())
		victoria = jugando = false;
	while(jugando && !victoria && pActual != nullptr){
		short hijos = pActual->cantHijos();
		pAnterior = pActual;
		switch(hijos){
			case 0:
				std::cout << "Está viendo un " << pActual->sDato << std::endl;
				if(leerSN())
					victoria = true;
				else
					jugando = false;
			break;
			case 1:
				std::cout << "¿El ave que está viendo tiene " << pActual->sDato << '?' << std::endl;
				if(leerSN())
					pActual = pActual->pIzq;
				else
					pActual = pActual->pDer;
			break;
			case 2:
				std::cout << "¿El ave que está viendo tiene " << pActual->sDato << '?' << std::endl;
				if(leerSN())
					pActual = pActual->pIzq;
				else
					pActual = pActual->pDer;
			break;
			default:
			break;
		}
	}
	if(!jugando && !victoria && vacio()){
		std::cout << "Perdí, ingrese el ave que está viendo: ";
		std::cin.ignore();
		std::getline(std::cin,nuevo);
		this->insertar(nuevo);
	}else if(!jugando && !victoria){
		std::string descripNuevo;
		std::cout << "Perdí, ingrese el ave que está viendo: ";
		std::cin.ignore();
		std::getline(std::cin,nuevo);
		std::cout << "Dime algo que " << nuevo << " tenga y que " << pActual->sDato << " no: ";
		std::cin.ignore();
		std::getline(std::cin,descripNuevo);
		pActual->insertarIzq(nuevo);
		pActual->insertarDer(descripNuevo);
		std::swap(pActual->sDato,pActual->pDer->sDato);
	}else if(victoria)
		std::cout << "Resultado encontrado" << std::endl;
	pausa();
}
void cArbol::cargar(){
	pRaiz = new cNodo;
	pRaiz->cargar();
}