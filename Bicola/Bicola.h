#include "Elem.h"
typedef struct NodoPrincipal{
	struct NodoPrincipal*izqN;
	Elem dato;
	struct NodoPrincipal*derN;
}*ApNodo;
typedef struct CNodo{
	ApNodo izq;
	ApNodo der;
}*Bicola;
Bicola nuevaB(){
	Bicola t=(Bicola)malloc(sizeof(struct CNodo));
	t->izq=t->der=NULL;
	return t;
}
int esNuevaB(Bicola q){	return ((q->izq==NULL)&&(q->der==NULL));}
Bicola formarBI(Elem e,Bicola q){
	ApNodo t=(ApNodo)malloc(sizeof(struct NodoPrincipal));
	t->dato=e;
	t->izqN=NULL;
	if (esNuevaB(q)){
		q->izq=q->der=t;
	}else{
		t->derN=q->izq;
		q->izq->izqN=q->izq=t;
	}
	return q;
}
Elem izquierdo(Bicola q){	return q->izq->dato;}
Bicola formarBD(Bicola q,Elem e){
	ApNodo t=(ApNodo)malloc(sizeof(struct NodoPrincipal));
	t->dato=e;
	t->derN=NULL;
	if (esNuevaB(q)){
		q->der=q->izq=t;
	}else{
		t->izqN=q->der;
		q->der->derN=q->der=t;
	}	
	return q;
}
Elem derecho(Bicola q){	return q->der->dato;}
Bicola desformarBI(Bicola q){
	ApNodo t;
	if (q->izq==q->der){
		return nuevaB();
	}else{
		t=q->izq;
		q->izq=q->izq->derN;
		q->izq->izqN=NULL;
		free(t);
		return q;
	}
}
Bicola desformarBD(Bicola q){
	ApNodo t;
	if (q->izq==q->der){
		return nuevaB();
	}else{
		t=q->der;
		q->der=q->der->izqN;
		q->der->derN=NULL;
		free(t);
		return q;
	}
}
void ImpBCI(Bicola q){
	ApNodo t=q->izq;
	while(t!=NULL){
		ImpElem(t->dato);
		t=t->derN;
	}	
}
void ImpBCD(Bicola q){
	ApNodo t=q->der;
	while(t!=NULL){
		ImpElem(t->dato);
		t=t->izqN;
	}	
}	
Bicola ImpBCI2(Bicola q){
	Bicola t=(Bicola)malloc(sizeof(struct CNodo));
	t=nuevaB();
	while(!esNuevaB(q)){
		ImpElem(izquierdo(q));
		t=formarBD(t,izquierdo(q));
		q=desformarBI(q);
	}
	return t;
}	
Bicola ImpBCD2(Bicola q){
	Bicola t=(Bicola)malloc(sizeof(struct CNodo));
	t=nuevaB();
	while(!esNuevaB(q)){
		ImpElem(derecho(q));
		t=formarBI(derecho(q),t);
		q=desformarBD(q);
	}
	return t;
}
