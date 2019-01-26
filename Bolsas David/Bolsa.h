#include "Lista.h"
typedef Lista Bolsa;
Bolsa vacioB(){
    return vacia();
}
int esVacioB(Bolsa s1){
    return esvacia(s1);
}
int EstaEnB(Elem e1,Bolsa s1){
    return EstaEn(e1,s1);
}
Bolsa InsertaB(Elem e1,Bolsa s1){
    if(esVacioB(s1))
        return cons(e1,s1);
    else
        return cons(e1,s1);
}
Bolsa EliminarElemB(Elem e1, Bolsa s1){
    return EliminarElem(e1,s1);
}
void ImpBolsa(Bolsa s1){
    ImpLista(s1);
} 
Bolsa unionB(Bolsa s1, Bolsa s2){
    if(esVacioB(s2))
        return s1;
    else if(EstaEnB(cabeza(s2),s1))
        return unionB(s1,resto(s2));
    else
        return unionB(InsertaB(cabeza(s2),s1),resto(s2));
}
Bolsa interseccionB(Bolsa s1, Bolsa s2){
    if(esVacioB(s2))
        return vacioB();
    else if(EstaEnB(cabeza(s2),s1))
        return InsertaB(cabeza(s2),interseccionB(s1,resto(s2)));
    else
        return interseccionB(s1,resto(s2));
}
Bolsa diferenciaB(Bolsa s1, Bolsa s2){
    if(esVacioB(s2)){
        return s1;
    }else if(EstaEnB(cabeza(s2),s1)){
        return diferenciaB(EliminarElemB(cabeza(s2),s1),resto(s2));
    }else if(!EstaEnB(cabeza(s2),s1)){
        return diferenciaB(s1,resto(s2));
    }
}
int cardinalidadB(Bolsa s1){
    if(esVacioB(s1)){
        return 0;
    }else{
         return 1+cardinalidadB(resto(s1));
    }
}
 /*printf("\ncabeza:");
    ImpElem(cabeza(s2));
    printf("\nConjutnos 1 =");
    ImpBolsa(s1);
    printf("\nConjutnos 2 =");
    ImpBolsa(s2);
    printf("\n");*/