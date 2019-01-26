#include "Lista.h"
typedef Lista Conjunto;
Conjunto vacioC(){
    return vacia();
}
int esVacioC(Conjunto s1){
    return esvacia(s1);
}
int EstaEnC(Elem e1,Conjunto s1){
    return EstaEn(e1,s1);
}
Conjunto InsertaC(Elem e1,Conjunto s1){
    if(esVacioC(s1))
        return cons(e1,s1);
    else if(EstaEn(e1,s1))
        return s1;
    else
        return cons(e1,s1);
}
Conjunto EliminarElemC(Elem e1, Conjunto s1){
    return EliminarElem(e1,s1);
}
void ImpConjunto(Conjunto s1){
    ImpLista(s1);
} 
Conjunto unionC(Conjunto s1, Conjunto s2){
    if(esVacioC(s2))
        return s1;
    else if(EstaEnC(cabeza(s2),s1))
        return unionC(s1,resto(s2));
    else
        return unionC(InsertaC(cabeza(s2),s1),resto(s2));
}
Conjunto interseccionC(Conjunto s1, Conjunto s2){
    if(esVacioC(s2))
        return vacioC();
    else if(EstaEnC(cabeza(s2),s1))
        return InsertaC(cabeza(s2),interseccionC(s1,resto(s2)));
    else
        return interseccionC(s1,resto(s2));
}
Conjunto diferenciaC(Conjunto s1, Conjunto s2){
    if(esVacioC(s2)){
        return s1;
    }else if(EstaEnC(cabeza(s2),s1)){
        return diferenciaC(EliminarElemC(cabeza(s2),s1),resto(s2));
    }else if(!EstaEnC(cabeza(s2),s1)){
        return diferenciaC(s1,resto(s2));
    }
}
int cardinalidadC(Conjunto s1){
    if(esVacioC(s1)){
        return 0;
    }else{
         return 1+cardinalidadC(resto(s1));
    }
}
 /*printf("\ncabeza:");
    ImpElem(cabeza(s2));
    printf("\nConjutnos 1 =");
    ImpConjunto(s1);
    printf("\nConjutnos 2 =");
    ImpConjunto(s2);
    printf("\n");*/