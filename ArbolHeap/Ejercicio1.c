#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Elem.h"
#include "Lista.h"
#include "ArbolHeap.h"

int main(void){
    Arbin a=vacioAB();

    Lista l=cons(54,cons(25,cons(43,cons(60,cons(16,cons(48,cons(49,vacia())))))));
    printf("Lista: \n");
    ImpLista(l);

    a=InsertaElems(l,a);

    printf("\nArbol: \n");
    ImprimirAB(a);

    printf("\nArbol heap: \n");
    a=ConsHeap(a);
    ImprimirAB(a);

    printf("\nUltimo Elemento: \n");
    ImpElem(UltimoElem(a));
    
    printf("\n Borra Ultimo Elemento: \n");
    a=BorraUltimoElem(a);
    ImprimirAB(a);

    return 0;
}