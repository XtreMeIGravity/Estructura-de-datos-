
#include "Lista.h"
typedef Lista Cola;
int esNueva(Cola q){
	return esvacia(q);
}
Cola nueva(){ return vacia();}
Cola formar(Cola q, Elem e){
	if (esNueva(q)){
		return cons(e,q);
	}else{
		return cons(cabeza(q),formar(resto(q),e));
	}
}
Elem primer(Cola q){
	return cabeza(q);
}
Cola desformar(Cola q){
	return resto(q);
}
void ImpCola(Cola q){
	ImpLista(q);
}
