#include <stdio.h>
#include <stdlib.h>

#include "Elem.h"
#include "conjuntos.h"

int main(){
    Conjunto s1=vacioC();
    s1=InsertaC('a',InsertaC('e',InsertaC('a',InsertaC('i',InsertaC('o',InsertaC('u',s1))))));
    Conjunto s2=vacioC();
    s2=InsertaC('a',InsertaC('b',InsertaC('c',InsertaC('d',InsertaC('e',s2)))));
    Conjunto s3=vacioC();
    s3=InsertaC('x',InsertaC('i',InsertaC('y',InsertaC('z',InsertaC('w',s3)))));

    printf("\nPrimero\n");
    ImpConjunto(s1);
    printf("\nSegundo\n");
    ImpConjunto(s2);

    printf("\nEliminar a c sin guardar en s2\n");
    ImpConjunto(EliminarElemC('c',s2));

    printf("\nUnion\n");
    ImpConjunto(unionC(s1,s2));

    printf("\nInterseccion\n");
    ImpConjunto(interseccionC(s1,s2));
    
    printf("\nCardinalidad\n");
    printf("%d",cardinalidadC(s1));

    printf("\nDiferencia s1 - s2\n");
    ImpConjunto(diferenciaC(s1,s2));

    printf("\nC^(A-B)\n");
    ImpConjunto(interseccionC(s3,diferenciaC(s1,s2)));

    printf("\n");
    return 0;
}