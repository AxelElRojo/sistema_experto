#include "cNodo.hpp"
#include "funciones.hpp"
void cNodo::ponerDato(std::string sNuevo){
	this->sDato = sNuevo;
}
void cNodo::insertar(std::string sNuevo){
	if(toTheLeft(sNuevo))
		if(this->pIzq==nullptr)
			pIzq = new cNodo(sNuevo);
		else
			pIzq->insertar(sNuevo);
	else
		if(this->pDer==nullptr)
			pDer = new cNodo(sNuevo);
		else
			pDer->insertar(sNuevo);
}
bool cNodo::toTheLeft(std::string sNuevo){
	return leerSN();
}
void cNodo::inOrder(){
	static std::ofstream salida("arbol.inOrder");
	if(this == nullptr)
		return;
	this->pIzq->inOrder();
	salida << (pIzq!=nullptr) << " " << (pDer!=nullptr) << " " << sDato << std::endl;
	this->pDer->inOrder();
}
void cNodo::preOrder(){
	static std::ofstream salida("arbol.preOrder");
	if(this == nullptr)
		return;
	salida << (this->pIzq!=this->pDer) << " " << this->sDato << std::endl;
	if(pIzq!=nullptr)
		this->pIzq->preOrder();
	if(pDer!=nullptr)
		this->pDer->preOrder();
}
void cNodo::postOrder(){
	static std::ofstream salida("arbol.postOrder");
	if(this == nullptr)
		return;
	if(pIzq!=nullptr)
		this->pIzq->postOrder();
	if(pDer!=nullptr)
		this->pDer->postOrder();
	salida << (pIzq!=nullptr) << " " << (pDer!=nullptr) << " " << sDato << std::endl;
}
int cNodo::cantHijos(){
	if(pIzq == nullptr && pDer == nullptr)
		return 0;
	else if(pIzq == nullptr && pDer != nullptr || pIzq != nullptr && pDer == nullptr)
		return 1;
	else if(pIzq != nullptr && pDer != nullptr)
		return 2;
	else
		return 0;
}
cNodo* cNodo::buscarExtremo(){
	cNodo* buscar = this;
	while(buscar->pDer != nullptr && buscar != nullptr)
		buscar = buscar->pDer;
	return buscar;
}
cNodo* cNodo::dameUnicoHijo(){
	if(pIzq != nullptr)
		return pIzq;
	else if(pDer != nullptr)
		return pDer;
	else
		return nullptr;
}
void cNodo::insertarIzq(std::string nuevo){
	this->pIzq = new cNodo(nuevo);
}
void cNodo::insertarDer(std::string nuevo){
	this->pDer = new cNodo(nuevo);
}
void cNodo::cargar(){
	static std::ifstream entradaPre("arbol.preOrder");
	std::string sDato;
	bool esRama;
	if(entradaPre.eof())
		return;
	entradaPre >> esRama;
	entradaPre.ignore();
	std::getline(entradaPre, sDato);
	this->sDato = sDato;
	if(esRama){
		this->pIzq = new cNodo;
		this->pDer = new cNodo;
	}
	if(pIzq != nullptr)
		pIzq->cargar();
	if(pDer != nullptr)
		pDer->cargar();
}