
#include "Elem.h"
typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
}*ApNodo;
typedef struct CNodo{
	ApNodo sal;
	ApNodo ent;
}*Cola;

Cola nueva(){
	Cola t=(Cola)malloc(sizeof(struct CNodo));
	t->sal=t->ent=NULL;
	return t;
}
int esNueva(Cola q){
	return ((q->sal==NULL)&&(q->ent==NULL));
}
Cola formar(Cola q,Elem e){
	ApNodo t=(ApNodo)malloc(sizeof(struct CNodo));
	t->dato=e;
	t->sig=NULL;
	if(esNueva(q)){
		q->ent=q->sal=t;
	}else{
		q->ent->sig=q->ent=t;
	}
	return q;
}
Elem primero(Cola q){
	return q->sal->dato;
}
Cola desformar(Cola q){
	ApNodo t=(ApNodo)malloc(sizeof(struct CNodo));
	if (q->sal==q->ent){
		return nueva();
	}else{
		t=q->sal;
		q->sal=q->sal->sig;
		free(t);
		return q;
	}
}

void ImpCola2(Cola q){
	ApNodo temp2=(ApNodo)malloc(sizeof(struct CNodo));
	if (!esNueva(q)){
		temp2->dato=(*q).sal->dato;
		ImpElem(temp2->dato);
		ImpCola2(desformar(temp2));
	}
	free(temp2);
}
void ImpCola(Cola q){
	Cola temp2=nueva();
	if (!esNueva(q)){
		temp2->sal=(*q).sal;
		temp2->ent=(*q).ent;
		ImpElem(primero(temp2));
		ImpCola(desformar(temp2));
	}
	free(temp2);
}