#include "Lista.h"

typedef Lista ColaPeor;

ColaPeor InsertarCP(Elem e,ColaPeor cp){
    return InsOrd(e,cp);
}
ColaPeor VaciaCP(){
    return vacia();
}
ColaPeor EliminarElemCP(Elem e1,ColaPeor cp){
    return EliminarElem(e1,cp);
}
ColaPeor EliminarElemCPEstrict(Elem e1,ColaPeor cp){
    if(esvacia(cp)){
        return vacia();
    }else if(sonIgualEstricto(e1,cabeza(cp))){
        return  resto(cp);
    }else{
        return cons(cabeza(cp),EliminarElem(e1,resto(cp)));
    }
}
void ImpCP(ColaPeor cp){
    ImpLista(cp);
}