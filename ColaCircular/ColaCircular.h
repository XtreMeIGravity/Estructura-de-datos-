#include "Elem.h"

typedef struct Nodo{
	Elem dato;
	struct Nodo*sig;
}*Circular;
int esNuevaC(Circular q){
	return q==NULL;
}
Circular nuevaC(){
	return NULL;
}
Circular formarC(Circular q,Elem e){
	Circular t=(Circular)malloc(sizeof(struct Nodo));
	t->dato=e;
	if (esNuevaC(q)){
		q=t;
		q->sig=q;
	}else{
		t->sig=q->sig;
		q->sig=t;
	}
	return t;
}
Elem primerC(Circular q){
	return q->sig->dato;
}
Circular desformarC(Circular q){
	Circular t;
	if (q==q->sig){
		return nuevaC();
	}else{
		t=q->sig;
		q->sig=q->sig->sig;
		free(t);
		return q;
	}
}
Circular rotar(Circular q){
	return q->sig;
}
