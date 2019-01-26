#include "ArbolBin.h"

typedef Arbin Heap;

Heap hazHeap(Elem e, Heap i, Heap d){
    if(esVacioAB(i)){
        return consAB(e,vacioAB(),vacioAB());
        //return consAB(e,i,vacioAB());
    }else if(esVacioAB(d)){
        if(raiz(i)<=e)
            return consAB(e,i,vacioAB());
        else
            return consAB(raiz(i),consAB(e,vacioAB(),vacioAB()),vacioAB());
    }else if(esMayorIgual(e,raiz(i))&&esMayorIgual(e,raiz(d))){
        return consAB(e,i,d);
    }else if(esMayor(raiz(i),raiz(d))){
        return consAB(raiz(i),hazHeap(e,izqAB(i),derAB(i)),d);
    }else{
        return consAB(raiz(d),i,hazHeap(e,izqAB(d),derAB(d)));
    }
}
Heap ConsHeap(Arbin a){
    if(esVacioAB(a))
        return a;
    else if((AlturaAB(izqAB(a))-AlturaAB(derAB(a)))<=1)
        return hazHeap(raiz(a),ConsHeap(izqAB(a)),ConsHeap(derAB(a)));
}
Arbin InsertaElems(Lista l, Arbin a){
    if(esvacia(l)){
        return a;
    }else{
        return InsertaElems(resto(l),hazCompleto(cabeza(l),a));
    }
}
Elem UltimoElem(Arbin a){
    if(esHoja(a)){
        return raiz(a);
    }else if(esLLeno(a)){
        return UltimoElem(derAB(a));
    }else if(AlturaAB(izqAB(a))==AlturaAB(derAB(a))) {
        return UltimoElem(derAB(a));
    }else{
        return UltimoElem(izqAB(a));
    }
}
Arbin BorraUltimoElem(Arbin a){
    if(esHoja(a)){
        return vacioAB();
    }else if(esLLeno(a)){
        return consAB(raiz(a),izqAB(a),BorraUltimoElem(derAB(a)));
    }else if(AlturaAB(izqAB(a))==AlturaAB(derAB(a))) {
        return consAB(raiz(a),izqAB(a),BorraUltimoElem(derAB(a)));
    }else{
        return consAB(raiz(a),BorraUltimoElem(izqAB(a)),derAB(a));
    }
}
